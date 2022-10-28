#include "../boolean.h"
#include <stdio.h>
#include "string.h"
#include "../wordmachine/wordmachine.h"
#include "../wordmachine/charmachine.h"

int main()
{
    String s;

    readString(&s);
    printf("String masukan: ");
    displayString(s);
    printf("Apakah string kosong? %d\n", isStringEmpty(s));
    printf("Apakah string penuh? %d\n", isStringFull(s));
    printf("Panjang string: %d\n", length(s));
    String rev;
    rev = reverse(s);
    printf("String jika dibalik: ");
    displayString(rev);
    printf("Apakah string palindrom? %d\n", isStringEqual(s, rev));

    char elmt;
    int idx;
    printf("Masukkan element: ");
    scanf(" %c", &elmt);

    insertSFirst(&s, elmt);
    printf("string setelah di insert elmt di idx pertama:\n");
    displayString(s);

    printf("Masukkan indeks: ");
    scanf("%d", &idx);
    insertSAt(&s, elmt, idx);
    printf("\nstring setelah di insert elmt di idx:\n");
    displayString(s);

    insertSLast(&s, elmt);
    printf("\nstring setelah di insert elmt di idx terakhir:\n");
    displayString(s);

    deleteSLast(&s, &elmt);
    printf("\nstring setelah di delete elmt di idx terakhir:\n");
    displayString(s);

    printf("Masukkan indeks:");
    scanf("%d", &idx);
    deleteSAt(&s, &elmt, idx);
    printf("\nstring setelah di delete elmt di idx:\n");
    displayString(s);

    deleteSFirst(&s, &elmt);
    printf("\nstring setelah di delete elmt di idx pertama:\n");
    displayString(s);

        return 0;
}