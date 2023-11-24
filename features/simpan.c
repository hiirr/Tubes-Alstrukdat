#include "simpan.h"
#include "../ADT/Wordmachine.h"
#include "../database/database.h"
#include "../ADT/DynamicList.h"
#include "../ADT/LinkedThread.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h> // Linux only


// char *getcwd(char *buf, size_t size);

struct stat info;

char *relative_folder_path, absolute_folder_path[1000];

void simpan() {
    printf("Masukkan nama folder penyimpanan:\n");
    clear_next_character();
    get_paragraph();
    
    
    relative_folder_path = input_to_string();
    if (stat(relative_folder_path, &info) != 0 || !(info.st_mode & __S_IFDIR)) {
        printf("Folder tidak ada. Folder akan dibuat...\n");
        make_directory(relative_folder_path);
    }

    getcwd(absolute_folder_path, sizeof(absolute_folder_path));
    my_strcat(absolute_folder_path, "/");
    my_strcat(absolute_folder_path, relative_folder_path);
    my_strcat(absolute_folder_path, "/");

    simpan_pengguna();
    simpan_kicauan();
    simpan_balasan();
    simpan_draf();
    simpan_utas();

    free(relative_folder_path);

    printf("Penyimpanan berhasil dilakukan.\n");
}

void simpan_pengguna() {
    char pengguna_file_location[1000];
    my_strcpy(pengguna_file_location, absolute_folder_path);
    my_strcat(pengguna_file_location, "pengguna.config");
    FILE *file = fopen(pengguna_file_location, "w");
    
    // fprintf(file, "Ini contoh doang");
    
    // Banyaknya pengguna

    fprintf(file, "%d\n", total_user);

    for (int i = 0; i < total_user; ++i) {
        fprintf(file, "%s\n", users[i].name);

        fprintf(file, "%s\n", users[i].password);

        fprintf(file, "%s\n", users[i].bio);

        fprintf(file, "%s\n", users[i].phone);

        fprintf(file, "%s\n", users[i].weton);

        if (users[i].is_public) {
            fprintf(file, "Publik\n");
        } else {
            fprintf(file, "Privat\n");
        }
        for (int row = 0; row < 5; ++row) {
            for (int col = 0; col < 10; ++col) {
                // char c = users[i].profile_picture.matrix[row][col];
                // char cs[2] = {c, '\0'};
                // fprintf(file, cs);
                // fprintf(file, " ");
                fprintf(file, "%c ", users[i].profile_picture.matrix[row][col]);
            }
            fprintf(file, "\n");
        }
    }
    for (int i = 0; i < total_user; ++i) {
        for (int j = 0; j < total_user; ++j) {
            if (i == j) {
                fprintf(file, "1 ");
            } else {
                fprintf(file, "%d ", friends.matrix[i][j]);
            }
        }
        fprintf(file, "\n");
    }
    
    int total_friend_requests = 0;
    for (int i = 0; i < total_user; ++i) {
        total_friend_requests += length_priority_queue_friend_request(users[i].friend_requests);
    }
    fprintf(file, "%d\n", total_friend_requests);
    for (int user_id = 0; user_id < total_user; ++user_id) {
        int length = length_priority_queue_friend_request(users[user_id].friend_requests);
        int start_idx = users[user_id].friend_requests.head;
        for (int i = 0; i < length; i++) {
            int index = start_idx - i;
            if (index < 0) {
                index += PRIORITY_QUEUE_FRIEND_REQUEST_CAPACITY;
            }
            // printf("\n| Priority: %d\n", i + 1);
            // printf("| Id: %d\n", p.queue[index].user_id);
            // printf("| Jumlah teman: %d\n", p.queue[index].current_total_friends);
            fprintf(file, "%d %d %d\n", users[user_id].friend_requests.queue[index].user_id, user_id, users[user_id].friend_requests.queue[index].current_total_friends);
        }
    }

    fclose(file);
}

void simpan_kicauan() {
    char kicauan_file_location[1000];
    my_strcpy(kicauan_file_location, absolute_folder_path);
    my_strcat(kicauan_file_location, "kicauan.config");
    FILE *file = fopen(kicauan_file_location, "w");

    fprintf(file, "%d\n", latest_tweet - 1);

    for (int tweet_id = 1; tweet_id < latest_tweet; ++tweet_id) {
        fprintf(file, "%d\n", tweet_id);

        fprintf(file, "%s\n", tweets[tweet_id].text);

        fprintf(file, "%d\n", tweets[tweet_id].likes);

        fprintf(file, "%s\n", users[tweets[tweet_id].author_id].name);

        fprintf(file, "%s\n", DATETIME_to_string(*tweets[tweet_id].datetime));
    }

    fclose(file);
}

