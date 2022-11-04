#ifndef OLAHMAKANAN_H
#define OLAHMAKANAN_H

#include "../../lib/queue/queue.h"
#include "../../lib/string/string.h"
#include "../../lib/matrix/matrix.h"
#include "../../lib/liststatik/liststatik.h"
#include "../../lib/point/point.h"
#include "../listmakanan/listmakanan.h"
#include "../inventory/inventory.h"
#include "../resep/resep.h"
#include <stdio.h>

void displayMakananFiltered(String aksi, ListMakanan *lfood, ListMakanan *lfiltered);
/*I.S. lfiltered sembarang*/
/*F.S. lfiltered yang berisi elemen-elemen dari lfood yang dapat dilakukan aksi*/

boolean isBahanAvailable(ListMakanan lfood, ListMakanan lneed);
/*mengembalikan nilai true apabila semua bahan yang diperlukan untuk memproses makanan tersedia*/

void process(String aksi,int i, ListMakanan *lfood, ListMakanan *lfiltered, Inventory *I, ResepTree Resep);
/*I.S. lfiltered sembarang, lfood*/
/*F.S. jika semua bahan tersedia, bahan makanan yang dibuat bertambah dan bahan makanan yang diperlukan berkurang di inventory,
       jika ada bahan yang tidak tersedia, menampilkan bahan-bahan yang tidak tersedia tersebut*/

#endif