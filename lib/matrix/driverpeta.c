#include <stdio.h>
#include "peta.c"
#include "matrix.c"
#include "../wordmachine/wordmachine.c"
#include "../wordmachine/charmachine.c"
#include "../point/point.c"

int main() {
    Peta p;
    PETA(p) = fileToPeta("../../test/peta.txt");
    DisplayPeta(p);
}