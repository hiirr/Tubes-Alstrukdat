#include "balas.h"
#include "../database/database.h"
#include "../ADT/Wordmachine.h"
#include "../ADT/ReplyTree.h"


void balas(int tweet_id, int reply_id) {
    if (current_user == -1) {
        printf("\nAnda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n\n");
        return;
    }
    if (tweet_id <= 0 || tweet_id >= latest_tweet) {
        printf("Tidak ada kicauan dengan ID %d.\n\n", tweet_id);
        return;
    }
    int tweet_author_id = tweets[tweet_id].author_id;
    if (tweet_author_id != current_user && !users[tweet_author_id].is_public && !friends.matrix[current_user][tweet_author_id]) {
        printf("Tidak dapat membalas karena kicauan privat dan anda belum berteman dengan pemilik kicauan.\n\n");
        return;
    }
    if (reply_id == -1) {
        char *text;
        while (true) {
            printf("Masukkan balasan:\n");
            clear_next_character();
            get_paragraph();
            if (current_input.length > MAX_TWEET_LENGTH) {
                printf("Teks terlalu panjang (%d karakter); melebihi %d karakter.\n", current_input.length, MAX_TWEET_LENGTH);
                continue;
            }
            text = input_to_string();
            break;
        }
        Tweet reply = new_tweet(latest_reply[tweet_id], text, current_user);
        add_reply_edge(&replies[tweet_id], 0, latest_reply[tweet_id], reply);
        printf("Balasan telah diterbitkan.\n");
        print_tweet(&replies[tweet_id].tweets[latest_reply[tweet_id]], 0);
        ++latest_reply[tweet_id];
        return;
    }
    if (reply_id <= 0 || reply_id >= latest_reply[tweet_id] || !replies[tweet_id].nodes[reply_id]) {
        printf("Tidak ada balasan dengan ID %d.\n", reply_id);
        return;
    }
    int reply_author_id = replies[tweet_id].tweets[reply_id].author_id;
    if (reply_author_id != current_user && !users[reply_author_id].is_public && !friends.matrix[current_user][reply_author_id]) {
        printf("Tidak dapat membalas karena pemilik balasan adalah privat dan anda belum berteman dengan pemilik balasan.\n\n");
        return;
    }

    char *text;
    while (true) {
        printf("Masukkan balasan:\n");
        clear_next_character();
        get_paragraph();
        if (current_input.length > MAX_TWEET_LENGTH) {
            printf("Teks terlalu panjang (%d karakter); melebihi %d karakter.\n", current_input.length, MAX_TWEET_LENGTH);
            continue;
        }
        text = input_to_string();
        break;
    }
    Tweet reply = new_tweet(latest_reply[tweet_id], text, current_user);

    add_reply_edge(&replies[tweet_id], reply_id, latest_reply[tweet_id], reply);
    ++latest_reply[tweet_id];

    printf("Balasan telah diterbitkan.\n\n");

    print_tweet(&reply, 0);
}