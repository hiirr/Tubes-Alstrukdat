#include "hapus_teman.h"
#include "../assets/User.h"
#include "../ADT/GraphMatrix.h"
#include "../database/database.h"
#include "../ADT/PriorityQueueFriendRequest.h"
#include "../ADT/Wordmachine.h"
#include <stdio.h>

void hapus_teman() {
    if (current_user == -1) {
        printf("\nAnda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        return;
    }
    printf("\nMasukkan nama pengguna:\n");
    get_paragraph();

    char *friend_name = input_to_string();
    int friend_id = search_id_by_name(friend_name);
    free(friend_name);

    if (friend_id == -1) {
        printf("\n%s tidak terdaftar dalam layanan BurBir.\n", friend_name);
        return;
    }
    if (friend_id == current_user) {
        printf("\nTidak dapat menghapus pertemanan dengan diri sendiri.\n");
        return;
    }
    if (friends.matrix[current_user][friend_id] == 0) {
        printf("\n%s bukan teman Anda.\n", friend_name);
        return;
    }
    printf("\nApakah anda yakin ingin menghapus %s dari daftar teman anda? (YA/TIDAK) ", friend_name);
    get_word();
    if (is_input_equal("YA")) {
        delete_relation(&friends, current_user, friend_id);
        users[current_user].total_friends--;
        users[friend_id].total_friends--;
        printf("\n%s berhasil dihapus dari daftar teman Anda.\n", friend_name);
    } else {
        printf("\nPenghapusan teman dibatalkan.\n");
    }
}
