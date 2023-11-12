#include "daftar_teman.h"
#include "teman.h"
#include "../assets/User.h"
#include "../ADT/GraphMatrix.h"
#include "../database/database.h"
#include "../ADT/PriorityQueueFriendRequest.h"
#include <stdio.h>

void daftar_teman() {
    if (current_user == -1) {
        printf("\nAnda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        return;
    }
    if (users[current_user].total_friends == 0) {
        printf("\n%s belum mempunyai teman.\n", users[current_user].name);
        return;
    }
    printf("\n%s memiliki %d teman.\n", users[current_user].name, users[current_user].total_friends);
    printf("Daftar teman %s:\n", users[current_user].name);
    for (int i = 0; i < total_user; i++) {
        if (friends.matrix[current_user][i] == 1) {
            printf("| %s\n", users[i].name);
        }
    }
}