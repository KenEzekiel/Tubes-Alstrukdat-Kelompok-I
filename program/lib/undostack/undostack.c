/* File undostack.c */
/* Definisi ADT UndoStack */

#include "undostack.h"

/* ************ Prototype ************ */

/* *** Konstruktor/Kreator *** */
/* I.S. sembarang; */
/* F.S. Membuat sebuah UndoStack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri UndoStack kosong : TOP bernilai Nil */
void CreateUndoStackEmpty(UndoStack *US)
{
    CreateStateStackEmpty(US);
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
/* Mengirim true jika UndoStack kosong: lihat definisi di atas */
boolean IsUndoStackEmpty(UndoStack US)
{
    return IsStateStackEmpty(US);
}

/* Mengirim true jika tabel penampung nilai elemen UndoStack penuh */
boolean IsUndoStackFull(UndoStack US)
{
    return IsStateStackFull(US);
}

/* ************ Menambahkan sebuah elemen ke UndoStack ************ */
/* Menambahkan X sebagai elemen UndoStack S. */
/* I.S. S mungkin kosong, tabel penampung elemen UndoStack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
void PushUndoStack(UndoStack *US, State X)
{
    PushStateStack(US, X);
}

/* ************ Menghapus sebuah elemen UndoStack ************ */
/* Menghapus X dari UndoStack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
void PopUndoStack(UndoStack *US, State *X)
{
    PopStateStack(US, X);
}
