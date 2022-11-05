/* File: simulator.h */
/* Definisi ADT SIMULATOR */

#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "../boolean.h"
#include "../string/string.h"
#include "../point/point.h"
#include "../time/time.h"
#include "../../program/lib/inventory/inventory.h"
#include "../../program/lib/deliverylist/deliverylist.h"
#include "../queue/prioqueuetime.h"
#include "../../program/lib/state/state.h"
#include "../../program/lib/olahmakanan/olahmakanan.h"

/* *** Definisi TYPE Makanan <id, nama, exp, aksi, delivTime> *** */
typedef struct
{
    String user;
    State S;
} Simulator;

/* *** Notasi Akses: selektor Simulator *** */
#define User(Sim) (Sim).user
#define State(Sim) (Sim).S

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */

/* *** Konstruktor: Membentuk sebuah Makanan dari komponen-komponennya *** */
void CreateStartSimulator(Simulator *Sim, String user);
/* Membentuk sebuah Simulator dari nama pengguna dengan komponen lain berupa komponen awal */

void CreateSimulator(Simulator *Sim, String user, State S);
/* Membentuk sebuah Simulator dari komponen-komponennya yang valid */
/* Prekondisi : user, loc, inventory valid untuk membentuk Makanan */

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaSimulator(Simulator *Sim);
/* I.S. : Simulator tidak terdefinisi */
/* F.S. : Simulator terdefinisi dan merupakan simulator yang valid */
/* Proses : mengulangi membaca komponen user, loc, inventory sehingga membentuk Simulator */
/* yang valid. Tidak mungkin menghasilkan Simulator yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen user, loc, inventory
   berbeda baris, masing-masing dipisahkan dan diakhiri enter. */

void TulisSimulator(Simulator Sim);
/* I.S. : Food sembarang */
/* F.S. : Nilai Food ditulis dg format ... */
/* Proses : menulis nilai setiap komponen Food ke layar dalam format ...*/

#endif