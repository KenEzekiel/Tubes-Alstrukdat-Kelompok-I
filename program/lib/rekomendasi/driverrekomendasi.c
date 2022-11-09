#include "rekomendasi.h"
#include <stdio.h>

int main()
{
    ListMakanan lm;
    CreateListMakanan(&lm);
    lm = readListMakanan("../../../test/makanan.txt");
    printCatalog(lm);

	ResepTree Resep;
	ReadFromFile(&Resep, 10, "../../../test/resep_2.txt");
    PrintResep(&lm, &Resep);

    Makanan a,b,c;
    a = ELMT_LM(lm, 0);
    b = ELMT_LM(lm, 1);
    c = ELMT_LM(lm, 3);

    Inventory Q;
    CreateInventory(&Q,3);
    addMakananToInventory(&Q, a);
    addMakananToInventory(&Q, b);
    addMakananToInventory(&Q, c);

    displayInventory(Q);

    printf("Tes Rekomendasi Makanan\n");
    printRekomendasiMakanan(lm, &Q, Resep);

    return 0;
}