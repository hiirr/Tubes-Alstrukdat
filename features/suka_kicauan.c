#include <stdio.h>
#include "suka_kicauan.h"
#include "../database/database.h"

void suka_kicauan(int tweet_id) {
    if (current_user == -1) {
        printf("\nAnda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n\n");
        return;
    }
    if (tweet_id >= latest_tweet) {
        printf("Tidak ditemukan kicauan dengan ID = %d.\n", tweet_id);
        return;
    }

    int author_id = tweets[tweet_id].author_id;
    if (current_user != author_id && !users[author_id].is_public && !friends.matrix[current_user][author_id]) {
        printf("Kicauan dibuat oleh akun privat yang anda belum berteman dengannya.\n");
        return;
    }

    ++tweets[tweet_id].likes;
    ++replies[tweet_id].tweets[0].likes;
    
    printf("Tweet berhasil disukai.\n");
    print_tweet(&tweets[tweet_id], 0);
}