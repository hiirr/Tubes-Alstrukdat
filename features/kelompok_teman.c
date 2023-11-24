#include "../assets/User.h"
#include "../ADT/GraphMatrix.h"
#include "../database/database.h"
#include <stdio.h>
#include "../ADT/dsu.h"

void cari_kelompok_teman() {
    if (current_user == -1) {
        printf("\nAnda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n\n");
        return;
    }

    DSU dsu;
    initialize_dsu(&dsu);

    form_friend_circles(&friends, &dsu);

    int id_root = find(&dsu, current_user);
    int total = 0;
    for (int i = 0; i < GRAPH_ROW_CAPACITY; i++) {
        if (find(&dsu, i) == id_root) {
            total++;
        }
    }

    printf("Terdapat %d orang dalam Kelompok Teman %s :\n", total, users[current_user].name);
    for (int i = 0; i < GRAPH_ROW_CAPACITY; i++) {
        if (find(&dsu, i) == id_root) {
            printf("%s\n", users[i].name);
        }
    }
}