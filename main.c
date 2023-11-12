#include <stdio.h>
#include "database/database.h"

// Include file features di yang sudah diimplementasikan
#include "features/daftar.h"
#include "features/masuk.h"
#include "features/keluar.h"

#include "features/muat.h"
#include "features/kicau.h"
#include "features/kicauan.h"
#include "features/ubah_kicauan.h"
#include "features/balas.h"
#include "features/balasan.h"
#include "features/hapus_balasan.h"

#include "ADT/Wordmachine.h"

int main() {
    
    printf(
".______    __    __  .______      .______    __  .______      \n"
"|   _  \\  |  |  |  | |   _  \\     |   _  \\  |  | |   _  \\     \n"
"|  |_)  | |  |  |  | |  |_)  |    |  |_)  | |  | |  |_)  |    \n"
"|   _  <  |  |  |  | |      /     |   _  <  |  | |      /     \n"
"|  |_)  | |  `--'  | |  |\\  \\----.|  |_)  | |  | |  |\\  \\----.\n"
"|______/   \\______/  | _| `._____||______/  |__| | _| `._____|\n\n\n");

    create_database();
    // load();

    START();

    while (true) {
        printf(">> ");

        get_word();

        if (is_input_equal("DAFTAR")) {
            daftar();
        } else if (is_input_equal("MASUK")) {
            masuk();
        } else if (is_input_equal("KELUAR")) { 
            keluar();
        } else if (is_input_equal("TUTUP_PROGRAM")) {
            printf("Anda telah keluar dari program BurBir. Sampai jumpa di penjelajahan berikutnya.\n");
            return 0;
        }

        else if (is_current_word_equal("UBAH_KICAUAN")) {
            get_word();
            int id_kicau = word_to_int();
            printf("ID_kicau = %d\n", id_kicau);
            ubah_kicauan(id_kicau);
        }
        else if (is_current_word_equal("BALAS")) {
            get_word();
            int id_kicau = word_to_int();
        }
        else if (is_current_word_equal("KICAUAN")) {
            kicauan();
            get_word();
            int id_balasan = word_to_int();
            // printf("Id_kicau = %d, id_balasan = %d\n", id_kicau, id_balasan);
        }
        else if (is_current_word_equal("KICAU")) {
            int id_kicau;
            int id_balasan;
            kicau();
            balas(id_kicau, id_balasan);
        } else if (is_current_word_equal("BALASAN")) {
            get_word();
            int id_kicau = word_to_int();
            balasan(id_kicau);
        } else if (is_current_word_equal("HAPUS_BALASAN")) {
            get_word();
            int id_kicau = word_to_int();

            get_word();
            int id_balasan = word_to_int();
            // printf("Id_kicau = %d, id_balasan = %d\n", id_kicau, id_balasan);

            hapus_balasan(id_kicau, id_balasan);
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
        
        else if (is_current_word_equal("KICAUAN")) {

        }



        
        else {
            printf("Belum...\n");
            print_input();
        }
    }
}