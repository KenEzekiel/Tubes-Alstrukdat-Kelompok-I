/* File Redostack.h */
/* Definisi ADT RedoStack */

#include "redostack.h"

/* ************ Prototype ************ */

/* *** Konstruktor/Kreator *** */
/* I.S. sembarang; */
/* F.S. Membuat sebuah RedoStack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri RedoStack kosong : TOP bernilai Nil */
void CreateRedoStackEmpty(RedoStack *RS)
{
    CreateStateStackEmpty(RS);
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */

/* Mengirim true jika RedoStack kosong: lihat definisi di atas */
boolean IsRedoStackEmpty(RedoStack RS)
{
    IsStateStackEmpty(RS);
}

/* Mengirim true jika tabel penampung nilai elemen RedoStack penuh */
boolean IsRedoStackFull(RedoStack RS)
{
    IsStateStackFull(RS);
}

/* ************ Menambahkan sebuah elemen ke RedoStack ************ */
/* Menambahkan X sebagai elemen RedoStack S. */
/* I.S. S mungkin kosong, tabel penampung elemen RedoStack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
void PushRedoStack(RedoStack *RS, State X)
{
    PushStateStack(RS, X);
}

/* ************ Menghapus sebuah elemen RedoStack ************ */
/* Menghapus X dari RedoStack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
void PopRedoStack(RedoStack *RS, State *X)
{
    if (IsStateStackEmpty(*RS))
    {
    }
    else
    {
        PopStateStack(RS, X);
    }
}
