#include <stdio.h>
#include "../ADT/Wordmachine.h"
#include "../database/database.h"
#include "../assets/User.h"

void daftar() {
    if (current_user != -1) {
        printf("Anda sudah masuk. Keluar terlebih dahulu untuk melakukan daftar.\n");
        return;
    } else if (total_user == MAX_USER) {
        printf("Daftar tidak bisa karena sudah mencapai jumlah pengguna maksimal yaitu %d.\n", MAX_USER);
        return;
    }

    char *name;
    while (true) {
        printf("Masukkan nama:\n");
        clear_next_character();
        get_paragraph();
        if (current_input.length > MAX_USERNAME_LENGTH) {
            printf("Nama anda memiliki %d karakter yang seharusnya maksimal %d karakater.\n", current_input.length, MAX_USERNAME_LENGTH);
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
    // print_input();
    char *password;
    while (true) {
        printf("Masukkan password:\n");
        clear_next_character();
        get_paragraph();
        if (current_input.length > MAX_PASSWORD_LENGTH) {
            printf("Password anda memiliki %d karakter yang seharusnya maksimal %d karakater.\n", current_input.length, MAX_PASSWORD_LENGTH);
            continue;
        }
        password = input_to_string();
        break;
    }
    // print_input();
    set_user_name(&users[total_user], name);
    set_user_password(&users[total_user], password);
    
    set_user_bio(&users[total_user], "");
    set_user_phone(&users[total_user], "");
    set_user_weton(&users[total_user], "");

    total_user += 1;

    printf("Pengguna telah berhasil terdaftar. Masuk untuk menikmati fitur-fitur BurBir.\n");
}