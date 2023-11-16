#include <stdio.h>
#include "buat_draft.h"
#include "../assets/Draft.h"
#include "../database/database.h"
#include "../ADT/Wordmachine.h"
#include "../ADT/Datetime.h"
#include "../ADT/StackDraft.h"
#include "../ADT/DynamicList.h"
#include "../assets/Tweet.h"

void buat_draft() {
    if (current_user == -1) {
        printf("Anda belum login\n\n");
        return;
    }

    printf("Masukkan draf:\n");
    get_paragraph();
    if (current_input.length > 280) {
        printf("Teks terlalu panjang (%d karakter); batas maksimal adalah 280 karakter.\n", current_input.length);
        return;
    }

    printf("Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?\n");
    get_word();
    if (is_input_equal("SIMPAN")) {
        char *text = input_to_string();
        Draft latest_draft = new_draft(text);
        if (!is_stack_draft_full(&users[current_user].drafts)) {
            push_stack_draft(&users[current_user].drafts, latest_draft);
            printf("Draf berhasil disimpan.\n");
        } else {
            printf("Draf tidak berhasil disimpan karena sudah mencapai kapasitas.\n");
        }
    } else if (is_input_equal("TERBIT")) {
        char *text = input_to_string();
        terbit_draft(text);
    } else if (is_input_equal("HAPUS")) {
        printf("Draf telah berhasil dihapus!\n");
    }
}

void terbit_draft(char *text) {
        Tweet t = new_tweet(latest_tweet, text, current_user);
    
        tweets[latest_tweet] = t;
        
        insert_last_dynamic_list(&users[current_user].tweets, latest_tweet);

        printf("Selamat! Draf kicauan telah diterbitkan!\n");
        print_tweet(&tweets[latest_tweet], 0);

        ++latest_tweet;
}