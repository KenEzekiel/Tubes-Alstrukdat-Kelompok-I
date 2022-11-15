#include <stdio.h>
#include "point.h"

int main() {
    POINT p;
    CreatePoint(&p,1,1);
    printf("%d,%d", Absis(p),Ordinat(p));

    MoveN(&p);
    printf("%d,%d", Absis(p),Ordinat(p));

    MoveE(&p);
    printf("%d,%d", Absis(p),Ordinat(p));

    MoveS(&p);
    printf("%d,%d", Absis(p),Ordinat(p));

    MoveW(&p);
    printf("%d,%d", Absis(p),Ordinat(p));
}
