#include <stdio.h>
#include "mekawaktu.h"

void UpdateActionTime(State *S){
    TIME t;
    CreateTime(&t,0,0,1);
    updateProcessList(&ProcessedList(*S),&InventoryState(*S),t, &DeliveredListState(*S));
    updateDeliveryList(&DeliveryListState(*S),&InventoryState(*S),t, &DeliveredListState(*S));
    updateInventory(&InventoryState(*S),t, &ExpListState(*S));
    UpdateGlobalTime(&TimeState(*S),t);
}

void UpdateWaitTime(State *S, TIME t){
    updateProcessList(&ProcessedList(*S),&InventoryState(*S),t, &DeliveredListState(*S));
    updateDeliveryList(&DeliveryListState(*S),&InventoryState(*S),t, &DeliveredListState(*S));
    updateInventory(&InventoryState(*S),t, &ExpListState(*S));
    UpdateGlobalTime(&TimeState(*S),t);
}

void UpdateGlobalTime(TIME *t, TIME t2) {
    int temp;
    temp = TIMEToMenit(*t) + TIMEToMenit(t2);
    *t = MenitToTIME(temp);
}

void StartTimeSimulator(TIME *t) {
    CreateTime(t,0,0,0);
}


