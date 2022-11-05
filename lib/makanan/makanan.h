/* File: makanan.h */
/* Definisi ADT MAKANAN */

#ifndef MAKANAN_H
#define MAKANAN_H

#include "../boolean.h"
#include "../string/string.h"
#include "../time/time.h"
#include "../wordmachine/wordmachine.h"
#include "../wordmachine/charmachine.h"

/* *** Definisi TYPE Makanan <id, nama, exp, aksi, delivTime> *** */
typedef struct
{
    int id;         /* ID Makanan */
    String nama;    /* Nama Makanan */
    TIME exp;       /* Waktu kadaluwarsa */
    String aksi;    /* Aksi yang bisa dilakukan */
    TIME delivTime; /* Lama pengiriman */
    TIME aksiTime;  /* Waktu pengolahan makanan */
    int ukBaris;
    int ukKolom;
} Makanan;

/* *** Notasi Akses: selektor Makanan *** */
#define ID(Food) (Food).id
#define Nama(Food) (Food).nama
#define Exp(Food) (Food).exp
#define Aksi(Food) (Food).aksi
#define DelivTime(Food) (Food).delivTime
#define AksiTime(Food) (Food).aksiTime
#define SizeBaris(Food) (Food).ukBaris
#define SizeKolom(Food) (Food).ukKolom

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */

/* *** Konstruktor: Membentuk sebuah Makanan dari komponen-komponennya *** */
void CreateMakanan(Makanan *Food, int id, String nama, TIME exp, String aksi, TIME delivTime, TIME aksiTime, int ukBaris, int ukKolom);
/* Membentuk sebuah Makanan dari komponen-komponennya yang valid */
/* Prekondisi : id, nama, exp, aksi, dan delivTime valid untuk membentuk Makanan */

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaMakanan(Makanan *Food);
/* I.S. : Food tidak terdefinisi */
/* F.S. : Food terdefinisi dan merupakan makanan yang valid */
/* Proses : mengulangi membaca komponen id, nama, exp, aksi, delivTime sehingga membentuk Food */
/* yang valid. Tidak mungkin menghasilkan Food yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen id, nama, exp, aksi, delivTime
   berbeda baris, masing-masing dipisahkan dan diakhiri enter. */

void TulisMakanan(Makanan Food);
/* I.S. : Food sembarang */
/* F.S. : Nilai Food ditulis dg format ... */
/* Proses : menulis nilai setiap komponen Food ke layar dalam format ...*/

#endif