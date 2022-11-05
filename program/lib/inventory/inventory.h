/* File inventory.h */
/* Definisi ADT Inventory */

#ifndef inventory_H
#define inventory_H

#include "../boolean.h"
#include "../../../lib/queue/prioqueuetime.h"
#include "../../../lib/time/time.h"
#include "../../../lib/makanan/makanan.h"
#include "../listmakanan/listmakanan.h"

/* Definisi Inventory adalah PrioQueueTime */
typedef PrioQueueTime Inventory;

/* *** Konstruktor *** */
void CreateInventory(Inventory *I, int max);

/* *** Operasi menambahkan item ke inventory *** */
/* I.S. Inventory terdefinisi */
/* F.S. food ditambahkan ke inventory sesuai priority nya, inventory di upgrade jika dibutuhkan */
void addMakananToInventory(Inventory *I, prioQueueInfotype food);

/* *** Update makanan di inventory *** */
/* I.S. I terdefinisi, diisi oleh makanan, bisa kosong */
/* F.S. Isi dari I di update */
/* Jika ada makanan yang expired, maka akan di delete */
/* Update semua makanan untuk mengurangi waktu expiration nya sejumlah time */
void updateInventory(Inventory *I, TIME t, ListMakanan *expired);

/* *** Update makanan di inventory *** */
/* I.S. I terdefinisi, diisi oleh makanan, bisa kosong */
/* F.S. Isi dari I di update */
/* Update semua makanan untuk menambah waktu expiration nya sejumlah time */
void reverseUpdateInventory(Inventory *I, TIME t);

/* *** Menghilangkan semua makanan yang expired *** */
/* I.S. I terdefinisi, tidak kosong */
/* F.S. semua makanan yang expired di I (TIME == 0) di delete di HEAD */
void deleteExpired(Inventory *I, ListMakanan *expired);

/* *** Mengurangi waktu dari semua makanan di inventory *** */
/* I.S. I terdefinisi, tidak kosong */
/* F.S. semua makanan dikurangi waktu expired nya sejumlah time,
jika hasil < 0, maka expiration time di set 0*/
void minusTime(Inventory *I, TIME t);

/* *** Menambah waktu dari semua makanan di inventory *** */
/* I.S. I terdefinisi, tidak kosong */
/* F.S. semua makanan ditambah waktu expired nya sejumlah time */
void plusTime(Inventory *I, TIME t);

/* *** Mengambil makanan dari inventory *** */
/* Mengembalikan makanan dari inventory dengan id tertentu */
/* Prekondisi : id makanan harus valid dan id tersebut harus ada didalam inventory */
prioQueueInfotype getMakananById(Inventory *I, int id);

/* *** Mengecek apakah suatu id makanan ada didalam inventory *** */
boolean isElmtById(Inventory I, int id);

/* *** Mengambil makanan dari inventory *** */
/* Mengembalikan makanan dari inventory dengan nama tertentu */
/* Prekondisi : id makanan harus valid dan nama tersebut harus ada didalam inventory */
prioQueueInfotype getMakananByName(Inventory *I, String nama);

/* *** Mengecek apakah suatu nama makanan ada didalam inventory *** */
boolean isElmtByName(Inventory I, String nama);

/* *** Menampilkan isi inventory *** */
void displayInventory(Inventory I);

/* *** Mengembalikan panjang inventory *** */
int lengthInventory(Inventory I);

/* *** Mengembalikan hasil pengecekan apakah inventory perlu di upgrade *** */
/* Upgrade dilakukan jika panjang inventory > 75% maxel nya */
boolean checkInventoryUpgrade(Inventory I);

/* *** Mengupgrade kapasitas dari inventory *** */
/* Perlu dilakukan apakah inventory perlu di upgrade atau tidak terlebih dahulu */
/* Upgrade adalah penambahan kapasitas 2 kali lipat aslinya */
void upgradeInventory(Inventory *I);

#endif