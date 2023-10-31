#include "teman.h"
#include "../assets/User.h"
#include "../ADT/GraphMatrix.h"
#include "../database/database.h"
#include "../ADT/PriorityQueueFriendRequest.h"
#include "../ADT/Wordmachine.h"
#include <stdio.h>

//search if "username" is in users, return id, PRIVATE FUNCTION only in teman.c
int search_id(char *username) {
    int i;
    for (i = 0; i < 20; i++) {
        if (my_strcmp(users[i].name, username) == 0) {
            return i;
        }
    }
    return -1;
};

void print_friend_list() {
    if (current_user == -1) {
        printf("\nAnda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        return;
    }
    if (users[current_user].total_friends == 0) {
        printf("\n%s belum mempunyai teman.\n", users[current_user].name);
        return;
    }
    printf("\n%s memiliki %d teman\n", users[current_user].name, users[current_user].total_friends);
    printf("Daftar teman %s\n", users[current_user].name);
    int i;
    for (i = 0; i < 20; i++) {
        if (friends.matrix[current_user][i] == 1) {
            printf("| %s\n", users[i].name);
        };
    }
};

void remove_friend() {
    if (current_user == -1) {
        printf("\nAnda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        return;
    }
    printf("\nMasukkan nama pengguna:\n");
    get_paragraph();
    char *friend_name = input_to_string();
    int id = search_id(friend_name);
    if (id == -1) {
        printf("\n%s bukan teman Anda.\n", friend_name);
        return;
    }
    printf("\nApakah anda yakin ingin menghapus %s dari daftar teman anda?(YA/TIDAK) ", friend_name);
    get_paragraph();
    char *input_option = input_to_string();
    if (my_strcmp(input_option, "YA") == 0) {
        delete_relation(&friends, current_user, id);
        users[current_user].total_friends--;
        printf("\n%s berhasil dihapus dari daftar teman Anda.\n", friend_name);
    } else {
        printf("\nPenghapusan teman dibatalkan.\n");
    }
    //NOTE: Belum implementasi Update popularitas current user di semua permintaan teman lain
};

void send_friend_request() {
    if (current_user == -1) {
        printf("\nAnda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        return;
    }
    if (!is_empty_priority_queue_friend_request(users[current_user].friend_requests)) {
        printf("\nTerdapat permintaan pertemanan yang belum Anda setujui. Silakan kosongkan daftar permintaan pertemanan untuk Anda terlebih dahulu.\n");
        return;
    }
    printf("\nMasukkan nama pengguna:\n");
    get_paragraph();
    char *friend_name = input_to_string();
    int id = search_id(friend_name);
    if (id == -1) {
        printf("\nPengguna bernama %s tidak ditemukan\n", friend_name);
        return;
    }
    FriendRequest req;
    create_friend_request(&req, current_user, users[current_user].total_friends);
    if (is_in_priority_queue_friend_request(users[id].friend_requests, req)) {
        printf("\nAnda sudah mengirimkan permintaan pertemanan kepada %s. Silakan tunggu hingga permintaan Anda disetujui.\n", friend_name);
        return;
    }
    enqueue_friend_request(&users[id].friend_requests, req);
    printf("\nPermintaan pertemanan kepada Bob telah dikirim. Tunggu beberapa saat hingga permintaan Anda disetujui.\n");
};

void cancel_friend_request() {
    if (current_user == -1) {
        printf("\nAnda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        return;
    }
};

void print_friend_requests() {
    if (current_user == -1) {
        printf("\nAnda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        return;
    }
};

void accept_friend_request() {
    if (current_user == -1) {
        printf("\nAnda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        return;
    }
};