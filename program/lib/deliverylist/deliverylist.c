#include "../../../lib/queue/prioqueuetime.h"
#include "../inventory/inventory.h"
#include "../boolean.h"
#include "../../../lib/time/time.h"
#include "../../../lib/makanan/makanan.h"
#include "../../../lib/string/string.h"
#include "../../../lib/liststatik/liststatik.h"
#include "../utility/utility.h"
#include "deliverylist.h"
#include <stdio.h>

/* *** Konstruktor *** */
void CreateDeliveryList(DeliveryList *DL, int max)
{
    MakeEmpty(DL, max);
}

/* *** Operasi Penambahan Makanan *** */
/* I.S. Simulator sedang berada di sebelah B, dan makanan yang dibeli sudah valid */
/* F.S. Makanan dimasukkan kedalam DeliveryList */
void buyMakanan(DeliveryList *DL, prioQueueInfotype food)
{
    int i, j;
    prioQueueInfotype temp;

    // ALGORITMA
    if (IsPrioQueueEmpty(*DL))
    {
        Head(*DL) = 0;
        Tail(*DL) = 0;
        InfoTail(*DL) = food;
    }
    else
    {
        // Mod untuk antisipasi jika Tail dari DL > IDX_MAX alias CAPACITY - 1
        Tail(*DL) = Tail(*DL) == MaxPrioQueueEl(*DL) - 1 ? 0 : Tail(*DL) + 1;
        InfoTail(*DL) = food;
        i = Tail(*DL);
        j = i == 0 ? MaxPrioQueueEl(*DL) - 1 : i - 1;
        while (i != Head(*DL) && TIMEToMenit(DelivTime(Elmt(*DL, i))) < TIMEToMenit(DelivTime(Elmt(*DL, j))))
        {
            temp = Elmt(*DL, i);
            Elmt(*DL, i) = Elmt(*DL, j);
            Elmt(*DL, j) = temp;
            i = j;
            j = i == 0 ? MaxPrioQueueEl(*DL) - 1 : i - 1;
        }
    }
}

/* *** Operasi Penambahan Makanan dengan id makanan *** */
/* I.S. Simulator sedang berada di sebelah B, id makanan yang dibeli sudah valid */
/* F.S. Makanan dengan id tertentu di List dimasukkan ke dalam DeliveryList */
/* Delivery list di upgrade jika dibutuhkan */
void buyMakananbyId(DeliveryList *DL, int id, ListMakanan L)
{
    // KAMUS LOKAL
    prioQueueInfotype food;
    // ALGORITMA

    food = ELMT_LM(L, indexOfID(L, id));

    upgradeDelivList(DL);
    buyMakanan(DL, food);
}

/* *** Operasi Penambahan Makanan dengan nama makanan *** */
/* I.S. Simulator sedang berada di sebelah B, dan nama makanan yang dibeli sudah valid */
/* F.S. Makanan dengan nama tertentu di List dimasukkan ke dalam DeliveryList */
/* Delivery list di upgrade jika dibutuhkan */
void buyMakananbyName(DeliveryList *DL, String nama, ListMakanan L)
{
    // KAMUS LOKAL
    prioQueueInfotype food;
    // ALGORITMA

    food = ELMT_LM(L, indexOfName(L, nama));

    upgradeDelivList(DL);
    buyMakanan(DL, food);
}

/* *** Mengembalikan hasil pengecekan apakah makanan ada dalam list makanan *** */
boolean isMakananValid(Makanan food, ListMakanan L)
{
    // KAMUS LOKAL
    int i = 0;
    boolean found = false;

    // ALGORITMA
    while (i < listMakananLength(L) && !found)
    {
        if (isStringEqual(Nama(food), Nama(ELMT_LM(L, i))) && ID(food) == ID(ELMT_LM(L, i)))
        {
            found = true;
        }
        else
        {
            i++;
        }
    }
    return found;
}

/* *** Mengembalikan hasil pengecekan apakah makanan ada dalam list makanan berdasarkan id *** */
boolean isMakananValidbyId(int id, ListMakanan L)
{
    // KAMUS LOKAL
    int i = 0;
    boolean found = false;

    // ALGORITMA
    while (i < listMakananLength(L) && !found)
    {
        if (id == ID(ELMT_LM(L, i)))
        {
            found = true;
        }
        else
        {
            i++;
        }
    }
    return found;
}

/* *** Mengembalikan hasil pengecekan apakah makanan ada dalam list makanan berdasarkan nama *** */
boolean isMakananValidbyName(String nama, ListMakanan L)
{
    // KAMUS LOKAL
    int i = 0;
    boolean found = false;

    // ALGORITMA
    while (i < listMakananLength(L) && !found)
    {
        if (isStringEqual(nama, Nama(ELMT_LM(L, i))))
        {
            found = true;
        }
        else
        {
            i++;
        }
    }
    return found;
}

/* *** Update DeliveryList dan Inventory *** */
/* I.S. DeliveryList dan Inventory terdefinisi sembarang */
/* F.S. Isi dari DL dan I di update*/
/* Jika ada makanan yang sudah 0 delivery time nya, akan dimasukkan ke I dan dikeluarkan dari DL*/
/* Update semua makanan untuk mengurangi waktu delivery time nya sebesar t */
void updateDeliveryList(DeliveryList *DL, Inventory *I, TIME t, ListMakanan *delivered)
{
    // KAMUS LOKAL

    // ALGORITMA

    if (!IsPrioQueueEmpty(*DL))
    {
        minusDelivTime(DL, t);
        deliver(DL, I, delivered);
    }
}

