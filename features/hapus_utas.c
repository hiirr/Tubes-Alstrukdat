#include <stdio.h>
#include "hapus_utas.h"
#include "../database/database.h"
#include "../ADT/LinkedThread.h"

void hapus_utas(int id_kicau, int idx) {
    if (current_user == -1) {
        printf("\nAnda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n\n");
        return;
    }
    if (id_kicau < 0 || id_kicau >= latest_tweet) {
        printf("Tidak ditemukan kicauan dengan ID %d\n", id_kicau);
        return;
    }

    if (tweets[id_kicau].author_id != current_user) {
        printf("Kicauan bukan milik anda.\n");
        return;
    }

    int length = length_linked_thread(tweets[id_kicau].thread);

    if (idx < 0 || idx > length) {
        printf("Utas tidak ditemukan.\n");
        return;
    }

    if (idx == 0) {
        printf("Anda tidak bisa menghapus kicauan dalam utas ini!\n");
        return;
    }

    delete_at_linked_thread(&tweets[id_kicau].thread, idx - 1);
    printf("Kicauan sambungan berhasil dihapus!\n");
}
