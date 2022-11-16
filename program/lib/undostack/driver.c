#include "undostack.h"

int main()
{
    stackaddr sa = CreateUndoStackEmpty();
    printf("Is Undo stack empty? %d\n", IsUndoStackEmpty(sa));
    printf("Is Undo stack full? %d\n", IsUndoStackFull(sa));

    // KAMUS LOKAL
    State S;
    TIME Waktu;
    POINT Lokasi;
    Inventory I;
    DeliveryList DL;
    ListMakanan expired, delivered;
    ProcessList PL;
    // ALGORITMA

    CreateTime(&Waktu, 1, 2, 3);
    CreatePoint(&Lokasi, 0, 0);
    CreateInventory(&I, 50);
    CreateDeliveryList(&DL, 50);
    CreateListMakanan(&expired);
    CreateListMakanan(&delivered);
    CreateProcessMakanan(&PL, 50);
    CreateState(&S, Lokasi, Waktu, I, DL, expired, delivered, PL);

    PushUndoStack(sa, S);
    PopUndoStack(sa, &S);
    displayState(S);
    ClearUndoStack(sa);
    return 0;
}