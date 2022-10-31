#include "../boolean.h"
#include "../queue/prioqueuetime.h"
#include "../time/time.h"
#include "../makanan/makanan.h"
#include "inventory.h"
#include <stdio.h>

/* Definisi Inventory adalah PrioQueueTime */
// typedef PrioQueueTime Inventory;

/* *** Konstruktor *** */
void CreateInventory(Inventory *I, int max)
{
    MakeEmpty(I, max);
}

/* *** Update makanan di inventory *** */
/* I.S. I terdefinisi, diisi oleh makanan, bisa kosong */
/* F.S. Isi dari I di update */
/* Jika ada makanan yang expired, maka akan di delete */
/* Update semua makanan untuk mengurangi waktu expiration nya sejumlah time */
void updateInventory(Inventory *I, TIME t)
{
    // KAMUS LOKAL

    // ALGORITMA

    if (!IsEmpty(*I))
    {
        minusTime(I, t);
        deleteExpired(I);
    }
}

/* *** Update makanan di inventory *** */
/* I.S. I terdefinisi, diisi oleh makanan, bisa kosong */
/* F.S. Isi dari I di update */
/* Update semua makanan untuk menambah waktu expiration nya sejumlah time */
void reverseUpdateInventory(Inventory *I, TIME t)
{
    // KAMUS LOKAL

    // ALGORITMA

    if (!IsEmpty(*I))
    {
        plusTime(I, t);
    }
}

/* *** Menghilangkan semua makanan yang expired *** */
/* I.S. I terdefinisi, tidak kosong */
/* F.S. semua makanan yang expired di I (TIME == 0) di delete di HEAD */
void deleteExpired(Inventory *I)
{
    // KAMUS LOKAL
    Inventory p;
    Inventory q = *I;
    infotype food;
    // ALGORITMA
    MakeEmpty(&p, MaxEl(*I));
    while (!IsEmpty(q))
    {
        Dequeue(&q, &food);
        if (TIMEToDetik(Exp(food)) != 0)
        {
            Enqueue(&p, food);
        }
    }
    *I = p;
}

/* *** Mengurangi waktu dari semua makanan di inventory *** */
/* I.S. I terdefinisi, tidak kosong */
/* F.S. semua makanan dikurangi waktu expired nya sejumlah time,
jika hasil < 0, maka expiration time di set 0*/
void minusTime(Inventory *I, TIME t)
{
    // KAMUS LOKAL
    Inventory p;
    Inventory q = *I;
    infotype food;
    int hasil;
    // ALGORITMA
    MakeEmpty(&p, MaxEl(*I));
    while (!IsEmpty(q))
    {
        Dequeue(&q, &food);
        hasil = TIMEToDetik(Exp(food)) - TIMEToDetik(t);
        if (hasil < 0)
        {
            hasil = 0;
        }
        Exp(food) = DetikToTIME(hasil);
        Enqueue(&p, food);
    }
    *I = p;
}

/* *** Menambah waktu dari semua makanan di inventory *** */
/* I.S. I terdefinisi, tidak kosong */
/* F.S. semua makanan ditambah waktu expired nya sejumlah time */
void plusTime(Inventory *I, TIME t)
{
    // KAMUS LOKAL
    Inventory p;
    Inventory q = *I;
    infotype food;
    int hasil;
    // ALGORITMA
    MakeEmpty(&p, MaxEl(*I));
    while (!IsEmpty(q))
    {
        Dequeue(&q, &food);
        hasil = TIMEToDetik(Exp(food)) + TIMEToDetik(t);
        Exp(food) = DetikToTIME(hasil);
        Enqueue(&p, food);
    }
    *I = p;
}

/* *** Mengambil makanan dari inventory *** */
/* I.S. I terdefinisi F.S. makanan dengan id tertentu dihilangkan dari I */
/* Mengembalikan makanan dari inventory dengan id tertentu */
/* Prekondisi : id makanan harus valid dan id tersebut harus ada didalam inventory */
infotype getMakananById(Inventory *I, int id)
{
    // KAMUS LOKAL
    infotype food, hasil;
    Inventory p = *I;
    Inventory q;
    // ALGORITMA
    MakeEmpty(&q, MaxEl(*I));
    while (!IsEmpty(p))
    {
        Dequeue(&p, &food);
        if (id == ID(food))
        {
            hasil = food;
        }
        else
        {
            Enqueue(&q, food);
        }
    }
    *I = q;
    return hasil;
}

/* *** Mengecek apakah suatu id makanan ada didalam inventory *** */
boolean isElmtById(Inventory I, int id)
{
    // KAMUS LOKAL
    Inventory temp = I;
    boolean found = false;
    infotype tempval;
    // ALGORITMA
    while ((!IsEmpty(temp)) && (!found))
    {
        Dequeue(&temp, &tempval);
        if (id == ID(tempval))
        {
            found = true;
        }
    }
    return found;
}

/* *** Mengambil makanan dari inventory *** */
/* I.S. I terdefinisi F.S. makanan dengan nama tertentu dihilangkan dari I */
/* Mengembalikan makanan dari inventory dengan nama tertentu */
/* Prekondisi : nama makanan harus valid dan nama tersebut harus ada didalam inventory */
infotype getMakananByName(Inventory *I, String nama)
{
    // KAMUS LOKAL
    infotype food, hasil;
    Inventory p = *I;
    Inventory q;
    // ALGORITMA
    MakeEmpty(&q, MaxEl(*I));
    while (!IsEmpty(p))
    {
        Dequeue(&p, &food);
        if (isStringEqual(nama, Nama(food)))
        {
            hasil = food;
        }
        else
        {
            Enqueue(&q, food);
        }
    }
    *I = q;
    return hasil;
}

/* *** Mengecek apakah suatu nama makanan ada didalam inventory *** */
boolean isElmtByName(Inventory I, String nama)
{
    // KAMUS LOKAL
    PrioQueueTime temp = I;
    boolean found = false;
    infotype tempval;
    // ALGORITMA
    while ((!IsEmpty(temp)) && (!found))
    {
        Dequeue(&temp, &tempval);
        if (isStringEqual(nama, Nama(tempval)))
        {
            found = true;
        }
    }
    return found;
}

/* *** Menampilkan isi inventory *** */
void displayInventory(Inventory I)
{
    printf("INVENTORY: \n");
    PrintPrioQueueTime(I);
}

/* *** Mengembalikan panjang inventory *** */
int lengthInventory(Inventory I)
{
    return NBElmt(I);
}

/* *** Mengembalikan hasil pengecekan apakah inventory perlu di upgrade *** */
/* Upgrade dilakukan jika panjang inventory > 75% maxel nya */
boolean checkInventoryUpgrade(Inventory I)
{
    int len, threshold;
    // ALGORITMA
    len = lengthInventory(I);
    threshold = 0.75 * MaxEl(I);

    if (len > threshold)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* *** Mengupgrade kapasitas dari inventory *** */
/* Perlu dilakukan apakah inventory perlu di upgrade atau tidak terlebih dahulu */
/* Upgrade adalah penambahan kapasitas 2 kali lipat aslinya */
void upgradeInventory(Inventory *I)
{
    // KAMUS LOKAL
    Inventory p = *I;
    Inventory q;
    infotype food;

    // ALGORITMA

    if (checkInventoryUpgrade(*I))
    {
        MakeEmpty(&q, MaxEl(*I) * 2);
        while (!IsEmpty(p))
        {
            Dequeue(&p, &food);
            Enqueue(&q, food);
        }
        *I = q;
    }
}