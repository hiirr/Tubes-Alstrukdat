#include <stdio.h>
#include "cetak_utas.h"
#include "../database/database.h"
#include "../ADT/LinkedThread.h"
#include "../ADT/Wordmachine.h"
#include "../database/database.h"

void cetak_utas(int id_kicau) {
    if (current_user == -1) {
        printf("\nAnda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        return;
    }
    if (id_kicau <= 0 || id_kicau >= latest_tweet) {
        printf("Tidak ditemukan kicauan dengan ID %d\n", id_kicau);
        return;
    }
    int author_id = tweets[id_kicau].author_id;
    if (current_user != author_id && !users[author_id].is_public && !friends.matrix[current_user][author_id]) {
        printf("Akun yang membuat utas ini adalah akun privat! Ikuti dahulu akun ini untuk melihat utasnya!\n");
        return;
    }
    

    printf("| ID = %d\n", tweets[id_kicau].id);
    printf("| %s\n", users[tweets[id_kicau].author_id].name);
    printf("| %s\n", tweets[id_kicau].datetime);
    printf("| %s\n\n", tweets[id_kicau].text);

    int length = length_linked_thread(tweets[id_kicau].thread);

    for (int i = 0; i < length; ++i) {
        ThreadComponent current_thread = get_element_linked_thread(tweets[id_kicau].thread, i);

        printf("   | INDEX = %d\n", i + 1);
        printf("   | %s\n", users[tweets[current_thread.tweet_id].author_id].name);
        printf("   | %s\n", current_thread.datetime);
        printf("   | %s\n\n", current_thread.text);
    }
}
