/* File : string.h */
/* Definisi ADT String */

#ifndef STRING_H
#define STRING_H

#include "../boolean.h"

#define CAPACITY 100

/* Definisi elemen dan address */
typedef char ElType;
typedef struct
{
    ElType buffer[CAPACITY];
    int length;
} String;

/* ********* AKSES (Selektor) ********* */
/* Jika s adalah String, maka : */
#define LENGTH(s) (s).length
#define ELMT(s, i) (s).buffer[(i)]

/* *** Kreator *** */
/* I.S. sembarang */
/* F.S. Sebuah s kosong terbentuk dengan kondisi length = 0 */
/* Proses : Melakukan alokasi, membuat sebuah string kosong */
void CreateString(String *s);

/* ********* Prototype ********* */
/* Mengirim true jika s kosong */
boolean isStringEmpty(String s);

/* Mengirim true jika tabel penampung elemen s sudah penuh */
boolean isStringFull(String s);

/* Mengirimkan banyaknya elemen string. Mengirimkan 0 jika q kosong. */
int length(String s);

/* *** Primitif Konstruktor *** */

/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. s mungkin kosong, tabel penampung elemen s TIDAK penuh */
/* F.S. s diisi elemen sebanyak n (diminta input) */
void readString(String *s);

/* *** Display *** */

/* Proses : Menuliskan isi String dengan traversal, */
/* I.S. s boleh kosong */
/* F.S. Jika s tidak kosong: "s1s2s3" */
/* Jika String kosong : menulis "" */
void displayString(String s);

/* *** Operator lain *** */

/* mengembalikan reverse dari String s */
String reverse(String s);

/* Mengembalikan hasil perbandingan s1 dan s2 */
boolean isStringEqual(String s1, String s2);

/* ********** MENAMBAH ELEMEN ********** */

/* Proses: Menambahkan c sebagai elemen pertama List */
/* I.S. String s boleh kosong, tetapi tidak penuh */
/* F.S. c adalah elemen pertama s yang baru */
void insertFirst(String *s, ElType c);

/* Proses: Menambahkan c sebagai elemen pada index idx String */
/* I.S. String s tidak kosong dan tidak penuh, idx merupakan index yang valid di s */
/* F.S. val adalah elemen yang disisipkan pada index idx l */
void insertAt(String *s, ElType c, int idx);

/* Proses: Menambahkan c sebagai elemen terakhir String */
/* I.S. String s boleh kosong, tetapi tidak penuh */
/* F.S. c adalah elemen terakhir s yang baru */
void insertLast(String *s, ElType c);

/* Proses: Menambahkan s2 sebagai substring dari s1 pada indeks tertentu */
/* I.S. String s1 tidak penuh, String s2 tidak kosong , length s1 + length s2 <= CAPACITY */
/* F.S. String s2 menjadi substring dari String s1 */
void insertSubstring(String *s1, String s2);

/* ********** MENGHAPUS ELEMEN ********** */

/* *** Menghapus elemen pertama *** */
/* Proses : Menghapus elemen pertama String */
/* I.S. String tidak kosong */
/* F.S. c adalah nilai char pertama s sebelum penghapusan, */
/*      Banyaknya elemen String berkurang satu */
/*      String s mungkin menjadi kosong */
void deleteFirst(String *s, ElType *c);

/* *** Menghapus elemen pada index tertentu *** */
/* Proses : Menghapus elemen pada index idx String */
/* I.S. List tidak kosong, idx adalah index yang valid di l */
/* F.S. val adalah nilai elemen pada index idx l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
void deleteAt(String *s, ElType *c, int idx);

/* *** Menghapus elemen terakhir *** */
/* Proses : Menghapus elemen terakhir String */
/* I.S. String tidak kosong */
/* F.S. c adalah nilai elemen terakhir s sebelum penghapusan, */
/*      Banyaknya elemen String berkurang satu */
/*      String s mungkin menjadi kosong */
void deleteLast(String *s, ElType *c);

#endif