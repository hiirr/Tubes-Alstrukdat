#include "Tweet.h"
#include "../database/database.h"
#include <stdlib.h>
#include "../ADT/Wordmachine.h"

void set_tweet_text(int id, char *text) {
    free(tweets[id].text);
    size_t length;
    my_strlen(text, &length);
    tweets[id].text = malloc((length + 1) * sizeof(char));
    my_strcpy(tweets[id].text, text);
}

void set_tweet_datetime(int id, char *datetime) {
    free(tweets[id].datetime);
    size_t length;
    my_strlen(datetime, &length);
    tweets[id].datetime = malloc((length + 1) * sizeof(char));
    my_strcpy(tweets[id].datetime, datetime);
}

void print_tweet(Tweet *t) {
    printf(
        "ID: %d"
        "Text: %s\n"
        "Likes: %d\n"
        "Author: %s\n"
        "Datetime: %s\n",
        
        t->id,
        t->text,
        t->likes,
        users[t->author_id].name,
        t->datetime);
}