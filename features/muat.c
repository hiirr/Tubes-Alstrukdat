#include "muat.h"

#include <stdio.h>
#include <stdlib.h>

#include "../ADT/math.h"
#include "../ADT/Wordmachine.h"
#include "../ADT/ReplyTree.h"

#include "../database/database.h"

#include "../assets/User.h"
#include "../assets/Tweet.h"

void muat() {
    if (current_user != -1) {
        printf("Anda harus keluar terlebih dahulu untuk melakukan pemuatan.\n");
        return;
    }
    printf("Masukkan nama folder untuk pemuatan konfigurasi: ");
    clear_next_character();
    get_paragraph();
    char *folder_name = input_to_string();

    muat_pengguna(folder_name);
    muat_kicauan(folder_name);
    muat_balasan(folder_name);
    muat_draf(folder_name);
    muat_utas(folder_name);
}

void muat_pengguna(char *folder_name) {
    char pengguna_file_location[1024];
    my_strcpy(pengguna_file_location, folder_name);
    my_strcat(pengguna_file_location, "/pengguna.config");
    // printf("Pengguna file: (%s)\n", pengguna_file_location);

    FILE *file;
    file = fopen(pengguna_file_location, "r");

    if (!file) {
        printf("%s tidak ada atau tidak dapat diakses karena tidak memiliki permission\n", pengguna_file_location);
        return;
    }

    char line[1024];
    DynamicList result;

    // Banyaknya pengguna
    my_getline(line, 1024, file);
    result = split_to_ints(line);
    total_user = result.list[0]; 
    deallocate_dynamic_list(&result);

    for (int i = 0; i < total_user; ++i) {
        // Nama
        my_getline(line, 1024, file);
        set_user_name(users + i, line);

        // Password
        my_getline(line, 1024, file);
        set_user_password(users + i, line);

        // Bio
        my_getline(line, 1024, file);
        set_user_bio(users + i, line);

        // no HP
        my_getline(line, 1024, file);
        set_user_phone(users + i, line);

        // Weton
        my_getline(line, 1024, file);
        set_user_weton(users + i, line);

        // Jenis akun
        my_getline(line, 1024, file);
        users[i].is_public = is_two_string_equal(line, "Publik"); // (my_strcmp(line, "Publik") == 0);

        // Foto profil
        for (int row = 0; row < 5; ++row) {
            my_getline(line, 1024, file);
            for (int col = 0; col < 5; ++col) {
                char color = line[4 * col];
                char character = line[4 * col + 2];
                users[i].profile_picture.matrix[row][2 * col] = color;
                users[i].profile_picture.matrix[row][2 * col + 1] = character;
            }
        }
    }
    // Matriks pertemanan
    for (int i = 0; i < total_user; ++i) {
        my_getline(line, 1024, file);
        for (int j = 0; j < total_user; ++j) {
            friends.matrix[i][j] = line[2 * j] - '0';
        }
    }
    // Permintaan pertemanan
    my_getline(line, 1024, file);
    int total_friend_requests;
    result = split_to_ints(line);
    total_friend_requests = result.list[0];
    deallocate_dynamic_list(&result);

    for (int i = 0; i < total_friend_requests; ++i) {
        my_getline(line, 1024, file);
        result = split_to_ints(line);
        int a = result.list[0], b = result.list[1], c = result.list[2];
        deallocate_dynamic_list(&result);
        
        FriendRequest request; request.user_id = a; request.current_total_friends = c;
        enqueue_friend_request(&users[b].friend_requests, request);
    }

    // for (int i = 0; i < total_user; ++i) {
    //     for (int j = 0; j < total_user; ++j) {
    //         printf("%d ", friends.matrix[i][j]);
    //     }
    //     printf("\n");
    // }
    // for (int i = 0; i < total_user; ++i) {
    //     printf("Nama: (%s)\n", users[i].name);
    //     printf("pass: (%s)\n", users[i].password);
    //     printf("bio: (%s)\n", users[i].bio);
    //     printf("phone: (%s)\n", users[i].phone);
    //     printf("weton: (%s)\n", users[i].weton);
    //     printf("tipe: (%d)\n", users[i].is_public);
    //     print_profile_picture(&users[i]);
    //     printf("\n\n");
    // }
}

