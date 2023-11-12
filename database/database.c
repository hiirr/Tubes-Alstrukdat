#include "database.h"

#include "../assets/User.h"
#include "../assets/Tweet.h"

#include "../ADT/Matrix.h"
#include "../ADT/GraphMatrix.h"
#include "../ADT/ReplyTree.h"
#include "../ADT/Wordmachine.h"

#include <stdlib.h>

int current_user = -1;
int total_user = 0;
User users[MAX_USER];
GraphMatrix friends;

// int latest_tweet = 1;
int total_tweets = 0;
Tweet tweets[MAX_TWEET];
int latest_reply[MAX_TWEET];
ReplyTree replies[MAX_TWEET];

void create_database() {
    // current_user
    current_user = -1;
    total_user = 0;
    // users
    for (int i = 0; i < MAX_USER; ++i) {
        users[i] = create_user();
    }
    // friends
    create_graph_matrix(&friends, 20, 20);
    // latest_tweet
    // latest_tweet = 1;
    total_tweets = 0;
    // tweets
    for (int i = 0; i < MAX_TWEET; ++i) {
        tweets[i] = create_tweet();
    }
    // latest_reply
    for (int i = 0; i < MAX_TWEET; ++i) {
        latest_reply[i] = 1;
    }
    // replies
    for (int i = 0; i < MAX_TWEET; ++i) {
        create_reply_tree(&replies[i]);
    }
}
int search_id_by_name(char *name) {
    for (int i = 0; i < total_user; i++) {
        if (is_two_string_equal(users[i].name, name)) {
            return i;
        }
    }
    return -1;
}
