#include <stdio.h>
#include "draft_tweet.h"
#include "../assets/Draft.h"
#include "../database/database.h"
#include "../ADT/Wordmachine.h"
#include "../ADT/Datetime.h"
#include "../ADT/StackDraft.h"
#include "../ADT/DynamicList.h"
#include "../assets/Tweet.h"

void buat_draft(StackDraft *s) {
    if (current_user == -1) {
        printf("Anda belum login\n\n");
        return;
    }

    printf("Masukkan draf:\n");
    clear_next_character();

    START();
    get_paragraph();

    char *text = input_to_string();
    char *time = current_time();

    printf("Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?\n");
    START();
    get_word();

    if (is_current_word_equal("SIMPAN")) {
        Draft lastest_draft = new_draft(text);
        if (!is_stack_draft_full(&s)) {
            push_stack_draft(&s, lastest_draft);
        }

    } else if (is_current_word_equal("TERBIT")) {
        terbit_draft(&text, &time);

    } else if (is_current_word_equal("HAPUS")) {
        printf("Draf telah berhasil dihapus!\n");
    }
}

void lihat_draft(StackDraft *s) {
    if (current_user == -1) {
        printf("Anda belum login\n\n");
        return;
    }

    if (is_stack_draft_empty(&s)) {
        printf("Yah, anda belum memiliki draf apapun! Buat dulu ya :D\n");
    } else {
        printf("Ini draf terakhir anda:\n");
        Draft latest_draft = top_stack_draft(&s);
        print_draft(&latest_draft);
        char *text = latest_draft.text;
        char *time = latest_draft.datetime;

        printf("Apakah anda ingin mengubah, menghapus, atau menerbitkan draf ini? (KEMBALI jika ingin kembali)");
        START();
        get_word();

        if (is_current_word_equal("HAPUS")) {
            Draft deleted_draft;
            pop_stack_draft(&s, &deleted_draft);

            printf("Draf telah berhasil dihapus!\n");

        } else if (is_current_word_equal("UBAH")) {
            printf("Masukkan draf yang baru:\n");
            clear_next_character();

            START();
            get_paragraph();

            *text = input_to_string();
            *time = current_time();

            printf("Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?\n");
            START();
            get_word();

            if (is_current_word_equal("SIMPAN")) {
                Draft lastest_draft = new_draft(text);
                if (!is_stack_draft_full(&s)) {
                    push_stack_draft(&s, lastest_draft);
                }

            } else if (is_current_word_equal("TERBIT")) {
                terbit_draft(&text, &time);

            } else if (is_current_word_equal("HAPUS")) {
                Draft deleted_draft;
                pop_stack_draft(&s, &deleted_draft);
                printf("Draf telah berhasil dihapus!\n");
            }
    
        } else if (is_current_word_equal("TERBIT")) {
            terbit_draft(&text, &time);
        }
    }
}

void terbit_draft(char *text, char *time) {
    tweets[latest_tweet].id = latest_tweet;
    tweets[latest_tweet].likes = 0;
    tweets[latest_tweet].author_id = current_user;
    set_tweet_text(&tweets[latest_tweet], text);
    set_tweet_datetime(&tweets[latest_tweet], time);
    
    insert_last_dynamic_list(&users[current_user].tweets, latest_tweet);

    printf("Selamat! Draf kicauan telah diterbitkan!\n");
    print_tweet(&tweets[latest_tweet], 0);

    latest_tweet++;
}