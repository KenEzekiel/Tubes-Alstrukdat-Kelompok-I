#include <stdio.h>
#include "../utility/utility.h"
#include "../deliverylist/deliverylist.h"
#include "olahmakanan.h"

int main()
{
    String aksiChop, aksiMix, aksiFry, aksiBoil;
    charToString("CHOP",&aksiChop,4);
    charToString("BOIL",&aksiBoil,4);
    charToString("MIX",&aksiMix,3);
    charToString("FRY",&aksiFry,3);

    ListMakanan lm;
    CreateListMakanan(&lm);
    lm = readListMakanan("../../../test/makanan.txt");

	ResepTree Resep;
	ReadFromFile(&Resep, 10, "../../../test/resep_2.txt");

    Makanan a,b,c;
    a = ELMT_LM(lm, 14);
    b = ELMT_LM(lm, 1);
    c = ELMT_LM(lm, 3);

    Inventory Q;
    CreateInventory(&Q,3);
    addMakananToInventory(&Q, a);
    addMakananToInventory(&Q, b);
    addMakananToInventory(&Q, c);
    displayInventory(Q);

    printf("Tes Makanan Filtered\n");
    ListMakanan lfiltered;
    CreateListMakanan(&lfiltered);
    printf("Makanan yang dibuat dengan chop\n");
    displayFilteredAksi(aksiChop, lm, &lfiltered);
    printf("Makanan yang dibuat dengan boil\n");
    displayFilteredAksi(aksiBoil, lm, &lfiltered);
    printf("Makanan yang dibuat dengan fry\n");
    displayFilteredAksi(aksiFry, lm, &lfiltered);
    printf("Makanan yang dibuat dengan mix\n");
    displayFilteredAksi(aksiMix, lm, &lfiltered);
    
    ListMakanan lneed = listNeeded(ID(a), Resep, lm);
    ProcessList P;
    CreateProcessMakanan(&P, 50);
    process(ID(a), &Q, lneed, lfiltered, &P);
    return 0;
}