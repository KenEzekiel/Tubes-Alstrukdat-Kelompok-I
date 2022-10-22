/* File : queue.c */
/*
NAMA : Kenneth Ezekiel Suprantoni
NIM : 13521089
*/
/* Definisi ADT Queue versi 3 dengan representasi array secara eksplisit dan alokasi statik */

#include "../boolean.h"
#include "queue.h"
#include <stdio.h>

/* ********* AKSES (Selektor) ********* */
/* Jika q adalah Queue, maka akses elemen : */
//#define IDX_HEAD(q) (q).idxHead
//#define IDX_TAIL(q) (q).idxTail
//#define HEAD(q) (q).buffer[(q).idxHead]
//#define TAIL(q) (q).buffer[(q).idxTail]

/* *** Kreator *** */
void CreateQueue(Queue *q)
{
    /* I.S. sembarang */
    /* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
    /* - Index head bernilai IDX_UNDEF */
    /* - Index tail bernilai IDX_UNDEF */
    /* Proses : Melakukan alokasi, membuat sebuah q kosong */
    // KAMUS LOKAL

    // ALGORITMA
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

/* ********* Prototype ********* */
boolean isEmpty(Queue q)
{
    /* Mengirim true jika q kosong: lihat definisi di atas */
    return (IDX_HEAD(q) == IDX_UNDEF) && (IDX_TAIL(q) == IDX_UNDEF);
}
boolean isFull(Queue q)
{
    /* Mengirim true jika tabel penampung elemen q sudah penuh */
    /* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/
    return (length(q) == CAPACITY);
}
int length(Queue q)
{
    /* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
    // KAMUS LOKAL

    // ALGORITMA
    if (isEmpty(q))
    {
        return 0;
    }
    else
    {
        if ((IDX_TAIL(q) - IDX_HEAD(q)) >= 0)
        {
            return IDX_TAIL(q) - IDX_HEAD(q) + 1;
        }
        else
        {
            return CAPACITY - (IDX_HEAD(q) - (IDX_TAIL(q) + 1));
        }
    }
}
/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, ElType val)
{
    /* Proses: Menambahkan val pada q dengan aturan FIFO */
    /* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
    /* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */
    // KAMUS LOKAL

    // ALGORITMA
    if (isEmpty(*q))
    {
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
        TAIL(*q) = val;
    }
    else
    {
        // Mod untuk antisipasi jika IDX_TAIL dari q > IDX_MAX alias CAPACITY - 1
        IDX_TAIL(*q) = (IDX_TAIL(*q) + 1) % (CAPACITY);
        TAIL(*q) = val;
    }
}
void dequeue(Queue *q, ElType *val)
{
    /* Proses: Menghapus val pada q dengan aturan FIFO */
    /* I.S. q tidak mungkin kosong */
    /* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */
    // KAMUS LOKAL

    // ALGORITMA
    if (length(*q) == 1)
    {
        *val = HEAD(*q);
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    }
    else
    {
        *val = HEAD(*q);
        IDX_HEAD(*q) = (IDX_HEAD(*q) + 1) % (CAPACITY);
    }
}

/* *** Display Queue *** */
void displayQueue(Queue q)
{
    /* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung
       siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan
       karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
    /* I.S. q boleh kosong */
    /* F.S. Jika q tidak kosong: [e1,e2,...,en] */
    /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
    /* Jika Queue kosong : menulis [] */
    // KAMUS LOKAL
    int i;
    ElType head;
    int len = length(q);
    // ALGORTIMA
    printf("[");
    if (!isEmpty(q))
    {
        for (i = 0; i < len; i++)
        {
            head = HEAD(q);
            printf("%d", head);
            IDX_HEAD(q) = (IDX_HEAD(q) + 1) % (CAPACITY);
            if (i != len - 1)
            {
                printf(",");
            }
        }
    }
    printf("]\n");
}
