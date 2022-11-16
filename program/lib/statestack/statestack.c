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
stackaddr CreateStateStackEmpty()
{
    stackaddr sa = (stackaddr)malloc(sizeof(StateStack));
    if (sa != NULL)
    {
        idxTop(*sa) = Empty;
    }
    return sa;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
/* Mengirim true jika StateStack kosong: lihat definisi di atas */
boolean IsStateStackEmpty(stackaddr sa)
{
    return idxTop(*sa) == Empty;
}

/* Mengirim true jika tabel penampung nilai elemen StateStack penuh */
boolean IsStateStackFull(stackaddr sa)
{
    return idxTop(*sa) == MaxEl - 1;
}

/* ************ Menambahkan sebuah elemen ke StateStack ************ */
/* Menambahkan X sebagai elemen StateStack S. */
/* I.S. SS mungkin kosong, tabel penampung elemen StateStack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
void PushStateStack(stackaddr sa, State X)
{
    if (IsStateStackEmpty(sa))
    {
        idxTop(*sa) = 0;
    }
    else
    {
        idxTop(*sa) = idxTop(*sa) + 1;
    }
    StateTop(*sa) = X;
}

/* ************ Menghapus sebuah elemen StateStack ************ */
/* Menghapus X dari StateStack S. */
/* I.S. SS  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
void PopStateStack(stackaddr sa, State *X)
{
    if (!IsStateStackEmpty(sa))
    {
        *X = StateTop(*sa);
        if (idxTop(*sa) == 0)
        {
            idxTop(*sa) = Empty;
        }
        else
        {
            idxTop(*sa) = idxTop(*sa) - 1;
        }
    }
}

/* ****** Clear stack ****** */
/* Menghapus semua elemen didalam stack */
void ClearStateStack(stackaddr sa)
{
    free(sa);
}