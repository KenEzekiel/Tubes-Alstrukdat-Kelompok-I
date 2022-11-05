/* File kulkas.c */
/* Definisi ADT Kulkas */

#include "kulkas.h"
#include <stdio.h>

/*
#define IDX(T) (T).idx
#define MAKANAN(T) (T).food
#define ROWUKURAN(T) MAKANAN(T).nrow
#define COLUKURAN(T) MAKANAN(T).ncol
#define TELMT(LT, i) (LT).T[(i)]
#define NEFF(LT) (LT).neff
#define MAP(K) (K).map
#define LISTTUPLE(K) (K).LT
*/

/* Operasi pada Tuple */

/* *** Konstruktor *** */
/* Membuat Tuple yang diisi dengan makanan food dan indeks idx */
void CreateTuple(Tuple *T, Makanan food, int idxrow, int idxcol, int idkulkas)
{
    MAKANAN(*T) = food;
    IDXROW(*T) = idxrow;
    IDXCOL(*T) = idxcol;
    IDKULKAS(*T) = idkulkas;
}

void displayTuple(Tuple T)
{
    printf("id kulkas : %d\n", IDKULKAS(T));
    displayString(Nama(MAKANAN(T)));
    printf("\n%d, %d \n", IDXROW(T), IDXCOL(T));
}

/* Operasi pada ListTuple */

/* *** Konstruktor *** */
/* Membuat List Tuple kosong */
void CreateListTuple(ListTuple *LT)
{
    NEFF(*LT) = 0;
}

/* Menambahkan elemen Tuple di depan List Tuple */
void insertFirstLT(ListTuple *LT, Tuple T)
{
    // KAMUS LOKAL
    int i;
    // ALGORITMA
    if (NEFF(*LT) == 0)
    {
        TELMT(*LT, 0) = T;
    }
    else
    {
        for (i = NEFF(*LT); i > 0; i--)
        {
            TELMT(*LT, i) = TELMT(*LT, i - 1);
        }
        TELMT(*LT, 0) = T;
    }
}

void insertLastLT(ListTuple *LT, Tuple T)
{
    TELMT(*LT, NEFF(*LT)) = T;
    NEFF(*LT) = NEFF(*LT) + 1;
}

void insertAtLT(ListTuple *LT, Tuple T, int idx)
{
    // KAMUS LOKAL
    int i;
    // ALGORITMA
    if (idx == 0)
    {
        insertFirstLT(LT, T);
    }
    else if (idx == NEFF(*LT) - 1)
    {
        insertLastLT(LT, T);
    }
    else
    {
        for (i = NEFF(*LT); i > idx; i--)
        {
            TELMT(*LT, i) = TELMT(*LT, i - 1);
        }
        TELMT(*LT, idx) = T;
    }
}

void deleteFirstLT(ListTuple *LT, Tuple *T)
{
    // KAMUS LOKAL
    int i;
    // ALGORITMA
    *T = TELMT(*LT, 0);
    for (i = 0; i < NEFF(*LT) - 1; i++)
    {
        TELMT(*LT, i) = TELMT(*LT, i + 1);
    }
    NEFF(*LT) = NEFF(*LT) - 1;
}

void deleteLastLT(ListTuple *LT, Tuple *T)
{
    // KAMUS LOKAL

    // ALGORITMA
    *T = TELMT(*LT, NEFF(*LT) - 1);
    NEFF(*LT) = NEFF(*LT) - 1;
}

void deleteAtLT(ListTuple *LT, Tuple *T, int idx)
{
    // KAMUS LOKAL
    int i;
    // ALGORITMA

    if (idx == 0)
    {
        deleteFirstLT(LT, T);
    }
    else if (idx == NEFF(*LT) - 1)
    {
        deleteLastLT(LT, T);
    }
    else
    {
        *T = TELMT(*LT, idx);
        for (i = idx; i < NEFF(*LT) - 1; i++)
        {
            TELMT(*LT, i) = TELMT(*LT, i + 1);
        }
        NEFF(*LT) = NEFF(*LT) - 1;
    }
}

void deleteElmtLT(ListTuple *LT, Tuple *T)
{
    // KAMUS LOKAL
    int idxrow = IDXROW(*T);
    int idxcol = IDXCOL(*T);
    Makanan food = MAKANAN(*T);
    int id = IDKULKAS(*T);
    boolean found = false;
    int i = 0;
    Tuple element;
    // ALGORITMA
    while (i < NEFF(*LT) && !found)
    {
        element = TELMT(*LT, i);
        if (IDKULKAS(element) == id && IDXROW(element) == idxrow && IDXCOL(element) == idxcol)
        {
            found = true;
            deleteAtLT(LT, T, i);
        }
        else
        {
            i++;
        }
    }
}

void deleteElmtByFoodLT(ListTuple *LT, Tuple *T, Makanan food)
{
    // KAMUS LOKAL
    int id = ID(food);
    boolean found = false;
    int i = 0;
    Tuple element;
    // ALGORITMA
    while (i < NEFF(*LT) && !found)
    {
        element = TELMT(*LT, i);
        if (ID(MAKANAN(element)) == id)
        {
            found = true;
            deleteAtLT(LT, T, i);
        }
        else
        {
            i++;
        }
    }
}

void displayListTuple(ListTuple LT)
{
    // KAMUS LOKAL
    int i;
    // ALGORITMA
    printf("[\n\n");
    for (i = 0; i < NEFF(LT); i++)
    {
        displayTuple(TELMT(LT, i));
        printf("\n");
    }
    printf("]\n");
}

