#include <stdio.h>
#include "../ADT/Wordmachine.h"
#include "../database/database.h"

void masuk(){
    if (current_user != -1){
        printf("Wah Anda sudah masuk. Keluar dulu yuk!\n");
    }
    else{
        boolean is_found_name = false;
        int idx = -1;
        do{
            printf("Masukkan nama:\n");
            START();
            get_paragraph();
            char *name = input_to_string();
            for(int i = 0; i < 20; i++){
                if(is_two_string_equal(name, users[i].name)){
                    is_found_name = true;
                    idx = i;
                }
            }
            free(name);
            if (is_found_name){
                printf("Wah, nama yang Anda cari tidak ada. Masukkan nama lain!\n");
            }
        } while (!is_found_name);
        boolean is_valid_password = false;
        do{
            printf("Masukkan kata sandi:\n");
            START();
            get_paragraph();
            char *password = input_to_string();
            if (is_two_string_equal(password, users[idx].password)){
                printf("Anda telah berhasil masuk dengan nama pengguna %s. Mari menjelajahi BurBir bersama Ande-Ande Lumut!\n", users[idx].name);
                is_valid_password = true;
            }
            else{
                printf("Wah, kata sandi yang Anda masukkan belum tepat. Periksa kembali kata sandi Anda!\n");
            }
        } while (!is_valid_password);
    }
}