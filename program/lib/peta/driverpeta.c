#include <stdio.h>
#include "peta.h"
#include "../../../lib/matrix/matrix.h"
#include "../../../lib/wordmachine/wordmachine.h"
#include "../../../lib/wordmachine/charmachine.h"
#include "../../../lib/point/point.h"

int main()
{
    Peta p;
    fileToPeta("../../../test/peta.txt", &PETA(p));
    DisplayPeta(p);
    POINT(p) = cariSimul(p);
    Update(&p, 5);
    MoveEast(&p);
    DisplayPeta(p);
    return 0;
}

// gcc -o main lib/matrix/driverpeta.c lib/matrix/peta.c lib/matrix/matrix.c lib/wordmachine/wordmachine.c lib/wordmachine/charmachine.c lib/point/point.c