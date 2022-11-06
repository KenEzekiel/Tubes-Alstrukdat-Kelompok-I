/* ********** Definisi TYPE Matrix dengan Index dan elemen integer ********** */

#ifndef MATRIX_H
#define MATRIX_H

#include "../boolean.h"

/* Ukuran maksimum baris dan kolom */
#define ROW_CAP 30
#define COL_CAP 30

typedef int IdxType; /* Index baris, kolom */
typedef char MatrixElType;
typedef struct
{
   MatrixElType mem[ROW_CAP][COL_CAP];
   int rowEff; /* banyaknya/ukuran baris yg terdefinisi */
   int colEff; /* banyaknya/ukuran kolom yg terdefinisi */
} Matrix;

void createMatrix(int nRows, int nCols, Matrix *m);

#define ROW_EFF(M) (M).rowEff
#define COL_EFF(M) (M).colEff
#define ELMT_MATRIX(M, i, j) (M).mem[(i)][(j)]

boolean isMatrixIdxValid(int i, int j);

IdxType getLastIdxRow(Matrix m);

IdxType getLastIdxCol(Matrix m);

boolean isIdxMatrixEff(Matrix m, IdxType i, IdxType j);

void copyMatrix(Matrix mIn, Matrix *mOut);

void readMatrix(Matrix *m, int nRow, int nCol);

void displayMatrix(Matrix m);

#endif