#ifndef OLAHMAKANAN_H
#define OLAHMAKANAN_H

#include "../../../lib/queue/queue.h"
#include "../../../lib/string/string.h"
#include "../../../lib/matrix/matrix.h"
#include "../../../lib/liststatik/liststatik.h"
#include "../../../lib/point/point.h"
#include "../listmakanan/listmakanan.h"
#include "../inventory/inventory.h"
#include "../resep/resep.h"
#include "../deliverylist/deliverylist.h"
#include <stdio.h>

typedef PrioQueueTime ProcessList;

/*I.S. lfiltered sembarang*/
/*F.S. lfiltered yang berisi elemen-elemen dari lfood yang dapat dilakukan aksi*/

ListMakanan listNeeded(int id, ResepTree Resep, ListMakanan lfood);

boolean isAvailable(Inventory I, ListMakanan lneed);
/*mengembalikan nilai true apabila semua bahan yang diperlukan untuk memproses makanan tersedia*/

void process(int id, Inventory *I, ListMakanan lneed, ListMakanan lfiltered, ProcessList *P);
/*I.S. lfiltered sembarang, lfood*/
/*F.S. jika semua bahan tersedia, bahan makanan yang dibuat bertambah dan bahan makanan yang diperlukan berkurang di inventory,
       jika ada bahan yang tidak tersedia, menampilkan bahan-bahan yang tidak tersedia tersebut*/
void CreateProcessMakanan(ProcessList *P,int max);

void updateProcessList(ProcessList *P, Inventory *I, TIME t, ListMakanan *delivered, ListMakanan *expired);

void updateProcessTime(ProcessList *P, TIME t, Inventory *I, ListMakanan *delivered, ListMakanan *expired);

void plusProcessTime(ProcessList *P, TIME t);

int lengthProcessList(ProcessList P);

boolean checkProcessUpgrade(ProcessList P);

void upgradeProcessList(ProcessList *P);

void displayProcessList(ProcessList P);

void addProcessList(ProcessList *PL, prioQueueInfotype food);

void delivproc(ProcessList *DL, Inventory *I, ListMakanan *delivered);

#endif