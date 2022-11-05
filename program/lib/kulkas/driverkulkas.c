#include "kulkas.h"

int main()
{
    Inventory Q;
    ListMakanan expired;
    prioQueueInfotype x, y, z, a;
    Kulkas K;
    CreateInventory(&Q, 4);
    CreateListMakanan(&expired);

    BacaMakanan(&x);
    BacaMakanan(&y);
    BacaMakanan(&z);
    //BacaMakanan(&a);
    addMakananToInventory(&Q, x);
    addMakananToInventory(&Q, y);
    addMakananToInventory(&Q, z);
    //addMakananToInventory(&Q, a);

    displayInventory(Q);

    CreateKulkas(&K, 10, 20);

    procInsertToKulkas(&K, &Q);
    procInsertToKulkas(&K, &Q);
    procInsertToKulkas(&K, &Q);

    procGetFromKulkas(&K, &Q);
    procGetFromKulkas(&K, &Q);
    procGetFromKulkas(&K, &Q);

    return 0;
}