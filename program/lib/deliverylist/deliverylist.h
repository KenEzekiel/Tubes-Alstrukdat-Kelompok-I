/* File deliverylist.h */
/* Definisi ADT Delivery List */

#ifndef delivlist_H
#define delivlist_H

#include "../../../lib/queue/prioqueuetime.h"
#include "../inventory/inventory.h"
#include "../boolean.h"
#include "../../../lib/time/time.h"
#include "../../../lib/makanan/makanan.h"
#include "../../../lib/string/string.h"
#include "../../../lib/liststatik/liststatik.h"
#include "../listmakanan/listmakanan.h"

/* *** Definisi DeliveryList adalah PrioQueueTime *** */
typedef PrioQueueTime DeliveryList;

/* *** Konstruktor *** */
void CreateDeliveryList(DeliveryList *DL, int max);

/* *** Operasi Penambahan Makanan *** */
/* I.S. Simulator sedang berada di sebelah B, dan makanan yang dibeli sudah valid */
/* F.S. Makanan dimasukkan kedalam DeliveryList */
void buyMakanan(DeliveryList *DL, Makanan food);

/* *** Operasi Penambahan Makanan dengan id makanan *** */
/* I.S. Simulator sedang berada di sebelah B, id makanan yang dibeli sudah valid */
/* F.S. Makanan dengan id tertentu di List dimasukkan ke dalam DeliveryList */
/* Delivery list di upgrade jika dibutuhkan */
void buyMakananbyId(DeliveryList *DL, int id, ListMakanan L);

/* *** Operasi Penambahan Makanan dengan nama makanan *** */
/* I.S. Simulator sedang berada di sebelah B, dan nama makanan yang dibeli sudah valid */
/* F.S. Makanan dengan nama tertentu di List dimasukkan kedalam DeliveryList */
/* Delivery list di upgrade jika dibutuhkan */
void buyMakananbyName(DeliveryList *DL, String nama, ListMakanan L);

/* *** Mengembalikan hasil pengecekan apakah makanan ada dalam list makanan *** */
boolean isMakananValid(Makanan food, ListMakanan L);

/* *** Mengembalikan hasil pengecekan apakah makanan ada dalam list makanan berdasarkan id *** */
boolean isMakananValidbyId(int id, ListMakanan L);

/* *** Mengembalikan hasil pengecekan apakah makanan ada dalam list makanan berdasarkan nama *** */
boolean isMakananValidbyName(String nama, ListMakanan L);

/* *** Update DeliveryList dan Inventory *** */
/* I.S. DeliveryList dan Inventory terdefinisi sembarang */
/* F.S. Isi dari DL dan I di update */
/* Jika ada makanan yang sudah 0 delivery time nya, akan dimasukkan ke I dan dikeluarkan dari DL*/
/* Update semua makanan untuk mengurangi waktu delivery time nya sebesar t */
void updateDeliveryList(DeliveryList *DL, Inventory *I, TIME t);

/* *** Update DeliveryList dan Inventory *** */
/* I.S. DeliveryList dan Inventory terdefinisi sembarang */
/* F.S. Isi dari DL dan I di update */
/* Update semua makanan untuk menambah waktu delivery time nya sebesar t */
void reverseUpdateDeliveryList(DeliveryList *DL, Inventory *I, TIME t);

/* *** Mengirim semua makanan yang delivery time nya sudah 0 *** */
/* I.S. DL terdefinisi dan tidak kosong */
/* F.S. Semua makanan yang delivery time nya sudah 0 didelete dari DL dan di masukkan ke I*/
void deliver(DeliveryList *DL, Inventory *I);

/* *** Mengurangi waktu dari delivery time semua makanan sebesar t *** */
/* I.S. DL terdefinisi, tidak kosong */
/* F.S. semua makanan dikurangi delivery time nya sebesar t
jika hasil < 0, maka delivery time di set 0 */
void minusDelivTime(DeliveryList *DL, TIME t);

/* *** Menambah waktu dari delivery time semua makanan sebesar t *** */
/* I.S. DL terdefinisi, tidak kosong */
/* F.S. semua makanan ditambah delivery time nya sebesar t */
void plusDelivTime(DeliveryList *DL, TIME t);

/* *** Menampilkan isi Delivery List *** */
void displayDeliveryList(DeliveryList DL);

/* *** Mengembalikan panjang inventory *** */
int lengthDeliveryList(DeliveryList DL);

/* *** Mengembalikan hasil pengecekan apakah delivery list perlu di upgrade *** */
/* Upgrade dilakukan jika panjang delivery list > 75% maxel nya */
boolean checkUpgrade(DeliveryList DL);

/* *** Mengupgrade kapasitas dari delivery list *** */
/* Perlu dilakukan apakah delivery list perlu di upgrade atau tidak terlebih dahulu */
/* Upgrade adalah penambahan kapasitas 2 kali lipat aslinya */
void upgradeDelivList(DeliveryList *DL);

#endif