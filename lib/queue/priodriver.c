#include "prioqueuetime.h"
#include <stdio.h>
#include "../boolean.h"
#include "../makanan/makanan.h"
#include "../time/time.h"

int main()
{
    PrioQueueTime Q;
    infotype x, y, z, a;
    MakeEmpty(&Q, 5);

    /*for (int i = 10; i > 0; i--)
    {
        printf("%d ", i);
        Time(x) = i;
        Info(x) = i;
        Enqueue(&Q, x);
    }*/
    BacaMakanan(&x);
    BacaMakanan(&y);
    BacaMakanan(&z);
    BacaMakanan(&a);
    Enqueue(&Q, x);
    Enqueue(&Q, y);
    Enqueue(&Q, z);
    Enqueue(&Q, a);
    printf("Apakah Q kosong? %d\n", IsEmpty(Q));
    printf("Apakah Q penuh? %d\n", IsFull(Q));
    printf("Jumlah elemen Q? %d\n", NBElmt(Q));
    printf("is x element Q? %d\n", isElmt(Q, x));
    deleteElmt(&Q, &x);
    printf("is x element Q setelah di delete? %d\n", isElmt(Q, x));
    Dequeue(&Q, &y);
    TulisMakanan(y);
    /*Dequeue(&Q, &x);
    printf("removed elmt x : %d\n", Time(x));
    printf("idx head : %d\t idx tail : %d\n", Head(Q), Tail(Q));
    Enqueue(&Q, a);
    printf("idx head : %d\t idx tail : %d\n", Head(Q), Tail(Q));
    Enqueue(&Q, a);
    printf("idx head : %d\t idx tail : %d\n", Head(Q), Tail(Q));
    Dequeue(&Q, &y);
    printf("idx head : %d\t idx tail : %d\n", Head(Q), Tail(Q));
    Dequeue(&Q, &z);
    printf("idx head : %d\t idx tail : %d\n", Head(Q), Tail(Q));
    Enqueue(&Q, x);
    printf("idx head : %d\t idx tail : %d\n", Head(Q), Tail(Q));
    Dequeue(&Q, &x);
    // harusnya idx head 5 sampe sini
    printf("idx head 5 : %d\t idx tail : %d\n", Head(Q), Tail(Q));
    Enqueue(&Q, x);
    printf("idx head : %d\t idx tail : %d\n", Head(Q), Tail(Q));
    Dequeue(&Q, &x);
    printf("idx head : %d\t idx tail : %d\n", Head(Q), Tail(Q));
    Enqueue(&Q, x);
    printf("idx head : %d\t idx tail : %d\n", Head(Q), Tail(Q));
    Dequeue(&Q, &x);
    printf("idx head : %d\t idx tail : %d\n", Head(Q), Tail(Q));
    Enqueue(&Q, x);
    printf("idx head : %d\t idx tail : %d\n", Head(Q), Tail(Q));
    Enqueue(&Q, x);
    printf("idx head : %d\t idx tail : %d\n", Head(Q), Tail(Q));*/
    PrintPrioQueueTime(Q);
    DeAlokasi(&Q);

    return 0;
}