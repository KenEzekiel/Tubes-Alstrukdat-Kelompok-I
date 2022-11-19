#include "set.h"
#include <stdio.h>

int main(){
    Set S1,S2;
    CreateSet(&S1);
    CreateSet(&S2);
    add(&S1,1);
    add(&S1,3);
    printSet(S1);
    copy(&S2,&S1);
    add(&S2,4);
    add(&S2,4);
    add(&S2,7);
    printSet(S2);
    printf("Is S1 subset of S2? %d", isSubset(S1,S2) );
    return 0;
}