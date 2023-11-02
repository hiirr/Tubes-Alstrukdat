#include <stdio.h>
#include "suka_kicauan.h"
#include "../database/database.h"

void suka_kicauan(int id_kicau) {
    if (current_user == -1) {
        printf("Anda belum login\n\n");
        return;
    }
    if (id_kicau < latest_tweet) {
        printf("Tidak ditemukan kicauan dengan ID = %d\n\n", id_kicau);
        return;
    }
    if (!users[tweets[id_kicau].author_id].is_public && !friends.matrix[current_user][tweets[id_kicau].author_id]) {
        printf("Kicauan tersebut dibuat oleh akun privat yang belum teman anda.\n\n");
        return;
    }

    tweets[id_kicau].likes++;

    print_tweet(&tweets[id_kicau], 0);
}