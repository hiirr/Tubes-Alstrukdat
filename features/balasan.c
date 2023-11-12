#include <stdio.h>
#include "balasan.h"
#include "../database/database.h"

void conditionally_print(ReplyTree *t, int node, int space) {
    // for (int i = 0; i < space; ++i) printf("\t");
    if (t->tweets[node].author_id != current_user && !users[t->tweets[node].author_id].is_public && !friends.matrix[current_user][t->tweets[node].author_id]) {
        print_private_tweet(&t->tweets[node], space);
    } else {
        print_tweet(&t->tweets[node], space);
    }

    for (int i = 0; i < t->adj[node].length; ++i) {
        conditionally_print(t, t->adj[node].list[i], space + 1);
    }
}

void balasan(int id_kicau) {
    if (current_user == -1) {
        printf("Anda belum log in.");
        return;
    }
    if (id_kicau >= latest_tweet) {
        printf("Tidak ada kicauan dengan ID %d\n", id_kicau);
        return;
    }
    if (tweets[id_kicau].author_id != current_user && !users[tweets[id_kicau].author_id].is_public && !friends.matrix[current_user][tweets[id_kicau].author_id]) {
        printf("Tidak dapat membalas karena kicauan privat dan anda belum berteman dengan pemilik kicauan.\n\n");
        return;
    }

    conditionally_print(&replies[id_kicau], 0, 0);
}