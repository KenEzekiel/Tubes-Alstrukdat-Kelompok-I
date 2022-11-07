#include <stdio.h>
#include "liststatik.h"
#include "../boolean.h"

int main()
{
    ListStatik L, L2, L3;

    printf("input list 1 (n elemen lalu isi list): ");
    readList(&L);
    printf("list length: %d\n", listLength(L));
    printf("first idx: %d\n", getFirstIdx(L));
    printf("last idx: %d\n", getLastIdx(L));

    printf("input idx: ");
    IdxType idx;
    scanf("%d", &idx);
    printf("is idx eff? %d\n", isIdxEff(L, idx));
    printf("is list empty? %d\n", isEmpty(L));
    printf("is list full? %d\n", isFull(L));
    printf("list: \n");
    printList(L);

    printf("\ninput list 2 (ukuran sama dengan list 1): ");
    readList(&L2);

    L3 = plusMinusList(L, L2, true);
    printf("hasil pertambahan list 1 dan list 2: \n");
    printList(L3);

    L3 = plusMinusList(L, L2, false);
    printf("\nhasil pengurangan list 1 dan list 2: \n");
    printList(L3);

    printf("\napakah list 1 dan list 2 sama? %d\n", isListEqual(L, L2));

    ElType elmt;
    printf("input elmt: ");
    scanf("%d", &elmt);

    printf("input idx (harus efektif): ");
    scanf("%d", &idx);

    printf("indeks elemen %d pertama di list 1 adalah: %d\n", elmt, indexOf(L, elmt));

    ElType min, max;
    extremeValues(L, &max, &min);
    printf("min di list 1: %d\nmax di list 1: %d\n", min, max);

    insertFirst(&L, elmt);
    printf("list 1 setelah di insert elmt di idx pertama:\n");
    printList(L);

    insertAt(&L, elmt, idx);
    printf("\nlist 1 setelah di insert elmt di idx:\n");
    printList(L);

    insertLast(&L, elmt);
    printf("\nlist 1 setelah di insert elmt di idx terakhir:\n");
    printList(L);

    deleteLast(&L, &elmt);
    printf("\nlist 1 setelah di delete elmt di idx terakhir:\n");
    printList(L);

    deleteAt(&L, &elmt, idx);
    printf("\nlist 1 setelah di delete elmt di idx:\n");
    printList(L);

    deleteFirst(&L, &elmt);
    printf("\nlist 1 setelah di delete elmt di idx pertama:\n");
    printList(L);

    sortList(&L, true);
    printf("\nlist 1 setelah di sort menaik:\n");
    printList(L);

    sortList(&L, false);
    printf("\nlist 1 setelah di sort menurun:\n");
    printList(L);

    return 0;
}