#include <stdio.h>
#include "../ADT/Wordmachine.h"
#include "../database/database.h"

void daftar() {
    if (current_user != -1){
        printf("Anda sudah masuk. Keluar terlebih dahulu untuk melakukan daftar.\n");
        return;
    } else if (total_user == 20) {
        printf("Daftar tidak bisa karena sudah mencapai jumlah pengguna maksimal yaitu 20.\n");
        return;
    }

    char *name;
    while (true) {
        printf("Masukkan nama:\n");
        get_paragraph();
        if (current_input.length > 20) {
            printf("Password anda memiliki %d karakter yang seharusnya maksimal 20 karakater.\n", current_input.length);
            continue;
        }
        boolean is_valid = true;
        name = input_to_string();
        for(int i = 0; i < total_user; i++){
            if (is_two_string_equal(name, users[i].name)){
                is_valid = false;
                break;
            }
        }
        if(!is_valid) {
            printf("Wah, sayang sekali nama tersebut telah diambil.\n");
            free(name);
            continue;
        }
        break;
    }

    char *password;
    while (true) {
        printf("Masukkan password:\n");
        get_paragraph();
        if (current_input.length > 20) {
            printf("Password anda memiliki %d karakter yang seharusnya maksimal 20 karakater.\n", current_input.length);
            continue;
        }
        password = input_to_string();
        break;
    }
    
    set_user_name(&users[total_user], name);
    set_user_password(&users[total_user], password);
    total_user += 1;

    printf("Pengguna telah berhasil terdaftar. Masuk untuk menikmati fitur-fitur BurBir.\n");
}