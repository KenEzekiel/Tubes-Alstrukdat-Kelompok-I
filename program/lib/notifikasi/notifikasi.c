#include "notifikasi.h"
#include "../utility/utility.h"
#include <stdio.h>

void CreateNotif(Notif *listNotif)
{
    /*KAMUS*/
    String mark;

    /*ALGORITMA*/
    CreateString(&mark);
    for (int i = IDX_MIN_NOTIF; i < CAPACITY_NOTIF; i++)
    {
        ELMT_N(*listNotif, i) = mark;
    }
}


int notifLength(Notif listNotif)
{
    /*KAMUS LOKAL*/
    int i = 0;
    /*ALGORITMA*/

    while ((i < CAPACITY_NOTIF) && (LENGTH(ELMT_N(listNotif, i)) != MARK_NOTIF))
    {
        i++;
    }
    return i;
}
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */

void insertLastNotif(Notif *listNotif, ELTYPE newNotif)
{
    if (notifLength(*listNotif) != CAPACITY_NOTIF)
    {
        ELMT_N(*listNotif, notifLength(*listNotif)) = newNotif;
    }
}
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */

void printNotif(Notif listNotif)
{
    print_blue("Notifikasi: ");
    if (notifLength(listNotif) == 0) 
    {
        printf("- \n");
    }
    else 
    {
        printf("\n");
        for (int i = 0; i < notifLength(listNotif); i++)
        {
            printf("%d. ", i+1);
            displayString(ELMT_N(listNotif, i));
            printf("\n");
        }
    }
}

void addDelivered(ListMakanan delivered, Notif *listNotif)
{
    /* KAMUS */
    String notifInfo, newNotif;

    /* ALGORITMA */
    charToString(" sudah diterima oleh Cooking BNMO! :D", &notifInfo, 37);
    for (int i = 0; i < listMakananLength(delivered); i++) 
    {
        newNotif = Nama(ELMT_LM(delivered, i));
        insertSubstring(&newNotif, notifInfo);
        insertLastNotif(listNotif, newNotif);
    }
}

void addExpired(ListMakanan expired,  Notif *listNotif)
{
    /* KAMUS */
    String notifInfo, newNotif;

    /* ALGORITMA */
    charToString(" kedaluwarsa ... :(", &notifInfo, 19);
    for (int i = 0; i < listMakananLength(expired); i++) 
    {
        newNotif = Nama(ELMT_LM(expired, i));
        insertSubstring(&newNotif, notifInfo);
        insertLastNotif(listNotif, newNotif);
    }
}

void updateUndoNotif(State current, State prev, Notif *listNotif)
{
    /* KAMUS */
    ProcessList tempPrev;
    DeliveryList tempPrevBuy;
    Makanan tempVal;
    int idx;
    String info1, info2, info3, newNotif, aksiFry, aksiMix, aksiChop, aksiBoil, aksiBuy;
    ListMakanan expPrev = ExpListState(prev);
    ListMakanan expCurr = ExpListState(current);
    ListMakanan delivPrev = DeliveredListState(prev);
    ListMakanan delivCurr = DeliveredListState(current);

    /* ALGORITMA */
    charToString(" dikembalikan ke inventory", &info1, 26);
    charToString(" dikeluarkan dari inventory", &info2, 27);
    charToString(" dibatalkan ... :(", &info3, 18);
    charToString("FRY", &aksiFry, 3);
    charToString("MIX", &aksiMix, 3);
    charToString("CHOP", &aksiChop, 4);
    charToString("BOIL", &aksiBoil, 4);
    charToString("BUY", &aksiBuy, 3);

    /* Menambahkan notif pembatalan aksi selain BUY*/
    tempPrev = ProcessedList(prev);
    while (!IsPrioQueueEmpty(tempPrev))
    {
        Dequeue(&tempPrev, &tempVal);
        if (!isElmtById(ProcessedList(current), ID(tempVal)))
        {
            if (isStringEqual(Aksi(tempVal), aksiFry))
            {
                charToString("Penggorengan ", &newNotif, 13);
            }
            else if (isStringEqual(Aksi(tempVal), aksiMix))
            {
                charToString("Pencampuran ", &newNotif, 12);
            }
            else if (isStringEqual(Aksi(tempVal), aksiBoil))
            {
                charToString("Perebusan ", &newNotif, 10);
            }
            else
            {
                charToString("Pemotongan ", &newNotif, 11);
            }
            insertSubstring(&newNotif, Nama(tempVal));
            insertSubstring(&newNotif, info3);
            insertLastNotif(listNotif, newNotif);
        }
    }

    /* Menambahkan notif pembatalan aksi BUY*/
    tempPrevBuy = DeliveryListState(prev);
    while (!IsPrioQueueEmpty(tempPrevBuy))
    {
        Dequeue(&tempPrevBuy, &tempVal);
        if (!isElmtById(DeliveryListState(current), ID(tempVal)))
        {
            charToString("Pembelian ", &newNotif, 11);
            insertSubstring(&newNotif, Nama(tempVal));
            insertSubstring(&newNotif, info3);
            insertLastNotif(listNotif, newNotif);
        }
    }

    /* Menambahkan notif pengembalian makanan */
    for (int i = 0; i < listMakananLength(expPrev); i++)
    {
        newNotif = Nama(ELMT_LM(expPrev, i));
        insertSubstring(&newNotif, info1);
        insertLastNotif(listNotif, newNotif);
    }

    /* Menambahkan notif pengeluaran makanan */
    for (int i = 0; i < listMakananLength(delivPrev); i++)
    {
        newNotif = Nama(ELMT_LM(delivPrev, i));
        insertSubstring(&newNotif, info2);
        insertLastNotif(listNotif, newNotif);
    }

    /* Menambahkan notif makanan sampai dan expired */
    addDelivered(delivCurr, listNotif);
    addExpired(expCurr, listNotif);
}

