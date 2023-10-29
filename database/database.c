#include "database.h"

#include "../assets/User.h"
#include "../assets/Tweet.h"

#include "../ADT/Matrix.h"
#include "../ADT/Tree.h"

int current_user = -1;
User users[MAX_USER];
Matrix friends;

int latest_tweet = 1;
Tweet tweets[MAX_TWEET];
int latest_reply[MAX_TWEET];
Tree replies[MAX_TWEET];