void muat_kicauan(char *folder_name) {
    char kicauan_file_location[1024];
    my_strcpy(kicauan_file_location, folder_name);
    my_strcat(kicauan_file_location, "/kicauan.config");

    FILE *file;
    file = fopen(kicauan_file_location, "r");

    if (!file) {
        printf("%s tidak ada atau tidak dapat diakses karena tidak memiliki permission\n", kicauan_file_location);
        return;
    }

    char line[1024];
    DynamicList result;
    
    my_getline(line, 1024, file);
    result = split_to_ints(line);
    latest_tweet = result.list[0] + 1;
    deallocate_dynamic_list(&result);

    for (int i = 0; i < latest_tweet - 1; ++i) {
        // ID kicauan
        my_getline(line, 1024, file);
        result = split_to_ints(line);
        int id = result.list[0];
        deallocate_dynamic_list(&result);
        tweets[id].id = id;

        // Teks kicauan
        my_getline(line, 1024, file);
        set_tweet_text(tweets + id, line);

        // Jumlah likes
        my_getline(line, 1024, file);
        result = split_to_ints(line);
        int likes = result.list[0];
        deallocate_dynamic_list(&result);
        tweets[id].likes = likes;

        // Author
        my_getline(line, 1024, file);
        boolean is_found = false;;
        for (int j = 0; j < total_user; ++j) {
            if (is_two_string_equal(line, users[j].name)) {
                tweets[id].author_id = j;
                is_found = true;
                break;
            }
        }
        if (!is_found) {
            printf("Ada file config yang tidak valid.\n");
            exit(0);
        }

        // Datetime
        my_getline(line, 1024, file);
        set_tweet_datetime(tweets + id, line);
        
        // Akomodasi database
        insert_last_dynamic_list(&users[tweets[id].author_id].tweets, id);
        replies[id].tweets[0] = tweets[id];
    }

    // for (int i = 1; i < latest_tweet; ++i) {
    //     printf("ID: %d\n", tweets[i].id);
    //     printf("Text: %s\n", tweets[i].text);
    //     printf("Likes: %d\n", tweets[i].likes);
    //     printf("Author id: %d\n", tweets[i].author_id);
    //     printf("Datetime: %s\n", tweets[i].datetime);
    //     printf("\n\n");
    // }
    // printf("Latest tweet: %d\n", latest_tweet);
}

void muat_balasan(char *folder_name) {
    char balasan_file_location[1024];
    my_strcpy(balasan_file_location, folder_name);
    my_strcat(balasan_file_location, "/balasan.config");

    FILE *file;
    file = fopen(balasan_file_location, "r");

    if (!file) {
        printf("%s tidak ada atau tidak dapat diakses karena tidak memiliki permission\n", balasan_file_location);
        return;
    }
    char line[1024];
    DynamicList result;

    my_getline(line, 1024, file);
    result = split_to_ints(line);
    int total_tweets = result.list[0];
    deallocate_dynamic_list(&result);

    for (int i = 0; i < total_tweets; ++i) {
        my_getline(line, 1024, file);
        result = split_to_ints(line);
        int tweet_id = result.list[0];
        deallocate_dynamic_list(&result);

        my_getline(line, 1024, file);
        result = split_to_ints(line);
        int total_replies = result.list[0];
        deallocate_dynamic_list(&result);

        int max_reply_id = 0;
        for (int j = 0; j < total_replies; ++j) {
            Tweet child_tweet = create_tweet();
            my_getline(line, 1024, file);
            result = split_to_ints(line);
            int a = result.list[0], b = result.list[1];
            deallocate_dynamic_list(&result);
            child_tweet.id = b;
            child_tweet.likes = 0;

            // Teks balasan
            my_getline(line, 1024, file);
            set_tweet_text(&child_tweet, line);

            // Author id
            boolean is_found = false;
            my_getline(line, 1024, file);
            for (int k = 0; k < total_user; ++k) {
                if (is_two_string_equal(line, users[k].name)) {
                    child_tweet.author_id = k;
                    is_found = true;
                    break;
                }
            }
            if (!is_found) {
                printf("Ada file config yang tidak valid.\n");
                exit(0);
            }

            // Datetime
            my_getline(line, 1024, file);
            set_tweet_datetime(&child_tweet, line);

            if (a == -1) { 
                add_reply_edge(&replies[tweet_id], 0, b, child_tweet);
            }
            else {
                add_reply_edge(&replies[tweet_id], a, b, child_tweet);
            }

            max_reply_id = max(max_reply_id, b);
        }
        latest_reply[tweet_id] = max_reply_id + 1;
    }
}

void muat_draf(char *folder_name) {
    return;
    // char draf_file_location[1024];
    // my_strcpy(draf_file_location, folder_name);
    // my_strcat(draf_file_location, "/draf.config");

    // FILE *file;
    // file = fopen(draf_file_location, "r");

    // if (!file) {
    //     printf("%s tidak ada atau tidak dapat diakses karena tidak memiliki permission\n", draf_file_location);
    //     return;
    // }
    // char line[1024];
    // DynamicList result;
}

void muat_utas(char *folder_name) {
    return;
}