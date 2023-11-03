#include "ADT/boolean.h"
#include "ADT/Wordmachine.h"
#include "assets/User.h"
#include "database/database.h"

User user[MAX_USER];

void atur_jenis_akun(int id_user){
    if (user[id_user].is_public){
        printf("Saat ini, akun Anda adalah akun Publik. Ingin mengubah ke akun Privat? (YA/TIDAK) ");
        input_to_string();
        if (is_current_word_equal("YA")){
            user[id_user].is_public = false;
        } 
    } else {
        printf("Saat ini, akun Anda adalah akun Privat. Ingin mengubah ke akun Publik? (YA/TIDAK) ");
        input_to_string();
        if (is_current_word_equal("YA")){
            user[id_user].is_public = true;
        } 
    }
}