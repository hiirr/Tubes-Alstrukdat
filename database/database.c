#include "database.h"

#include "../assets/User.h"
#include "../assets/Tweet.h"

#include "../ADT/Matrix.h"
#include "../ADT/Tree.h"

#include <stdlib.h>

int current_user = -1;
User users[MAX_USER];
Matrix friends;

int latest_tweet = 1;
Tweet tweets[MAX_TWEET];
int latest_reply[MAX_TWEET];
Tree replies[MAX_TWEET];

void setup_database() {
    // current_user
    current_user = -1;
    // users
    for (int i = 0; i < MAX_USER; ++i) {
        users[i].name = malloc(sizeof(char));
        users[i].password = malloc(sizeof(char));
        users[i].bio = malloc(sizeof(char));
        users[i].phone = malloc(sizeof(char));
        users[i].weton = malloc(sizeof(char));
        users[i].is_public = true;

        create_matrix(&users[i].profile_picture, 5, 10);

        users[i].total_friends = 0;
        create_priority_queue_friend_request(&users[i].friend_requests);

        create_dynamic_list(&users[i].tweets, 1);

        create_stack_draft(&users[i].drafts);
    }
    // friends
    create_matrix(&friends, 20, 20);
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            friends.matrix[i][j] = 0;
        }
    }
    // latest_tweet
    latest_tweet = 1;
    // tweets
    for (int i = 0; i < MAX_TWEET; ++i) {
        tweets[i].id = -1;
        tweets[i].text = malloc(sizeof(char));
        tweets[i].likes = 0;
        tweets[i].author_id = -1;
        tweets[i].datetime = malloc(sizeof(char));
    }
    // latest_reply
    for (int i = 0; i < MAX_TWEET; ++i) {
        latest_reply[i] = 1;
    }
    // replies
    for (int i = 0; i < MAX_TWEET; ++i) {
        create_tree(&replies[i]);
    }
}