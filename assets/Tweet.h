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

Tweet new_tweet(char *text, int tweet_id, int author_id);

void set_tweet_text_from_id(int id, char *text);

void set_tweet_datetime_from_id(int id, char *datetime);

void set_tweet_text(Tweet *t, char *text);

void set_tweet_datetime(Tweet *t, char *datetime);

void print_tweet(Tweet *t, int spaces);

void print_private_tweet(Tweet *t, int spaces);

#endif