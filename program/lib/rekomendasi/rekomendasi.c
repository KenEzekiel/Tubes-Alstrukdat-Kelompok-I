#include "rekomendasi.h"
#include <stdio.h>
#include "../utility/utility.h"

Set inventorySet(Inventory *I, ListMakanan LM)
{
    /* KAMUS */
    Set S;
    int id;

    /* ALGORITMA */
    CreateSet(&S);

    for(int i = 0; i < listMakananLength(LM); i++)
    {
        ELMT_S(S, i) = 0;
        id = ID(ELMT_LM(LM, i));
        if (isElmtById(*I, id))
        {
            ELMT_S(S, i) = 1;
        }
    }
    lengthS(S) = listMakananLength(LM);
    return S;
}

void initializeSet(Set *S, ListMakanan LM) 
{
    for (int i = 0; i < listMakananLength(LM); i++)
    {
        ELMT_S(*S, i) = 0;
    }
    lengthS(*S) = listMakananLength(LM);
}

Set resepSet(Tree *t, ListMakanan LM)
{
    Set S;
    CreateSet(&S);
    initializeSet(&S, LM);

    for (int i = 0; i < TREECOUNT(*t); i++)
    {
        int childIdx = indexOfID(LM, ROOT(SUBTREE(*t,i)));
        ELMT_S(S, childIdx) = 1;
    }

    return S;
}

// void rekomendasiTingkat(ListMakanan *recom, ListMakanan LM, Tree *t, Set invSet, Set *treeSet)
// {
    
// }

void cekTreeSubset(ListMakanan *recom, ListMakanan LM, Tree *t, Set invSet)
{
    Set treeSet;
    CreateSet(&treeSet);
    treeSet = resepSet(t, LM);
    if (isSubset(treeSet, invSet))
    {
        int idx = indexOfID(LM, ROOT(*t));
        insertLastMakanan(recom, ELMT_LM(LM, idx));
    }
    // else 
    // {
    //     rekomendasiTingkat(recom, LM, t, invSet, &treeSet);
    // }
    for (int i = 0; i < TREECOUNT(*t); i++)
    {
        if (!HasNoChild(SUBTREE(*t,i)))
        {
            cekTreeSubset(recom, LM, &SUBTREE(*t,i),invSet);
        }
    }
}

void rekomendasiMakanan(ListMakanan *recom, ListMakanan LM, Inventory *I, ResepTree Resep)
{
    Set setI;
    CreateSet(&setI);
    setI = inventorySet(I, LM);
    for (int i = 0; i < RESEPCOUNT(Resep); i++)
    {
        cekTreeSubset(recom, LM, &TREE(Resep, i), setI);
    }
}

void printRekomendasiMakanan(ListMakanan LM, Inventory *I, ResepTree Resep)
{
    int no = 1;
    print_blue("\n====================REKOMENDASI====================\n");
    print_cyan("Rekomendasi makanan buat kamu ;)\n");

    ListMakanan recom;
    CreateListMakanan(&recom);
    rekomendasiMakanan(&recom, LM, I, Resep);

    if(listMakananLength(recom) == 0)
    {
        print_red("Belum ada rekomendasi yang pas, nih! Beli bahan dulu, yuk :D\n");
    }
    else
    {
        for (int i = 0; i < listMakananLength(recom); i++)
        {
            printf("%d. ", no);
            no++;
            displayString(Nama(ELMT_LM(recom, i)));
            printf("\n");
        }
    }
}