void simpan_balasan() {
    char balasan_file_location[1000];
    my_strcpy(balasan_file_location, absolute_folder_path);
    my_strcat(balasan_file_location, "balasan.config");
    FILE *file = fopen(balasan_file_location, "w");

    int total_tweets_with_reply = 0;
    for (int tweet_id = 1; tweet_id < latest_tweet; ++tweet_id) {
        for (int j = 1; j < latest_reply[tweet_id]; ++j) {
            if (replies[tweet_id].nodes[j]) {
                ++total_tweets_with_reply;
                break;
            }
        }
        // if (latest_reply[tweet_id] > 1) {
        //     ++total_tweets_with_reply;
        // }
    }
    fprintf(file, "%d\n", total_tweets_with_reply);

    for (int tweet_id = 1; tweet_id < latest_tweet; ++tweet_id) {
        int total_replies = 0;
        for (int j = 1; j < latest_reply[tweet_id]; ++j) {
            if (replies[tweet_id].nodes[j]) {
                ++total_replies;
            }
        }
        if (total_replies == 0) continue;
        fprintf(file, "%d\n", tweet_id);

        fprintf(file, "%d\n", total_replies);
        // root
        for (int i = 0; i < replies[tweet_id].adj[0].length; ++i) {
            int id = replies[tweet_id].adj[0].list[i];
            fprintf(file, "-1 %d\n", id);
            fprintf(file, "%s\n", replies[tweet_id].tweets[id].text);
            fprintf(file, "%s\n", users[replies[tweet_id].tweets[id].author_id].name);
            fprintf(file, "%s\n", DATETIME_to_string(*replies[tweet_id].tweets[id].datetime));
        }
        // nonroot
        for (int reply = 1; reply < latest_reply[tweet_id] - 1; ++reply) {
            for (int i = 0; i < replies[tweet_id].adj[reply].length; ++i) {
                int id = replies[tweet_id].adj[reply].list[i];
                fprintf(file, "%d %d\n", reply, id);
                fprintf(file, "%s\n", replies[tweet_id].tweets[id].text);
                fprintf(file, "%s\n", users[replies[tweet_id].tweets[id].author_id].name);
                fprintf(file, "%s\n", DATETIME_to_string(*replies[tweet_id].tweets[id].datetime));
            }
        }
    }
    fclose(file);
}

void simpan_draf() {
    char draf_file_location[1000];
    my_strcpy(draf_file_location, absolute_folder_path);
    my_strcat(draf_file_location, "draf.config");
    FILE *file = fopen(draf_file_location, "w");

    int total_user_with_draft = 0;
    for (int i = 0; i < total_user; ++i) {
        if (users[i].drafts.top != -1) {
            ++total_user_with_draft;
        }
    }
    
    fprintf(file, "%d\n", total_user_with_draft);

    for (int i = 0; i < total_user; ++i) {
        if (users[i].drafts.top != -1) {
            fprintf(file, "%s %d\n", users[i].name, users[i].drafts.top + 1);
            for (int j = users[i].drafts.top; j >= 0; --j) {
                fprintf(file, "%s\n", users[i].drafts.stack[j].text);
                fprintf(file, "%s\n", users[i].drafts.stack[j].datetime);
            }    
        }
    }
    fclose(file);
}

void simpan_utas() {
    char utas_file_location[1000];
    my_strcpy(utas_file_location, absolute_folder_path);
    my_strcat(utas_file_location, "utas.config");
    FILE *file = fopen(utas_file_location, "w");

    int total_tweets_with_thread = 0;
    for (int tweet_id = 1; tweet_id < latest_tweet; ++tweet_id) {
        if (!is_empty_linked_thread(tweets[tweet_id].thread)) {
            ++total_tweets_with_thread;
        }
    }
    fprintf(file, "%d\n", total_tweets_with_thread);
    for (int tweet_id = 1; tweet_id < latest_tweet; ++tweet_id) {
        if (!is_empty_linked_thread(tweets[tweet_id].thread)) {
            fprintf(file, "%d\n", tweet_id);
            int length = length_linked_thread(tweets[tweet_id].thread);
            fprintf(file, "%d\n", length);
            LinkedThreadComponentAddress current = tweets[tweet_id].thread;
            for (int utas = 0; utas < length; ++utas) {
                fprintf(file, "%s\n", current->thread.text);
                fprintf(file, "%s\n", users[tweets[tweet_id].author_id].name);
                fprintf(file, "%s\n", current->thread.datetime);
                current = current->next;
            }
        }
    }

    fclose(file);
}

void make_directory(const char* name) {
   #ifdef __linux__
       mkdir(name, 777); 
   #else
       _mkdir(name);
   #endif
}