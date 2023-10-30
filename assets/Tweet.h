#ifndef TWEET_H
#define TWEET_H

typedef struct Tweet {
    int id;
    char *text;
    int likes;
    int author_id;
    char *datetime;

    // TODO:
    // LinkedListTweet threads;    
} Tweet;

void set_tweet_text(int id, char *text);

void set_tweet_datetime(int id, char *datetime);

void print_tweet(Tweet *t);

#endif