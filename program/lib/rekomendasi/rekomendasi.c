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
}

// Set resepSet(Tree *t, ListMakanan LM)
// {
//     Set S;
//     CreateSet(&S);

//     for (int i = 0; i < TREECOUNT(*t); i++)
//     {
//         int childIdx = indexOfID(LM, ROOT(SUBTREE(*t,i)));
//         ELMT_S(S, childIdx) = 1;
//     }
// }

// void printRekomendasiMakanan(ListMakanan LM, Inventory *I, ResepTree Resep)
// {
//     Set setR1, setR2, setI;
//     boolean found = false;
//     int idx;
//     int no = 1;
//     Tree root, subtree;

//     CreateSet(&setR1);
//     CreateSet(&setR2);
//     CreateSet(&setI);

//     setI = inventorySet(I, LM);
    
//     print_cyan("Rekomendasi makanan buat kamu ;)\n");

//     for (int i = 0; i < RESEPCOUNT(Resep); i++)
//     {
//         root = TREE(Resep, i);
//         setR1 = resepSet(&root, LM);
//         if (isSubset(setR1, setI))
//         {
//             found = true;
//             printf("%d. ", no);
//             no++;
//             idx = indexOfID(LM, ROOT(root));
//             displayString(Nama(ELMT_LM(LM, idx)));
//             printf("\n");
//         }
//         subtree = SUBTREE(root, i);
//         for (int i = 0; i < TREECOUNT(root); i++)
//         {
//             if(!HasNoChild(subtree))
//             {
//                 setR2 = resepSet(&subtree, LM);
//                 if (isSubset(setR2, setI))
//                 {
//                     found = true;
//                     printf("%d. ", no);
//                     no++;
//                     idx = indexOfID(LM, ROOT(subtree));
//                     displayString(Nama(ELMT_LM(LM, idx)));
//                     printf("\n");
//                 }
//             }
//         }

//     }

//     if(!found)
//     {
//         print_red("Belum ada rekomendasi yang pas, nih! Beli bahan dulu, yuk :D\n");
//     }
// }

