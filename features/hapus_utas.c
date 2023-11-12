#include <stdio.h>
#include "hapus_utas.h"
#include "../database/database.h"
#include "../ADT/LinkedThread.h"

void hapus_utas(int id_utas, int idx) {
    LinkedThread l;
    create_linked_thread(&l);

    // id_utas tidak valid atau idx tidak valid
    if (id_utas == NULL || idx == NULL) {
        printf("Utas tidak ditemukan!\n");
    }
    // id_utas punya orang lain
    else if (id_utas != current_user) {
        printf("Anda tidak bisa menghapus kicauan dalam utas ini!\n");
    }
    // idx == 0 (kicauan utama)
    else if (idx == 0) {
        printf("Anda tidak bisa menghapus kicauan utama!\n");
    }
    else {
        ThreadComponent deleted_thread;
        delete_at_linked_thread(&l, idx, &deleted_thread);

        if (deleted_thread.text != NULL) {
            printf("Kicauan sambungan berhasil dihapus!\n");
        } else {
            printf("Kicauan sambungan dengan index %d tidak ditemukan pada utas!\n", idx);
        }
    }
}
