#include "prioqueuetime.h"
#include <stdio.h>
#include "../boolean.h"

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
    Time(x) = 1;
    Info(x) = 'j';
    Time(y) = 2;
    Info(y) = 'd';
    Time(z) = 2;
    Info(z) = 'g';
    Time(a) = 4;
    Info(a) = 'o';
    Enqueue(&Q, x);
    Enqueue(&Q, y);
    Enqueue(&Q, z);
    Enqueue(&Q, a);
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

    return 0;
}