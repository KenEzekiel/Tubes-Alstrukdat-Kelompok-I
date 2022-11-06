#include "set.h"
#include <stdio.h>

void CreateSet(Set *S)
{
    /*I.S. Set tidak terdefinisi*/
    /*F.S. Terbentuk Set kosong*/
    int i;
    /*ALGORITMA*/
    for (i = 0; i < SETCAPACITY; i++)
    {
        ELMT_S(*S, i) = 0;
    }
    lengthS(*S) = 0;
}

boolean isEmptySet(Set S)
{
    /*Memeriksa apakah set kosong atau tidak*/
    return (lengthS(S) == 0);
}

int lengthSet(Set S)
{
    /*Menghasilkan panjang dari Set*/
    return lengthS(S);
}

boolean IsIn(Set S, SEltype val)
{
    /*Menghasilkan nilai true apabila val ada di dalam set*/
    int i;
    boolean found = false;
    while (i < lengthSet(S))
    {
        if (ELMT_S(S, i) == val)
        {
            found = true;
        }
    }
    return found;
}
void add(Set *S, SEltype val)
{
    /*I.S. Sebuah Set, boleh kosong*/
    /*F.S. Set yang telah ditambahkan elemen val*/
    ELMT_S(*S, val) = 1;
}

void copy(Set *S1, Set *S2)
{
    /*I.S. Set S1 tidak terdefinisi, S2 terdefinisi*/
    /*F.S. Menyalin isi S2 ke S1 sehingga S1=S2*/
    for (int i = 0; i < lengthS(*S2); i++)
    {
        ELMT_S(*S1, i) = ELMT_S(*S2, i);
    }
}

boolean isSubset(Set S1, Set S2)
{
    /*Menghasilkan true apabila S1 adalah subset dari S2*/
    boolean sama = true;
    for (int i = 0; i < lengthS(S1); i++)
    {
        if (ELMT_S(S1, i) == 1)
        {
            if (ELMT_S(S2, i) != 1)
            {
                sama = false;
            }
        }
    }
    return sama;
}