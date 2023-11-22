#include "tambah_teman.h"
#include "../assets/User.h"
#include "../ADT/GraphMatrix.h"
#include "../database/database.h"
#include "../ADT/PriorityQueueFriendRequest.h"
#include "../ADT/Wordmachine.h"
#include <stdio.h>

void tambah_teman() {
    if (current_user == -1) {
        printf("\nAnda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        return;
    }
    if (!is_empty_priority_queue_friend_request(users[current_user].friend_requests)) {
        printf("\nTerdapat permintaan pertemanan yang belum Anda setujui. Silakan kosongkan daftar permintaan pertemanan untuk Anda terlebih dahulu.\n");
        return;
    }

    printf("\nMasukkan nama pengguna:\n");
    clear_next_character();
    get_paragraph();
    char *friend_name = input_to_string();
    int friend_id = search_id_by_name(friend_name);
    free(friend_name);
    
    if (friend_id == -1) {
        printf("\nPengguna tidak ditemukan.\n");
        return;
    }
    if (friend_id == current_user) {
        printf("\nTidak dapat mengirim permintaan pertemanan kepada diri sendiri.\n");
        return;
    }
    if (friends.matrix[friend_id][current_user] == 1) {
        printf("\nAnda sudah berteman dengannya. Tidak dapat mengirim permintaan pertemanan.\n");
        return;
    }
    FriendRequest req;
    create_friend_request(&req, current_user, users[current_user].total_friends);
    if (is_in_priority_queue_friend_request(users[friend_id].friend_requests, req.user_id)) {
        printf("\nAnda sudah mengirimkan permintaan pertemanan kepadanya. Silakan tunggu hingga permintaan Anda disetujui.\n\n");
        return;
    }
    enqueue_friend_request(&users[friend_id].friend_requests, req);
    printf("\nPermintaan pertemanan kepadanya telah dikirim. Tunggu beberapa saat hingga permintaan Anda disetujui.\n");
}
