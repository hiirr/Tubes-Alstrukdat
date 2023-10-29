#include "load.h"

#include <stdio.h>
#include <stdlib.h>

#include "../ADT/Wordmachine.h"

#include "../database/database.h"

#include "../assets/User.h"


void my_getline(char *line, int size, FILE *file) {
    fgets(line, size, file);
    remove_new_line(line);
}

void load() {
    if (current_user != -1) {
        printf("Anda harus keluar terlebih dahulu untuk melakukan pemuatan.\n");
        return;
    }

    printf("Masukkan nama folder untuk pemuatan konfigurasi: ");
    char folder_name[1024];
    my_getline(folder_name, 1024, stdin);
    printf("Folder name: (%s)\n", folder_name);

    char pengguna_file_location[1024];
    my_strcpy(pengguna_file_location, folder_name);
    my_strcat(pengguna_file_location, "/pengguna.config");
    printf("Pengguna file: (%s)\n", pengguna_file_location);

    FILE *file;
    file = fopen(pengguna_file_location, "r");

    if (!file) {
        printf("%s tidak dapat ada atau tidak memiliki permission\n", pengguna_file_location);
        return;
    }

    char line[1024];
    
    my_getline(line, 1024, file);
    int total_users;
    sscanf(line, "%d", &total_users);
    printf("Banyaknya pengguna: %d\n", total_users);

    for (int i = 0; i < total_users; ++i) {;
        my_getline(line, 1024, file);
        set_user_name(users + i, line);


        my_getline(line, 1024, file);
        set_user_password(users + i, line);

        my_getline(line, 1024, file);
        set_user_bio(users + i, line);

        my_getline(line, 1024, file);
        set_user_phone(users + i, line);

        my_getline(line, 1024, file);
        set_user_weton(users + i, line);


        my_getline(line, 1024, file);
        users[i].is_public = (my_strcmp(line, "Publik") == 0);

        for (int row = 0; row < 5; ++row) {
            my_getline(line, 1024, file);
            for (int col = 0; col < 5; ++col){}
            my_getline(line, 1024, file);
        }
    }
    
    for (int i = 0; i < total_users; ++i) {
        printf("Nama: (%s)\n", users[i].name);
        printf("pass: (%s)\n", users[i].password);
        printf("bio: (%s)\n", users[i].bio);
        printf("phone: (%s)\n", users[i].phone);
        printf("weton: (%s)\n", users[i].weton);
        printf("tipe: (%d)\n", users[i].is_public);
        printf("\n\n");
    }
}