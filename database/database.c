#include "database.h"

#include "../assets/User.h"
#include "../assets/Tweet.h"

#include "../ADT/Matrix.h"
#include "../ADT/GraphMatrix.h"
#include "../ADT/ReplyTree.h"

#include <stdlib.h>

int current_user = -1;
int total_user = 0;
User users[MAX_USER];
GraphMatrix friends;

int latest_tweet = 1;
Tweet tweets[MAX_TWEET];
int latest_reply[MAX_TWEET];
ReplyTree replies[MAX_TWEET];

void setup_database() {
    // current_user
    current_user = -1;
    total_user = 0;
    // users
    for (int i = 0; i < MAX_USER; ++i) {
        users[i].is_public = true;
        for (int row = 0; row < 5; ++row) {
            for (int col = 0; col < 5; ++col) {
                users[i].profile_picture.matrix[row][2 * col] = 'R';
                users[i].profile_picture.matrix[row][2 * col + 1] = '*';
            }
        }
        users[i].name = malloc(sizeof(char));
        users[i].password = malloc(sizeof(char));
        users[i].bio = malloc(sizeof(char));
        users[i].phone = malloc(sizeof(char));
        users[i].weton = malloc(sizeof(char));

        create_matrix(&users[i].profile_picture, 5, 10);

        users[i].total_friends = 0;
        create_priority_queue_friend_request(&users[i].friend_requests);

        create_dynamic_list(&users[i].tweets, 1);

        create_stack_draft(&users[i].drafts);
    }
    // friends
    create_graph_matrix(&friends, 20, 20);
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
        create_reply_tree(&replies[i]);
    }
}