int ElmtIdxInLT(ListTuple LT, Tuple T)
{
    // KAMUS LOKAL
    int idxrow = IDXROW(T);
    int idxcol = IDXCOL(T);
    Makanan food = MAKANAN(T);
    int id = IDKULKAS(T);
    boolean found = false;
    int i = 0;
    Tuple element;
    // ALGORITMA
    while (i < NEFF(LT) && !found)
    {
        element = TELMT(LT, i);
        if (IDKULKAS(element) == id && IDXROW(element) == idxrow && IDXCOL(element) == idxcol)
        {
            found = true;
        }
        else
        {
            i++;
        }
    }
    return i;
}

int ElmtIdxInLTByIdKulkas(ListTuple LT, int idkulkas)
{
    // KAMUS LOKAL
    boolean found = false;
    int i = 0;
    Tuple element;
    // ALGORITMA
    while (i < NEFF(LT) && !found)
    {
        element = TELMT(LT, i);
        if (IDKULKAS(element) == idkulkas)
        {
            found = true;
        }
        else
        {
            i++;
        }
    }
    return i;
}

/* Operasi pada Kulkas */

void CreateKulkas(Kulkas *K, int nrow, int ncol)
{
    // KAMUS LOKAL
    int i, j;
    // ALGORITMA
    createMatrix(nrow, ncol, &MAP(*K));
    CreateListTuple(&LISTTUPLE(*K));
    for (i = 0; i < nrow; i++)
    {
        for (j = 0; j < ncol; j++)
        {
            ELMT_MATRIX(MAP(*K), i, j) = 'O';
        }
    }
}

boolean isIdxKosong(Kulkas K, int irow, int icol)
{
    return (ELMT_MATRIX(MAP(K), irow, icol) == 'O');
}

/* row dan col adalah indeks paling kiri atas */
void insertAtIdx(Kulkas *K, int row, int col, Makanan food, int idkulkas, boolean *valid)
{
    // KAMUS LOKAL
    int i, j;
    boolean kosong = true;
    Tuple T;
    // ALGORITMA
    // Cek apakah tempatnya mencukupi
    i = row;
    while (i < row + SizeBaris(food) && kosong)
    {
        j = col;
        while (j < col + SizeKolom(food) && kosong)
        {
            if (!isIdxKosong(*K, i, j))
            {
                kosong = false;
            }
            j++;
        }
        i++;
    }

    if (!kosong)
    {
        printf("Slot tidak bisa diisi\n");
        *valid = false;
    }
    else
    {
        CreateTuple(&T, food, row, col, idkulkas);
        for (i = row; i < row + SizeBaris(food); i++)
        {
            for (j = col; j < col + SizeKolom(food); j++)
            {
                ELMT_MATRIX(MAP(*K), i, j) = 'X';
            }
        }
        insertLastLT(&LISTTUPLE(*K), T);
        *valid = true;
    }
}

void getFoodbyIdKulkas(Kulkas *K, Makanan *food, int idkulkas)
{
    // KAMUS LOKAL
    int i, j;
    int row, col;
    int idx = ElmtIdxInLTByIdKulkas(LISTTUPLE(*K), idkulkas);
    Tuple element;
    // ALGORITMA
    row = SizeBaris(*food);
    col = SizeKolom(*food);
    *food = MAKANAN(TELMT(LISTTUPLE(*K), idx));
    deleteAtLT(&LISTTUPLE(*K), &element, idx);
    for (i = row; i < row + SizeBaris(*food); i++)
    {
        for (j = col; j < col + SizeKolom(*food); j++)
        {
            ELMT_MATRIX(MAP(*K), i, j) = 'O';
        }
    }
}

void displayKulkas(Kulkas K)
{
    // KAMUS LOKAL

    // ALGORITMA
    printf("Mapping Kulkas: \n");
    displayMatrix(MAP(K));
    printf("Isi Kulkas: \n");
    displayListTuple(LISTTUPLE(K));
}

void procInsertToKulkas(Kulkas *K, Inventory *I)
{
    // KAMUS LOKAL
    int i;
    int id, idxrow, idxcol, idkulkas;
    Makanan food;
    boolean valid;

    // ALGORITMA
    displayInventory(*I);
    displayKulkas(*K);
    printf("Masukkan id makanan yang ingin dimasukkan ke kulkas: ");
    STARTWORD();
    id = WordToInt(currentWord);

    printf("Masukkan indeks baris paling atas di kulkas: ");
    STARTWORD();
    idxrow = WordToInt(currentWord);

    printf("Masukkan indeks kolom paling kiri di kulkas: ");
    STARTWORD();
    idxcol = WordToInt(currentWord);

    printf("Masukkan id makanan di kulkas: ");
    STARTWORD();
    idkulkas = WordToInt(currentWord);

    food = getMakananById(I, id);
    insertAtIdx(K, idxrow, idxcol, food, idkulkas, &valid);
    if (!valid)
    {
        Enqueue(I, food);
    }

    displayInventory(*I);
    displayKulkas(*K);
}

void procGetFromKulkas(Kulkas *K, Inventory *I)
{
    // KAMUS LOKAL
    int i;
    int idkulkas, idxrow, idxcol;
    Makanan food;

    // ALGORITMA
    displayInventory(*I);
    displayKulkas(*K);
    printf("Masukkan id makanan di kulkas yang ingin diambil dari kulkas: ");
    STARTWORD();
    idkulkas = WordToInt(currentWord);

    getFoodbyIdKulkas(K, &food, idkulkas);
    printf("1\n");
    Enqueue(I, food);
    printf("2\n");

    displayInventory(*I);
    displayKulkas(*K);
}
