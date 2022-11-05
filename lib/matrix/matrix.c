// NAMA : ALEX SANDER
// NIM : 13521061
// TOPIK : ADT MATRIX


#include "matrix.h"
#include <stdio.h>
#include "../boolean.h"
#include <math.h>
/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void createMatrix(int nRows, int nCols, Matrix *m){
    ROW_EFF(*m) = nRows;
    COL_EFF(*m) = nCols;

}
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */


/* *** Selektor "Dunia Matrix" *** */
boolean isMatrixIdxValid(int i, int j){
    return (0<=i && i< ROW_CAP && 0<=j && j<COL_CAP);
}
/* Mengirimkan true jika i, j adalah index yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IdxType getLastIdxRow(Matrix m){
    return (ROW_EFF(m)-1);
}
/* Mengirimkan Index baris terbesar m */
IdxType getLastIdxCol(Matrix m){
    return (COL_EFF(m)-1);
}
/* Mengirimkan Index kolom terbesar m */
boolean isIdxMatrixEff(Matrix m, IdxType i, IdxType j){
    return (0<=j && j<COL_EFF(m) && 0<=i && i<ROW_EFF(m));
}
/* Mengirimkan true jika i, j adalah Index efektif bagi m */

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mOut){
    createMatrix(ROW_EFF(mIn),COL_EFF(mIn),mOut);
    for (int i = 0; i<ROW_EFF(mIn);i++) {
        for (int j = 0; j<COL_EFF(mIn);j++) {
            ELMT_MATRIX(*mOut,i,j) = ELMT_MATRIX(mIn,i,j);
        }
    }
}
/* Melakukan assignment mOut <- mIn */

/* ********** KELOMPOK BACA/TULIS ********** */
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
void displayMatrix(Matrix m){
    for (int i = 0; i<ROW_EFF(m);i++) {
        for (int j = 0; j<COL_EFF(m);j++) {
            if (j == 0) {
                printf("%c", ELMT_MATRIX(m,i,j));
            }
            else {
                printf(" %c", ELMT_MATRIX(m,i,j));
            }
        }
        printf("\n");
    }
}
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */

/* I.S. m terdefinisi, k terdefinisi */
/* F.S. Mengalikan setiap elemen m dengan k */

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
