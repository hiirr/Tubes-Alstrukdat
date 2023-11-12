#include <stdio.h>

#include "kicauan.h"
#include "../database/database.h"
#include "../ADT/Wordmachine.h"
#include "../ADT/DynamicList.h"
#include "../assets/Tweet.h"
#include "../assets/User.h"

void kicauan() {
    if (current_user == -1) {
        printf("Anda belum login.\n\n");
        return;
    }

    DynamicList visible_tweets;
    create_dynamic_list(&visible_tweets, 1);

    for (int i = 0; i < total_user; ++i) {
        if (!users[i].is_public) return;
        for (int j = 0; j < users[i].tweets.length; ++j) {
            insert_last_dynamic_list(&visible_tweets, users[i].tweets.list[j]);
        }
    }

    for (int i = 0; i < total_user; ++i) {
        if (!friends.matrix[current_user][i]) return;
        if (users[i].is_public) return;
        for (int j = 0; j < users[i].tweets.length; ++j) {
            insert_last_dynamic_list(&visible_tweets, users[i].tweets.list[j]);
        }
    }

    sort_descending_dynamic_list(&visible_tweets);    

    for (int i = 0; i < visible_tweets.length; ++i) {
        print_tweet(&tweets[i], 0);
        printf("\n\n");
    }


}