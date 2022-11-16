/* File Redostack.h */
/* Definisi ADT RedoStack */

#ifndef redostack_H
#define redostack_H

#include "../../../lib/stack/stack.h"
#include "../../../lib/time/time.h"
#include "../boolean.h"
#include "../inventory/inventory.h"
#include "../deliverylist/deliverylist.h"
#include "../statestack/statestack.h"

//#define Nil -1
//#define MaxEl 100
/* Nil adalah stack dengan elemen kosong . */

/*
typedef struct state
{
    TIME t;
    Inventory I;
    DeliveryList DL;
} State;
*/

// Redo move mau simpen state peta atau move ke tempat sebelumnya tanpa increase time?

// typedef int address; /* indeks tabel */

/* Contoh deklarasi variabel bertype Redostack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
/* Definisi ADT RedoStack */
typedef StateStack RedoStack;
/* Definisi Redostack US kosong : US.TOP = Nil */
/* Elemen yang dipakai menyimpan nilai Stack T[0]..T[MaxEl-1] */
/* Jika US adalah RedoStack maka akses elemen : */
/* US.T[(S.TOP)] untuk mengakses elemen TOP */
/* US.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
//#define Top(US) (US).TOP
//#define StateTop(US) (US).T[(S).TOP]

/* ************ Prototype ************ */

/* *** Konstruktor/Kreator *** */
/* I.S. sembarang; */
/* F.S. Membuat sebuah RedoStack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri RedoStack kosong : TOP bernilai Nil */
stackaddr CreateRedoStackEmpty();

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */

/* Mengirim true jika RedoStack kosong: lihat definisi di atas */
boolean IsRedoStackEmpty(stackaddr sa);

/* Mengirim true jika tabel penampung nilai elemen RedoStack penuh */
boolean IsRedoStackFull(stackaddr sa);

/* ************ Menambahkan sebuah elemen ke RedoStack ************ */
/* Menambahkan X sebagai elemen RedoStack S. */
/* I.S. S mungkin kosong, tabel penampung elemen RedoStack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
void PushRedoStack(stackaddr sa, State X);

/* ************ Menghapus sebuah elemen RedoStack ************ */
/* Menghapus X dari RedoStack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
void PopRedoStack(stackaddr sa, State *X);

/* ****** Clear stack ****** */
/* Menghapus semua elemen didalam stack */
void ClearRedoStack(stackaddr sa);

#endif