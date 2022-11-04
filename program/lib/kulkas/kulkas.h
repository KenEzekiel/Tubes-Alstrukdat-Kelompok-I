/* File kulkas.h */
/* Definisi ADT Kulkas */

#ifndef Kulkas_h
#define Kulkas_h

#include "../../../lib/matrix/matrix.h"
#include "../../../lib/makanan/makanan.h"
#include "../../../lib/string/string.h"

#define ELMT_CAP 100

typedef struct
{
    int idx; // top-left index
    Makanan food;
} Tuple;

typedef struct
{
    Tuple T[ELMT_CAP];
    int neff;
} ListTuple;

/* Definisi ADT Kulkas */
typedef struct
{
    Matrix map;
    ListTuple LT;
} Kulkas;

#define IDX(T) (T).idx
#define MAKANAN(T) (T).food
#define TELMT(LT, i) (LT).T[(i)]
#define NEFF(LT) (LT).neff
#define MAP(K) (K).map
#define LISTTUPLE(K) (K).LT

/* Operasi pada Tuple */

void CreateEmptyTuple(Tuple *T);

void CreateTuple(Tuple *T, Makanan food, int idx);

/* Operasi pada ListTuple */

void CreateListTuple(ListTuple *LT, int nrow, int ncol);

void insertFirstLT(ListTuple *LT, Tuple T);

void insertLastLT(ListTuple *LT, Tuple T);

void insertAtLT(ListTuple *LT, Tuple T, int idx);

void deleteFirstLT(ListTuple *LT, Tuple *T);

void deleteLastLT(ListTuple *LT, Tuple *T);

void deleteAtLT(ListTuple *LT, Tuple *T);

void deleteElmtLT(ListTuple *LT, Tuple *T);

void deleteElmtByIdxLT(ListTuple *LT, Tuple *T, int idx);

void deleteElmtByFoodLT(ListTuple *LT, Tuple *T, Makanan food);

/* Operasi pada Kulkas */

void CreateKulkas(Kulkas *K, int nrow, int ncol);

void insertAtIdx(Kulkas *K, int row, int col, Makanan food);

void getFood(Kulkas *K, Makanan *food);

void getFoodByName(Kulkas *K, Makanan *food, String name);

void getFoodById(Kulkas *K, Makanan *food, int id);

#endif