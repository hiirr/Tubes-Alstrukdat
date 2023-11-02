#include "ADT/boolean.h"
#include "ADT/Wordmachine.h"
#include "assets/User.h"
#include "database/database.h"

User user[MAX_USER];

void lihat_profil(char *name){
    int id_user = -1;
    for (int i = 0; i < MAX_USER; i++){
        if (is_current_word_equal(user[i].name)){
            id_user = i;
            break;
        }
    }

    if (!user[id_user].is_public){
        printf("Sayangnya akun %c diprivat:( Ikuti dulu yuk biar bisa lihat profil %c!\n", user[id_user].name, user[id_user].name);
    } else {
        printf("| Nama: %c\n", user[id_user].name);
        printf("| Bio Akun: %c\n", user[id_user].bio);
        printf("| No HP: %c\n", user[id_user].phone);
        printf("| Weton: %c\n", user[id_user].weton);
        printf("Foto profil akun %c\n", user[id_user].name);
        print_profile_picture(&user[id_user]);
    }
}