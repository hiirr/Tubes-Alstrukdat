#include "load.h"

#include <stdio.h>
#include <stdlib.h>

#include "../database/database.h"

void my_strlen(const char *str, size_t *len) {
    for (*len = 0; str[*len]; (*len)++);
}
char *my_strcpy(char *str_destination, const char *str_source) {
    char *temp = str_destination;
    while ( (*(str_destination++) = *(str_source++)) );
    return temp;
}

char *my_strcat(char *destination, const char *source) {
    char *r_destination = destination;
    while (*destination) destination++;
    while ((*destination++ = *source++));
    return r_destination;
}

int my_strcmp(const char *s1, const char *s2) {
    while(*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}


void remove_new_line(char* string) {
    size_t length;
    my_strlen(string, &length);
    if((length > 0) && (string[length-1] == '\n')) {
        string[length-1] ='\0';
    }
}

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

    my_getline(line, 1024, file);
    printf("Satu (%s)\n", line);
    long long length;
    my_strlen(line, &length);
    printf("Length = %d\n", length);
    users[0].name = (char*)malloc((length + 1) * sizeof(char));
    my_strcpy(users[0].name, line);
    printf("Dua (%s)\n", users[0].name);

    long long l2;
    my_strlen(users[0].name, &l2);
    printf("Length2 = %d\n", l2);

    // for (int i = 0; i < total_users; ++i) {;
    //     my_getline(line, file);
    //     printf("Bisakah! (%s)\n", line);
    //     // users[i].name = line;
    //     my_strcpy(users[i].name, line);
    //     printf("Bisakah! (%s)\n", users[i].name);


    //     my_getline(line, file);
    //     // users[i].password = line;
    //     my_strcpy(users[i].password, line);


    //     my_getline(line, file);
    //     // users[i].bio = line;
    //     my_strcpy(users[i].bio, line);

    //     my_getline(line, file);
    //     // users[i].phone = line;
    //     my_strcpy(users[i].phone, line);

    //     my_getline(line, file);
    //     // users[i].weton = line;
    //     my_strcpy(users[i].weton, line);


    //     my_getline(line, file);
    //     users[i].is_public = (my_strcmp(line, "Publik") == 0);

    //     for (int j = 0; j < 5; ++j) {
    //         my_getline(line, file);
    //     }
    //     // printf("Done.!\n\n");
    // }
    
    // for (int i = 0; i < total_users; ++i) {
    //     printf("Nama: (%s)\n", users[i].name);
    //     printf("pass: (%s)\n", users[i].password);
    //     printf("bio: (%s)\n", users[i].bio);
    //     printf("phone: (%s)\n", users[i].phone);
    //     printf("weton: (%s)\n", users[i].weton);
    //     // printf("tipe: (%d)\n", users[i].is_public);
    //     printf("\n\n");
    // }
}