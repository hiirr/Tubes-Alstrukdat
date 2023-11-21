#include <stdio.h>
#include "balasan.h"
#include "../database/database.h"

void conditionally_print(ReplyTree *t, int node, int space) {
    int author_id = t->tweets[node].author_id;
    if (author_id != current_user && !users[author_id].is_public && !friends.matrix[current_user][author_id]) {
        print_private_tweet(&t->tweets[node], space);
    } else {
        print_tweet(&t->tweets[node], space);
    }
    for (int i = 0; i < t->adj[node].length; ++i) {
        conditionally_print(t, t->adj[node].list[i], space + 1);
    }
}

void balasan(int tweet_id) {
    if (current_user == -1) {
        printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        return;
    }
    if (tweet_id <= 0 || tweet_id >= latest_tweet) {
        printf("Tidak ada kicauan dengan ID %d\n", tweet_id);
        return;
    }
    int author_id = tweets[tweet_id].author_id;
    if (author_id != current_user && !users[author_id].is_public && !friends.matrix[current_user][author_id]) {
        printf("Tidak dapat melihat balasan karena kicauan privat dan anda belum berteman dengan pemilik kicauan.\n\n");
        return;
    }

    conditionally_print(&replies[tweet_id], 0, 0);
}