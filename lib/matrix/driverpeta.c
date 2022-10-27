#include <stdio.h>
#include "peta.h"
#include "matrix.h"
#include "../wordmachine/wordmachine.c"
#include "../wordmachine/charmachine.c"
#include "../point/point.c"

int main() {
    Peta p;
    fileToPeta("../../test/peta.txt", &PETA(p));
    DisplayPeta(p);
}