#include <stdio.h>
#include "database/database.h"
#include "ADT/Charmachine.h"
#include "ADT/Wordmachine.h"
#include "ADT/Datetime.h"

#include "features/inisialisi.h"
#include "features/daftar.h"
#include "features/masuk.h"
#include "features/keluar.h"
#include "features/ganti_profil.h"
#include "features/lihat_profil.h"
#include "features/atur_jenis_akun.h"
#include "features/ubah_foto_profil.h"
#include "features/daftar_teman.h"
#include "features/hapus_teman.h"
#include "features/tambah_teman.h"
#include "features/daftar_permintaan_pertemanan.h"
#include "features/setujui_pertemanan.h"
#include "features/kicau.h"
#include "features/kicauan.h"
#include "features/suka_kicauan.h"
#include "features/ubah_kicauan.h"
#include "features/balas.h"
#include "features/balasan.h"
#include "features/hapus_balasan.h"
#include "features/buat_draf.h"
#include "features/lihat_draf.h"
// UTAS
#include "features/simpan.h"
#include "features/muat.h"


int main() {
    create_database();

    SET_STDIN();

    inisialisi();
    
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
        } else if (is_input_equal("GANTI_PROFIL")) {
            ganti_profil();
        } else if (is_input_equal("LIHAT_PROFIL")) {
            get_paragraph();
            char *name = input_to_string();
            lihat_profil(name);
            free(name);
        } else if (is_input_equal("ATUR_JENIS_AKUN")) {
            atur_jenis_akun();
        } else if (is_input_equal("UBAH_FOTO_PROFIL")) {
            ubah_foto_profil();
        } else if (is_input_equal("DAFTAR_TEMAN")) {
            daftar_teman();
        } else if (is_input_equal("HAPUS_TEMAN")) {
            hapus_teman();
        } else if (is_input_equal("TAMBAH_TEMAN")) {
            tambah_teman();
        } else if (is_input_equal("DAFTAR_PERMINTAAN_PERTEMANAN")) {
            daftar_permintaan_pertemanan();
        } else if (is_input_equal("SETUJUI_PERTEMANAN")) {
            setujui_pertemanan();
        } else if (is_input_equal("KICAU")) {
            kicau();
        } else if (is_input_equal("KICAUAN")) {
            kicauan();
        } else if (is_input_equal("SUKA_KICAUAN")) {
            get_word();
            int tweet_id = input_to_int();
            suka_kicauan(tweet_id);
        } else if (is_input_equal("UBAH_KICAUAN")) {
            get_word();
            int tweet_id = input_to_int();
            ubah_kicauan(tweet_id);
        } else if (is_input_equal("BALAS")) {
            get_word();
            int tweet_id = input_to_int();
            get_word();
            int reply_id = input_to_int();
            balas(tweet_id, reply_id);
        } else if (is_input_equal("BALASAN")) {
            get_word();
            int tweet_id = input_to_int();
            balasan(tweet_id);
        } else if (is_input_equal("HAPUS_BALASAN")) {
            get_word();
            int tweet_id = input_to_int();
            get_word();
            int reply_id = input_to_int();
            hapus_balasan(tweet_id, reply_id);
        } else if (is_input_equal("BUAT_DRAF")) {
            buat_draf();
        } else if (is_input_equal("LIHAT_DRAF")) {
            lihat_draf();
        }
        // Start utas (belum)
        else if (is_input_equal("UTAS")) {
            printf("Belum diimplementasi.\n");
        } else if (is_input_equal("SAMBUNG_UTAS")) {
            printf("Belum diimplementasi.\n");
        } else if (is_input_equal("HAPUS_UTAS")) {
            printf("Belum diimplementasi.\n");
        } else if (is_input_equal("CETAK_ UTAS")) {
            printf("Belum diimplementasi.\n");
        }
        // End utas
        

        // Start simpan (belum)
        else if (is_input_equal("SIMPAN")) {
            printf("Belum diimplementasi.\n");
            // simpan();
        } else if (is_input_equal("MUAT")) {
            muat();
        }
        // End simpan
        
        else {
            printf("Perintah tidak dikenal ");
            print_input();
        }
    }
}