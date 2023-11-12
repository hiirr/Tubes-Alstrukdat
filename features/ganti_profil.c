#include <stdio.h>
#include <stdlib.h>
#include "ganti_profil.h"

#include "../ADT/boolean.h"
#include "../ADT/Wordmachine.h"

#include "../assets/User.h"
#include "../database/database.h"

void ganti_profil(){

    printf("| Nama: %c\n", users[current_user].name);
    printf("| Bio Akun: %c\n", users[current_user].bio);
    printf("| No HP: %c\n", users[current_user].phone);
    printf("| Weton: %c\n", users[current_user].weton);

    printf("Masukkan Bio Akun: \n");
    get_paragraph();
    char *new_bio = input_to_string();
    if (!is_current_word_equal("")){
        set_user_bio(&users[current_user], new_bio);
    }

    printf("Masukkan No HP: \n");
    get_word();
    char *new_phone = input_to_string();
    boolean valid = false;
    while (!is_current_word_equal("") && !valid){
        if (is_all_int(new_phone)){
            set_user_phone(&users[current_user], new_phone);
            valid = true;
        } else {
            printf("Nomor HP anda tidak valid, coba ulangi masukan!");
            *new_phone = input_to_string();
        }
    } 

    printf("Masukkan Weton: \n");
    get_word();
    char *new_weton = input_to_string();
    boolean valid = false;
    while (!is_current_word_equal("") && !valid){
        for (int i = 0; i < current_word.length; ++i) {
            new_weton[i] = to_lower(new_weton[i]);
        }
        if (is_two_string_equal("pahing", &new_weton) || is_two_string_equal("kliwon", &new_weton) || is_two_string_equal("wage", &new_weton) || is_two_string_equal("pon", &new_weton) || is_two_string_equal("legi", &new_weton)){
            set_user_weton(&users[current_user], new_weton);
            valid = true;
        } else {
            printf("Weton anda tidak valid, coba ulangi masukan!");
            *new_weton = input_to_string();
        }
    } 
}
