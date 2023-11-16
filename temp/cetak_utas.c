#include <stdio.h>
#include "cetak_utas.h"
#include "../database/database.h"
#include "../ADT/LinkedThread.h"
#include "../ADT/Wordmachine.h"

void cetak_utas(int id_utas) {
    if (id_utas == NULL) {
        printf("Utas tidak ditemukan!\n");
    } else {
        User utas_owner = users[id_utas];
        Tweet utas_tweet = tweets[id_utas];

        if (utas_owner.is_public) {
            printf("| ID = %d\n", utas_tweet.id);
            printf("| %s\n", utas_owner.name);
            printf("| %s\n", utas_tweet.datetime);
            printf("| %s\n\n", utas_tweet.text);

            LinkedThread utas_threads;
            create_linked_thread(&utas_threads);

            for (int i = 0; i < length_linked_thread(utas_threads); ++i) {
                ThreadComponent current_thread = get_element_linked_thread(utas_threads, i);

                printf("   | INDEX = %d\n", i + 1);
                printf("   | %s\n", utas_owner.name);
                printf("   | %s\n", current_thread.datetime);
                printf("   | %s\n\n", current_thread.text);
            }
        } else {
            printf("Akun yang membuat utas ini adalah akun privat! Ikuti dahulu akun ini untuk melihat utasnya!\n");
        }
    }
}
