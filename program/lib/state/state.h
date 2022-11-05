/* File state.h */
/* ADT State */

#ifndef state_H
#define state_H

#include "../../../lib/time/time.h"
#include "../../../lib/point/point.h"
#include "../inventory/inventory.h"
#include "../deliverylist/deliverylist.h"
#include "../listmakanan/listmakanan.h"
#include "../olahmakanan/olahmakanan.h"
#include "../peta/peta.h"
#include "../boolean.h"

/* Definisi ADT State */
typedef struct state
{
    Peta P;
    TIME T;
    Inventory I;
    DeliveryList DL;
    ProcessList PL;
    ListMakanan expiredList;
    ListMakanan deliveredList;
} State;

/* Definisi Selektor */
#define PetaState(S) (S).P
#define TimeState(S) (S).T
#define InventoryState(S) (S).I
#define DeliveryListState(S) (S).DL
#define ExpListState(S) (S).expiredList
#define DeliveredListState(S) (S).deliveredList
#define ProcessedList(S) (S).PL

/* Konstruktor */
/* I.S. S terdefinisi sembarang, T, I, DL terisi */
/* F.S. S terisi sesuai T, I, DL */
void CreateState(State *S, Peta P, TIME T, Inventory I, DeliveryList DL, ListMakanan expList, ListMakanan deliveredList, ProcessList PL);

/* Menampilkan State */
void displayState(State S);

#endif