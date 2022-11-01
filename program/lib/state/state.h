/* File state.h */
/* ADT State */

#ifndef state_H
#define state_H

#include "../../../lib/time/time.h"
#include "../../../lib/point/point.h"
#include "../inventory/inventory.h"
#include "../deliverylist/deliverylist.h"
#include "../boolean.h"

/* Definisi ADT State */
typedef struct state
{
    POINT P;
    TIME T;
    Inventory I;
    DeliveryList DL;
} State;

/* Definisi Selektor */
#define Position(S) (S).P
#define TimeState(S) (S).T
#define InventoryState(S) (S).I
#define DeliveryListState(S) (S).DL

/* Konstruktor */
/* I.S. S terdefinisi sembarang, T, I, DL terisi */
/* F.S. S terisi sesuai T, I, DL */
void CreateState(State *S, POINT P, TIME T, Inventory I, DeliveryList DL);

#endif