void updateRedoNotif(State current, State prev, Notif *listNotif)
{
    /* KAMUS */
    ProcessList tempCurr;
    DeliveryList tempCurrBuy;
    Makanan tempVal;
    int idx;
    String info, newNotif, aksiFry, aksiMix, aksiChop, aksiBoil, aksiBuy;
    ListMakanan expPrev = ExpListState(prev);
    ListMakanan expCurr = ExpListState(current);
    ListMakanan delivPrev = DeliveredListState(prev);
    ListMakanan delivCurr = DeliveredListState(current);

    /* ALGORITMA */
    charToString(" dilakukan ... :D", &info, 17);
    charToString("FRY", &aksiFry, 3);
    charToString("MIX", &aksiMix, 3);
    charToString("CHOP", &aksiChop, 4);
    charToString("BOIL", &aksiBoil, 4);
    charToString("BUY", &aksiBuy, 3);

    /* Menambahkan notif aksi dilakukan selain BUY */
    tempCurr = ProcessedList(current);
    while (!IsPrioQueueEmpty(tempCurr))
    {
        Dequeue(&tempCurr, &tempVal);
        if (!isElmtById(ProcessedList(prev), ID(tempVal)))
        {
            if (isStringEqual(Aksi(tempVal), aksiFry))
            {
                charToString("Penggorengan ", &newNotif, 13);
            }
            else if (isStringEqual(Aksi(tempVal), aksiMix))
            {
                charToString("Pencampuran ", &newNotif, 12);
            }
            else if (isStringEqual(Aksi(tempVal), aksiBoil))
            {
                charToString("Perebusan ", &newNotif, 10);
            }
            else
            {
                charToString("Pemotongan ", &newNotif, 11);
            }
            insertSubstring(&newNotif, Nama(tempVal));
            insertSubstring(&newNotif, info);
            insertLastNotif(listNotif, newNotif);
        }
    }

    /* Menambahkan notif aksi BUY dilakukan */
    tempCurrBuy = DeliveryListState(current);
    while (!IsPrioQueueEmpty(tempCurrBuy))
    {
        Dequeue(&tempCurrBuy, &tempVal);
        if (!isElmtById(DeliveryListState(prev), ID(tempVal)))
        {
            charToString("Pembelian ", &newNotif, 11);
            insertSubstring(&newNotif, Nama(tempVal));
            insertSubstring(&newNotif, info);
            insertLastNotif(listNotif, newNotif);
        }
    }

    /* Menambahkan notif makanan sampai dan expired */
    addDelivered(delivCurr, listNotif);
    addExpired(expCurr, listNotif);
}

void updateNotif(State *curr, Notif *listNotif)
{
    addDelivered(DeliveredListState(*curr), listNotif);
    addExpired(ExpListState(*curr), listNotif);
}

void initializeNotif(State *curr)
{
    initializeUlang(&DeliveredListState(*curr));
    initializeUlang(&ExpListState(*curr));
}

void warningNotif(Notif *listNotif)
{
    String newNotif;
    charToString("Ups! Kamu tidak bisa bergerak karena terhalang :D", &newNotif, 49);
    insertLastNotif(listNotif, newNotif);
}
