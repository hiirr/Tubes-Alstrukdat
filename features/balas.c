#include "balas.h"
#include "../database/database.h"
#include "../ADT/Wordmachine.h"
#include "../ADT/ReplyTree.h"


void balas(int id_kicau, int id_balas) {
    if (current_user == -1) {
        printf("Anda belum login.\n\n");
        return;
    }
    if (id_kicau < latest_tweet) {
        printf("Tidak ada kicauan dengan ID %d\n\n", id_kicau);
        return;
    }
    if (tweets[id_kicau].author_id != current_user && !users[tweets[id_kicau].author_id].is_public && !friends.matrix[current_user][tweets[id_kicau].author_id]) {
        printf("Tidak dapat membalas karena kicauan privat dan anda belum berteman dengan pemilik kicauan.\n\n");
        return;
    }
    if (replies[id_kicau].tweets[id_balas].author_id != current_user && !users[replies[id_kicau].tweets[id_balas].author_id].is_public && !friends.matrix[current_user][replies[id_kicau].tweets[id_balas].author_id]) {
        printf("Tidak dapat membalas karena pemilik balasan adalah privat dan anda belum berteman dengan pemilik balasan.\n\n");
        return;
    }

    clear_next_character();
    START();
    get_paragraph();
    char *text = input_to_string();
    // printf("(%s)", text);

    Tweet reply = new_tweet(text, latest_reply[id_kicau], current_user);

    if (id_balas == -1) {
        add_reply_edge(&replies[id_kicau], 0, latest_reply[id_kicau], reply);
    } else {
        add_reply_edge(&replies[id_kicau], id_balas, latest_reply[id_kicau], reply);
    }

    ++latest_reply[id_kicau];

    printf("Balasan telah diterbitkan.\n\n");

    print_tweet(&reply, 0);
    printf("\n\n");
}