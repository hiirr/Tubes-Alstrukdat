#include <stdio.h>

#include "../database/database.h"
#include "../ADT/Wordmachine.h"
#include "../ADT/Datetime.h"
#include "../ADT/DynamicList.h"
#include "../assets/Tweet.h"

void kicau() {
    if (current_user == -1) {
        printf("Anda belum login\n\n");
        return;
    }

    printf("Masukkan kicauan:\n");
    get_paragraph();

    if (current_input.length > 280) {
        printf("Panjang kicauan (%d karakter) melebihi 280 karakter.\n", current_input.length);
        return;
    }

    char *text = input_to_string();
    if (is_all_space(text)) {
        free(text);
        printf("Tidak boleh hanya mengandung spasi saja.\n");
        return;
    }

    tweets[latest_tweet] = new_tweet(latest_tweet, text, current_user);
    
    insert_last_dynamic_list(&users[current_user].tweets, latest_tweet);

    printf("Kicauan berhasil diterbitkan:\n");
    print_tweet(&tweets[latest_tweet], 0);

    latest_tweet++;
}