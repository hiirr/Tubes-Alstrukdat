#include "ADT/boolean.h"
#include "ADT/Wordmachine.h"
#include "assets/User.h"
#include "database/database.h"

User user[MAX_USER];

void ganti_profil(int id_user){

    printf("| Nama: %c\n", user[id_user].name);
    printf("| Bio Akun: %c\n", user[id_user].bio);
    printf("| No HP: %c\n", user[id_user].phone);
    printf("| Weton: %c\n", user[id_user].weton);

    printf("Masukkan Bio Akun: \n");
    char *new_bio = input_to_string();
    if (!is_current_word_equal("")){
        set_user_bio(&user[id_user], new_bio);
    }

    printf("Masukkan No HP: \n");
    char *new_phone = input_to_string();
    boolean valid = false;
    while (!is_current_word_equal("") && !valid){
        if (is_all_int(new_phone)){
            set_user_bio(&user[id_user], new_phone);
            valid = true;
        } else {
            printf("Nomor HP anda tidak valid, coba ulangi masukan!");
            *new_phone = input_to_string();
        }
    } 

    printf("Masukkan Weton: \n");
    char *new_bio = input_to_string();
    boolean valid = false;
    while (!is_current_word_equal("") && !valid){
        if (is_current_word_equal("Pahing") || is_current_word_equal("pahing") || is_current_word_equal("Kliwon") || is_current_word_equal("kliwon") || is_current_word_equal("Wage") || is_current_word_equal("wage") || is_current_word_equal("Pon") || is_current_word_equal("pon") || is_current_word_equal("Legi") || is_current_word_equal("legi")){
            set_user_bio(&user[id_user], new_bio);
            valid = true;
        } else {
            printf("Weton anda tidak valid, coba ulangi masukan!");
            *new_bio = input_to_string();
        }
    } 
}