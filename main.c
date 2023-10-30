#include <stdio.h>
#include "database/database.h"

#include "features/load.h"

#include "ADT/Wordmachine.h"

int main() {
    
    printf(
".______    __    __  .______      .______    __  .______      \n"
"|   _  \\  |  |  |  | |   _  \\     |   _  \\  |  | |   _  \\     \n"
"|  |_)  | |  |  |  | |  |_)  |    |  |_)  | |  | |  |_)  |    \n"
"|   _  <  |  |  |  | |      /     |   _  <  |  | |      /     \n"
"|  |_)  | |  `--'  | |  |\\  \\----.|  |_)  | |  | |  |\\  \\----.\n"
"|______/   \\______/  | _| `._____||______/  |__| | _| `._____|\n\n\n");

    setup_database();
    load();

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

            START();
            get_paragraph();

            print_word();
        } else if (is_current_word_equal("TEST2")) {

        } 
        
        
        else {
            printf("Belum...\n");
            print_word();
        }
    }
}