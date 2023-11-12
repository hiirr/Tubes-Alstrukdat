#include <stdio.h>
#include "../ADT/Wordmachine.h"
#include "../database/database.h"

void masuk() {
    if (current_user != -1){
        printf("Wah Anda sudah masuk. Keluar dulu yuk!\n");
        return;
    }

    int idx;
    while (true) {
        printf("Masukkan nama:\n");
        get_paragraph();
        char *name = input_to_string();
        boolean is_found = false;
        for (int i = 0; i < total_user; i++){
            if (is_two_string_equal(name, users[i].name)) {
                free(name);
                is_found = true;
                idx = i;
                break;
            }
        }
        if (!is_found) {
            free(name);
            printf("Wah, nama yang Anda cari tidak ada. Masukkan nama lain!\n");
        }
    }

    while (true) {
        printf("Masukkan kata sandi:\n");
        get_paragraph();
        char *password = input_to_string();
        if (is_two_string_equal(password, users[idx].password)) {
            free(password);
            printf("Anda telah berhasil masuk dengan nama pengguna %s. Mari menjelajahi BurBir bersama Ande-Ande Lumut!\n", users[idx].name);
            current_user = idx;
            break;
        }
        else {
            free(password);
            printf("Wah, kata sandi yang Anda masukkan belum tepat. Periksa kembali kata sandi Anda!\n");
        }
    }
}