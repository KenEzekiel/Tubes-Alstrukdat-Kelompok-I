#include "../inventory/inventory.h"
#include "../deliverylist/deliverylist.h"
#include "../boolean.h"

void StartTimeSimulator(TIME *t);
void UpdateActionTime(DeliveryList *DL, Inventory *I, TIME *tglob);
void UpdateGlobalTime(TIME *t, TIME t2);
void UpdateWaitTime(DeliveryList *DL, Inventory *I, TIME t, TIME *tglob);