/* *** Update DeliveryList dan Inventory *** */
/* I.S. DeliveryList dan Inventory terdefinisi sembarang */
/* F.S. Isi dari DL dan I di update */
/* Update semua makanan untuk menambah waktu delivery time nya sebesar t */
void reverseUpdateDeliveryList(DeliveryList *DL, Inventory *I, TIME t)
{
    // KAMUS LOKAL

    // ALGORITMA

    if (!IsPrioQueueEmpty(*DL))
    {
        plusDelivTime(DL, t);
    }
}

/* *** Mengirim semua makanan yang delivery time nya sudah 0 *** */
/* I.S. DL terdefinisi dan tidak kosong */
/* F.S. Semua makanan yang delivery time nya sudah 0 didelete dari DL dan di masukkan ke I*/
void deliver(DeliveryList *DL, Inventory *I, ListMakanan *delivered)
{
    // KAMUS LOKAL
    DeliveryList p;
    DeliveryList q = *DL;
    prioQueueInfotype food;
    // ALGORITMA
    MakeEmpty(&p, MaxPrioQueueEl(*DL));
    while (!IsPrioQueueEmpty(q))
    {
        Dequeue(&q, &food);
        if (TIMEToMenit(DelivTime(food)) != 0)
        {
            buyMakanan(&p, food);
        }
        else
        {
            Enqueue(I, food);
            insertLastMakanan(delivered, food);
        }
    }
    *DL = p;
}

/* *** Mengurangi waktu dari delivery time semua makanan sebesar t *** */
/* I.S. DL terdefinisi, tidak kosong */
/* F.S. semua makanan dikurangi delivery time nya sebesar t
jika hasil < 0, maka delivery time di set 0 */
void minusDelivTime(DeliveryList *DL, TIME t)
{
    // KAMUS LOKAL
    DeliveryList p;
    DeliveryList q = *DL;
    prioQueueInfotype food;
    int hasil;
    // ALGORITMA
    MakeEmpty(&p, MaxPrioQueueEl(*DL));
    while (!IsPrioQueueEmpty(q))
    {
        Dequeue(&q, &food);
        hasil = TIMEToMenit(DelivTime(food)) - TIMEToMenit(t);
        if (hasil < 0)
        {
            hasil = 0;
        }
        DelivTime(food) = MenitToTIME(hasil);
        buyMakanan(&p, food);
    }
    *DL = p;
}

/* *** Menambah waktu dari delivery time semua makanan sebesar t *** */
/* I.S. DL terdefinisi, tidak kosong */
/* F.S. semua makanan ditambah delivery time nya sebesar t */
void plusDelivTime(DeliveryList *DL, TIME t)
{
    // KAMUS LOKAL
    DeliveryList p;
    DeliveryList q = *DL;
    prioQueueInfotype food;
    int hasil;
    // ALGORITMA
    MakeEmpty(&p, MaxPrioQueueEl(*DL));
    while (!IsPrioQueueEmpty(q))
    {
        Dequeue(&q, &food);
        hasil = TIMEToMenit(DelivTime(food)) + TIMEToMenit(t);
        DelivTime(food) = MenitToTIME(hasil);
        buyMakanan(&p, food);
    }
    *DL = p;
}

/* *** Menampilkan isi Delivery List *** */
void displayDeliveryList(DeliveryList DL)
{
    print_blue("\n========================DELIVERY LIST========================\n");
    if (IsPrioQueueEmpty(DL))
    {
        print_red("Delivery List Kosong\n");
    }
    else
    {
        print_blue("List Makanan di Perjalanan \n");
        print_yellow(" (nama - waktu sisa delivery) \n");

        prioQueueInfotype val;
        PrioQueueTime temp;
        int i = 1;
        temp = DL;
        if (!IsPrioQueueEmpty(DL))
        {
            while (!IsPrioQueueEmpty(temp))
            {
                Dequeue(&temp, &val);
                printf("%d. (%d) ", i, ID(val));
                displayString(Nama(val));
                printf(" - ");
                PrintTime(DelivTime(val));
                printf("\n");
                // TulisMakanan(val);
                //  idx = (idx % NBElmt(Q)) + 1;
                i++;
            }
        }
    }
}

/* *** Mengembalikan panjang inventory *** */
int lengthDeliveryList(DeliveryList DL)
{
    return NBElmt(DL);
}

/* *** Mengembalikan hasil pengecekan apakah delivery list perlu di upgrade *** */
/* Upgrade dilakukan jika panjang delivery list > 75% maxel nya */
boolean checkUpgrade(DeliveryList DL)
{
    // KAMUS LOKAL
    int len, threshold;
    // ALGORITMA
    len = lengthDeliveryList(DL);
    threshold = 0.75 * MaxPrioQueueEl(DL);

    if (len > threshold)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* *** Mengupgrade kapasitas dari delivery list *** */
/* Perlu dilakukan apakah delivery list perlu di upgrade atau tidak terlebih dahulu */
/* Upgrade adalah penambahan kapasitas 2 kali lipat aslinya */
void upgradeDelivList(DeliveryList *DL)
{
    // KAMUS LOKAL
    DeliveryList p = *DL;
    DeliveryList q;
    prioQueueInfotype food;

    // ALGORITMA

    if (checkUpgrade(*DL))
    {
        MakeEmpty(&q, MaxPrioQueueEl(*DL) * 2);
        while (!IsPrioQueueEmpty(p))
        {
            Dequeue(&p, &food);
            buyMakanan(&q, food);
        }
        *DL = q;
    }
}
