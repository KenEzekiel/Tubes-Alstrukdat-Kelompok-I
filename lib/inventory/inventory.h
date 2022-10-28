#include "../boolean.h"
#include "../queue/prioqueuetime.h"
#include "../time/time.h"
#include "../makanan/makanan.h"

/* Definisi Inventory adalah PrioQueueTime */
typedef PrioQueueTime Inventory;

/* *** Update makanan di inventory *** */
/* I.S. I terdefinisi, diisi oleh makanan, bisa kosong */
/* F.S. Isi dari I di update */
/* Jika ada makanan yang expired, maka akan di delete */
/* Update semua makanan untuk mengurangi waktu expiration nya sejumlah time */
void updateInventory(Inventory *I, TIME t);

/* *** Menghilangkan semua makanan yang expired *** */
/* I.S. I terdefinisi, tidak kosong */
/* F.S. semua makanan yang expired di I (TIME == 0) di delete di HEAD */
void deleteExpired(Inventory *I);

/* *** Mengurangi waktu dari semua makanan di inventory *** */
/* I.S. I terdefinisi, tidak kosong */
/* F.S. semua makanan dikurangi waktu expired nya sejumlah time,
jika hasil < 0, maka expiration time di set 0*/
void minusTime(Inventory *I, TIME t);

/* *** Mengambil makanan dari inventory *** */
/* Mengembalikan makanan dari inventory dengan id tertentu */
/* Prekondisi : id makanan harus valid dan id tersebut harus ada didalam inventory */
infotype getMakananById(Inventory *I, int id);

/* *** Mengecek apakah suatu id makanan ada didalam inventory *** */
boolean isElmtById(Inventory I, int id);

/* *** Mengambil makanan dari inventory *** */
/* Mengembalikan makanan dari inventory dengan nama tertentu */
/* Prekondisi : id makanan harus valid dan nama tersebut harus ada didalam inventory */
infotype getMakananByName(Inventory *I, String nama);

/* *** Mengecek apakah suatu nama makanan ada didalam inventory *** */
boolean isElmtByName(Inventory I, String nama);