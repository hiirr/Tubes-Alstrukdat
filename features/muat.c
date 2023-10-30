#include "muat.h"

#include <stdio.h>
#include <stdlib.h>

#include "../ADT/math.h"
#include "../ADT/Wordmachine.h"
#include "../ADT/ReplyTree.h"

#include "../database/database.h"

#include "../assets/User.h"
#include "../assets/Tweet.h"

void load() {
    if (current_user != -1) {
        printf("Anda harus keluar terlebih dahulu untuk melakukan pemuatan.\n");
        return;
    }

    printf("Masukkan nama folder untuk pemuatan konfigurasi: ");
    char folder_name[1024];
    my_getline(folder_name, 1024, stdin);
    // printf("Folder name: (%s)\n", folder_name);

    load_users(folder_name);
    load_tweets(folder_name);
    load_replies(folder_name);
}

void load_users(char *folder_name) {
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
    
    my_getline(line, 1024, file);
    int total_users;
    sscanf(line, "%d", &total_users);
    // printf("Banyaknya pengguna: %d\n", total_users);

    for (int i = 0; i < total_users; ++i) {;
        my_getline(line, 1024, file);
        set_user_name(users + i, line);


        my_getline(line, 1024, file);
        set_user_password(users + i, line);

        my_getline(line, 1024, file);
        set_user_bio(users + i, line);

        my_getline(line, 1024, file);
        set_user_phone(users + i, line);

        my_getline(line, 1024, file);
        set_user_weton(users + i, line);


        my_getline(line, 1024, file);
        users[i].is_public = is_two_string_equal(line, "Publik"); // (my_strcmp(line, "Publik") == 0);

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
    for (int i = 0; i < total_users; ++i) {
        my_getline(line, 1024, file);
        for (int j = 0; j < total_users; ++j) {
            friends.matrix[i][j] = line[2 * j] - '0';
        }
    }

    my_getline(line, 1024, file);
    int total_friend_requests;
    sscanf(line, "%d", &total_friend_requests);
    // printf("Total friend requests: %d\n", total_friend_requests);

    for (int i = 0; i < total_friend_requests; ++i) {
        my_getline(line, 1024, file);
        int a, b, c;
        sscanf(line, "%d %d %d", &a, &b, &c);
        FriendRequest request; request.user_id = a; request.current_total_friends = c;
        enqueue_friend_request(&users[b].friend_requests, request);
        // printf("its %d %d %d\n", a, b, c);
    }

    // for (int i = 0; i < total_users; ++i) {
    //     for (int j = 0; j < total_users; ++j) {
    //         printf("%d ", friends.matrix[i][j]);
    //     }
    //     printf("\n");
    // }
    // for (int i = 0; i < total_users; ++i) {
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

void load_tweets(char *folder_name) {
    char kicauan_file_location[1024];
    my_strcpy(kicauan_file_location, folder_name);
    my_strcat(kicauan_file_location, "/kicauan.config");
    // printf("Pengguna file: (%s)\n", pengguna_file_location);

    FILE *file;
    file = fopen(kicauan_file_location, "r");

    if (!file) {
        printf("%s tidak ada atau tidak dapat diakses karena tidak memiliki permission\n", kicauan_file_location);
        return;
    }

    char line[1024];
    
    my_getline(line, 1024, file);
    int total_tweets;
    int max_id = 0;
    sscanf(line, "%d", &total_tweets);
    for (int i = 0; i < total_tweets; ++i) {
        int id;
        my_getline(line, 1024, file);
        sscanf(line, "%d", &id);
        tweets[id].id = id;
        max_id = max(max_id, id);

        my_getline(line, 1024, file);
        set_tweet_text_from_id(id, line);

        int likes;
        my_getline(line, 1024, file);
        sscanf(line, "%d", &likes);
        tweets[id].likes = likes;

        my_getline(line, 1024, file);
        for (int j = 0; j < 20; ++j) {
            if (is_two_string_equal(line, users[j].name)) {
                tweets[id].author_id = j;
                break;
            }
        }

        my_getline(line, 1024, file);
        set_tweet_datetime_from_id(id, line);
    }
    latest_tweet = max_id + 1;

    // for (int i = 1; i <= 2; ++i) {
    //     printf("ID: %d\n", tweets[i].id);
    //     printf("Text: %s\n", tweets[i].text);
    //     printf("Likes: %d\n", tweets[i].likes);
    //     printf("Author id: %d\n", tweets[i].author_id);
    //     printf("Datetime: %s\n", tweets[i].datetime);
    //     printf("\n\n");
    // }
    // printf("Latest tweet: %d\n", latest_tweet);
}

void load_replies(char *folder_name) {
    char balasan_file_location[1024];
    my_strcpy(balasan_file_location, folder_name);
    my_strcat(balasan_file_location, "/balasan.config");
    // printf("Pengguna file: (%s)\n", pengguna_file_location);

    FILE *file;
    file = fopen(balasan_file_location, "r");

    if (!file) {
        printf("%s tidak ada atau tidak dapat diakses karena tidak memiliki permission\n", balasan_file_location);
        return;
    }

    char line[1024];

    my_getline(line, 1024, file);
    int total_tweets;
    sscanf(line, "%d", &total_tweets);
    // printf("Total tweets: %d\n", total_tweets);
    for (int i = 0; i < total_tweets; ++i) {
        int tweet_id;
        my_getline(line, 1024, file);
        sscanf(line, "%d", &tweet_id);
        // printf("ID: %d\n", tweet_id);

        my_getline(line, 1024, file);
        int total_replies;
        sscanf(line, "%d", &total_replies);
        // printf("Total replies: %d\n", total_replies);

        int max_id = 0;
        for (int j = 0; j < total_replies; ++j) {
            int a, b;
            my_getline(line, 1024, file);
            sscanf(line, "%d %d", &a, &b);
            // printf("a   b = %d %d\n", a, b);
            // printf("Bisa kah??\n");
            // printf("text: %s", line);
            my_getline(line, 1024, file); // text
            
            // printf("text: %s", line);
            // return;
            Tweet child_tweet;
            child_tweet.id = b;
            child_tweet.text = line;
            // set_tweet_text(&child_tweet, line);
            child_tweet.likes = 0;
            my_getline(line, 1024, file); // Author's name
            for (int k = 0; k < 20; ++k) {
                if (is_two_string_equal(line, users[k].name)) {
                    child_tweet.author_id = k;
                    break;
                }
            }
            my_getline(line, 1024, file);  // Datetetime
            child_tweet.datetime = line;
            // set_tweet_datetime(&child_tweet, line);

            if (a == -1) add_reply_edge(&replies[tweet_id], 0, b, child_tweet);
            else add_reply_edge(&replies[tweet_id], a, b, child_tweet);
        
            max_id = max(max_id, b);
        }
        latest_reply[tweet_id] = max_id + 1;
    }
    // print_reply_tree(&replies[1]);
}