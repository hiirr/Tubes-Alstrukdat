#include <stdio.h>
#include "ubah_kicauan.h"
#include "../database/database.h"
#include "../ADT/Wordmachine.h"

void ubah_kicauan(int tweet_id) {
    if (current_user == -1) {
        printf("Anda belum login\n\n");
        return;
    }
    if (tweet_id >= latest_tweet) {
        printf("Tidak ditemukan kicauan dengan ID = %d\n\n", tweet_id);
        return;
    }
    if (tweets[tweet_id].author_id != current_user) {
        printf("Kicauan bukan milik anda.\n\n");
        return;
    }

    while (true) {
        printf("Masukkan kicauan baru:\n");
        get_paragraph();
        if (current_input.length > 280) {
            printf("Kicauan (%d karakter) melewati batas 280 karakter. Silakan ulangi.\n\n", current_input.length);
            continue;
        }
        char *text = input_to_string();
        set_tweet_text(&tweets[tweet_id], text);
        printf("Kicauan berhasil diubah.\n\n");
        print_tweet(&tweets[tweet_id], 0);
        printf("\n\n");
        break;
    }
}