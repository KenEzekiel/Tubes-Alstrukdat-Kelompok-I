/* File Statestack.c */
/* Definisi ADT StateStack */

#include <stdio.h>
#include "statestack.h"

//#define Empty -1
//#define MaxEl 100
/* Empty adalah stack dengan elemen kosong . */

// Undo/redo move mau simpen state peta atau move ke tempat sebelumnya tanpa increase time?

/* ************ Prototype ************ */

/* *** Konstruktor/Kreator *** */
/* I.S. sembarang; */
/* F.S. Membuat sebuah StateStack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri StateStack kosong : TOP bernilai Empty */
void CreateStateStackEmpty(StateStack *SS)
{
    idxTop(*SS) = Empty;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
/* Mengirim true jika StateStack kosong: lihat definisi di atas */
boolean IsStateStackEmpty(StateStack SS)
{
    return idxTop(SS) == Empty;
}

/* Mengirim true jika tabel penampung nilai elemen StateStack penuh */
boolean IsStateStackFull(StateStack SS)
{
    return idxTop(SS) == MaxEl - 1;
}

/* ************ Menambahkan sebuah elemen ke StateStack ************ */
/* Menambahkan X sebagai elemen StateStack S. */
/* I.S. SS mungkin kosong, tabel penampung elemen StateStack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
void PushStateStack(StateStack *SS, State X)
{
    if (IsStateStackEmpty(*SS))
    {
        idxTop(*SS) = 0;
    }
    else
    {
        idxTop(*SS) = idxTop(*SS) + 1;
    }
    StateTop(*SS) = X;
}

/* ************ Menghapus sebuah elemen StateStack ************ */
/* Menghapus X dari StateStack S. */
/* I.S. SS  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
void PopStateStack(StateStack *SS, State *X)
{
    *X = StateTop(*SS);
    if (idxTop(*SS) == 0)
    {
        idxTop(*SS) = Empty;
    }
    else
    {
        idxTop(*SS) = idxTop(*SS) - 1;
    }
}
