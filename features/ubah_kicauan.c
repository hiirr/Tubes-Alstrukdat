#include <stdio.h>
#include "ubah_kicauan.h"
#include "../database/database.h"
#include "../ADT/Wordmachine.h"

void ubah_kicauan(int tweet_id) {
    if (current_user == -1) {
        printf("\nAnda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n\n");
        return;
    }
    if (tweet_id >= latest_tweet) {
        printf("Tidak ditemukan kicauan dengan ID = %d\n", tweet_id);
        return;
    }
    if (tweets[tweet_id].author_id != current_user) {
        printf("Kicauan bukan milik anda.\n\n");
        return;
    }

        printf("Masukkan kicauan baru:\n");
        clear_next_character();
        get_paragraph();
        if (current_input.length > MAX_TWEET_LENGTH) {
            printf("Teks terlalu panjang (%d karakter); melebihi %d karakter. Kicauan Anda akan dipotong.\n\n", current_input.length, MAX_TWEET_LENGTH);
        }
        char *text = input_to_string_limited(280);
        set_tweet_text(&tweets[tweet_id], text);
        set_tweet_text(&replies[tweet_id].tweets[0], text);
        printf("Kicauan berhasil diubah.\n\n");
        print_tweet(&tweets[tweet_id], 0);
    
}