/* File: simulator.h */
/* Implementasi ADT SIMULATOR */

#include "../boolean.h"
#include "../string/string.h"
#include "../point/point.h"
#include "../queue/prioqueuetime.h"
#include "simulator.h"
#include <stdio.h>

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */

/* *** Konstruktor: Membentuk sebuah Makanan dari komponen-komponennya *** */
void CreateStartSimulator (Simulator * Sim, String user){
    User(*Sim) = user;
    Absis(Loc(*Sim)) = 0;
    Ordinat(Loc(*Sim)) = 0;
    MakeEmpty(&Inventory(*Sim), 100);
}
/* Membentuk sebuah Simulator dari nama pengguna dengan komponen lain berupa komponen awal */

void CreateSimulator (Simulator * Sim, String user, POINT loc, PrioQueueTime inventory){
    User(*Sim) = user;
    Loc(*Sim) = loc;
    Inventory(*Sim) = inventory;
}
/* Membentuk sebuah Simulator dari komponen-komponennya yang valid */
/* Prekondisi : user, loc, inventory valid untuk membentuk Makanan */

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaSimulator (Simulator * Sim){
    String user;
    POINT loc;
    PrioQueueTime inventory;

    readString(&user);
    BacaPOINT(&loc);
    MakeEmpty(&inventory, 100);
    
    CreateSimulator(Sim, user, loc, inventory);

}
/* I.S. : Simulator tidak terdefinisi */
/* F.S. : Simulator terdefinisi dan merupakan simulator yang valid */
/* Proses : mengulangi membaca komponen user, loc, inventory sehingga membentuk Simulator */
/* yang valid. Tidak mungkin menghasilkan Simulator yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen user, loc, inventory
   berbeda baris, masing-masing dipisahkan dan diakhiri enter. */
   
void TulisSimulator (Simulator Sim){
    printf("Nama user: ");
    displayString(User(Sim));
    printf("Lokasi saat ini: ");
    TulisPOINT(Loc(Sim));
    printf("Inventory user: ");
    PrintPrioQueueTime(Inventory(Sim));
}
/* I.S. : Simulator sembarang */
/* F.S. : Nilai Simulator ditulis dg format ... */
/* Proses : menulis nilai setiap komponen Simulator ke layar dalam format ...*/ 