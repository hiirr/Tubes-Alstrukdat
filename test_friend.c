#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "database/database.h"

// Include file features di yang sudah diimplementasikan
#include "features/muat.h"
#include "features/teman.h"
#include "ADT/GraphMatrix.h"
#include "ADT/Wordmachine.h"

void add_friend(int id1, int id2) {
    add_relation(&friends, id1, id2);
    users[id1].total_friends++;
    users[id2].total_friends++;
}

void setup_user_for_friend_testing() {
    total_user = 7;
    users[0].name = "USER0";
    users[1].name = "USER1";
    users[2].name = "USER2";
    users[3].name = "USER3";
    users[4].name = "USER4";
    users[5].name = "USER5";
    users[6].name = "USER6";
    add_friend(0, 1);
    add_friend(0, 2);
    add_friend(2, 3);
    add_friend(0, 4);
}

int main() {
    
    printf(
".______    __    __  .______      .______    __  .______      \n"
"|   _  \\  |  |  |  | |   _  \\     |   _  \\  |  | |   _  \\     \n"
"|  |_)  | |  |  |  | |  |_)  |    |  |_)  | |  | |  |_)  |    \n"
"|   _  <  |  |  |  | |      /     |   _  <  |  | |      /     \n"
"|  |_)  | |  `--'  | |  |\\  \\----.|  |_)  | |  | |  |\\  \\----.\n"
"|______/   \\______/  | _| `._____||______/  |__| | _| `._____|\n\n\n");
    setup_database();
    setup_user_for_friend_testing();
    while (true) {
        printf("\nCurrent user id: ");
        scanf("%d", &current_user);
        printf("\n>> ");
        START();

        get_word();

        if (is_current_word_equal("DAFTAR_TEMAN")) {
            print_friend_list();
        } else if (is_current_word_equal("HAPUS_TEMAN")) {
            remove_friend();
        } else if (is_current_word_equal("TAMBAH_TEMAN")) {
            send_friend_request();
        } else if (is_current_word_equal("BATAL_TAMBAH_TEMAN")) {
            cancel_friend_request();
        } else if (is_current_word_equal("DAFTAR_PERMINTAAN_TEMAN")) {
            print_friend_requests();
        } else if (is_current_word_equal("SETUJUI_PERTEMANAN")) {
            accept_friend_request();
        } else if (is_current_word_equal("PRINT_FRIENDS")) {
            print_graph_matrix(&friends);
        }
        else {
            printf("Belum...\n");
            print_input();
        }
    }
}