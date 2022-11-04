#include <stdio.h>
#include "mekawaktu.h"

void UpdateActionTime(DeliveryList *DL,Inventory *I, TIME *tglob, ListMakanan *expired, ListMakanan *delivered){
    TIME t;
    CreateTime(&t,0,1,0);
    updateInventory(I,t, expired);
    updateDeliveryList(DL,I,t, delivered);
    UpdateGlobalTime(tglob,t);
}

void UpdateWaitTime(DeliveryList *DL,Inventory *I, TIME t, TIME *tglob, ListMakanan *expired, ListMakanan *delivered){
    updateInventory(I,t, expired);
    updateDeliveryList(DL,I,t, delivered);
    UpdateGlobalTime(tglob,t);
}

void UpdateGlobalTime(TIME *t, TIME t2) {
    int temp;
    temp = TIMEToMenit(*t) + TIMEToMenit(t2);
    *t = MenitToTIME(temp);
}

void StartTimeSimulator(TIME *t) {
    CreateTime(t,0,0,0);
}


