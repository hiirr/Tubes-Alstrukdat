#include <stdio.h>
#include <stdlib.h>
#include "atur_jenis_akun.h"

#include "../ADT/boolean.h"
#include "../ADT/Wordmachine.h"

#include "../assets/User.h"
#include "../database/database.h"

void atur_jenis_akun() {
    if (current_user == -1) {
        printf("Anda belum login\n");
        return;
    }

    if (users[current_user].is_public){
        printf("Saat ini, akun Anda adalah akun Publik. Ingin mengubah ke akun Privat? (YA/TIDAK)\n");
        get_word();
        char *answer = input_to_string();
        if (is_two_string_equal("YA", answer)) {
            users[current_user].is_public = false;
            printf("Akun anda telah diubah menjadi akun Privat\n");
        } else {
            printf("Perubahan tidak jadi dilakukan.\n");
        }
        free(answer);
    } else {
        printf("Saat ini, akun Anda adalah akun Privat. Ingin mengubah ke akun Publik? (YA/TIDAK)\n");
        get_word();
        char *answer = input_to_string();
        if (is_two_string_equal("YA", &answer)) {
            users[current_user].is_public = true;
            printf("Akun anda telah diubah menjadi akun Publik\n");
        } else {
            printf("Perubahan tidak jadi dilakukan.\n");
        }
        free(answer);
    }
}
