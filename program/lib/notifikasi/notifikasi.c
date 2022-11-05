#include "notifikasi.h"
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
    printf("Notifikasi: ");
    if (notifLength == 0) 
    {
        printf(" - \n");
    }
    else 
    {
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
    char c[] = " sudah diterima oleh Cooking BNMO! :D";
    String notifInfo, newNotif;

    /* ALGORITMA */
    charToString(c, &notifInfo, 37);
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
    char c[] = " kedaluwarsa ... :(";
    String notifInfo, newNotif;

    /* ALGORITMA */
    charToString(c, &notifInfo, 19);
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
    char c1[] = " dikembalikan ke inventory";
    char c2[] = " dikeluarkan dari inventory";
    char c3[] = " dibatalkan ... :(";
    char c4[] = "FRY";
    char c5[] = "MIX";
    char c6[] = "CHOP";
    char c7[] = "BOIL";
    char c8[] = " ";
    Inventory tempPrev;
    Makanan tempVal;
    int idx;
    String info1, info2, info3, newNotif, aksiFry, aksiMix, aksiChop, aksiBoil, space;
    ListMakanan expPrev = ExpListState(prev);
    ListMakanan expCurr = ExpListState(current);
    ListMakanan delivPrev = DeliveredListState(prev);
    ListMakanan delivCurr = DeliveredListState(current);

    /* ALGORITMA */
    charToString(c1, &info1, 26);
    charToString(c2, &info2, 27);
    charToString(c3, &info3, 18);
    charToString(c4, &aksiFry, 3);
    charToString(c5, &aksiMix, 3);
    charToString(c6, &aksiChop, 4);
    charToString(c7, &aksiBoil, 4);
    charToString(c8, &space, 1);

    /* Menambahkan notif pembatalan aksi */
    tempPrev = InventoryState(prev);
    while (!IsPrioQueueEmpty(tempPrev))
    {
        Dequeue(&tempPrev, &tempVal);
        if (!isElmtById(InventoryState(current), ID(tempVal)))
        {
            idx = indexOfID(delivPrev, ID(tempVal));
            if (idx == IDX_UNDEF_LMAKANAN)
            {
                if (isStringEqual(Aksi(tempVal), aksiFry))
                {
                    newNotif = aksiFry;
                }
                else if (isStringEqual(Aksi(tempVal), aksiMix))
                {
                    newNotif = aksiMix;
                }
                else if (isStringEqual(Aksi(tempVal), aksiBoil))
                {
                    newNotif = aksiBoil;
                }
                else
                {
                    newNotif = aksiChop;
                }
                insertSubstring(&newNotif, space);
                insertSubstring(&newNotif, Nama(tempVal));
                insertSubstring(&newNotif, info3);
                insertLastNotif(listNotif, newNotif);
            }
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
    char c3[] = " dilakukan ... :D";
    char c4[] = "FRY";
    char c5[] = "MIX";
    char c6[] = "CHOP";
    char c7[] = "BOIL";
    char c8[] = " ";
    Inventory tempCurr;
    Makanan tempVal;
    int idx;
    String info, newNotif, aksiFry, aksiMix, aksiChop, aksiBoil, space;
    ListMakanan expPrev = ExpListState(prev);
    ListMakanan expCurr = ExpListState(current);
    ListMakanan delivPrev = DeliveredListState(prev);
    ListMakanan delivCurr = DeliveredListState(current);

    /* ALGORITMA */
    charToString(c3, &info, 17);
    charToString(c4, &aksiFry, 3);
    charToString(c5, &aksiMix, 3);
    charToString(c6, &aksiChop, 4);
    charToString(c7, &aksiBoil, 4);
    charToString(c8, &space, 1);

    /* Menambahkan notif pembatalan aksi */
    tempCurr = InventoryState(current);
    while (!IsPrioQueueEmpty(tempCurr))
    {
        Dequeue(&tempCurr, &tempVal);
        if (!isElmtById(InventoryState(prev), ID(tempVal)))
        {
            idx = indexOfID(delivCurr, ID(tempVal));
            if (idx == IDX_UNDEF_LMAKANAN)
            {
                if (isStringEqual(Aksi(tempVal), aksiFry))
                {
                    newNotif = aksiFry;
                }
                else if (isStringEqual(Aksi(tempVal), aksiMix))
                {
                    newNotif = aksiMix;
                }
                else if (isStringEqual(Aksi(tempVal), aksiBoil))
                {
                    newNotif = aksiBoil;
                }
                else
                {
                    newNotif = aksiChop;
                }
                insertSubstring(&newNotif, space);
                insertSubstring(&newNotif, Nama(tempVal));
                insertSubstring(&newNotif, info);
                insertLastNotif(listNotif, newNotif);
            }
        }
    }

    /* Menambahkan notif makanan sampai dan expired */
    addDelivered(delivCurr, listNotif);
    addExpired(expCurr, listNotif);
}

void updateNotif(State curr, Notif *listNotif)
{
    addDelivered(DeliveredListState(curr), listNotif);
    addExpired(ExpListState(curr), listNotif);
}

