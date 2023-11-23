#include <stdio.h>
#include "utas.h"
#include "../ADT/LinkedThread.h"
#include "../ADT/Wordmachine.h"
#include "../database/database.h"
#include "../ADT/Datetime.h"

void utas(int id_kicau) {
    if (current_user == -1) {
        printf("\nAnda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n\n");
        return;
    }
    if (id_kicau <= 0 || id_kicau >= latest_tweet) {
        printf("Tidak ditemukan kicauan dengan ID %d\n", id_kicau);
        return;
    }

    if (tweets[id_kicau].author_id != current_user) {
        printf("Kicauan bukan milik anda.\n");
        return;
    }
    if (!is_empty_linked_thread(tweets[id_kicau].thread)) {
        printf("Utas sudah pernah dibuat. Silakan gunakan SAMBUNG_UTAS atau HAPUS_UTAS untuk menyambung dan menghapus utas.\n");
        return;
    }

    while (true) {
        ThreadComponent utas;
        printf("Masukkan kicauan:\n");
        clear_next_character();
        get_paragraph();
        if (current_input.length > MAX_TWEET_LENGTH) {
            printf("Teks terlalu panjang (%d karakter); melebihi %d karakter. Kicauan Anda akan dipotong.\n\n", current_input.length, MAX_TWEET_LENGTH);
        }
        utas.text = input_to_string_limited(280);
        utas.datetime = current_time();
        utas.tweet_id = id_kicau;

        printf("Apakah Anda ingin melanjutkan utas ini? (YA/TIDAK) ");
        get_word();
        if (is_input_equal("TIDAK")) {
            insert_last_linked_thread(&tweets[id_kicau].thread, utas);
            return;
        } else if (!is_input_equal("YA")) {
            printf("Jawaban tidak valid. Utas tidak dilanjutkan.\n");
            return;
        }
        insert_last_linked_thread(&tweets[id_kicau].thread, utas);
    }

}