#ifndef REC_H
#define REC_H

#include "../listmakanan/listmakanan.h"
#include "../resep/resep.h"
#include "../../../lib/set/set.h"
#include "../inventory/inventory.h"
#include "../boolean.h"


Set inventorySet(Inventory *I, ListMakanan LM);

void initializeSet(Set *S, ListMakanan LM); 


#endif