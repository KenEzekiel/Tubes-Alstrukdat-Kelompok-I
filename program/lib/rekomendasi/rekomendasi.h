#ifndef REC_H
#define REC_H

#include "../listmakanan/listmakanan.h"
#include "../resep/resep.h"
#include "../../../lib/set/set.h"
#include "../inventory/inventory.h"
#include "../boolean.h"


Set inventorySet(Inventory *I, ListMakanan LM);

void initializeSet(Set *S, ListMakanan LM); 

Set resepSet(Tree *t, ListMakanan LM);

void cekTreeSubset(ListMakanan *recom, ListMakanan LM, Tree *t, Set invSet);

void rekomendasiMakanan(ListMakanan *recom, ListMakanan LM, Inventory *I, ResepTree Resep);

void printRekomendasiMakanan(ListMakanan LM, Inventory *I, ResepTree Resep);

#endif