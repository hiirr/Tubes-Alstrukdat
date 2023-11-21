#include <stdio.h>
#include <stdlib.h>
#include "atur_jenis_akun.h"

#include "../ADT/boolean.h"
#include "../ADT/Wordmachine.h"

#include "../assets/User.h"
#include "../database/database.h"

void atur_jenis_akun() {
    if (current_user == -1) {
        printf("Anda belum login. Silakan login terlebih dahulu.\n");
        return;
    }

    if (users[current_user].is_public){
        printf("Saat ini, akun Anda adalah akun Publik. Ingin mengubah ke akun Privat? (YA/TIDAK)\n");
        clear_next_character();
        get_word();
        char *answer = input_to_string();
        if (is_two_string_equal("YA", answer)) {
            users[current_user].is_public = false;
            printf("Akun anda telah diubah menjadi akun Privat.\n");
        } else if (is_two_string_equal("TIDAK", answer)) {
            printf("Perubahan menjadi akun privat tidak jadi dilakukan.\n");
        } else {
            printf("Jawaban tidak valid.\n");
        }
        free(answer);
    } else {
        printf("Saat ini, akun Anda adalah akun Privat. Ingin mengubah ke akun Publik? (YA/TIDAK)\n");
        clear_next_character();
        get_word();
        char *answer = input_to_string();
        if (is_two_string_equal("YA", answer)) {
            users[current_user].is_public = true;
            printf("Akun anda telah diubah menjadi akun Publik.\n");
        } else if (is_input_equal("TIDAK")){
            printf("Perubahan menjadi akun publik tidak jadi dilakukan.\n");
        } else {
            printf("Jawaban tidak valid.\n");
        }
        free(answer);
    }
}
