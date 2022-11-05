
#include "peta.h"
#include <stdio.h>
#include <stdlib.h>
#include "../../../lib/wordmachine/wordmachine.h"

void Update(Peta *m, int P)
{
    switch (P)
    {
    case 1:
        ELMT_MATRIX(PETA(*m), Absis(POINT(*m)) + 1, Ordinat(POINT(*m))) = '.';
        ELMT_MATRIX(PETA(*m), Absis(POINT(*m)), Ordinat(POINT(*m))) = 'S';

        if (Ordinat(POINT(*m)) - 1 >= 0)
        {
            NORTH(*m) = ELMT_MATRIX(PETA(*m), Absis(POINT(*m)) - 1, Ordinat(POINT(*m)));
        }
        else
        {
            NORTH(*m) = ' ';
        }
        if (Ordinat(POINT(*m)) + 1 < ROW_EFF(PETA(*m)))
        {
            SOUTH(*m) = ELMT_MATRIX(PETA(*m), Absis(POINT(*m)) + 1, Ordinat(POINT(*m)));
        }
        else
        {
            SOUTH(*m) = ' ';
        }
        if (Absis(POINT(*m)) + 1 < COL_EFF(PETA(*m)))
        {
            EAST(*m) = ELMT_MATRIX(PETA(*m), Absis(POINT(*m)), Ordinat(POINT(*m)) + 1);
        }
        else
        {
            EAST(*m) = ' ';
        }
        if (Absis(POINT(*m)) - 1 >= 0)
        {
            WEST(*m) = ELMT_MATRIX(PETA(*m), Absis(POINT(*m)), Ordinat(POINT(*m)) - 1);
        }
        else
        {
            WEST(*m) = ' ';
        }
        break;
    case 2:
        ELMT_MATRIX(PETA(*m), Absis(POINT(*m)), Ordinat(POINT(*m)) - 1) = '.';
        ELMT_MATRIX(PETA(*m), Absis(POINT(*m)), Ordinat(POINT(*m))) = 'S';

        if (Ordinat(POINT(*m)) - 1 >= 0)
        {
            NORTH(*m) = ELMT_MATRIX(PETA(*m), Absis(POINT(*m)) - 1, Ordinat(POINT(*m)));
        }
        else
        {
            NORTH(*m) = ' ';
        }
        if (Ordinat(POINT(*m)) + 1 < ROW_EFF(PETA(*m)))
        {
            SOUTH(*m) = ELMT_MATRIX(PETA(*m), Absis(POINT(*m)) + 1, Ordinat(POINT(*m)));
        }
        else
        {
            SOUTH(*m) = ' ';
        }
        if (Absis(POINT(*m)) + 1 < COL_EFF(PETA(*m)))
        {
            EAST(*m) = ELMT_MATRIX(PETA(*m), Absis(POINT(*m)), Ordinat(POINT(*m)) + 1);
        }
        else
        {
            EAST(*m) = ' ';
        }
        if (Absis(POINT(*m)) - 1 >= 0)
        {
            WEST(*m) = ELMT_MATRIX(PETA(*m), Absis(POINT(*m)), Ordinat(POINT(*m)) - 1);
        }
        else
        {
            WEST(*m) = ' ';
        }
        break;
    case 3:
        ELMT_MATRIX(PETA(*m), Absis(POINT(*m)) - 1, Ordinat(POINT(*m))) = '.';
        ELMT_MATRIX(PETA(*m), Absis(POINT(*m)), Ordinat(POINT(*m))) = 'S';

        if (Ordinat(POINT(*m)) - 1 >= 0)
        {
            NORTH(*m) = ELMT_MATRIX(PETA(*m), Absis(POINT(*m)) - 1, Ordinat(POINT(*m)));
        }
        else
        {
            NORTH(*m) = ' ';
        }
        if (Ordinat(POINT(*m)) + 1 < ROW_EFF(PETA(*m)))
        {
            SOUTH(*m) = ELMT_MATRIX(PETA(*m), Absis(POINT(*m)) + 1, Ordinat(POINT(*m)));
        }
        else
        {
            SOUTH(*m) = ' ';
        }
        if (Absis(POINT(*m)) + 1 < COL_EFF(PETA(*m)))
        {
            EAST(*m) = ELMT_MATRIX(PETA(*m), Absis(POINT(*m)), Ordinat(POINT(*m)) + 1);
        }
        else
        {
            EAST(*m) = ' ';
        }
        if (Absis(POINT(*m)) - 1 >= 0)
        {
            WEST(*m) = ELMT_MATRIX(PETA(*m), Absis(POINT(*m)), Ordinat(POINT(*m)) - 1);
        }
        else
        {
            WEST(*m) = ' ';
        }
        break;
    case 4:
        ELMT_MATRIX(PETA(*m), Absis(POINT(*m)), Ordinat(POINT(*m)) + 1) = '.';
        ELMT_MATRIX(PETA(*m), Absis(POINT(*m)), Ordinat(POINT(*m))) = 'S';

        if (Ordinat(POINT(*m)) - 1 >= 0)
        {
            NORTH(*m) = ELMT_MATRIX(PETA(*m), Absis(POINT(*m)) - 1, Ordinat(POINT(*m)));
        }
        else
        {
            NORTH(*m) = ' ';
        }
        if (Ordinat(POINT(*m)) + 1 < ROW_EFF(PETA(*m)))
        {
            SOUTH(*m) = ELMT_MATRIX(PETA(*m), Absis(POINT(*m)) + 1, Ordinat(POINT(*m)));
        }
        else
        {
            SOUTH(*m) = ' ';
        }
        if (Absis(POINT(*m)) + 1 < COL_EFF(PETA(*m)))
        {
            EAST(*m) = ELMT_MATRIX(PETA(*m), Absis(POINT(*m)), Ordinat(POINT(*m)) + 1);
        }
        else
        {
            EAST(*m) = ' ';
        }
        if (Absis(POINT(*m)) - 1 >= 0)
        {
            WEST(*m) = ELMT_MATRIX(PETA(*m), Absis(POINT(*m)), Ordinat(POINT(*m)) - 1);
        }
        else
        {
            WEST(*m) = ' ';
        }
        break;
    case 5:
        if (Ordinat(POINT(*m)) - 1 >= 0)
        {
            NORTH(*m) = ELMT_MATRIX(PETA(*m), Absis(POINT(*m)) - 1, Ordinat(POINT(*m)));
        }
        else
        {
            NORTH(*m) = ' ';
        }
        if (Ordinat(POINT(*m)) + 1 < ROW_EFF(PETA(*m)))
        {
            SOUTH(*m) = ELMT_MATRIX(PETA(*m), Absis(POINT(*m)) + 1, Ordinat(POINT(*m)));
        }
        else
        {
            SOUTH(*m) = ' ';
        }
        if (Absis(POINT(*m)) + 1 < COL_EFF(PETA(*m)))
        {
            EAST(*m) = ELMT_MATRIX(PETA(*m), Absis(POINT(*m)), Ordinat(POINT(*m)) + 1);
        }
        else
        {
            EAST(*m) = ' ';
        }
        if (Absis(POINT(*m)) - 1 >= 0)
        {
            WEST(*m) = ELMT_MATRIX(PETA(*m), Absis(POINT(*m)), Ordinat(POINT(*m)) - 1);
        }
        else
        {
            WEST(*m) = ' ';
        }
        break;
    }
}

