#include <stdio.h>
#include "ADT/Wordmachine.h"

int main() {
    while (true) {
        printf(">> ");
        START();

        get_word();

        if (is_current_word_equal("DAFTAR")) {
            
        } else if (is_current_word_equal("MASUK")) {

        } else if (is_current_word_equal("KELUAR")) { 
        
        } else if (is_current_word_equal("TUTUP_PROGRAM")) {

        } else if (is_current_word_equal("SIMPAN")) {

        } else if (is_current_word_equal("MUAT")) {

        } else if (is_current_word_equal("TEST")) {
            clear_new_line();
            printf("Input Bio 1: ");
            START();

            get_paragraph();
            print_word();

            printf("Input paragraph 2: ");
            START();
            get_paragraph();

            print_word();
        } 
        else {
            printf("Belum...\n");
            print_word();
        }
    }
}