#include "olahmakanan.h"

void displayMakananFiltered(String aksi, ListMakanan *lfood, ListMakanan *lfiltered) {
    Makanan food;
    String nama;

    /*printf("========================");
    printf("=        %c            =", aksi);
    printf("========================");*/

    //ListMakanan* lfiltered;
    CreateListMakanan(lfiltered);
    *lfiltered= filterByAksi(*lfood,aksi);
    printf("List Bahan Makanan yang Bisa Dibuat: ");
    for(int i=0; i< listMakananLength(*lfiltered); i++){
        food = ELMT_LM(*lfiltered, i);
        nama = Nama(food);
        printf("%d. %c", i+1, nama);
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
        printf("%c sedang diproses!",Nama(food));
    }
    else{
        printf("Gagal membuat %c karena kamu tidak memiliki bahan berikut: ",Nama(food));
        //ListMakanan lkosong;
        //CreateListMakanan(&lkosong);
        eltype val;
        int count=0;
        for(i=0; i<listMakananLength(lneed); i++){
            if (!isElmtById(I,ID(ELMT_LM(lneed,i)))) {
                count++;
                //insertLastMakanan(&lkosong,val);
                printf("%d. %c", count, Nama(ELMT_LM(lneed,i)));
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

    if (!IsEmpty(*P))
    {
        minusDelivTime(P, t);
        deliver(P, I, delivered);
    }
}

void minusProcessTime(ProcessList *P, TIME t){
    // KAMUS LOKAL
    ProcessList p;
    ProcessList q = *P;
    infotype food;
    int hasil;
    // ALGORITMA
    MakeEmpty(&p, MaxEl(*P));
    while (!IsEmpty(q))
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
    *P = p;
}

void plusProcessTime(ProcessList *P, TIME t){
    // KAMUS LOKAL
    ProcessList p;
    ProcessList q = *P;
    infotype food;
    int hasil;
    // ALGORITMA
    MakeEmpty(&p, MaxEl(*P));
    while (!IsEmpty(q))
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
    *P = p;

}

int lengthProcessList(ProcessList P){
    return NBElmt(P);
}

boolean checkUpgrade(ProcessList P){
    // KAMUS LOKAL
    int len, threshold;
    // ALGORITMA
    len = lengthDeliveryList(P);
    threshold = 0.75 * MaxEl(P);

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
    upgradeDelivList(P);
}

void displayDeliveryList(ProcessList P){
    
    printf("PROCESSING LIST: \n");
    PrintPrioQueueTime(P);

}