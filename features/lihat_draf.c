#include "lihat_draf.h"
#include "../ADT/StackDraft.h"
#include "../assets/Draft.h"
#include "../database/database.h"
#include "../ADT/Wordmachine.h"
#include "buat_draf.h"

void lihat_draf() {
    if (current_user == -1) {
        printf("\nAnda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n\n");
        return;
    }
    
    if (is_stack_draft_empty(&users[current_user].drafts)) {
        printf("Yah, anda belum memiliki draf apapun! Buat dulu ya :D\n");
    } else {
        printf("Ini draf terakhir anda:\n");
        Draft latest_draft = top_stack_draft(&users[current_user].drafts);
        print_draft(&latest_draft);
        char *text = latest_draft.text;

        printf("Apakah anda ingin mengubah (UBAH), menghapus (HAPUS), atau menerbitkan (TERBIT) draf ini? (KEMBALI jika ingin kembali)\n");
        clear_next_character();
        get_word();

        if (is_input_equal("HAPUS")) {
            Draft deleted_draft;
            pop_stack_draft(&users[current_user].drafts, &deleted_draft);
            delete_draft(&deleted_draft);
            printf("Draf telah berhasil dihapus!\n");
        } else if (is_input_equal("UBAH")) {            
            Draft deleted_draft = create_draft();
            pop_stack_draft(&users[current_user].drafts, &deleted_draft);

            delete_draft(&deleted_draft);


            printf("Masukkan draf yang baru:\n");
            clear_next_character();
            get_paragraph();
            if (current_input.length > MAX_TWEET_LENGTH) {
                printf("Teks terlalu panjang (%d karakter); batas maksimal adalah %d karakter. Draf Anda akan dipotong.\n\n", current_input.length, MAX_TWEET_LENGTH);
            }
            char *text = input_to_string_limited(280);

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
    
        } else if (is_input_equal("TERBIT")) {
            terbit_draft(text);
            Draft deleted;
            pop_stack_draft(&users[current_user].drafts, &deleted);
            printf("\nDraf berhasil diterbitkan.\n");
        } else if (is_input_equal("KEMBALI")) {
            printf("Kembali.\n");
        } else {
            printf("Jawaban tidak valid.\n");
        }
    }
}