boolean isValidJalan(Peta m, int i)
{
    boolean check = false;
    if (i == 1)
    {
        if (ELMT_MATRIX(PETA(m), Absis(POINT(m)) - 1, Ordinat(POINT(m))) == '.')
        {
            check = true;
        }
    }
    else if (i == 2)
    {
        if (ELMT_MATRIX(PETA(m), Absis(POINT(m)), Ordinat(POINT(m)) + 1) == '.')
        {
            check = true;
        }
    }
    else if (i == 3)
    {
        if (ELMT_MATRIX(PETA(m), Absis(POINT(m)) + 1, Ordinat(POINT(m))) == '.')
        {
            check = true;
        }
    }
    else if (i == 4)
    {
        if (ELMT_MATRIX(PETA(m), Absis(POINT(m)), Ordinat(POINT(m)) - 1) == '.')
        {
            check = true;
        }
    }
    return check;
}

void MoveNorth(Peta *m, boolean *gerak)
{
    if (Absis(POINT(*m)) - 1 >= 0)
    {
        if (isValidJalan(*m, 1))
        {
            MoveN(&POINT(*m));
            Update(m, 1);
            *gerak = true;
        }
    }

}

void MoveEast(Peta *m, boolean *gerak)
{
    if (Ordinat(POINT(*m)) + 1 < COL_EFF(PETA(*m)))
    {
        if (isValidJalan(*m, 2))
        {
            MoveE(&POINT(*m));
            Update(m, 2);
            *gerak = true;
        }
    }
}

