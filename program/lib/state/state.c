/* File state.hc*/
/* ADT State */

#include "../../../lib/time/time.h"
#include "../inventory/inventory.h"
#include "../deliverylist/deliverylist.h"
#include "state.h"
#include "../boolean.h"

/* Konstruktor */
/* I.S. S terdefinisi sembarang, T, I, DL terisi */
/* F.S. S terisi sesuai T, I, DL */
void CreateState(State *S, POINT P, TIME T, Inventory I, DeliveryList DL)
{
    Position(*S) = P;
    TimeState(*S) = T;
    InventoryState(*S) = I;
    DeliveryListState(*S) = DL;
}
