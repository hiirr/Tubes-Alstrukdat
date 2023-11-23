#include <stdio.h>
#include "../ADT/Wordmachine.h"

int main() {
    while (true) {
        printf(">> ");
        START();

        get_word();

        if (is_input_equal("DAFTAR")) {
            
        } else if (is_input_equal("MASUK")) {

        } else if (is_input_equal("KELUAR")) { 
            break;
        } else if (is_input_equal("TUTUP_PROGRAM")) {

        } else if (is_input_equal("SIMPAN")) {

        } else if (is_input_equal("MUAT")) {

        } else if (is_input_equal("TEST")) {
            printf("Input Bio 1: ");
            START();

            get_paragraph();
            print_input();

            printf("Input paragraph 2: ");
            START();
            get_paragraph();

            print_input();
        } 
        else {
            printf("Belum...\n");
            print_input();
        }
    }
}