#include <stdio.h>
#include <stdlib.h>
#include "sambung_utas.h"
#include "../database/database.h"
#include "../ADT/LinkedThread.h"
#include "../ADT/Wordmachine.h"
#include "../ADT/Datetime.h"


void sambung_utas(int id_kicau, int idx) {
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

    int length = length_linked_thread(tweets[id_kicau].thread);

    if (idx > length + 1) {
        printf("Index terlalu tinggi!\n");
        return;
    }
    if (idx <= 0) {
        printf("Indeks terlalu rendah.\n");
        return;
    }

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

    insert_at_linked_thread(&tweets[id_kicau].thread, utas, idx - 1);

    LinkedThreadComponentAddress current = tweets[id_kicau].thread;
    for (int i = 0; i < length; ++i) {
        current = current->next;
    }
}