void MoveSouth(Peta *m, boolean *gerak)
{
    if (Absis(POINT(*m)) + 1 < ROW_EFF(PETA(*m)))
    {
        if (isValidJalan(*m, 3))
        {
            MoveS(&POINT(*m));
            Update(m, 3);
            *gerak = true;
        }
    }
}

void MoveWest(Peta *m, boolean *gerak)
{
    if (Ordinat(POINT(*m)) - 1 >= 0)
    {
        if (isValidJalan(*m, 4))
        {
            MoveW(&POINT(*m));
            Update(m, 4);
            *gerak=false;
        }
    }
}

void DisplayPos(Peta m)
{
    printf("(%d,%d)\n", Absis(POINT(m)), Ordinat(POINT(m)));
}

void DisplayPeta(Peta m)
{
    Matrix petatemp;
    int i, j;
    createMatrix(ROW_EFF(PETA(m)) + 2, COL_EFF(PETA(m)) + 2, &petatemp);
    for (i = 0; i < ROW_EFF(petatemp); i++)
    {
        for (j = 0; j < COL_EFF(petatemp); j++)
        {
            if (i == 0 || j == 0 || i == ROW_EFF(petatemp) - 1 || j == COL_EFF(petatemp) - 1)
            {
                ELMT_MATRIX(petatemp, i, j) = '*';
            }
            else
            {
                ELMT_MATRIX(petatemp, i, j) = ELMT_MATRIX(PETA(m), i - 1, j - 1);
            }
        }
    }
    displayMatrix(petatemp);
}

void fileToPeta(char *dir, Matrix *m)
{
    int row, col, i, j;
    char temp;
    STARTFILEWORD(dir);
    row = WordToInt(currentWord);
    ADVLINE();
    col = WordToInt(currentWord);

    createMatrix(row, col, m);

    for (i = 0; i < row; i++)
    {
        ADVLINE();
        for (j = 0; j < col; j++)
        {
            temp = currentWord.TabWord[j];
            if (temp == '#')
            {
                temp = '.';
            }
            ELMT_MATRIX(*m, i, j) = temp;
        }
    }
}

POINT cariSimul(Peta m)
{
    POINT p;
    for (int i = 0; i < ROW_EFF(PETA(m)); i++)
    {
        for (int j = 0; j < COL_EFF(PETA(m)); j++)
        {
            if (ELMT_MATRIX(PETA(m), i, j) == 'S')
            {
                Absis(p) = i;
                Ordinat(p) = j;
            }
        }
    }
    return p;
}
void CreatePeta(Peta *m) {
    Matrix mat;
    POINT point;
    createMatrix(0,0,&mat);
    PETA(*m) = mat;
    CreatePoint(&point,0,0);
    POINT(*m) = point;
    NORTH(*m) = ' ';
    EAST(*m) = ' ';
    WEST(*m) = ' ';
    SOUTH(*m) = ' ';
}

void StartPeta(Peta *m, char* dir) {
    fileToPeta(dir, &PETA(*m));
    POINT(*m) = cariSimul(*m);
    Update(m, 5);
}

boolean CanOrder(Peta m){
    return (NORTH(m)=='T' || EAST(m)=='T'|| WEST(m)=='T' || SOUTH(m) == 'T');
}
boolean CanMix(Peta m){
    return (NORTH(m)=='M' || EAST(m)=='M'|| WEST(m)=='M' || SOUTH(m) == 'M');
}
boolean CanCut(Peta m){
    return (NORTH(m)=='C' || EAST(m)=='C'|| WEST(m)=='C' || SOUTH(m) == 'C');
}
boolean CanFry(Peta m){
    return (NORTH(m)=='F' || EAST(m)=='F'|| WEST(m)=='F' || SOUTH(m) == 'F');
}
boolean CanBoil(Peta m){
    return (NORTH(m)=='B' || EAST(m)=='B'|| WEST(m)=='B' || SOUTH(m) == 'B');
}
