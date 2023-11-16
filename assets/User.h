#ifndef USER_H
#define USER_H

#include "boolean.h"
#include "../ADT/Matrix.h"
#include "../ADT/PriorityQueueFriendRequest.h"
#include "../ADT/DynamicList.h"
#include "../ADT/StackDraft.h"

#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20
#define MAX_BIO_LENGTH 135

typedef struct User {
    char *name;
    char *password;

    boolean is_public;
    char *bio;
    char *phone;
    char *weton;
    Matrix profile_picture;

    int total_friends;
    PriorityQueueFriendRequest friend_requests;

    DynamicList tweets;
    
    StackDraft drafts;
} User;

User create_user();

void set_user_name(User *s, char *name);

void set_user_password(User *s, char *password);

void set_user_bio(User *s, char *bio);

void set_user_phone(User *s, char *phone);

void set_user_weton(User *s, char *weton);

void print_profile_picture(User *s);

#endif