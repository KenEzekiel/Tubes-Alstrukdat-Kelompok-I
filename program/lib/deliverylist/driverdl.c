#include "deliverylist.h"
#include "../../../lib/string/string.h"
#include <stdio.h>

int main()
{
    DeliveryList DL;
    Inventory I;
    ListMakanan L, delivered;
    infotype x, y, z, a;

    MakeEmpty(&DL, 3);
    CreateInventory(&I, 3);
    CreateListMakanan(&L);
    CreateListMakanan(&delivered);

    BacaMakanan(&x);
    BacaMakanan(&y);
    BacaMakanan(&z);
    BacaMakanan(&a);
    insertLastMakanan(&L, x);
    insertLastMakanan(&L, y);
    insertLastMakanan(&L, z);
    insertLastMakanan(&L, a);
    printCatalog(L);

    int id;
    String s;
    printf("Masukkan id makanan yang mau dibeli: ");
    scanf("%d", &id);
    while (!isMakananValidbyId(id, L))
    {
        printf("ID tidak valid \n");
        printf("Masukkan ID makanan yang mau dibeli: ");
        scanf("%d", &id);
    }
    buyMakananbyId(&DL, id, L);
    displayDeliveryList(DL);

    printf("Masukkan nama makanan yang mau dibeli: ");
    readString(&s);
    while (!isMakananValidbyName(s, L))
    {
        printf("nama tidak valid \n");
        printf("Masukkan nama makanan yang mau dibeli: ");
        readString(&s);
    }
    buyMakananbyName(&DL, s, L);
    displayDeliveryList(DL);

    int sec;
    printf("Masukkan menit update: ");
    scanf("%d", &sec);
    updateDeliveryList(&DL, &I, MenitToTIME(sec), &delivered);
    displayDeliveryList(DL);
    displayInventory(I);
    printf("Makanan yang sudah dikirim: \n");
    printCatalog(delivered);

    reverseUpdateDeliveryList(&DL, &I, MenitToTIME(sec));
    displayDeliveryList(DL);
    displayInventory(I);

    printf("Masukkan id makanan yang mau dibeli: ");
    scanf("%d", &id);
    while (!isMakananValidbyId(id, L))
    {
        printf("ID tidak valid \n");
        printf("Masukkan ID makanan yang mau dibeli: ");
        scanf("%d", &id);
    }
    buyMakananbyId(&DL, id, L);
    displayDeliveryList(DL);

    if (lengthDeliveryList(DL) == 2)
    {
        printf("Masukkan id makanan yang mau dibeli: ");
        scanf("%d", &id);
        while (!isMakananValidbyId(id, L))
        {
            printf("ID tidak valid \n");
            printf("Masukkan ID makanan yang mau dibeli: ");
            scanf("%d", &id);
        }
        buyMakananbyId(&DL, id, L);
        displayDeliveryList(DL);
    }

    // upgradeDelivList(&DL);

    // cek apakah kapasitas sudah bertambah jadi 2x lipat nya
    printf("Masukkan id makanan yang mau dibeli: ");
    scanf("%d", &id);
    while (!isMakananValidbyId(id, L))
    {
        printf("ID tidak valid \n");
        printf("Masukkan ID makanan yang mau dibeli: ");
        scanf("%d", &id);
    }
    buyMakananbyId(&DL, id, L);
    displayDeliveryList(DL);

    // upgradeDelivList(&DL);

    printf("Masukkan id makanan yang mau dibeli: ");
    scanf("%d", &id);
    while (!isMakananValidbyId(id, L))
    {
        printf("ID tidak valid \n");
        printf("Masukkan ID makanan yang mau dibeli: ");
        scanf("%d", &id);
    }
    buyMakananbyId(&DL, id, L);
    displayDeliveryList(DL);

    // upgradeDelivList(&DL);

    printf("Masukkan id makanan yang mau dibeli: ");
    scanf("%d", &id);
    while (!isMakananValidbyId(id, L))
    {
        printf("ID tidak valid \n");
        printf("Masukkan ID makanan yang mau dibeli: ");
        scanf("%d", &id);
    }
    buyMakananbyId(&DL, id, L);
    displayDeliveryList(DL);

    return 0;
}

