#include <stdio.h>
#include "ubah_kicauan.h"
#include "../database/database.h"
#include "../ADT/Wordmachine.h"

void ubah_kicauan(int id_kicau) {
    if (current_user == -1) {
        printf("Anda belum login\n\n");
        return;
    }
    if (id_kicau < latest_tweet) {
        printf("Tidak ditemukan kicauan dengan ID = %d\n\n", id_kicau);
        return;
    }
    if (tweets[id_kicau].author_id != current_user) {
        printf("Kicauan bukan milik anda.\n\n");
    }

    clear_next_character();
    START();
    get_paragraph();

    char *text = input_to_string();
    set_tweet_text(&tweets[id_kicau], text); 
}