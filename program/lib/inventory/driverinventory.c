#include "inventory.h"
#include "../boolean.h"
#include "../../../lib/queue/prioqueuetime.h"
#include "../../../lib/time/time.h"
#include "../../../lib/makanan/makanan.h"
#include <stdio.h>

int main()
{
    Inventory Q;
    ListMakanan expired;
    infotype x, y, z, a;
    CreateInventory(&Q, 4);
    CreateListMakanan(&expired);

    BacaMakanan(&x);
    BacaMakanan(&y);
    BacaMakanan(&z);
    BacaMakanan(&a);
    addMakananToInventory(&Q, x);
    addMakananToInventory(&Q, y);
    addMakananToInventory(&Q, z);
    addMakananToInventory(&Q, a);

    displayInventory(Q);

    int id;
    printf("Masukkan id makanan yang ingin diambil: ");
    scanf("%d", &id);
    if (isElmtById(Q, id))
    {
        getMakananById(&Q, id);
    }

    String nama;
    printf("Masukkan nama makanan yang ingin diambil: ");
    readString(&nama);
    if (isElmtByName(Q, nama))
    {
        getMakananByName(&Q, nama);
    }

    displayInventory(Q);

    TIME t;
    CreateTime(&t, 0, 10, 0);

    updateInventory(&Q, t, &expired);

    printf("Inventory setelah makanan telah di update 10 menit: \n");
    displayInventory(Q);

    printf("List makanan yang sudah kedaluwarsa: \n");
    printCatalog(expired);

    reverseUpdateInventory(&Q, t);

    printf("Inventory setelah makanan di reverseupdate 10 menit: \n");
    displayInventory(Q);

    addMakananToInventory(&Q, x);

    addMakananToInventory(&Q, y);

    addMakananToInventory(&Q, z);

    addMakananToInventory(&Q, a);
    displayInventory(Q);
}

