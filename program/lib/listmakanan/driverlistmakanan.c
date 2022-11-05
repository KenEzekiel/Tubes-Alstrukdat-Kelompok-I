#include "listmakanan.h"
#include <stdio.h>

int main()
{
    ListMakanan lfood1, lbuy;
    String aksi;
    int id, idx;

    CreateListMakanan(&lfood1);
    CreateListMakanan(&lbuy);

    printf("Menampilkan list makanan hasil pembacaan dari file konfigurasi\n");
    lfood1 = readListMakanan("../../../test/makanan.txt");
    printCatalog(lfood1);

    printf("Mengecek indeks dari ID Makanan\n");
    printf("ID Makanan: ");
    STARTWORD();
    id = WordToInt(currentWord);
    idx = indexOfID(lfood1, id);
    printf("Makanan dengan ID %d berada pada indeks %d\n", id, idx);

    printf("Masukkan aksi yang ingin dilakukan: ");
    readString(&aksi);
    printf("Menampilkan list makanan yang sesuai dengan aksi\n");
    displayFilteredAksi(aksi, lfood1, &lbuy);

    printf("Masukkan aksi yang ingin dilakukan: ");
    readString(&aksi);
    printf("Menampilkan list makanan yang sesuai dengan aksi\n");
    displayFilteredAksi(aksi, lfood1, &lbuy);

    return 0;
}