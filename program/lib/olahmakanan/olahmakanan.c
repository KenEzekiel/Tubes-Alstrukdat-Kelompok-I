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
        printf("        =", aksi);
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

boolean isBahanAvailable(ListMakanan lfood, ListMakanan lneed){
    boolean ada=true;
    int j = 0;
    while (ada && j<listMakananLength(lneed)){
        Makanan food = ELMT_LM(lneed,j);
        if (indexOfID(lfood,ID(food)) == IDX_UNDEF){
            ada = false;
        }
        else{
            j++;
        }
    }
    
    return ada;
}

void process(String aksi,int i, ListMakanan *lfood, Inventory I, ListMakanan *lfiltered, ProcessList *P, ResepTree Resep){
    //Makanan food = Makanan
    //i = input dari command
    boolean berhasil = false;
    Makanan food = ELMT_LM(*lfiltered, i-1);
    Tree t = FindID(Resep,ID(food));

    ListMakanan lneed;
    CreateListMakanan(&lneed);

    //membuat listmakanan yang berisi bahan yang dibutuhkan
    for (int i=0; i<listMakananLength(*lfood); i++){
        if (TraverseTree(t,ID(ELMT_LM(*lfood, i)))) {
            insertLastMakanan(&lneed,ELMT_LM(*lfood, i));
        }
    }

    if (isBahanAvailable(*lfood,lneed)) {
        for (i=0; i<listMakananLength(lneed); i++){
            //mengurangi bahan yang diperlukan dari inventory 
            getMakananById(P, ID(ELMT_LM(lneed,i)));
        }
        //menambahkan makanan yang sudah diolah
        upgradeProcessList(P);
        Enqueue(P,food);
        displayString(Nama(food));
        printf(" sedang diproses!\n");
    }
    else{
        printf("Gagal membuat ");
        displayString(Nama(food));
        printf(" karena kamu tidak memiliki bahan berikut:\n ");
        //ListMakanan lkosong;
        //CreateListMakanan(&lkosong);
        eltype val;
        int count=0;
        for(i=0; i<listMakananLength(lneed); i++){
            if (!isElmtById(I,ID(ELMT_LM(lneed,i)))) {
                count++;
                //insertLastMakanan(&lkosong,val);
                printf("%d. ");
                displayString(Nama(ELMT_LM(lneed,i)));
                printf("\n");
            }
        }
    }
}

void CreateProcessMakanan(ProcessList *P, int max){
    MakeEmpty(P, max);
}

void updateProcessList(ProcessList *P, Inventory *I, TIME t, ListMakanan *delivered){
    // KAMUS LOKAL

    // ALGORITMA

    if (!IsPrioQueueEmpty(*P))
    {
        minusProcessTime(P, t);
        deliver(P, I, delivered);
    }
}

void minusProcessTime(ProcessList *P, TIME t){
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
        hasil = TIMEToMenit(DelivTime(food)) - TIMEToMenit(t);
        if (hasil < 0)
        {
            hasil = 0;
        }
        DelivTime(food) = MenitToTIME(hasil);
        addProcessList(&p, food);
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
        hasil = TIMEToMenit(DelivTime(food)) - TIMEToMenit(t);
        if (hasil < 0)
        {
            hasil = 0;
        }
        DelivTime(food) = MenitToTIME(hasil);
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
        while (i != Head(*PL) && TIMEToMenit(DelivTime(Elmt(*PL, i))) < TIMEToMenit(DelivTime(Elmt(*PL, j))))
        {
            temp = Elmt(*PL, i);
            Elmt(*PL, i) = Elmt(*PL, j);
            Elmt(*PL, j) = temp;
            i = j;
            j = i == 0 ? MaxPrioQueueEl(*PL) - 1 : i - 1;
        }
    }
}