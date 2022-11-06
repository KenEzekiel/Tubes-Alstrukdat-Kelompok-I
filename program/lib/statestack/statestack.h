/* File Statestack.h */
/* Definisi ADT StateStack */

#ifndef Statestack_H
#define Statestack_H

#include "../../../lib/stack/stack.h"
#include "../../../lib/time/time.h"
#include "../boolean.h"
#include "../inventory/inventory.h"
#include "../deliverylist/deliverylist.h"
#include "../state/state.h"

#define Empty -1
#define MaxEl 30
/* Empty adalah stack dengan elemen kosong . */

// Undo/redo move mau simpen state peta atau move ke tempat sebelumnya tanpa increase time?

typedef int address; /* indeks tabel */

/* Contoh deklarasi variabel bertype Statestack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
/* Definisi ADT StateStack */
typedef struct Statestack
{
    State T[MaxEl]; /* tabel penyimpan elemen */
    address TOP;    /* alamat TOP: elemen puncak */
} StateStack;
/* Definisi Statestack US kosong : US.TOP = Empty */
/* Elemen yang dipakai menyimpan nilai Stack T[0]..T[MaxEl-1] */
/* Jika US adalah StateStack maka akses elemen : */
/* US.T[(S.TOP)] untuk mengakses elemen TOP */
/* US.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
#define idxTop(SS) (SS).TOP
#define StateTop(SS) (SS).T[(SS).TOP]

/* ************ Prototype ************ */

/* *** Konstruktor/Kreator *** */
/* I.S. sembarang; */
/* F.S. Membuat sebuah StateStack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri StateStack kosong : TOP bernilai Empty */
void CreateStateStackEmpty(StateStack *SS);

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
/* Mengirim true jika StateStack kosong: lihat definisi di atas */
boolean IsStateStackEmpty(StateStack SS);

/* Mengirim true jika tabel penampung nilai elemen StateStack penuh */
boolean IsStateStackFull(StateStack SS);

/* ************ Menambahkan sebuah elemen ke StateStack ************ */
/* Menambahkan X sebagai elemen StateStack S. */
/* I.S. S mungkin kosong, tabel penampung elemen StateStack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
void PushStateStack(StateStack *SS, State X);

/* ************ Menghapus sebuah elemen StateStack ************ */
/* Menghapus X dari StateStack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
void PopStateStack(StateStack *SS, State *X);

#endif