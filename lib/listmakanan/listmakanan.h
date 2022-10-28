/* File: makanan.h */
/* Definisi ADT LIST MAKANAN */

#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H

#include "../boolean.h"
#include "../makanan/makanan.h"
#include "../wordmachine/wordmachine.h"

/*  Kamus Umum */
#define CAPACITY_LMAKANAN 100
/* Kapasitas penyimpanan */
#define IDX_MIN_LMAKANAN 0
/* Indeks minimum list */
#define IDX_UNDEF_LMAKANAN -1
/* Indeks tak terdefinisi*/
#define MARK_LMAKANAN -9999
/* Nilai elemen tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef Makanan eltype; /* type elemen List */
typedef int IdxType;
typedef struct
{
   eltype contents[CAPACITY]; /* memori tempat penyimpan elemen (container) */
} ListMakanan;
/* Indeks yang digunakan [0..CAPACITY-1] */
/* Jika l adalah ListStatik, cara deklarasi dan akses: */
/* Deklarasi : l : ListStatik */
/* Maka cara akses:
   ELMT(l,i) untuk mengakses elemen ke-i */
/* Definisi :
   List kosong: semua elemen bernilai MARK
   Definisi elemen pertama: ELMT(l,i) dengan i=0 */


/* ********** SELEKTOR ********** */
#define ELMT_LM(l, i) (l).contents[(i)]

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListMakanan(ListMakanan *lfood);
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan MARK */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listMakananLength(ListMakanan lfood);
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */

void insertLastMakanan(ListMakanan *lfood, eltype val);
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */

ListMakanan readListMakanan(char* dir);
/* Membaca file dari directory dan menghasilkan List Statik yang elemennya berisi tipe Makanan */
/* Ketentuan file konfigurasi: baris pertama berisi banyaknya elemen, dilanjutkan tiap baris membaca tipe makanan dengan
urutan ID Makanan, Nama Makanan, Waktu Kadaluwarsa, Lama Pengiriman, Aksi yang Dapat Dilakukan, Waktu Pengolahan Makanan */

ListMakanan filterByAksi(ListMakanan lfood, String aksi);
/* Menghasilkan list makanan baru yang bisa dilakukan aksi */

int indexOfID(ListMakanan lfood, int idfood);
/* Menghasilkan indeks list dengan ID Makanan sesuai idfood, mengembalikan IDX_UNDEF jika ID Makanan tidak ditemukan */

void printCatalog(ListMakanan lfood);
/* I.S. lfood terdefinisi */
/* I.S. Menampilkan list makanan lfood */

#endif