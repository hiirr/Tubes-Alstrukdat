#ifndef TWEET_H
#define TWEET_H

#include "../ADT/LinkedThread.h"

typedef struct Tweet {
    int id;
    char *text;
    int likes;
    int author_id;
    char *datetime;

    LinkedThread thread; 
} Tweet;

Tweet create_tweet();

void delete_tweet(Tweet *t);

Tweet new_tweet(int tweet_id, char *text, int author_id);

void set_tweet_text(Tweet *t, char *text);

void set_tweet_datetime(Tweet *t, char *datetime);

void print_tweet(Tweet *t, int spaces);

void print_private_tweet(Tweet *t, int spaces);

// void set_tweet_text_from_id(int id, char *text);

// void set_tweet_datetime_from_id(int id, char *datetime);

#endif