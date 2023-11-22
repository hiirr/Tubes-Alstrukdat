#include <stdio.h>
#include "buat_draf.h"
#include "../assets/Draft.h"
#include "../database/database.h"
#include "../ADT/Wordmachine.h"
#include "../ADT/Datetime.h"
#include "../ADT/StackDraft.h"
#include "../ADT/DynamicList.h"
#include "../assets/Tweet.h"

void buat_draf() {
    if (current_user == -1) {
        printf("\nAnda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n\n");
        return;
    }

    printf("Masukkan draf:\n");
    clear_next_character();
    get_paragraph();
    if (current_input.length > MAX_TWEET_LENGTH) {
        printf("Teks terlalu panjang (%d karakter); batas maksimal adalah %d karakter.\n", current_input.length, MAX_TWEET_LENGTH);
        return;
    }
    char *text = input_to_string();

    printf("Apakah anda ingin menghapus (HAPUS), menyimpan (SIMPAN), atau menerbitkan (TERBIT) draf ini?\n");
    clear_next_character();
    get_word();
    if (is_input_equal("SIMPAN")) {
        Draft latest_draft = new_draft(text);
        if (!is_stack_draft_full(&users[current_user].drafts)) {
            push_stack_draft(&users[current_user].drafts, latest_draft);
            printf("Draf berhasil disimpan.\n");
        } else {
            printf("Draf tidak berhasil disimpan karena sudah mencapai kapasitas.\n");
            free(text);
        }
    } else if (is_input_equal("TERBIT")) {
        terbit_draft(text);
        printf("Draf berhasil diterbitkan.\n");
        print_tweet(&tweets[latest_tweet - 1], 0);
    } else if (is_input_equal("HAPUS")) {
        printf("Draf telah berhasil dihapus!\n");
        free(text);
    } else {
        printf("Jawaban tidak valid.\n");
        free(text);
    }
}

void terbit_draft(char *text) {
    Tweet t = new_tweet(latest_tweet, text, current_user);

    tweets[latest_tweet] = t;
    replies[latest_tweet].tweets[0] = t;

    insert_last_dynamic_list(&users[current_user].tweets, latest_tweet);

    printf("\n\nSelamat! Draf kicauan telah diterbitkan!\n");
    print_tweet(&tweets[latest_tweet], 0);
    
    ++latest_tweet;
}