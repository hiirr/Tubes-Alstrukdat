#include "database.h"

#include "../assets/User.h"
#include "../assets/Tweet.h"

#include "../ADT/Matrix.h"
#include "../ADT/GraphMatrix.h"
#include "../ADT/ReplyTree.h"
#include "../ADT/Wordmachine.h"
#include "../ADT/StaticList.h"

#include <stdlib.h>

int current_user = -1;
int total_user = 0;
StaticListUser users;
GraphMatrix friends;

int latest_tweet = 1;
StaticListTweet tweets;
StaticListReplyID latest_reply;
StaticListReply replies;

void create_database() {
    // current_user
    current_user = -1;
    // total_user
    total_user = 0;
    // users
    for (int i = 0; i < MAX_USER; ++i) {
        users[i] = create_user();
    }
    // friends
    create_graph_matrix(&friends, 20, 20);
    // latest_tweet
    latest_tweet = 1;
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

void restart_database() {
    for (int user_id = 0; user_id < total_user; ++user_id) {
        deallocate_user(&users[user_id]);
    }
    for (int tweet_id = 1; tweet_id < latest_tweet; ++tweet_id) {
        delete_tweet(&tweets[tweet_id]);
    }
    for (int i = 0; i < MAX_TWEET; ++i) {
        deallocate_reply_tree(&replies[i]);
    }
    create_database();
}

int search_id_by_name(char *name) {
    for (int i = 0; i < total_user; i++) {
        if (is_two_string_equal(users[i].name, name)) {
            return i;
        }
    }
    return -1;
}
