#include "olahmakanan.h"


boolean isPointTrue(String aksi, POINT P) {
    boolean found = false;
    //if (isStringEqual(aksi, wordToString("MIX")));
    return found;
}

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

boolean isBahanAvailable(ListMakanan lfood){
    boolean ada=true;
    return ada;
}

void process(String aksi,int i, ListMakanan *lfood, ListMakanan *lfiltered, Inventory I, ResepTree Resep){
    //Makanan food = Makanan
    boolean berhasil = false;
    Makanan food = ELMT_LM(*lfiltered, i);
    int ID = ID(food);
    Tree t = FindID(Resep,ID);

    ListMakanan lneed;
    CreateListMakanan(&lneed);

    //membuat listmakanan yang berisi bahan yang dibutuhkan
    for (int i=0; i<listMakananLength(*lfood); i++){
        if (TraverseTree(t,ID(ELMT_LM(*lfood, i)))) {
            insertLastMakanan(&lneed,ELMT_LM(*lfood, i));
        }
    }

    if (isBahanAvailable(lneed)) {
        printf("%c berhasil dibuat dan sudah masuk ke dalam inventory!",Nama(food));
    }
    else{
        printf("Gagal membuat %c karena kamu tidak memiliki bahan berikut: ",Nama(food));
        ListMakanan lkosong;
        CreateListMakanan(&lkosong);
        eltype val;
        for(i=0; i<listMakananLength(*lfiltered); i++){
            if (!isElmtById(I,ID(food))) {
                insertLastMakanan(&lkosong,val);
            }
        }
    }
}