#include <stdio.h>
#include "matrix.h"

int main() {
    MatrixElType var;
    Matrix m;
    createMatrix(2,2,&m);
    for (int i = 0; i<ROW_EFF(m);i++) {
        for (int j = 0; j<COL_EFF(m); j++){
            scanf("%d",&var);
            ELMT_MATRIX(m,i,j) = var;
        }
    }
    displayMatrix(m);
}