#include <stdio.h>
#include "utas.h"
#include "../ADT/LinkedThread.h"
#include "../ADT/Wordmachine.h"

void utas(int id_kicau){
    LinkedThread l;
    create_linked_thread(&l);
    ThreadComponent text;
    if (id_kicau != NULL){
        printf("Utas berhasil dibuat!\n\n");
        boolean is_cont_thread = true;
        while (is_cont_thread){
            printf("Masukkan kicauan:\n");
            START();
            get_paragraph();
            insert_last_linked_thread(&l, text);
            printf("Apakah Anda ingin melanjutkan utas ini? (YA/TIDAK) ");
            START();
            get_word();
            if (is_current_word_equal("TIDAK")){
                is_cont_thread = false;
            }
        }
        printf("Utas selesai!\n\n");
    }
    else{
        printf("Utas ini bukan milik anda!\n\n");
    }
}