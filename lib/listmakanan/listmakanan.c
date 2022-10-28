
#include "../boolean.h"
#include "../makanan/makanan.h"
#include "../wordmachine/wordmachine.h"
#include "../time/time.h"
#include "../string/string.h"
#include "listmakanan.h"
#include <stdio.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListMakanan(ListMakanan *lfood) {
    /* I.S. l sembarang */
    /* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
    /* Proses: Inisialisasi semua elemen List l dengan MARK */
    /*KAMUS LOKAL*/
    int i;
    Makanan markFood;
    TIME markTime;
    String markString;

    /*ALGORITMA*/
    CreateString(&markString);
    CreateTime(&markTime, 0, 0, 0);
    for (i = IDX_MIN_LMAKANAN; i < CAPACITY; i++)
    {
        CreateMakanan(&markFood, MARK_LMAKANAN, markString, markTime, markString, markTime, markTime);
        ELMT_LM(*lfood, i) = markFood;
    }
}
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan MARK */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listMakananLength(ListMakanan lfood){
    /*KAMUS LOKAL*/
    int i = 0;
    /*ALGORITMA*/

    while ((i < CAPACITY_LMAKANAN) && (ID(ELMT_LM(lfood, i)) != MARK_LMAKANAN))
    {
        i++;
    }
    return i;
}
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */

void insertLastMakanan(ListMakanan *lfood, eltype val){
    if (listMakananLength(*lfood) != CAPACITY_LMAKANAN){
        ELMT_LM(*lfood, listMakananLength(*lfood)) = val;
    }
}
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */

ListMakanan readListMakanan(char* dir){
    /* KAMUS */
    ListMakanan ret;
    Makanan food;
    int id, HH, MM, SS;
    String aksi, nama;
    TIME exp, delivTime, aksiTime;

    /* ALGORITMA */
    CreateListMakanan(&ret);

    STARTFILEWORD(dir);
	int len = WordToInt(currentWord);
    for(int i = 0; i < len; i++) {
        /* ID Makanan */
        ADVWORD();
        id = WordToInt(currentWord);
        /* Nama makanan */
        ADVLINE();
        nama = wordToString(currentWord);
        /* Waktu Kadaluwarsa */
        ADVWORD(); HH = WordToInt(currentWord);
        ADVWORD(); MM = WordToInt(currentWord);
        ADVWORD(); SS = WordToInt(currentWord);
        CreateTime(&exp, HH, MM, SS);
        /* Lama Pengiriman */
        ADVWORD(); HH = WordToInt(currentWord);
        ADVWORD(); MM = WordToInt(currentWord);
        ADVWORD(); SS = WordToInt(currentWord);
        CreateTime(&delivTime, HH, MM, SS);
        /* Aksi */
        ADVWORD();
        aksi = wordToString(currentWord);
        /* Waktu Pengolahan */
        ADVWORD(); HH = WordToInt(currentWord);
        ADVWORD(); MM = WordToInt(currentWord);
        ADVWORD(); SS = WordToInt(currentWord);
        CreateTime(&aksiTime, HH, MM, SS);
        /* Pembentukan makanan */
        CreateMakanan(&food, id, nama, exp, aksi, delivTime, aksiTime);
        insertLastMakanan(&ret, food);
    }
    return ret;
}
/* Membaca file dari directory dan menghasilkan List Statik yang elemennya berisi tipe Makanan */
/* Ketentuan file konfigurasi: baris pertama berisi banyaknya elemen, dilanjutkan tiap baris membaca tipe makanan dengan
urutan ID Makanan, Nama Makanan, Waktu Kadaluwarsa, Lama Pengiriman, Aksi yang Dapat Dilakukan, Waktu Pengolahan Makanan */

ListMakanan filterByAksi(ListMakanan lfood, String aksi){
    ListMakanan ret;
    String aksiFood;

    CreateListMakanan(&ret);
    for (int i = 0; i < listMakananLength(lfood); i++) {
        aksiFood = Aksi(ELMT_LM(lfood, i));
        if (isStringEqual(aksiFood, aksi)) {
            insertLastMakanan(&ret, ELMT_LM(lfood, i));
        }
    }
    return ret;
}
/* Menghasilkan list makanan baru yang bisa dilakukan aksi */

int indexOfID(ListMakanan lfood, int idfood){
    /* KAMUS */
    int idx;
    boolean found = false;
    int i = 0;

    /* ALGORITMA */
    while (i < listMakananLength(lfood) && !found){
        if (ID(ELMT_LM(lfood, i)) == idfood){
            found = true;
        } else {
            i++;
        }
    }
    if (found) {
        idx = i;
    } else {
        idx = IDX_UNDEF_LMAKANAN;
    }
    return idx;
}
/* Menghasilkan indeks list dengan ID Makanan sesuai idfood, mengembalikan IDX_UNDEF jika ID Makanan tidak ditemukan */

void printCatalog(ListMakanan lfood){
    Makanan food;
    printf("==========================================List Makanan=============================================\n");
    printf("Nama Makanan - Durasi Kedaluwarsa - Aksi yang Diperlukan - Delivery Time - Waktu Pengolahan Makanan\n");
    for (int i = 0; i < listMakananLength(lfood); i++) {
        food = ELMT_LM(lfood, i);
        printf("%d. ", i+1);
        displayString(Nama(food));
        printf(" - ");
        PrintTime(Exp(food));
        printf(" - ");
        displayString(Aksi(food));
        printf(" - ");
        PrintTime(DelivTime(food));
        printf(" - ");
        PrintTime(AksiTime(food));
        printf("\n");
    }
}
/* I.S. lfood terdefinisi */
/* I.S. Menampilkan list makanan lfood */