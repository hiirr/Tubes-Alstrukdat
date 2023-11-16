#include <stdio.h>
#include <stdlib.h>
#include "sambung_utas.h"
#include "../database/database.h"
#include "../ADT/LinkedThread.h"
#include "../ADT/Wordmachine.h"

void sambung_utas(int id_utas, int idx) {
    LinkedThread l;
    create_linked_thread(&l);
    ThreadComponent *text;
    int latest_thread = 0;

    // idx > latest thread
    if (idx > length_linked_thread(l)) {
        printf("Index terlalu tinggi!\n");
    }
    // id_utas tidak ada
    else if (id_utas == NULL || idx == NULL) {
        printf("Utas tidak ditemukan!\n");
    }
    // id_utas punya orang
    else if (id_utas != current_user) {
        printf("Anda tidak bisa menyambung utas ini!\n");
    } else {
        printf("Masukkan kicauan:\n");
        clear_next_character();
        START();
        get_paragraph();

        text = input_to_string();
        char *time = current_time();

        insert_last_linked_thread(&l, text);
    }
}
