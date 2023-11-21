#include <stdio.h>
#include <stdlib.h>
#include "ubah_foto_profil.h"

#include "../ADT/boolean.h"
#include "../ADT/Matrix.h"
#include "../ADT/Wordmachine.h"

#include "../assets/User.h"
#include "../database/database.h"

void ubah_foto_profil() {
    if (current_user == -1){
        printf("Anda belum login. Silakan login terlebih dahulu.\n");
    } else {
        printf("Foto profil Anda saat ini adalah\n");
        print_profile_picture(&users[current_user]);
        printf("\n");

        Matrix new_profil;
        printf("Masukkan foto profil yang baru\n");
        create_matrix(&new_profil, 5, 10);
        clear_next_character();
        get_paragraph();
        for (int row = 0; row < 5; ++row) {
            for (int col = 0; col < 5; ++col) {
                new_profil.matrix[row][2 * col] = current_input.input[20 * row + 4 * col];
                new_profil.matrix[row][2 * col + 1] = current_input.input[20 * row + 4 * col + 2];
            }
        }
        copy_matrix(&new_profil, &users[current_user].profile_picture);
        printf("Foto profil anda sudah berhasil diganti!\n");
        print_profile_picture(&users[current_user]);
        printf("\n");
    }
}