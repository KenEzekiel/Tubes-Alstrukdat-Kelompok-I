#include <stdio.h>
#include "peta.h"
#include "../../../lib/matrix/matrix.h"
#include "../../../lib/wordmachine/wordmachine.h"
#include "../../../lib/wordmachine/charmachine.h"
#include "../../../lib/point/point.h"

int main()
{
    Peta p;
    boolean pllll;
    fileToPeta("../../../test/peta.txt", &PETA(p));
    DisplayPeta(p);
    POINT(p) = cariSimul(p);
    Update(&p, 5);
    MoveEast(&p,&pllll);
    MoveEast(&p,&pllll);
    DisplayPeta(p);
    return 0;
}