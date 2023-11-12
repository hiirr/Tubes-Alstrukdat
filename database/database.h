#ifndef DATABASE_H
#define DATABASE_H

#include "../assets/User.h"
#include "../assets/Tweet.h"

#include "../ADT/GraphMatrix.h"
#include "../ADT/ReplyTree.h"

#define MAX_TWEET 1000
#define MAX_USER 20

extern int current_user;
extern int total_user;
extern User users[MAX_USER];
extern GraphMatrix friends;

extern int latest_tweet;
extern Tweet tweets[MAX_TWEET];
extern int latest_reply[MAX_TWEET];
extern ReplyTree replies[MAX_TWEET];

void setup_database();

#endif