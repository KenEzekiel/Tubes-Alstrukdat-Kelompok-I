#include "../inventory/inventory.h"
#include "../deliverylist/deliverylist.h"
#include "../boolean.h"


void StartTimeSimulator(TIME *t);
void UpdateActionTime(DeliveryList *DL,Inventory *I);
void UpdateWaitTime(DeliveryList *DL,Inventory *I, TIME t);



