#include "../inventory/inventory.h"
#include "../deliverylist/deliverylist.h"
#include "../listmakanan/listmakanan.h"
#include "../olahmakanan/olahmakanan.h"
#include "../boolean.h"

void StartTimeSimulator(TIME *t);
void UpdateActionTime(DeliveryList *DL, Inventory *I, TIME *tglob, ListMakanan *expired, ListMakanan *delivered, ProcessList *PL);
void UpdateGlobalTime(TIME *t, TIME t2);
void UpdateWaitTime(DeliveryList *DL, Inventory *I, TIME t, TIME *tglob, ListMakanan *expired, ListMakanan *delivered,ProcessList *PL);