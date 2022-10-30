#include <stdio.h>
#include "mekawaktu.h"

void UpdateActionTime(DeliveryList *DL,Inventory *I){
    TIME t;
    CreateTime(&t,0,1,0);
    updateInventory(I,t);
    updateDeliveryList(DL,I,t);
}

void UpdateWaitTime(DeliveryList *DL,Inventory *I, TIME t){
    updateInventory(I,t);
    updateDeliveryList(DL,I,t);
}

void StartTimeSimulator(TIME *t) {
    CreateTime(t,0,0,0);
}

