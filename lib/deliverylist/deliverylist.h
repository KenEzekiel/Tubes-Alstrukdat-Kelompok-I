/* File deliverylist.h */
/* Definisi ADT Delivery List */

#ifndef delivlist_H
#define delivlist_H

#include "../queue/prioqueuetime.h"
#include "../inventory/inventory.h"
#include "../boolean.h"
#include "../time/time.h"
#include "../makanan/makanan.h"
#include "../string/string.h"
#include "../liststatik/liststatik.h"

/* *** Definisi DeliveryList adalah PrioQueueTime *** */
typedef PrioQueueTime DeliveryList;

/* *** Operasi Penambahan Makanan *** */
/* I.S. Simulator sedang berada di sebelah B, dan makanan yang dibeli sudah valid */
/* F.S. Makanan dimasukkan kedalam DeliveryList */
void buyMakanan(DeliveryList *DL, Makanan food);

/* *** Operasi Penambahan Makanan dengan id makanan *** */
/* I.S. Simulator sedang berada di sebelah B, id makanan yang dibeli sudah valid */
/* F.S. Makanan dengan id tertentu di List dimasukkan ke dalam DeliveryList */
void buyMakananbyId(DeliveryList *DL, int id, ListStatik L);

/* *** Operasi Penambahan Makanan dengan nama makanan *** */
/* I.S. Simulator sedang berada di sebelah B, dan nama makanan yang dibeli sudah valid */
/* F.S. Makanan dengan nama tertentu di List dimasukkan kedalam DeliveryList */
void buyMakananbyName(DeliveryList *DL, String nama, ListStatik L);

/* *** Mengembalikan hasil pengecekan apakah makanan ada dalam list makanan *** */
boolean isMakananValid(Makanan food, ListStatik L);

/* *** Mengembalikan hasil pengecekan apakah makanan ada dalam list makanan berdasarkan id *** */
boolean isMakananValidbyId(int id, ListStatik L);

/* *** Mengembalikan hasil pengecekan apakah makanan ada dalam list makanan berdasarkan nama *** */
boolean isMakananValidbyName(String nama, ListStatik L);

/* *** Update DeliveryList dan Inventory *** */
/* I.S. DeliveryList dan Inventory terdefinisi sembarang */
/* F.S. Isi dari DL dan I di update*/
/* Jika ada makanan yang sudah 0 delivery time nya, akan dimasukkan ke I dan dikeluarkan dari DL*/
/* Update semua makanan untuk mengurangi waktu delivery time nya sebesar t */
void updateDeliveryList(DeliveryList *DL, Inventory *I, TIME t);

/* *** Mengirim semua makanan yang delivery time nya sudah 0 *** */
/* I.S. DL terdefinisi dan tidak kosong */
/* F.S. Semua makanan yang delivery time nya sudah 0 didelete dari DL dan di masukkan ke I*/
void deliver(DeliveryList *DL, Inventory *I);

/* *** Mengurangi waktu dari delivery time semua makanan sebesar t *** */
/* I.S. DL terdefinisi, tidak kosong */
/* F.S. semua makanan dikurangi delivery time nya sebesar t
jika hasil < 0, maka delivery time di set 0 */
void minusDelivTime(DeliveryList *DL, TIME t);

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