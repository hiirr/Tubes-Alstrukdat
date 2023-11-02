#include "ADT/boolean.h"
#include "ADT/Matrix.h"
#include "ADT/Wordmachine.h"
#include "assets/User.h"
#include "database/database.h"

User user[MAX_USER];

void ubah_foto_profil(int id_user){
    printf("Foto profil Anda saat ini adalah\n");
    print_profile_picture(&user[id_user]);
    Matrix new_profil;
    create_matrix(&new_profil, 20, 20);
    read_matrix(&new_profil, 20, 20);
    user[id_user].profile_picture;
}