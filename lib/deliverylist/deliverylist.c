#include "../queue/prioqueuetime.h"
#include "../inventory/inventory.h"
#include "../boolean.h"
#include "../time/time.h"
#include "../makanan/makanan.h"
#include "../string/string.h"
#include "../liststatik/liststatik.h"
#include "../deliverylist/deliverylist.h"

/* *** Operasi Penambahan Makanan *** */
/* I.S. Simulator sedang berada di sebelah B, dan makanan yang dibeli sudah valid */
/* F.S. Makanan dimasukkan kedalam DeliveryList */
void buyMakanan(DeliveryList *DL, infotype food)
{
    boolean found;
    int idx;
    int i, j;
    infotype temp;

    // ALGORITMA
    if (IsEmpty(*DL))
    {
        Head(*DL) = 0;
        Tail(*DL) = 0;
        InfoTail(*DL) = food;
    }
    else
    {
        // Mod untuk antisipasi jika Tail dari DL > IDX_MAX alias CAPACITY - 1
        Tail(*DL) = Tail(*DL) == MaxEl(*DL) - 1 ? 0 : Tail(*DL) + 1;
        InfoTail(*DL) = food;
        i = Tail(*DL);
        j = i == 0 ? MaxEl(*DL) - 1 : i - 1;
        while (i != Head(*DL) && TIMEToDetik(DelivTime(Elmt(*DL, i))) < TIMEToDetik(DelivTime(Elmt(*DL, j))))
        {
            temp = Elmt(*DL, i);
            Elmt(*DL, i) = Elmt(*DL, j);
            Elmt(*DL, j) = temp;
            i = j;
            j = i == 0 ? MaxEl(*DL) - 1 : i - 1;
        }
    }
}

/* *** Operasi Penambahan Makanan dengan id makanan *** */
/* I.S. Simulator sedang berada di sebelah B, id makanan yang dibeli sudah valid */
/* F.S. Makanan dengan id tertentu di List dimasukkan ke dalam DeliveryList */
void buyMakananbyId(DeliveryList *DL, int id, ListStatik L)
{
    // KAMUS LOKAL
    infotype food;
    // ALGORITMA
    // TODO : getMakananByIdList
    buyMakanan(DL, food);
}

/* *** Operasi Penambahan Makanan dengan nama makanan *** */
/* I.S. Simulator sedang berada di sebelah B, dan nama makanan yang dibeli sudah valid */
/* F.S. Makanan dengan nama tertentu di List dimasukkan ke dalam DeliveryList */
void buyMakananbyName(DeliveryList *DL, String nama, ListStatik L);

/* *** Mengembalikan hasil pengecekan apakah makanan ada dalam list makanan *** */
boolean isMakananValid(Makanan food, ListStatik L);

/* *** Mengembalikan hasil pengecekan apakah makanan ada dalam list makanan berdasarkan id *** */
boolean isMakananValidbyId(int id, ListStatik L);

/* *** Mengembalikan hasil pengecekan apakah makanan ada dalam list makanan berdasarkan nama *** */
boolean isMakananValidbyName(String nama, ListStatik L);

/* *** Update DeliveryList dan Inventory *** */
/* I.S. DeliveryList dan Inventory terdefinisi sembarang */
/* F.S. Isi dari DL dan I di update*/
/* Jika ada makanan yang sudah 0 delivery time nya, akan dimasukkan ke I dan dikeluarkan dari DL*/
/* Update semua makanan untuk mengurangi waktu delivery time nya sebesar t */
void updateDeliveryList(DeliveryList *DL, Inventory *I, TIME t)
{
    // KAMUS LOKAL

    // ALGORITMA

    if (!IsEmpty(*DL))
    {
        minusDelivTime(DL, t);
        deliver(DL, I);
    }
}

/* *** Mengirim semua makanan yang delivery time nya sudah 0 *** */
/* I.S. DL terdefinisi dan tidak kosong */
/* F.S. Semua makanan yang delivery time nya sudah 0 didelete dari DL dan di masukkan ke I*/
void deliver(DeliveryList *DL, Inventory *I)
{
    // KAMUS LOKAL
    DeliveryList p;
    DeliveryList q = *DL;
    infotype food;
    // ALGORITMA
    MakeEmpty(&p, MaxEl(*DL));
    while (!IsEmpty(q))
    {
        Dequeue(&q, &food);
        if (TIMEToDetik(DelivTime(food)) != 0)
        {
            buyMakanan(&p, food);
        }
        else
        {
            Enqueue(I, food);
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
    infotype food;
    int hasil;
    // ALGORITMA
    MakeEmpty(&p, MaxEl(*DL));
    while (!IsEmpty(q))
    {
        Dequeue(&q, &food);
        hasil = TIMEToDetik(DelivTime(food)) - TIMEToDetik(t);
        if (hasil < 0)
        {
            hasil = 0;
        }
        DelivTime(food) = DetikToTIME(hasil);
        buyMakanan(&p, food);
    }
    *DL = p;
}

/* *** Menampilkan isi Delivery List *** */
void displayDeliveryList(DeliveryList DL)
{
    PrintPrioQueueTime(DL);
}

/* *** Mengembalikan panjang inventory *** */
int lengthDeliveryList(DeliveryList DL)
{
    return NBElmt(DL);
}

/* *** Mengembalikan hasil pengecekan apakah delivery list perlu di upgrade *** */
/* Upgrade dilakukan jika panjang delivery list > 75% maxel nya */
void checkUpgrade(DeliveryList DL)
{
    // KAMUS LOKAL
    int len, threshold;
    // ALGORITMA
    len = lengthDeliveryList(DL);
    threshold = 0.75 * MaxEl(DL);

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
void upgradeDelivList(DeliveryList *DL);