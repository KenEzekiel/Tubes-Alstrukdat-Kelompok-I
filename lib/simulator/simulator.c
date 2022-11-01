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
void CreateStartSimulator(Simulator *Sim, String user)
{
    // KAMUS LOKAL
    State S;
    TIME Waktu;
    POINT Lokasi;
    Inventory I;
    DeliveryList DL;
    // ALGORITMA
    User(*Sim) = user;

    CreateTime(&Waktu, 0, 0, 0);
    CreatePoint(&Lokasi, 0, 0);
    CreateInventory(&I, 100);
    CreateDeliveryList(&DL, 100);
    CreateState(&S, Lokasi, Waktu, I, DL);
    State(*Sim) = S;
}
/* Membentuk sebuah Simulator dari nama pengguna dengan komponen lain berupa komponen awal */

void CreateSimulator(Simulator *Sim, String user, State S)
{
    User(*Sim) = user;
    State(*Sim) = S;
}
/* Membentuk sebuah Simulator dari komponen-komponennya yang valid */
/* Prekondisi : user, loc, inventory valid untuk membentuk Makanan */

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaSimulator(Simulator *Sim)
{
    String user;
    POINT loc;
    float x, y;
    TIME T;
    Inventory inventory;
    DeliveryList DL;
    State S;

    printf("Masukkan nama user: ");
    readString(&user);

    printf("Masukkan lokasi x y: ");
    scanf("%f %f", &x, &y);
    CreatePoint(&loc, x, y);

    printf("Masukkan time: ");
    BacaTIME(&T);

    CreateInventory(&inventory, 100);
    CreateDeliveryList(&DL, 100);

    CreateState(&S, loc, T, inventory, DL);

    CreateSimulator(Sim, user, S);
}
/* I.S. : Simulator tidak terdefinisi */
/* F.S. : Simulator terdefinisi dan merupakan simulator yang valid */
/* Proses : mengulangi membaca komponen user, loc, inventory sehingga membentuk Simulator */
/* yang valid. Tidak mungkin menghasilkan Simulator yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen user, loc, inventory
   berbeda baris, masing-masing dipisahkan dan diakhiri enter. */

void TulisSimulator(Simulator Sim)
{
    printf("Nama user: ");
    displayString(User(Sim));

    printf("Lokasi saat ini: ");
    printf("(%d, %d)\n", Absis(Position(State(Sim))), Ordinat(Position(State((Sim)))));

    printf("Waktu saat ini: ");
    PrintTime(TimeState(State(Sim)));

    printf("Inventory user: ");
    displayInventory(InventoryState(State((Sim))));

    printf("Delivery List user: ");
    displayDeliveryList(DeliveryListState(State(Sim)));
}
/* I.S. : Simulator sembarang */
/* F.S. : Nilai Simulator ditulis dg format ... */
/* Proses : menulis nilai setiap komponen Simulator ke layar dalam format ...*/