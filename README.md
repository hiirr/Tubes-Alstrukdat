# TUGAS BESAR - Algoritma & Struktur Data
## K02 - KELOMPOK A
#### Tugas Besar 2 Aljabar Linier dan Geometri IF2123
#### Aplikasi Aljabar Vektor dalam Sistem Temu Balik Gambar

| **NIM** | **Nama Anggota** |
|:---:|:---:|
| 13522062 | Salsabiila |
| 13522067 | Randy Verdian |
| 13522073 | Juan Alfred Wijaya |
| 13522085 | Zahira Dina Amalia |
| 13522109 | Azmi Mahmud Bazeid |
| 13519212 | Ryan Kurnia Hidayatullah |

## Tentang Program
Burbir merupakan sebuah program simulasi berbasis command line interface (CLI) dalam bahasa C yang menggunakan struktur data abstrak. Tujuan dibuatnya Burbir adalah untuk membantu Ande-Ande Lumut yang ingin membuat aplikasi sosial media baru karena iba mendengar kisah perundungan Klenting Kuning oleh ibu tirinya di aplikasi sosial media Y. Fitur utama dari Burbir adalah pengguna dapat mengirimkan kicauan serta melihat dan membalas kicauan teman.
Laporan ini berisikan tentang penjelasan setiap struktur data abstrak atau abstract data type (ADT) yang digunakan dalam pembuatan program simulasi dan penjelasan mengenai program utamanya. Selain itu, terdapat pula penjelasan mengenai data test dan test script hasil uji coba program, pembagian kerja dalam kelompok, dan lampiran.
Kesimpulan yang dapat diambil dari pengerjaan tugas besar ini adalah bagaimana cara kami mengimplementasikan tipe ADT yang tepat sebagai solusi untuk merealisasikan suatu ide pembuatan program simulasi sosial media berbasis teks.

## Cara Kompilasi Program
Clone git ini, lalu ketik `gcc -o main -Wall main.c ADT/*.c assets/*.c database/*.c features/*.c` pada terminal.

## Cara Menjalankan Program & Daftar Fitur
1. Ketik `./main` pada terminal.
2. Masukan nama folder letak file-file konfigurasi berada.
3. Masukan perintah-perintah yang diinginkan sesuai detail berikut,
- DAFTAR: pengguna mendaftarkan akun baru Burbir
- MASUK: pengguna masuk ke akun Burbir yang telah terdafatr
- KELUAR: pengguna keluar dari akun Burbir yang sedang masuk
- TUTUP_PROGRAM: pengguna menghentikan program Burbir
- GANTI_PROFIL: pengguna mengganti info profil akunnya
- LIHAT_PROFIL: pengguna melihat info profil akunnya
- ATUR_JENIS_AKUN: pengguna dapat memilih tipe akun antara privat dan publik
- UBAH_FOTO_PROFIL: pengguna mengganti foto profil akunnya
- DAFTAR_TEMAN: pengguna melihat daftar teman Burbirnya
- HAPUS_TEMAN: pengguna menghapus teman Burbirnya
- TAMBAH_TEMAN: pengguna mengirimkan permintaan pertemanan ke pada akun lain
- DAFTAR_PERMINTAAN_PERTEMANAN: pengguna melihat daftar permintaan pertemanan yang ditujukan ke pada akunnya
- SETUJUI_PERTEMANAN: pengguna menyetujui permintaan pertemanan
- KICAU: pengguna mengirimkan kicauan
- KICAUAN: pengguna melihat kicauan
- SUKA_KICAUAN: pengguna menyukai sebuah kicauan
- UBAH_KICAUAN: pengguna mengubah kicauan yang telah diunggah
- BALAS: pengguna mengirimkan balasan ke sebuah - kicauan atau balasan lain
- BALASAN: pengguna melihat balasan dari sebuah kicauan atau balasan lain
- HAPUS_BALASAN: pengguna menghapus balasan yang telah diunggah
- BUAT_DRAF: pengguna menambahkan sebuah draf
- LIHAT_DRAF: pengguna melihat draf terakhit yang dibuat
- UTAS: pengguna membuat sebuah utas baru
- SAMBUNG_UTAS: pengguna menambah sebuah kicauan baru dalam sebuah utas
- HAPUS_UTAS: pengguna menghapus kicauan dalam sebuah utas
- CETAK_UTAS: pengguna mencetak keseleuruhan kicauan dalam sebuah utas
- SIMPAN: pengguna menyimpan kondisi dari BurBir daat itu ke dalam suatu folder berisi berkas-berkas konfigurasi
- MUAT: pengguna memuat kondisi folder berisi berkas-berkas konfigurasi ke dalam BurBir


## Pembagian Tugas
| **NIM** | **Nama Anggota** | **Tugas**|
|:---:|:---:|:---:|
| 13522062 | Salsabiila | ADT Word machine, Fitur yang berhubungan dengan draf + Keluar, PIC laporan |
| 13522067 | Randy Verdian | ADT Linked Thread, Stack Draft, Fitur yang berhubungan dengan utas + Daftar |
| 13522073 | Juan Alfred Wijaya | ADT Date Time, Graph Matrix, Word machine, Fitur yang berhubungan dengan teman |
| 13522085 | Zahira Dina Amalia | ADT Matrix, Word machine, Fitur yang berhubungan dengan profil, PIC laporan |
| 13522109 | Azmi Mahmud Bazeid | selain dari yang di atas (karena kalau ditulis banyak banget) |
| 13519212 | Ryan Kurnia Hidayatullah |  |

