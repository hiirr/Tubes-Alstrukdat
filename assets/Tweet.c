#include "Tweet.h"
#include "../database/database.h"
#include <stdlib.h>
#include "../ADT/Wordmachine.h"
#include "../ADT/Datetime.h"

Tweet create_tweet() {
    Tweet tweet;
    tweet.id = -1;
    tweet.text = NULL;
    tweet.likes = 0;
    tweet.author_id = -1;
    tweet.datetime = NULL;
    create_linked_thread(&tweet.thread);
    return tweet;
}

void delete_tweet(Tweet *t) {
    t->id = -1;
    free(t->text);
    t->text = NULL;
    t->likes = 0;
    t->author_id = -1;
    free(t->datetime);
    t->datetime = NULL;
    while (length_linked_thread(t->thread)) delete_first_linked_thread(&t->thread);
}

Tweet new_tweet(int tweet_id, char *text, int author_id) {
    Tweet t = create_tweet();
    t.id = tweet_id;
    t.text = text;
    t.likes = 0;
    t.author_id = author_id;
    DATETIME *current_datetime = malloc(sizeof(DATETIME));
    *current_datetime = get_current_DATETIME();
    set_tweet_datetime(&t, current_datetime);
    return t;
}

void set_tweet_text(Tweet *t, char *text) {
    if (t->text != NULL) {
        free(t->text);
    }
    size_t length;
    my_strlen(text, &length);
    t->text = malloc((length + 1) * sizeof(char));
    my_strcpy(t->text, text);
}

void set_tweet_datetime(Tweet *t, DATETIME *datetime) {
    if (t->datetime != NULL) {
        free(t->datetime);
    }
    t->datetime = datetime;
}

void print_tweet(Tweet *t, int spaces) {
    for (int i = 0; i < spaces; ++i) printf("\t");
    printf("ID: %d\n", t->id);

    for (int i = 0; i < spaces; ++i) printf("\t");
    printf("Text: %s\n", t->text);

    for (int i = 0; i < spaces; ++i) printf("\t");
    printf("Likes: %d\n", t->likes);

    for (int i = 0; i < spaces; ++i) printf("\t");
    printf("Author: %s\n", users[t->author_id].name);

    for (int i = 0; i < spaces; ++i) printf("\t");
    char *datetime_str = DATETIME_to_string(*(t->datetime));
    printf("Datetime: %s\n", datetime_str);
    free(datetime_str);

    printf("\n\n");
    // printf("ID: %d\n"
    //     "Text: %s\n"
    //     "Likes: %d\n"
    //     "Author: %s\n"
    //     "Datetime: %s\n",
        
    //     t->id,
    //     t->text,
    //     t->likes,
    //     users[t->author_id].name,
    //     t->datetime);
}

void print_private_tweet(Tweet *t, int spaces) {
    for (int i = 0; i < spaces; ++i) printf("\t");
    printf("ID: %d\n", t->id);

    for (int i = 0; i < spaces; ++i) printf("\t");
    printf("PRIVAT\n");

    for (int i = 0; i < spaces; ++i) printf("\t");
    printf("PRIVAT\n");

    for (int i = 0; i < spaces; ++i) printf("\t");
    printf("PRIVAT\n");

    for (int i = 0; i < spaces; ++i) printf("\t");
    printf("PRIVAT\n\n");
    // printf("ID: %d\n"
    //     "Text: %s\n"
    //     "Likes: %d\n"
    //     "Author: %s\n"
    //     "Datetime: %s\n",
        
    //     t->id,
    //     t->text,
    //     t->likes,
    //     users[t->author_id].name,
    //     t->datetime);
}

// Tweet new_tweet(char *text, int tweet_id, int author_id) {
//     Tweet tweet;

//     tweet.id = tweet_id;
//     tweet.text = text;
//     tweet.likes = 0;
//     tweet.author_id = author_id;
//     tweet.datetime = current_time();

//     return tweet;
// }

// void set_tweet_text_from_id(int id, char *text) {
//     free(tweets[id].text);
//     size_t length;
//     my_strlen(text, &length);
//     tweets[id].text = malloc((length + 1) * sizeof(char));
//     my_strcpy(tweets[id].text, text);
// }

// void set_tweet_datetime_from_id(int id, char *datetime) {
//     free(tweets[id].datetime);
//     size_t length;
//     my_strlen(datetime, &length);
//     tweets[id].datetime = malloc((length + 1) * sizeof(char));
//     my_strcpy(tweets[id].datetime, datetime);
// }
