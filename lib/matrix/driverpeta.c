#include <stdio.h>
#include "peta.c"
#include "matrix.c"
#include "../wordmachine/wordmachine.c"
#include "../wordmachine/charmachine.c"
#include "../point/point.c"

int main() {
    Peta p;
    fileToPeta("../../test/peta.txt", &PETA(p));
    DisplayPeta(p);
    POINT(p) = cariSimul(p);
    Update(&p,5);
    MoveEast(&p);
    DisplayPeta(p);
    return 0;
}