#ifndef DATABASE_H
#define DATABASE_H

#include "../assets/User.h"
#include "../assets/Tweet.h"

#include "../ADT/Matrix.h"
#include "../ADT/Tree.h"

#define MAX_TWEET 1000
#define MAX_USER 20

extern int current_user;
extern User users[MAX_USER];
extern  Matrix friends;

extern int latest_tweet;
extern Tweet tweets[MAX_TWEET];
extern int latest_reply[MAX_TWEET];
extern Tree replies[MAX_TWEET];

void setup_database();

#endif