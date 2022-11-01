#include <stdio.h>
#include "mekawaktu.h"

void UpdateActionTime(DeliveryList *DL,Inventory *I, TIME *tglob){
    TIME t;
    CreateTime(&t,0,1,0);
    updateInventory(I,t);
    updateDeliveryList(DL,I,t);
    UpdateGlobalTime(tglob,t);
}

void UpdateWaitTime(DeliveryList *DL,Inventory *I, TIME t, TIME *tglob){
    updateInventory(I,t);
    updateDeliveryList(DL,I,t);
    UpdateGlobalTime(tglob,t);
}

void UpdateGlobalTime(TIME *t, TIME t2) {
    int temp;
    temp = TIMEToDetik(*t) + TIMEToDetik(t2);
    *t = DetikToTIME(temp);
}

void StartTimeSimulator(TIME *t) {
    CreateTime(t,0,0,0);
}

