#include "lihat_draft.h"
#include "../ADT/StackDraft.h"
#include "../assets/Draft.h"
#include "../database/database.h"
#include "../ADT/Wordmachine.h"
#include "buat_draft.h"

void lihat_draft() {
    if (current_user == -1) {
        printf("Anda belum login\n\n");
        return;
    }
    
    if (is_stack_draft_empty(&users[current_user].drafts)) {
        printf("Yah, anda belum memiliki draf apapun! Buat dulu ya :D\n");
    } else {
        printf("Ini draf terakhir anda:\n");
        Draft latest_draft = top_stack_draft(&users[current_user].drafts);
        print_draft(&latest_draft);
        char *text = latest_draft.text;

        printf("Apakah anda ingin mengubah, menghapus, atau menerbitkan draf ini? (KEMBALI jika ingin kembali)");
        get_word();

        if (is_input_equal("HAPUS")) {
            Draft deleted_draft;
            pop_stack_draft(&users[current_user].drafts, &deleted_draft);
            delete_draft(&deleted_draft);
            printf("Draf telah berhasil dihapus!\n");
        } else if (is_input_equal("UBAH")) {
            Draft deleted_draft;
            pop_stack_draft(&users[current_user].drafts, &deleted_draft);
            delete_draft(&deleted_draft);

            printf("Masukkan draf yang baru:\n");

            get_paragraph();

            Draft edited = new_draft(input_to_string());
            push_stack_draft(&users[current_user].drafts, edited);
            printf("Draft berhasil diubah.\n\n");
            print_draft(&edited);

            printf("\n\n");

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
    
        } else if (is_input_equal("TERBIT")) {
            terbit_draft(text);
            Draft deleted;
            pop_stack_draft(&users[current_user].drafts, &deleted);
            delete_draft(&deleted);
            printf("Draf berhasil dihapus.\n");
        }
    }
}