/* File state.hc*/
/* ADT State */

#include "../../../lib/time/time.h"
#include "../inventory/inventory.h"
#include "../deliverylist/deliverylist.h"
#include "state.h"
#include "../boolean.h"
#include <stdio.h>

/* Konstruktor */
/* I.S. S terdefinisi sembarang, T, I, DL terisi */
/* F.S. S terisi sesuai T, I, DL */
void CreateState(State *S, Peta P, TIME T, Inventory I, DeliveryList DL, ListMakanan expList, ListMakanan deliveredList, ProcessList PL)
{
    PetaState(*S) = P;
    TimeState(*S) = T;
    InventoryState(*S) = I;
    DeliveryListState(*S) = DL;
    ExpListState(*S) = expList;
    DeliveredListState(*S) = deliveredList;
    ProcessedList(*S) = PL;
}

/* Menampilkan State */
void displayState(State S)
{
    printf("Position: (%d, %d)\n", Absis(POINT(PetaState(S))), Ordinat(POINT(PetaState(S))));

    printf("Time: ");
    PrintTime(TimeState(S));

    printf("Inventory user: ");
    displayInventory(InventoryState(S));

    printf("Delivery List user: ");
    displayDeliveryList(DeliveryListState(S));
}