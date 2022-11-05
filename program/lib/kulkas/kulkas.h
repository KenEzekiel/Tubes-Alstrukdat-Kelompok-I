/* File kulkas.h */
/* Definisi ADT Kulkas */

#ifndef Kulkas_h
#define Kulkas_h

#include "../../../lib/matrix/matrix.h"
#include "../../../lib/makanan/makanan.h"
#include "../../../lib/string/string.h"
#include "../../lib/inventory/inventory.h"
#include "../../../lib/wordmachine/charmachine.h"
#include "../../../lib/wordmachine/wordmachine.h"

#define ELMT_CAP 100

typedef struct
{
    int idxrow; // top-left index di kulkas
    int idxcol;
    Makanan food;
    int idkulkas; // id harus unik
} Tuple;

typedef struct
{
    Tuple T[ELMT_CAP];
    int neff; // jumlah elemen efektif
} ListTuple;

/* Definisi ADT Kulkas */
typedef struct
{
    Matrix map;
    ListTuple LT;
} Kulkas;

#define IDXROW(T) (T).idxrow
#define IDXCOL(T) (T).idxcol
#define IDKULKAS(T) (T).idkulkas
#define MAKANAN(T) (T).food
#define ROWUKURAN(T) MAKANAN(T).nrow
#define COLUKURAN(T) MAKANAN(T).ncol
#define TELMT(LT, i) (LT).T[(i)]
#define NEFF(LT) (LT).neff
#define MAP(K) (K).map
#define LISTTUPLE(K) (K).LT

/* Operasi pada Tuple */

/* *** Konstruktor *** */
/* Membuat Tuple yang diisi dengan makanan food dan indeks idx */
void CreateTuple(Tuple *T, Makanan food, int idxrow, int idxcol, int idkulkas);

void displayTuple(Tuple T);

/* Operasi pada ListTuple */

/* *** Konstruktor *** */
/* Membuat List Tuple kosong */
void CreateListTuple(ListTuple *LT);

/* Menambahkan elemen Tuple di depan List Tuple */
void insertFirstLT(ListTuple *LT, Tuple T);

void insertLastLT(ListTuple *LT, Tuple T);

void insertAtLT(ListTuple *LT, Tuple T, int idx);

void deleteFirstLT(ListTuple *LT, Tuple *T);

void deleteLastLT(ListTuple *LT, Tuple *T);

void deleteAtLT(ListTuple *LT, Tuple *T, int idx);

void deleteElmtLT(ListTuple *LT, Tuple *T);

void deleteElmtByFoodLT(ListTuple *LT, Tuple *T, Makanan food);

void displayListTuple(ListTuple LT);

int ElmtIdxInLT(ListTuple LT, Tuple T);

int ElmtIdxInLTByIdKulkas(ListTuple LT, int idkulkas);

/* Operasi pada Kulkas */

void CreateKulkas(Kulkas *K, int nrow, int ncol);

boolean isIdxKosong(Kulkas K, int irow, int icol);

void insertAtIdx(Kulkas *K, int row, int col, Makanan food, int idkulkas);

void getFoodbyIdKulkas(Kulkas *K, Makanan *food, int idkulkas);

void displayKulkas(Kulkas K);

void procInsertToKulkas(Kulkas *K, Inventory *I);

void procGetFromKulkas(Kulkas *K, Inventory *I);

#endif