#include <stdio.h>
#include <stdlib.h>
#include "ganti_profil.h"

#include "../ADT/boolean.h"
#include "../ADT/Wordmachine.h"

#include "../assets/User.h"
#include "../database/database.h"

void ganti_profil() {
    if (current_user == -1) {
        printf("\nAnda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n\n");
        return;
    }

    printf("| Nama: %s\n", users[current_user].name);
    printf("| Bio Akun: %s\n", users[current_user].bio);
    printf("| No HP: %s\n", users[current_user].phone);
    printf("| Weton: %s\n", users[current_user].weton);

    
    printf("Masukkan Bio Akun: \n");
    clear_next_character();
    get_paragraph();
    if (current_input.length > MAX_BIO_LENGTH) {
        printf("Bio terlalu panjang (%d karakter). Panjang maksimum bio adalah %d karakter. Bio Anda akan dipotong.\n", current_input.length, MAX_BIO_LENGTH);
    }
    char *new_bio = input_to_string_limited(MAX_BIO_LENGTH);
    set_user_bio(&users[current_user], new_bio);

    printf("Masukkan No HP: \n");
    while (true) {
        clear_next_character();
        get_paragraph();
        char *new_phone = input_to_string();
        if (is_all_int(new_phone)){
            set_user_phone(&users[current_user], new_phone);
            break;
        } else {
            free(new_phone);
            printf("Nomor HP anda tidak valid, coba ulangi masukan!\n");
        }
    } 

    printf("Masukkan Weton: \n");
    while (true) {
        clear_next_character();
        get_paragraph();
        char *new_weton = input_to_string();
        for (int i = 0; i < current_input.length; ++i) {
            new_weton[i] = to_lower(new_weton[i]);
        }
        if (is_two_string_equal("pahing", new_weton) ||
            is_two_string_equal("kliwon", new_weton) ||
            is_two_string_equal("wage", new_weton) ||
            is_two_string_equal("pon", new_weton) ||
            is_two_string_equal("legi", new_weton) || 
            is_two_string_equal("", new_weton)) {
            set_user_weton(&users[current_user], new_weton);
            break;
        } else {
            free(new_weton);
            printf("Weton anda tidak valid, coba ulangi masukan!\n");
        }
    }

    printf("Profil berhasil diganti.\n\n");
    printf("| Nama: %s\n", users[current_user].name);
    printf("| Bio Akun: %s\n", users[current_user].bio);
    printf("| No HP: %s\n", users[current_user].phone);
    printf("| Weton: %s\n", users[current_user].weton);
}
