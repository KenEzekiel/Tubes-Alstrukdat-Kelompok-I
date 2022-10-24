/* File: simulator.h */
/* Definisi ADT SIMULATOR */

#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "../boolean.h"
#include "../string/string.h"
#include "../point/point.h"
#include "../queue/prioqueuetime.h"

/* *** Definisi TYPE Makanan <id, nama, exp, aksi, delivTime> *** */
typedef struct { 
	String user;
    POINT loc;
    PrioQueueTime inventory;
} Simulator;

/* *** Notasi Akses: selektor Simulator *** */
#define User(Sim) (Sim).user 
#define Loc(Sim) (Sim).loc 
#define Inventory(Sim) (Sim).inventory 


/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsSimulatorValid (String user, POINT loc, PrioQueueTime inventory);
/* Mengirim true jika user, loc, inventory dapat membentuk Simulator yang valid */

/* *** Konstruktor: Membentuk sebuah Makanan dari komponen-komponennya *** */
void CreateStartSimulator (Simulator * Sim, String user);
/* Membentuk sebuah Simulator dari nama pengguna dengan komponen lain berupa komponen awal */

void CreateSimulator (Simulator * Sim, String user, POINT loc, PrioQueueTime inventory);
/* Membentuk sebuah Simulator dari komponen-komponennya yang valid */
/* Prekondisi : user, loc, inventory valid untuk membentuk Makanan */

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaSimulator (Simulator * Sim);
/* I.S. : Simulator tidak terdefinisi */
/* F.S. : Simulator terdefinisi dan merupakan simulator yang valid */
/* Proses : mengulangi membaca komponen user, loc, inventory sehingga membentuk Simulator */
/* yang valid. Tidak mungkin menghasilkan Simulator yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen user, loc, inventory
   berbeda baris, masing-masing dipisahkan dan diakhiri enter. */
   
void TulisSimulator (Simulator Sim);
/* I.S. : Food sembarang */
/* F.S. : Nilai Food ditulis dg format ... */
/* Proses : menulis nilai setiap komponen Food ke layar dalam format ...*/ 

#endif