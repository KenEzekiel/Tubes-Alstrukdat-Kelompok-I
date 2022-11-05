
#include "peta.h"
#include <stdio.h>
#include <stdlib.h>
#include "../../../lib/wordmachine/wordmachine.h"

void Update(Peta *m, int P)
{
    switch (P)
    {
    case 1:
        ELMT(PETA(*m), Absis(POINT(*m)) + 1, Ordinat(POINT(*m))) = '.';
        ELMT(PETA(*m), Absis(POINT(*m)), Ordinat(POINT(*m))) = 'S';

        if (Ordinat(POINT(*m)) - 1 >= 0)
        {
            NORTH(*m) = ELMT(PETA(*m), Absis(POINT(*m)) - 1, Ordinat(POINT(*m)));
        }
        else
        {
            NORTH(*m) = ' ';
        }
        if (Ordinat(POINT(*m)) + 1 < ROW_EFF(PETA(*m)))
        {
            SOUTH(*m) = ELMT(PETA(*m), Absis(POINT(*m)) + 1, Ordinat(POINT(*m)));
        }
        else
        {
            SOUTH(*m) = ' ';
        }
        if (Absis(POINT(*m)) + 1 < COL_EFF(PETA(*m)))
        {
            EAST(*m) = ELMT(PETA(*m), Absis(POINT(*m)), Ordinat(POINT(*m)) + 1);
        }
        else
        {
            EAST(*m) = ' ';
        }
        if (Absis(POINT(*m)) - 1 >= 0)
        {
            WEST(*m) = ELMT(PETA(*m), Absis(POINT(*m)), Ordinat(POINT(*m)) - 1);
        }
        else
        {
            WEST(*m) = ' ';
        }
        break;
    case 2:
        ELMT(PETA(*m), Absis(POINT(*m)), Ordinat(POINT(*m)) - 1) = '.';
        ELMT(PETA(*m), Absis(POINT(*m)), Ordinat(POINT(*m))) = 'S';

        if (Ordinat(POINT(*m)) - 1 >= 0)
        {
            NORTH(*m) = ELMT(PETA(*m), Absis(POINT(*m)) - 1, Ordinat(POINT(*m)));
        }
        else
        {
            NORTH(*m) = ' ';
        }
        if (Ordinat(POINT(*m)) + 1 < ROW_EFF(PETA(*m)))
        {
            SOUTH(*m) = ELMT(PETA(*m), Absis(POINT(*m)) + 1, Ordinat(POINT(*m)));
        }
        else
        {
            SOUTH(*m) = ' ';
        }
        if (Absis(POINT(*m)) + 1 < COL_EFF(PETA(*m)))
        {
            EAST(*m) = ELMT(PETA(*m), Absis(POINT(*m)), Ordinat(POINT(*m)) + 1);
        }
        else
        {
            EAST(*m) = ' ';
        }
        if (Absis(POINT(*m)) - 1 >= 0)
        {
            WEST(*m) = ELMT(PETA(*m), Absis(POINT(*m)), Ordinat(POINT(*m)) - 1);
        }
        else
        {
            WEST(*m) = ' ';
        }
        break;
    case 3:
        ELMT(PETA(*m), Absis(POINT(*m)) - 1, Ordinat(POINT(*m))) = '.';
        ELMT(PETA(*m), Absis(POINT(*m)), Ordinat(POINT(*m))) = 'S';

        if (Ordinat(POINT(*m)) - 1 >= 0)
        {
            NORTH(*m) = ELMT(PETA(*m), Absis(POINT(*m)) - 1, Ordinat(POINT(*m)));
        }
        else
        {
            NORTH(*m) = ' ';
        }
        if (Ordinat(POINT(*m)) + 1 < ROW_EFF(PETA(*m)))
        {
            SOUTH(*m) = ELMT(PETA(*m), Absis(POINT(*m)) + 1, Ordinat(POINT(*m)));
        }
        else
        {
            SOUTH(*m) = ' ';
        }
        if (Absis(POINT(*m)) + 1 < COL_EFF(PETA(*m)))
        {
            EAST(*m) = ELMT(PETA(*m), Absis(POINT(*m)), Ordinat(POINT(*m)) + 1);
        }
        else
        {
            EAST(*m) = ' ';
        }
        if (Absis(POINT(*m)) - 1 >= 0)
        {
            WEST(*m) = ELMT(PETA(*m), Absis(POINT(*m)), Ordinat(POINT(*m)) - 1);
        }
        else
        {
            WEST(*m) = ' ';
        }
        break;
    case 4:
        ELMT(PETA(*m), Absis(POINT(*m)), Ordinat(POINT(*m)) + 1) = '.';
        ELMT(PETA(*m), Absis(POINT(*m)), Ordinat(POINT(*m))) = 'S';

        if (Ordinat(POINT(*m)) - 1 >= 0)
        {
            NORTH(*m) = ELMT(PETA(*m), Absis(POINT(*m)) - 1, Ordinat(POINT(*m)));
        }
        else
        {
            NORTH(*m) = ' ';
        }
        if (Ordinat(POINT(*m)) + 1 < ROW_EFF(PETA(*m)))
        {
            SOUTH(*m) = ELMT(PETA(*m), Absis(POINT(*m)) + 1, Ordinat(POINT(*m)));
        }
        else
        {
            SOUTH(*m) = ' ';
        }
        if (Absis(POINT(*m)) + 1 < COL_EFF(PETA(*m)))
        {
            EAST(*m) = ELMT(PETA(*m), Absis(POINT(*m)), Ordinat(POINT(*m)) + 1);
        }
        else
        {
            EAST(*m) = ' ';
        }
        if (Absis(POINT(*m)) - 1 >= 0)
        {
            WEST(*m) = ELMT(PETA(*m), Absis(POINT(*m)), Ordinat(POINT(*m)) - 1);
        }
        else
        {
            WEST(*m) = ' ';
        }
        break;
    case 5:
        if (Ordinat(POINT(*m)) - 1 >= 0)
        {
            NORTH(*m) = ELMT(PETA(*m), Absis(POINT(*m)) - 1, Ordinat(POINT(*m)));
        }
        else
        {
            NORTH(*m) = ' ';
        }
        if (Ordinat(POINT(*m)) + 1 < ROW_EFF(PETA(*m)))
        {
            SOUTH(*m) = ELMT(PETA(*m), Absis(POINT(*m)) + 1, Ordinat(POINT(*m)));
        }
        else
        {
            SOUTH(*m) = ' ';
        }
        if (Absis(POINT(*m)) + 1 < COL_EFF(PETA(*m)))
        {
            EAST(*m) = ELMT(PETA(*m), Absis(POINT(*m)), Ordinat(POINT(*m)) + 1);
        }
        else
        {
            EAST(*m) = ' ';
        }
        if (Absis(POINT(*m)) - 1 >= 0)
        {
            WEST(*m) = ELMT(PETA(*m), Absis(POINT(*m)), Ordinat(POINT(*m)) - 1);
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
        if (ELMT(PETA(m), Absis(POINT(m)) - 1, Ordinat(POINT(m))) == '.')
        {
            check = true;
        }
    }
    else if (i == 2)
    {
        if (ELMT(PETA(m), Absis(POINT(m)), Ordinat(POINT(m)) + 1) == '.')
        {
            check = true;
        }
    }
    else if (i == 3)
    {
        if (ELMT(PETA(m), Absis(POINT(m)) + 1, Ordinat(POINT(m))) == '.')
        {
            check = true;
        }
    }
    else if (i == 4)
    {
        if (ELMT(PETA(m), Absis(POINT(m)), Ordinat(POINT(m)) - 1) == '.')
        {
            check = true;
        }
    }
    return check;
}

void MoveNorth(Peta *m)
{
    if (Absis(POINT(*m)) - 1 >= 0)
    {
        if (isValidJalan(*m, 1))
        {
            MoveN(&POINT(*m));
            Update(m, 1);
        }
        NotifTidakGerak(1);
    }
    NotifTidakGerak(1);
}

void MoveEast(Peta *m)
{
    if (Ordinat(POINT(*m)) + 1 < COL_EFF(PETA(*m)))
    {
        if (isValidJalan(*m, 2))
        {
            MoveE(&POINT(*m));
            Update(m, 2);
        }
        NotifTidakGerak(2);
    }
    NotifTidakGerak(2);
}

void MoveSouth(Peta *m)
{
    if (Absis(POINT(*m)) + 1 < ROW_EFF(PETA(*m)))
    {
        if (isValidJalan(*m, 3))
        {
            MoveS(&POINT(*m));
            Update(m, 3);
        }
        NotifTidakGerak(3);
    }
    NotifTidakGerak(3);
}

void MoveWest(Peta *m)
{
    if (Ordinat(POINT(*m)) - 1 >= 0)
    {
        if (isValidJalan(*m, 4))
        {
            MoveW(&POINT(*m));
            Update(m, 4);
        }
        NotifTidakGerak(4);
    }
    NotifTidakGerak(4);
}

void DisplayPos(Peta m)
{
    printf("(%d,%d)", Absis(POINT(m)), Ordinat(POINT(m)));
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
                ELMT(petatemp, i, j) = '*';
            }
            else
            {
                ELMT(petatemp, i, j) = ELMT(PETA(m), i - 1, j - 1);
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
            ELMT(*m, i, j) = temp;
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
            if (ELMT(PETA(m), i, j) == 'S')
            {
                Absis(p) = i;
                Ordinat(p) = j;
            }
        }
    }
    return p;
}

void StartPeta(Peta *m) {
    fileToPeta("../../test/peta.txt", &PETA(*m));
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

void NotifTidakGerak(int x){
    printf("TIDAK DAPAT BERGERAK KE ARAH ");
    if (x==1){
        printf("UTARA.\n");
    }
    else if (x==2) {
        printf("TIMUR.\n");
    }
    else if (x==3) {
        printf("SELATAN.\n");
    }
    else if (x==4) {
        printf("BARAT.\n");
    }
}