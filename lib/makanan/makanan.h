/* File: makanan.h */
/* Definisi ADT MAKANAN */

#ifndef MAKANAN_H
#define MAKANAN_H

#include "../boolean.h"
#include "../string/string.h"
#include "../time/time.h"

/* *** Definisi TYPE Makanan <id, nama, exp, aksi, delivTime> *** */
typedef struct { 
	int id;
	String nama;
    TIME exp;
    String aksi;
    TIME delivTime;
} Makanan;

/* *** Notasi Akses: selektor Makanan *** */
#define ID(Food) (Food).id 
#define Nama(Food) (Food).nama 
#define Exp(Food) (Food).exp 
#define Aksi(Food) (Food).aksi 
#define DelivTime(Food) (Food).delivTime 

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */

/* *** Konstruktor: Membentuk sebuah Makanan dari komponen-komponennya *** */
void CreateMakanan (Makanan * Food, int id, String nama, TIME exp, String aksi, TIME delivTime);
/* Membentuk sebuah Makanan dari komponen-komponennya yang valid */
/* Prekondisi : id, nama, exp, aksi, dan delivTime valid untuk membentuk Makanan */

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaMakanan (Makanan * Food);
/* I.S. : Food tidak terdefinisi */
/* F.S. : Food terdefinisi dan merupakan makanan yang valid */
/* Proses : mengulangi membaca komponen id, nama, exp, aksi, delivTime sehingga membentuk Food */
/* yang valid. Tidak mungkin menghasilkan Food yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen id, nama, exp, aksi, delivTime
   berbeda baris, masing-masing dipisahkan dan diakhiri enter. */
   
void TulisMakanan (Makanan Food);
/* I.S. : Food sembarang */
/* F.S. : Nilai Food ditulis dg format ... */
/* Proses : menulis nilai setiap komponen Food ke layar dalam format ...*/ 

#endif