#include "inventory.h"
#include "../boolean.h"
#include "../queue/prioqueuetime.h"
#include "../time/time.h"
#include "../makanan/makanan.h"
#include <stdio.h>

int main()
{
    Inventory Q;
    infotype x, y, z, a;
    MakeEmpty(&Q, 5);

    BacaMakanan(&x);
    BacaMakanan(&y);
    BacaMakanan(&z);
    BacaMakanan(&a);
    Enqueue(&Q, x);
    Enqueue(&Q, y);
    Enqueue(&Q, z);
    Enqueue(&Q, a);

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

    updateInventory(&Q, t);

    printf("Inventory setelah makanan telah di update 10 menit: \n");
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