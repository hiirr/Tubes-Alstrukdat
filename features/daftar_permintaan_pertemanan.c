#include "daftar_permintaan_pertemanan.h"
#include "../assets/User.h"
#include "../ADT/GraphMatrix.h"
#include "../database/database.h"
#include "../ADT/PriorityQueueFriendRequest.h"
#include "../ADT/Wordmachine.h"
#include <stdio.h>

void daftar_permintaan_pertemanan() {
    if (current_user == -1) {
        printf("\nAnda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n\n");
        return;
    }
    if (is_empty_priority_queue_friend_request(users[current_user].friend_requests)) {
        printf("\nTidak ada permintaan pertemanan untuk Anda.\n");
        return;
    }
    int length = length_priority_queue_friend_request(users[current_user].friend_requests);
    printf("\nTerdapat %d permintaan pertemanan untuk Anda.\n", length);
    
    PriorityQueueFriendRequest friend_requests = users[current_user].friend_requests;

    int start_idx = friend_requests.head;
    for (int i = 0; i < length_priority_queue_friend_request(friend_requests); i++) {
        int index = start_idx - i;
        if (index < 0) {
            index += PRIORITY_QUEUE_FRIEND_REQUEST_CAPACITY;
        }
        printf("\n| %s\n", users[friend_requests.queue[index].user_id].name);
        printf("| Jumlah teman: %d\n", friend_requests.queue[index].current_total_friends);
    }
}