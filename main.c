#include <stdio.h>
#include "database/database.h"

// Include file features di yang sudah diimplementasikan
#include "features/muat.h"
#include "features/suka_kicauan.h"

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

        }

        else if (is_current_word_equal("SUKA_KICAUAN")) {
            get_word();
            int id_kicau = word_to_int();
            printf("ID_kicau = %d\n", id_kicau);
            suka_kicauan(id_kicau);
        }

        else if (is_current_word_equal("CONTOH_1")) {
            // Misal contoh commandnya "CONTOH_1 22 27;".
            // Mau dapetin 22 dan 27.
            // Caranya gini:
            
            
            get_word();
            int a = word_to_int(); // 22

            get_word();
            int b = word_to_int(); // 27;

            printf("a = %d, b = %d\n", a, b); // Bakal ngeprint "a = 22, b = 27";

            // Terus buat file contoh_1.c dan contoh_1.h. Terus buat fungsi
            // void contoh_1() yang pake get_word dan yg lain-lainnya. nanti kodenya di fungsi itu ya.


    
        } else if (is_current_word_equal("CONTOH_2")) {
            // Misal contoh commandnya "CONTOH_2;"
            // Terus nanti dimintain paragraf (bisa bio, dll).
            // Caranya gini:

            clear_next_character();
            // next_character di sini, characternya selalu newline. karena setelah user mengetik "CONTOH_2;", karakter selanjuatnya yang 
            // diketik adalah newline, sehingga agar newline tidak termasuk paragraf, harus di dipanggil fungsi clear_next_character();


            START();
            // Start penting karena tadi sudah ketemu ; waktu parsing "CONTOH_2;", jadi harus START ulang lagi 
            
            get_paragraph();
            

            print_input();
            // ini buat print input (bisa word atau paragraph). ini bisa buat debugging kalau ada masalah.
        }
        

        
        else {
            printf("Belum...\n");
            print_input();
        }
    }
}