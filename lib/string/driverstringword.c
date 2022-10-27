#include "../boolean.h"
#include <stdio.h>
#include "string.h"
#include "../wordmachine/wordmachine.h"
#include "../wordmachine/charmachine.h"

int main()
{
    int retval;
    STARTWORD();
    String a = wordToString(currentWord);
    displayString(a);

    String b;
    procwordToString(currentWord, &b);
    displayString(b);

    return 0;
}