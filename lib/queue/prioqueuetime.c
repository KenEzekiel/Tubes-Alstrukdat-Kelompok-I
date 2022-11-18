/* Definisi ADT Priority Queue Char dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */
/* Elemen queue terurut membesar berdasarkan elemen time */

#include "../boolean.h"
#include "../makanan/makanan.h"
#include "../time/time.h"
#include "../../program/lib/utility/utility.h"
#include "prioqueuetime.h"
#include <stdlib.h>
#include <stdio.h>

/* ********* AKSES (Selektor) ********* */
/* Jika e adalah infotype dan Q adalah PrioQueueTime, maka akses elemen : */
/*
#define Time(e)     (e).time
#define Info(e)     (e).info
#define Head(Q)     (Q).HEAD
#define Tail(Q)     (Q).TAIL
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoTail(Q) (Q).T[(Q).TAIL]
#define MaxPrioQueueEl(Q)    (Q).MaxPrioQueueEl
#define Elmt(Q,i)   (Q).T[(i)]
*/

/* ********* Prototype ********* */
boolean IsPrioQueueEmpty(PrioQueueTime Q)
{
    /* Mengirim true jika Q kosong: lihat definisi di atas */
    return (Head(Q) == Empty) && (Tail(Q) == Empty);
}
boolean IsPrioQueueFull(PrioQueueTime Q)
{
    /* Mengirim true jika tabel penampung elemen Q sudah penuh */
    /* yaitu mengandung elemen sebanyak MaxPrioQueueEl */
    return MaxPrioQueueEl(Q) == NBElmt(Q);
}
int NBElmt(PrioQueueTime Q)
{
    /* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
    if (IsPrioQueueEmpty(Q))
    {
        return 0;
    }
    else
    {
        if ((Tail(Q) - Head(Q)) >= 0)
        {
            return Tail(Q) - Head(Q) + 1;
        }
        else
        {
            return MaxPrioQueueEl(Q) - (Head(Q) - (Tail(Q) + 1));
        }
    }
}

/* *** Kreator *** */
void MakeEmpty(PrioQueueTime *Q, int Max)
{
    /* I.S. sembarang */
    /* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
    /* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
    /* atau : jika alokasi gagal, Q kosong dg MaxPrioQueueEl=0 */
    /* Proses : Melakukan alokasi, membuat sebuah Q kosong */
    (*Q).T = (prioQueueInfotype *)malloc((Max) * sizeof(prioQueueInfotype));
    if ((*Q).T == NULL)
    {
        MaxPrioQueueEl(*Q) = 0;
    }
    else
    {
        Head(*Q) = Empty;
        Tail(*Q) = Empty;
        MaxPrioQueueEl(*Q) = Max;
    }
}

/* *** Destruktor *** */
void DeAlokasi(PrioQueueTime *Q)
{
    /* Proses: Mengembalikan memori Q */
    /* I.S. Q pernah dialokasi */
    /* F.S. Q menjadi tidak terdefinisi lagi, MaxPrioQueueEl(Q) diset 0 */
    Head(*Q) = Empty;
    Tail(*Q) = Empty;
    MaxPrioQueueEl(*Q) = 0;
    free((*Q).T);
}

/* *** Primitif Add/Delete *** */
void Enqueue(PrioQueueTime *Q, prioQueueInfotype X)
{
    /* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan time */
    /* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
    /* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
            TAIL "maju" dengan mekanisme circular buffer; */
    int i, j;
    prioQueueInfotype temp;

    // ALGORITMA
    if (IsPrioQueueEmpty(*Q))
    {
        Head(*Q) = 0;
        Tail(*Q) = 0;
        InfoTail(*Q) = X;
    }
    else
    {
        // Mod untuk antisipasi jika Tail dari Q > IDX_MAX alias CAPACITY - 1
        Tail(*Q) = Tail(*Q) == MaxPrioQueueEl(*Q) - 1 ? 0 : Tail(*Q) + 1;
        InfoTail(*Q) = X;
        i = Tail(*Q);
        j = i == 0 ? MaxPrioQueueEl(*Q) - 1 : i - 1;
        while (i != Head(*Q) && TIMEToMenit(Exp(Elmt(*Q, i))) < TIMEToMenit(Exp(Elmt(*Q, j))))
        {
            temp = Elmt(*Q, i);
            Elmt(*Q, i) = Elmt(*Q, j);
            Elmt(*Q, j) = temp;
            i = j;
            j = i == 0 ? MaxPrioQueueEl(*Q) - 1 : i - 1;
        }
    }
}
void Dequeue(PrioQueueTime *Q, prioQueueInfotype *X)
{
    /* Proses: Menghapus X pada Q dengan aturan FIFO */
    /* I.S. Q tidak mungkin kosong */
    /* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
            Q mungkin kosong */
    if (NBElmt(*Q) == 1)
    {
        *X = InfoHead(*Q);
        Head(*Q) = Empty;
        Tail(*Q) = Empty;
    }
    else
    {
        *X = InfoHead(*Q);
        Head(*Q) = (Head(*Q) == MaxPrioQueueEl(*Q) - 1) ? 0 : Head(*Q) + 1;
    }
}

/* Operasi Tambahan */
void PrintPrioQueueTime(PrioQueueTime Q)
{
    /* Mencetak isi queue Q ke layar */
    /* I.S. Q terdefinisi, mungkin kosong */
    /* F.S. Q tercetak ke layar dengan format:
    <time-1> <elemen-1>
    ...
    <time-n> <elemen-n>
    #
    */
    prioQueueInfotype val;
    PrioQueueTime temp;
    int i = 1;
    temp = Q;
    print_blue("List Makanan di Inventory\n");
    print_yellow(" (nama -- waktu sisa kedaluarsa) \n");
    if (!IsPrioQueueEmpty(Q))
    {
        while (!IsPrioQueueEmpty(temp))
        {
            Dequeue(&temp, &val);
            printf("%d. (%d) ", i, ID(val));
            displayString(Nama(val));
            printf(" - ");
            PrintTime(Exp(val));
            printf("\n");
            // TulisMakanan(val);
            //  idx = (idx % NBElmt(Q)) + 1;
            i++;
        }
    }
    printf("\n");
}

boolean isElmt(PrioQueueTime Q, prioQueueInfotype val)
{
    /* Mengirimkan true jika val terdapat didalam Q */
    // KAMUS LOKAL
    PrioQueueTime temp = Q;
    boolean found = false;
    prioQueueInfotype tempval;
    // ALGORITMA
    while ((!IsPrioQueueEmpty(temp)) && (!found))
    {
        Dequeue(&temp, &tempval);
        if (ID(val) == ID(tempval) && isStringEqual(Nama(val), Nama(tempval)))
        {
            found = true;
        }
    }
    return found;
}

void deleteElmt(PrioQueueTime *Q, prioQueueInfotype *val)
{
    /* Delete suatu elemen val dari Q */
    /* I.S Q terdefinisi, mungkin kosong */
    /* F.S val didelete jika ada didalam Q */
    // KAMUS LOKAL
    PrioQueueTime temp = *Q;
    PrioQueueTime hasil;
    boolean found = false;
    prioQueueInfotype tempval;

    // ALGORITMA
    MakeEmpty(&hasil, MaxPrioQueueEl(*Q));
    if (isElmt(*Q, *val))
    {
        while ((!IsPrioQueueEmpty(temp)) && (!found))
        {
            Dequeue(&temp, &tempval);
            if (ID(*val) == ID(tempval))
            {
                found = true;
            }
            else
            {
                Enqueue(&hasil, tempval);
            }
        }
        while ((!IsPrioQueueEmpty(temp)) && (found))
        {
            Dequeue(&temp, &tempval);
            Enqueue(&hasil, tempval);
        }
        *Q = hasil;
    }
}