/*
hasil:
Masukkan id: 1
Masukkan nama makanan: ayam
Masukkan waktu kadaluwarsa: 0 10 0
Masukkan aksi yang bisa dilakukan: goreng
Masukkan lama pengiriman: 0 20 0
Masukkan waktu pengolahan makanan: 0 30 0
Masukkan id: 2
Masukkan nama makanan: nasi
Masukkan waktu kadaluwarsa: 0 30 0
Masukkan aksi yang bisa dilakukan: kukus
Masukkan lama pengiriman: 0 40 0
Masukkan waktu pengolahan makanan: 0 20 0
Masukkan id: 3
Masukkan nama makanan: kari
Masukkan waktu kadaluwarsa: 0 40 0
Masukkan aksi yang bisa dilakukan: makan
Masukkan lama pengiriman: 0 30 0
Masukkan waktu pengolahan makanan: 0 50 0
Masukkan id: 4
Masukkan nama makanan: bubur
Masukkan waktu kadaluwarsa: 0 15 0
Masukkan aksi yang bisa dilakukan: aduk
Masukkan lama pengiriman: 0 15 0
Masukkan waktu pengolahan makanan: 9 0 0
==========================================List Makanan=============================================
Nama Makanan - Durasi Kedaluwarsa - Aksi yang Diperlukan - Delivery Time - Waktu Pengolahan Makanan
1. ayam - 10 menit - goreng - 20 menit - 30 menit
2. nasi - 30 menit - kukus - 40 menit - 20 menit
3. kari - 40 menit - makan - 30 menit - 50 menit
4. bubur - 15 menit - aduk - 15 menit - 9 jam
Masukkan id makanan yang mau dibeli:
3
ID: 3
Nama makanan: kari
Waktu kadaluwarsa: 0:40:0
Lokasi aksi: makan
Lama pengiriman: 0:30:0
Waktu pengolahan makanan: 0:50:0
#
Masukkan nama makanan yang mau dibeli: ayam
ID: 1
Nama makanan: ayam
Waktu kadaluwarsa: 0:10:0
Lokasi aksi: goreng
Lama pengiriman: 0:20:0
Waktu pengolahan makanan: 0:30:0
ID: 3
Nama makanan: kari
Waktu kadaluwarsa: 0:40:0
Lokasi aksi: makan
Lama pengiriman: 0:30:0
Waktu pengolahan makanan: 0:50:0
#
Masukkan detik update: 1200
ID: 3
Nama makanan: kari
Waktu kadaluwarsa: 0:40:0
Lokasi aksi: makan
Lama pengiriman: 0:10:0
Waktu pengolahan makanan: 0:50:0
#
INVENTORY:
ID: 1
Nama makanan: ayam
Waktu kadaluwarsa: 0:10:0
Lokasi aksi: goreng
Lama pengiriman: 0:0:0
Waktu pengolahan makanan: 0:30:0
#
Masukkan id makanan yang mau dibeli: 2
ID: 3
Nama makanan: kari
Waktu kadaluwarsa: 0:40:0
Lokasi aksi: makan
Lama pengiriman: 0:10:0
Waktu pengolahan makanan: 0:50:0
ID: 2
Nama makanan: nasi
Waktu kadaluwarsa: 0:30:0
Lokasi aksi: kukus
Lama pengiriman: 0:40:0
Waktu pengolahan makanan: 0:20:0
#
Masukkan id makanan yang mau dibeli: 4
ID: 3
Nama makanan: kari
Waktu kadaluwarsa: 0:40:0
Lokasi aksi: makan
Lama pengiriman: 0:10:0
Waktu pengolahan makanan: 0:50:0
ID: 4
Nama makanan: bubur
Waktu kadaluwarsa: 0:15:0
Lokasi aksi: aduk
Lama pengiriman: 0:15:0
Waktu pengolahan makanan: 9:0:0
ID: 2
Nama makanan: nasi
Waktu kadaluwarsa: 0:30:0
Lokasi aksi: kukus
Lama pengiriman: 0:40:0
Waktu pengolahan makanan: 0:20:0
#
Masukkan id makanan yang mau dibeli: 1
ID: 3
Nama makanan: kari
Waktu kadaluwarsa: 0:40:0
Lokasi aksi: makan
Lama pengiriman: 0:10:0
Waktu pengolahan makanan: 0:50:0
ID: 4
Nama makanan: bubur
Waktu kadaluwarsa: 0:15:0
Lokasi aksi: aduk
Lama pengiriman: 0:15:0
Waktu pengolahan makanan: 9:0:0
ID: 1
Nama makanan: ayam
Waktu kadaluwarsa: 0:10:0
Lokasi aksi: goreng
Lama pengiriman: 0:20:0
Waktu pengolahan makanan: 0:30:0
ID: 2
Nama makanan: nasi
Waktu kadaluwarsa: 0:30:0
Lokasi aksi: kukus
Lama pengiriman: 0:40:0
Waktu pengolahan makanan: 0:20:0
#
Masukkan id makanan yang mau dibeli: 2
ID: 3
Nama makanan: kari
Waktu kadaluwarsa: 0:40:0
Lokasi aksi: makan
Lama pengiriman: 0:10:0
Waktu pengolahan makanan: 0:50:0
ID: 4
Nama makanan: bubur
Waktu kadaluwarsa: 0:15:0
Lokasi aksi: aduk
Lama pengiriman: 0:15:0
Waktu pengolahan makanan: 9:0:0
ID: 1
Nama makanan: ayam
Waktu kadaluwarsa: 0:10:0
Lokasi aksi: goreng
Lama pengiriman: 0:20:0
Waktu pengolahan makanan: 0:30:0
ID: 2
Nama makanan: nasi
Waktu kadaluwarsa: 0:30:0
Lokasi aksi: kukus
Lama pengiriman: 0:40:0
Waktu pengolahan makanan: 0:20:0
ID: 2
Nama makanan: nasi
Waktu kadaluwarsa: 0:30:0
Lokasi aksi: kukus
Lama pengiriman: 0:40:0
Waktu pengolahan makanan: 0:20:0
#
Masukkan id makanan yang mau dibeli: 5
ID tidak valid
Masukkan ID makanan yang mau dibeli: 3
ID: 3
Nama makanan: kari
Waktu kadaluwarsa: 0:40:0
Lokasi aksi: makan
Lama pengiriman: 0:10:0
Waktu pengolahan makanan: 0:50:0
ID: 4
Nama makanan: bubur
Waktu kadaluwarsa: 0:15:0
Lokasi aksi: aduk
Lama pengiriman: 0:15:0
Waktu pengolahan makanan: 9:0:0
ID: 1
Nama makanan: ayam
Waktu kadaluwarsa: 0:10:0
Lokasi aksi: goreng
Lama pengiriman: 0:20:0
Waktu pengolahan makanan: 0:30:0
ID: 3
Nama makanan: kari
Waktu kadaluwarsa: 0:40:0
Lokasi aksi: makan
Lama pengiriman: 0:30:0
Waktu pengolahan makanan: 0:50:0
ID: 2
Nama makanan: nasi
Waktu kadaluwarsa: 0:30:0
Lokasi aksi: kukus
Lama pengiriman: 0:40:0
Waktu pengolahan makanan: 0:20:0
ID: 2
Nama makanan: nasi
Waktu kadaluwarsa: 0:30:0
Lokasi aksi: kukus
Lama pengiriman: 0:40:0
Waktu pengolahan makanan: 0:20:0
#
*/