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

#endif