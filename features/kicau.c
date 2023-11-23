#include <stdio.h>

#include "../database/database.h"
#include "../ADT/Wordmachine.h"
#include "../ADT/Datetime.h"
#include "../ADT/DynamicList.h"
#include "../assets/Tweet.h"

void kicau() {
    if (current_user == -1) {
        printf("\nAnda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n\n");
        return;
    }

    printf("Masukkan kicauan:\n");
    clear_next_character();
    get_paragraph();

    if (current_input.length > MAX_TWEET_LENGTH) {
        printf("Teks terlalu panjang (%d karakter); melebihi %d karakter. Kicauan Anda akan dipotong.\n\n", current_input.length, MAX_TWEET_LENGTH);
    }

    char *text = input_to_string_limited(280);
    if (is_all_space(text)) {
        free(text);
        printf("Tidak boleh hanya mengandung spasi saja.\n");
        return;
    }

    tweets[latest_tweet] = new_tweet(latest_tweet, text, current_user);
    
    insert_last_dynamic_list(&users[current_user].tweets, latest_tweet);
    replies[latest_tweet].tweets[0] = tweets[latest_tweet];

    printf("Kicauan berhasil diterbitkan:\n\n");
    print_tweet(&tweets[latest_tweet], 0);

    latest_tweet++;
}