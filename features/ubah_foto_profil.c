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
        printf("Anda belum login\n");
    } else {
        printf("Foto profil Anda saat ini adalah\n");
        print_profile_picture(&users[current_user]);
        print("\n");

        Matrix new_profil;
        printf("Masukkan foto profil yang baru\n");
        create_matrix(&new_profil, 5, 10);
        read_matrix(&new_profil, 5, 10);
        copy_matrix(&new_profil, &users[current_user].profile_picture);
        clear_next_character();
    }
}