#include <stdio.h>
#include "keluar.h"
#include "../database/database.h"

void keluar() {
    if (current_user == -1) {
        printf("Anda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
    } else {
        current_user = -1;
        printf("Anda berhasil logout. Sampai jumpa di pertemuan berikutnya!\n");
    }
}