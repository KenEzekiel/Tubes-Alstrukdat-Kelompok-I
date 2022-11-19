#include "olahmakanan.h"


void displayMakananFiltered(String aksi, ListMakanan *lfood, ListMakanan *lfiltered) {
    Makanan food;
    String nama;
    String aksiChop, aksiMix, aksiFry, aksiBoil;

    charToString("CHOP",&aksiChop,4);
    charToString("BOIL",&aksiBoil,4);
    charToString("MIX",&aksiMix,3);
    charToString("FRY",&aksiFry,3);
    if (isStringEqual(aksi,aksiChop) || isStringEqual(aksi,aksiBoil)) {
        printf("========================\n");
        printf("=        ");
        displayString(aksi);
        printf("        =\n");
        printf("========================\n\n");
    }
    else if (isStringEqual(aksi,aksiMix) || isStringEqual(aksi,aksiFry)) {
        printf("========================");
        printf("=         ");
        displayString(aksi);
        printf("        =");
        printf("========================\n\n");
    }

    //ListMakanan* lfiltered;
    //CreateListMakanan(lfiltered);
    *lfiltered= filterByAksi(*lfood,aksi);
    printf("List Bahan Makanan yang Bisa Dibuat:\n");
    for(int i=0; i< listMakananLength(*lfiltered); i++){
        food = ELMT_LM(*lfiltered, i);
        nama = Nama(food);
        printf("%d. ", i+1);
        displayString(nama);
        printf("\n");
    }
}

ListMakanan listNeeded(int id, ResepTree Resep, ListMakanan lfood)
{
    Tree t = FindID(Resep, id);
    
    ListMakanan lneed;
    CreateListMakanan(&lneed);

    for (int i = 0; i < TREECOUNT(t); i++)
    {
        int childIdx = indexOfID(lfood, ROOT(SUBTREE(t,i)));
        insertLastMakanan(&lneed, ELMT_LM(lfood, childIdx));
    }
    return lneed;
}

boolean isAvailable(Inventory I, ListMakanan lneed){
    
    boolean avail = true;

    for (int i = 0; i < listMakananLength(lneed); i++)
    {
        if (!isElmtById(I, ID(ELMT_LM(lneed, i))))
        {
            avail = false;
        }
    }
    return avail;
}

void process(int id, Inventory *I, ListMakanan lneed, ListMakanan lfiltered, ProcessList *P){
    //Makanan food = Makanan
    //i = input dari command
    int idxFood = indexOfID(lfiltered, id);
    Makanan food = ELMT_LM(lfiltered, idxFood);

    for (int i = 0; i < listMakananLength(lneed); i++)
    {
        int idDel = ID(ELMT_LM(lneed, i));
        deleteFoodById(I, idDel);
    }
    upgradeProcessList(P);
    Enqueue(P,food);
    displayString(Nama(food));
    printf(" sedang diproses!\n");

}

void CreateProcessMakanan(ProcessList *P, int max){
    MakeEmpty(P, max);
}

void updateProcessList(ProcessList *P, Inventory *I, TIME t, ListMakanan *delivered, ListMakanan *expired){
    // KAMUS LOKAL

    // ALGORITMA

    if (!IsPrioQueueEmpty(*P))
    {
        updateProcessTime(P, t, I, delivered, expired);
    }
}

void updateProcessTime(ProcessList *P, TIME t, Inventory *I, ListMakanan *delivered, ListMakanan *expired){
    // KAMUS LOKAL
    ProcessList p;
    ProcessList q = *P;
    prioQueueInfotype food;
    int hasil, exp;
    // ALGORITMA
    MakeEmpty(&p, MaxPrioQueueEl(*P));
    while (!IsPrioQueueEmpty(q))
    {
        Dequeue(&q, &food);
        hasil = TIMEToMenit(AksiTime(food)) - TIMEToMenit(t);
        if (hasil > 0)
        {
            AksiTime(food) = MenitToTIME(hasil);
            buyMakanan(&p, food);
        }
        else
        {
            exp = hasil + TIMEToMenit(Exp(food));
            if (exp > 0)
            {
                insertLastMakanan(delivered, food);
                Exp(food) = MenitToTIME(exp);
                Enqueue(I, food);
            }
            else
            {
                insertLastMakanan(delivered, food);
                insertLastMakanan(expired, food);
            }
        }
    }
    *P = p;
}

void plusProcessTime(ProcessList *P, TIME t){
    // KAMUS LOKAL
    ProcessList p;
    ProcessList q = *P;
    prioQueueInfotype food;
    int hasil;
    // ALGORITMA
    MakeEmpty(&p, MaxPrioQueueEl(*P));
    while (!IsPrioQueueEmpty(q))
    {
        Dequeue(&q, &food);
        hasil = TIMEToMenit(AksiTime(food)) - TIMEToMenit(t);
        if (hasil < 0)
        {
            hasil = 0;
        }
        AksiTime(food) = MenitToTIME(hasil);
        addProcessList(&p, food);
    }
    *P = p;

}

int lengthProcessList(ProcessList P){
    return NBElmt(P);
}

boolean checkProcessUpgrade(ProcessList P){
    // KAMUS LOKAL
    int len, threshold;
    // ALGORITMA
    len = lengthProcessList(P);
    threshold = 0.75 * MaxPrioQueueEl(P);

    if (len > threshold)
    {
        return true;
    }
    else
    {
        return false;
    }

}

void upgradeProcessList(ProcessList *P){
    // KAMUS LOKAL
    ProcessList p = *P;
    ProcessList q;
    prioQueueInfotype food;

    // ALGORITMA

    if (checkProcessUpgrade(*P))
    {
        MakeEmpty(&q, MaxPrioQueueEl(*P) * 2);
        while (!IsPrioQueueEmpty(p))
        {
            Dequeue(&p, &food);
            addProcessList(&q, food);
        }
        *P = q;
    }
}

void displayProcessList(ProcessList P){
    
    printf("PROCESSING LIST: \n");
    PrintPrioQueueTime(P);

}

void addProcessList(ProcessList *PL, prioQueueInfotype food) {
    int i, j;
    prioQueueInfotype temp;

    // ALGORITMA
    if (IsPrioQueueEmpty(*PL))
    {
        Head(*PL) = 0;
        Tail(*PL) = 0;
        InfoTail(*PL) = food;
    }
    else
    {
        // Mod untuk antisipasi jika Tail dari DL > IDX_MAX alias CAPACITY - 1
        Tail(*PL) = Tail(*PL) == MaxPrioQueueEl(*PL) - 1 ? 0 : Tail(*PL) + 1;
        InfoTail(*PL) = food;
        i = Tail(*PL);
        j = i == 0 ? MaxPrioQueueEl(*PL) - 1 : i - 1;
        while (i != Head(*PL) && TIMEToMenit(AksiTime(Elmt(*PL, i))) < TIMEToMenit(AksiTime(Elmt(*PL, j))))
        {
            temp = Elmt(*PL, i);
            Elmt(*PL, i) = Elmt(*PL, j);
            Elmt(*PL, j) = temp;
            i = j;
            j = i == 0 ? MaxPrioQueueEl(*PL) - 1 : i - 1;
        }
    }
}

void delivproc(ProcessList *DL, Inventory *I, ListMakanan *delivered)
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
        if (TIMEToMenit(AksiTime(food)) != 0)
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