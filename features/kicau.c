#include <stdio.h>

#include "../database/database.h"
#include "../ADT/Wordmachine.h"
#include "../ADT/Datetime.h"
#include "../assets/Tweet.h"

void kicau() {
    if (current_user == -1) {
        printf("Anda belum login\n\n");
        return;
    }

    printf("Masukkan kicauan:\n");
    clear_next_character();

    START();
    get_paragraph();

    char *text = input_to_string();
    char *time = current_time();

    tweets[latest_tweet].id = latest_tweet;
    tweets[latest_tweet].likes = 0;
    tweets[latest_tweet].author_id = current_user;
    set_tweet_text(&tweets[latest_tweet], text);
    set_tweet_datetime(&tweets[latest_tweet], time);


    printf("Kicauan berhasil diterbitkan:\n");
    print_tweet(&tweets[latest_tweet], 0);

    latest_tweet++;
}