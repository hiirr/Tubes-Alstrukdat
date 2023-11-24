#include "setujui_pertemanan.h"
#include "../assets/User.h"
#include "../ADT/GraphMatrix.h"
#include "../database/database.h"
#include "../ADT/PriorityQueueFriendRequest.h"
#include "../ADT/Wordmachine.h"
#include <stdio.h>

void setujui_pertemanan() {
    if (current_user == -1) {
        printf("\nAnda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n\n");
        return;
    }
    if (is_empty_priority_queue_friend_request(users[current_user].friend_requests)) {
        printf("\nTidak ada permintaan pertemanan untuk Anda.\n");
        return;
    }
    FriendRequest req;
    dequeue_friend_request(&users[current_user].friend_requests, &req);
    printf("\nPermintaan pertemanan teratas dari %s.\n", users[req.user_id].name);
    printf("\n| %s\n", users[req.user_id].name);
    printf("| Jumlah teman: %d\n", req.current_total_friends);
    printf("\nApakah Anda ingin menyetujui permintaan pertemanan ini? (YA/TIDAK) ");
    clear_next_character();
    get_word();

    if (is_input_equal("YA")) {
        int friend_id = req.user_id;
        add_relation(&friends, current_user, friend_id);
        users[current_user].total_friends++;
        users[friend_id].total_friends++;
        printf("\nPermintaan pertemanan dari %s telah disetujui. Selamat! Anda telah berteman dengan %s.\n", users[friend_id].name, users[friend_id].name);
    } else {
        printf("\nPermintaan pertemanan dari %s telah ditolak.\n", users[req.user_id].name);
    }
}