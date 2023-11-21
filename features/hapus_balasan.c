#include <stdio.h>
#include "hapus_balasan.h"
#include "../database/database.h"
#include "../ADT/ReplyTree.h"

void hapus_balasan(int tweet_id, int reply_id) {
    if (current_user == -1) {
        printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n\n");
        return;
    }
    if (tweet_id <= 0 || tweet_id >= latest_tweet) {
        printf("Tidak ada kicauan dengan ID %d\n\n", tweet_id);
        return;
    }
    if (reply_id <= 0 || reply_id >= latest_reply[tweet_id] || !replies[tweet_id].nodes[reply_id]) {
        printf("Tidak ada balasan dengan ID %d\n\n", reply_id);
        return;
    }
    int author_id = replies[tweet_id].tweets[reply_id].author_id;
    if (author_id != current_user) {
        printf("Hei, ini balasan punya siapa? Jangan dihapus ya!\n\n");
        return;
    }
    delete_reply_node(&replies[tweet_id], reply_id);
    printf("Balasan berhasil dihapus.\n\n");
}