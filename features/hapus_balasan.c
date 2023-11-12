#include <stdio.h>
#include "hapus_balasan.h"
#include "../database/database.h"
#include "../ADT/ReplyTree.h"

void hapus_balasan(int id_kicau, int id_balas) {
    if (current_user == -1) {
        printf("Anda belum login.\n\n");
        return;
    }
    if (id_kicau >= latest_tweet) {
        printf("Tidak ada kicauan dengan ID %d\n\n", id_kicau);
        return;
    }
    if (!replies[id_kicau].nodes[id_balas]) {
        printf("Tidak ada balasan dengan ID %d\n\n", id_balas);
        return;
    }
    if (replies[id_kicau].tweets[id_balas].author_id != current_user) {
        printf("Balasan bukan milik anda.\n\n");
        return;
    }

    delete_reply_node(&replies[id_kicau], id_balas);
}