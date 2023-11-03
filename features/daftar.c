#include <stdio.h>
#include "../ADT/Wordmachine.h"
#include "../database/database.h"

void daftar(){
    char *name, *password;
    if (current_user != -1){
        printf("Anda sudah masuk. Keluar terlebih dahulu untuk melakukan daftar.\n");
    }
    else{
        boolean is_valid_name = true;
        do{
            is_valid_name = true;
            printf("Masukkan nama:\n");
            START();
            get_paragraph();
            name = input_to_string();
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
        password = input_to_string();
        set_user_name(&users[total_user], name);
        set_user_password(&users[total_user], password);
        total_user += 1;
        printf("Pengguna telah berhasil terdaftar. Masuk untuk menikmati fitur-fitur BurBir.\n");
    }
}