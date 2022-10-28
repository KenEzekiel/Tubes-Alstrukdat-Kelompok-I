#include "listmakanan.h"
#include <stdio.h>

int main() {
    ListMakanan lfood1, lbuy;
    String aksi;
    int id, idx;

    CreateListMakanan(&lfood1);
    CreateListMakanan(&lbuy);

    printf("Menampilkan list makanan hasil pembacaan dari file konfigurasi\n");
    lfood1 = readListMakanan("../../test/test.txt");
    printCatalog(lfood1);

    printf("Mengecek indeks dari ID Makanan\n");
    printf("ID Makanan: ");
    scanf("%d", &id);
    idx = indexOfID(lfood1, id);
    printf("Makanan dengan ID %d berada pada indeks %d\n", id, idx);

    printf("Masukkan aksi yang ingin dilakukan\n");
    readString(&aksi);
    lbuy = filterByAksi(lfood1, aksi);
    printf("Menampilkan list makanan yang sesuai dengan aksi\n");
    printCatalog(lbuy);

    return 0;
}