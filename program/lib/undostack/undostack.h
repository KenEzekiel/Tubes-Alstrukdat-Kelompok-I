/* File undostack.h */
/* Definisi ADT UndoStack */

#ifndef undostack_H
#define undostack_H

#include "../../../lib/stack/stack.h"
#include "../../../lib/time/time.h"
#include "../boolean.h"
#include "../inventory/inventory.h"
#include "../deliverylist/deliverylist.h"
#include "../statestack/statestack.h"

//#define Nil -1
//#define MaxEl 100
/* Nil adalah stack dengan elemen kosong . */

// Undo move mau simpen state peta atau move ke tempat sebelumnya tanpa increase time?

// typedef int address; /* indeks tabel */

/* Contoh deklarasi variabel bertype undostack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
/* Definisi ADT UndoStack */
typedef StateStack UndoStack;
/* Definisi undostack US kosong : US.TOP = Nil */
/* Elemen yang dipakai menyimpan nilai Stack T[0]..T[MaxEl-1] */
/* Jika US adalah UndoStack maka akses elemen : */
/* US.T[(S.TOP)] untuk mengakses elemen TOP */
/* US.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
//#define Top(US) (US).TOP
//#define StateTop(US) (US).T[(S).TOP]

/* ************ Prototype ************ */

/* *** Konstruktor/Kreator *** */
/* I.S. sembarang; */
/* F.S. Membuat sebuah UndoStack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri UndoStack kosong : TOP bernilai Nil */
stackaddr CreateUndoStackEmpty();

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
/* Mengirim true jika UndoStack kosong: lihat definisi di atas */
boolean IsUndoStackEmpty(stackaddr sa);

/* Mengirim true jika tabel penampung nilai elemen UndoStack penuh */
boolean IsUndoStackFull(stackaddr sa);

/* ************ Menambahkan sebuah elemen ke UndoStack ************ */
/* Menambahkan X sebagai elemen UndoStack S. */
/* I.S. S mungkin kosong, tabel penampung elemen UndoStack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
void PushUndoStack(stackaddr sa, State X);

/* ************ Menghapus sebuah elemen UndoStack ************ */
/* Menghapus X dari UndoStack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
void PopUndoStack(stackaddr sa, State *X);

/* ****** Clear stack ****** */
/* Menghapus semua elemen didalam stack */
void ClearUndoStack(stackaddr sa);

#endif