/*
1
Masukkan string: Ayam
0
10
0
Masukkan string: goreng
1
0
0
2
Masukkan string: Nasi
0
20
0
Masukkan string: kukus
3
0
0
3
Masukkan string: Lontong
2
0
0
Masukkan string: Masak
0
5
0
4
Masukkan string: Kari
0
25
0
*/
/*
hasil dijalankan
Masukkan id: 1
Masukkan nama makanan: ayam
Masukkan waktu kadaluwarsa: 0 10 0
Masukkan aksi yang bisa dilakukan: beli
Masukkan lama pengiriman: 0 20 0
Masukkan waktu pengolahan makanan: 0 30 0
Masukkan id: 2
Masukkan nama makanan: nasi
Masukkan waktu kadaluwarsa: 0 25 0
Masukkan aksi yang bisa dilakukan: kukus
Masukkan lama pengiriman: 0 30 0
Masukkan waktu pengolahan makanan: 0 15 0
Masukkan id: 3
Masukkan nama makanan: kari
Masukkan waktu kadaluwarsa: 0 20 0
Masukkan aksi yang bisa dilakukan: makan
Masukkan lama pengiriman: 0 20 0
Masukkan waktu pengolahan makanan: 0 10 0
Masukkan id: 4
Masukkan nama makanan: bubut
Masukkan waktu kadaluwarsa: 1 0 0
Masukkan aksi yang bisa dilakukan: aduk
Masukkan lama pengiriman: 0 15 0
Masukkan waktu pengolahan makanan: 9 0 0
ID: 1
Nama makanan: ayam
Waktu kadaluwarsa: 0:10:0
Lokasi aksi: beli
Lama pengiriman: 0:20:0
Waktu pengolahan makanan: 0:30:0
ID: 3
Nama makanan: kari
Waktu kadaluwarsa: 0:20:0
Lokasi aksi: makan
Lama pengiriman: 0:20:0
Waktu pengolahan makanan: 0:10:0
ID: 2
Nama makanan: nasi
Waktu kadaluwarsa: 0:25:0
Lokasi aksi: kukus
Lama pengiriman: 0:30:0
Waktu pengolahan makanan: 0:15:0
ID: 4
Nama makanan: bubut
Waktu kadaluwarsa: 1:0:0
Lokasi aksi: aduk
Lama pengiriman: 0:15:0
Waktu pengolahan makanan: 9:0:0
#
Masukkan id makanan yang ingin diambil: 2
Masukkan nama makanan yang ingin diambil: bubut
ID: 1
Nama makanan: ayam
Waktu kadaluwarsa: 0:10:0
Lokasi aksi: beli
Lama pengiriman: 0:20:0
Waktu pengolahan makanan: 0:30:0
ID: 3
Nama makanan: kari
Waktu kadaluwarsa: 0:20:0
Lokasi aksi: makan
Lama pengiriman: 0:20:0
Waktu pengolahan makanan: 0:10:0
#
Inventory setelah makanan telah di update 10 menit:
ID: 3
Nama makanan: kari
Waktu kadaluwarsa: 0:10:0
Lokasi aksi: makan
Lama pengiriman: 0:20:0
Waktu pengolahan makanan: 0:10:0
#
ID: 3
Nama makanan: kari
Waktu kadaluwarsa: 0:10:0
Lokasi aksi: makan
Lama pengiriman: 0:20:0
Waktu pengolahan makanan: 0:10:0
ID: 1
Nama makanan: ayam
Waktu kadaluwarsa: 0:10:0
Lokasi aksi: beli
Lama pengiriman: 0:20:0
Waktu pengolahan makanan: 0:30:0
ID: 3
Nama makanan: kari
Waktu kadaluwarsa: 0:20:0
Lokasi aksi: makan
Lama pengiriman: 0:20:0
Waktu pengolahan makanan: 0:10:0
ID: 2
Nama makanan: nasi
Waktu kadaluwarsa: 0:25:0
Lokasi aksi: kukus
Lama pengiriman: 0:30:0
Waktu pengolahan makanan: 0:15:0
ID: 4
Nama makanan: bubut
Waktu kadaluwarsa: 1:0:0
Lokasi aksi: aduk
Lama pengiriman: 0:15:0
Waktu pengolahan makanan: 9:0:0
#

Masukkan id: 1
Masukkan nama makanan: ayam
Masukkan waktu kadaluwarsa: 0 10 0
Masukkan aksi yang bisa dilakukan: goreng
Masukkan lama pengiriman: 1 0 0
Masukkan waktu pengolahan makanan: 1 0 0
Masukkan id: 2
Masukkan nama makanan: nasi
Masukkan waktu kadaluwarsa: 0 20 0
Masukkan aksi yang bisa dilakukan: kukus
Masukkan lama pengiriman: 1 0 0
Masukkan waktu pengolahan makanan: 3 0 0
Masukkan id: 3
Masukkan nama makanan: kari
Masukkan waktu kadaluwarsa: 0 15 0
Masukkan aksi yang bisa dilakukan: sate
Masukkan lama pengiriman: 0 1 0
Masukkan waktu pengolahan makanan: 1 0 0
Masukkan id: 4
Masukkan nama makanan: bubur
Masukkan waktu kadaluwarsa: 0 40 0
Masukkan aksi yang bisa dilakukan: aduk
Masukkan lama pengiriman: 1 0 0
Masukkan waktu pengolahan makanan: 9 0 0
INVENTORY:
ID: 1
Nama makanan: ayam
Waktu kadaluwarsa: 0:10:0
Lokasi aksi: goreng
Lama pengiriman: 1:0:0
Waktu pengolahan makanan: 1:0:0
ID: 3
Nama makanan: kari
Waktu kadaluwarsa: 0:15:0
Lokasi aksi: sate
Lama pengiriman: 0:1:0
Waktu pengolahan makanan: 1:0:0
ID: 2
Nama makanan: nasi
Waktu kadaluwarsa: 0:20:0
Lokasi aksi: kukus
Lama pengiriman: 1:0:0
Waktu pengolahan makanan: 3:0:0
ID: 4
Nama makanan: bubur
Waktu kadaluwarsa: 0:40:0
Lokasi aksi: aduk
Lama pengiriman: 1:0:0
Waktu pengolahan makanan: 9:0:0
#
Masukkan id makanan yang ingin diambil: 4
Masukkan nama makanan yang ingin diambil: 2
INVENTORY:
ID: 1
Nama makanan: ayam
Waktu kadaluwarsa: 0:10:0
Lokasi aksi: goreng
Lama pengiriman: 1:0:0
Waktu pengolahan makanan: 1:0:0
ID: 3
Nama makanan: kari
Waktu kadaluwarsa: 0:15:0
Lokasi aksi: sate
Lama pengiriman: 0:1:0
Waktu pengolahan makanan: 1:0:0
ID: 2
Nama makanan: nasi
Waktu kadaluwarsa: 0:20:0
Lokasi aksi: kukus
Lama pengiriman: 1:0:0
Waktu pengolahan makanan: 3:0:0
#
Inventory setelah makanan telah di update 10 menit:
INVENTORY:
ID: 3
Nama makanan: kari
Waktu kadaluwarsa: 0:5:0
Lokasi aksi: sate
Lama pengiriman: 0:1:0
Waktu pengolahan makanan: 1:0:0
ID: 2
Nama makanan: nasi
Waktu kadaluwarsa: 0:10:0
Lokasi aksi: kukus
Lama pengiriman: 1:0:0
Waktu pengolahan makanan: 3:0:0
#
Inventory setelah makanan di reverseupdate 10 menit:
INVENTORY:
ID: 3
Nama makanan: kari
Waktu kadaluwarsa: 0:15:0
Lokasi aksi: sate
Lama pengiriman: 0:1:0
Waktu pengolahan makanan: 1:0:0
ID: 2
Nama makanan: nasi
Waktu kadaluwarsa: 0:20:0
Lokasi aksi: kukus
Lama pengiriman: 1:0:0
Waktu pengolahan makanan: 3:0:0
#
INVENTORY:
ID: 1
Nama makanan: ayam
Waktu kadaluwarsa: 0:10:0
Lokasi aksi: goreng
Lama pengiriman: 1:0:0
Waktu pengolahan makanan: 1:0:0
ID: 3
Nama makanan: kari
Waktu kadaluwarsa: 0:15:0
Lokasi aksi: sate
Lama pengiriman: 0:1:0
Waktu pengolahan makanan: 1:0:0
ID: 3
Nama makanan: kari
Waktu kadaluwarsa: 0:15:0
Lokasi aksi: sate
Lama pengiriman: 0:1:0
Waktu pengolahan makanan: 1:0:0
ID: 2
Nama makanan: nasi
Waktu kadaluwarsa: 0:20:0
Lokasi aksi: kukus
Lama pengiriman: 1:0:0
ID: 2
Nama makanan: nasi
Waktu kadaluwarsa: 0:20:0
Lokasi aksi: kukus
Lama pengiriman: 1:0:0
Waktu pengolahan makanan: 3:0:0
ID: 4
Nama makanan: bubur
Waktu kadaluwarsa: 0:40:0
Lokasi aksi: aduk
Lama pengiriman: 1:0:0
Waktu pengolahan makanan: 9:0:0
#
PS C
*/