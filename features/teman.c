#include "teman.h"
#include "../assets/User.h"
#include "../ADT/Matrix.h"
#include "../database/database.h"
#include "../ADT/PriorityQueueFriendRequest.h"
#include "../ADT/Wordmachine.h"
#include <stdio.h>

//search if "username" is in users, return id
//private function
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
        printf("\n%s belum mempunyai teman.\n");
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
    char *friend_name = current_word.word;
    int id = search_id(friend_name);
    if (id == -1) {
        printf("%s bukan teman Anda.\n", friend_name);
    } else {
        printf("\nApakah anda yakin ingin menghapus Bob dari daftar teman anda?(YA/TIDAK) ");
        get_paragraph();
        if (my_strcmp(current_word.word, "YA") == 0) {
            delete_relation(&friends, current_user, id);
            printf("\n%s berhasil dihapus dari daftar teman Anda.\n", friend_name);
        } else {
            printf("\n Penghapusan teman dibatalkan.\n");
        }
    }
};

void send_friend_request() {
    if (current_user == -1) {
        printf("\nAnda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        return;
    }
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