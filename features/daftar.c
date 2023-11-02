#include <stdio.h>
#include "..\ADT\Wordmachine.h"
#include "../database/database.h"

void daftar(){
    if (current_user != -1){
        printf("Anda sudah masuk. Keluar terlebih dahulu untuk melakukan daftar.\n");
    }
    else{
        boolean is_valid_name = true;
        do{
            printf("Masukkan nama:\n");
            START();
            get_paragraph();
            char *name = input_to_string();
            for(int i = 0; i < 20; i++){
                if (is_two_string_equal(name, users[i].name)){
                    is_valid_name = false;
                }
            }
            free(name);
            if(!is_valid_name){
                printf("Wah, sayang sekali nama tersebut telah diambil.\n");
            }
        }
        while (!is_valid_name);
        printf("Masukkan kata sandi:\n");
        START();
        get_paragraph();
        char *password = input_to_string();
        printf("Pengguna telah berhasil terdaftar. Masuk untuk menikmati fitur-fitur BurBir.\n");
    }
}