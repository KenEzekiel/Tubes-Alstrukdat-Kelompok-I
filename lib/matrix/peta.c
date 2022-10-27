
#include "peta.h"
#include <stdio.h>
#include <stdlib.h>

ElType CheckCurrent(Peta m){
    return CP(m);
}
void Update(Peta *m,int P) {
    char temp;
    switch (P)
    {
    case 1:
        temp = CP(*m);
        ELMT(PETA(*m),Absis(POINT(*m))+1,Ordinat(POINT(*m))) = CP(*m);
        CP(*m) = ELMT(PETA(*m),Absis(POINT(*m)),Ordinat(POINT(*m)));
        ELMT(PETA(*m),Absis(POINT(*m)),Ordinat(POINT(*m))) = 'S';

        if (Ordinat(POINT(*m))-1>=0) {
            NORTH(*m) = ELMT(PETA(*m),Absis(POINT(*m))-1,Ordinat(POINT(*m)));
        }
        else {
            NORTH(*m) = ' ';
        }
        if (Ordinat(POINT(*m))+1<rowEff(PETA(*m))) {
            SOUTH(*m) = ELMT(PETA(*m),Absis(POINT(*m))+1,Ordinat(POINT(*m)));
        }
        else {
            SOUTH(*m) = ' ';
        }
        if (Absis(POINT(*m))+1<colEff(PETA(*m))) {
            EAST(*m) = ELMT(PETA(*m),Absis(POINT(*m)),Ordinat(POINT(*m))+1);
        }
        else {
            EAST(*m) = ' ';
        }
        if (Absis(POINT(*m))-1>=0) {
            WEST(*m) = ELMT(PETA(*m),Absis(POINT(*m)),Ordinat(POINT(*m))-1);
        }
        else {
            WEST(*m) = ' ';
        }
        break;
    case 2:
        temp = CP(*m);
        ELMT(PETA(*m),Absis(POINT(*m)),Ordinat(POINT(*m))-1) = CP(*m);
        CP(*m) = ELMT(PETA(*m),Absis(POINT(*m)),Ordinat(POINT(*m)));
        ELMT(PETA(*m),Absis(POINT(*m)),Ordinat(POINT(*m))) = 'S';

        if (Ordinat(POINT(*m))-1>=0) {
            NORTH(*m) = ELMT(PETA(*m),Absis(POINT(*m))-1,Ordinat(POINT(*m)));
        }
        else {
            NORTH(*m) = ' ';
        }
        if (Ordinat(POINT(*m))+1<rowEff(PETA(*m))) {
            SOUTH(*m) = ELMT(PETA(*m),Absis(POINT(*m))+1,Ordinat(POINT(*m)));
        }
        else {
            SOUTH(*m) = ' ';
        }
        if (Absis(POINT(*m))+1<colEff(PETA(*m))) {
            EAST(*m) = ELMT(PETA(*m),Absis(POINT(*m)),Ordinat(POINT(*m))+1);
        }
        else {
            EAST(*m) = ' ';
        }
        if (Absis(POINT(*m))-1>=0) {
            WEST(*m) = ELMT(PETA(*m),Absis(POINT(*m)),Ordinat(POINT(*m))-1);
        }
        else {
            WEST(*m) = ' ';
        }
        break;
    case 3:
        temp = CP(*m);
        ELMT(PETA(*m),Absis(POINT(*m))-1,Ordinat(POINT(*m))) = CP(*m);
        CP(*m) = ELMT(PETA(*m),Absis(POINT(*m)),Ordinat(POINT(*m)));
        ELMT(PETA(*m),Absis(POINT(*m)),Ordinat(POINT(*m))) = 'S';

        if (Ordinat(POINT(*m))-1>=0) {
            NORTH(*m) = ELMT(PETA(*m),Absis(POINT(*m))-1,Ordinat(POINT(*m)));
        }
        else {
            NORTH(*m) = ' ';
        }
        if (Ordinat(POINT(*m))+1<rowEff(PETA(*m))) {
            SOUTH(*m) = ELMT(PETA(*m),Absis(POINT(*m))+1,Ordinat(POINT(*m)));
        }
        else {
            SOUTH(*m) = ' ';
        }
        if (Absis(POINT(*m))+1<colEff(PETA(*m))) {
            EAST(*m) = ELMT(PETA(*m),Absis(POINT(*m)),Ordinat(POINT(*m))+1);
        }
        else {
            EAST(*m) = ' ';
        }
        if (Absis(POINT(*m))-1>=0) {
            WEST(*m) = ELMT(PETA(*m),Absis(POINT(*m)),Ordinat(POINT(*m))-1);
        }
        else {
            WEST(*m) = ' ';
        }
        break;
    case 4:
        temp = CP(*m);
        ELMT(PETA(*m),Absis(POINT(*m)),Ordinat(POINT(*m))+1) = CP(*m);
        CP(*m) = ELMT(PETA(*m),Absis(POINT(*m)),Ordinat(POINT(*m)));
        ELMT(PETA(*m),Absis(POINT(*m)),Ordinat(POINT(*m))) = 'S';

        if (Ordinat(POINT(*m))-1>=0) {
            NORTH(*m) = ELMT(PETA(*m),Absis(POINT(*m))-1,Ordinat(POINT(*m)));
        }
        else {
            NORTH(*m) = ' ';
        }
        if (Ordinat(POINT(*m))+1<rowEff(PETA(*m))) {
            SOUTH(*m) = ELMT(PETA(*m),Absis(POINT(*m))+1,Ordinat(POINT(*m)));
        }
        else {
            SOUTH(*m) = ' ';
        }
        if (Absis(POINT(*m))+1<colEff(PETA(*m))) {
            EAST(*m) = ELMT(PETA(*m),Absis(POINT(*m)),Ordinat(POINT(*m))+1);
        }
        else {
            EAST(*m) = ' ';
        }
        if (Absis(POINT(*m))-1>=0) {
            WEST(*m) = ELMT(PETA(*m),Absis(POINT(*m)),Ordinat(POINT(*m))-1);
        }
        else {
            WEST(*m) = ' ';
        }
        break;
    }
}

boolean isValidJalan(Peta m, int i) {
    switch (i)
    {
    case 1:
        return (ELMT(PETA(m),Absis(POINT(m))-1,Ordinat(POINT(m)))== '.');
    case 2:
        return (ELMT(PETA(m),Absis(POINT(m)),Ordinat(POINT(m))+1)== '.');
    case 3:
        return (ELMT(PETA(m),Absis(POINT(m))+1,Ordinat(POINT(m)))== '.');
    case 4:
        return (ELMT(PETA(m),Absis(POINT(m)),Ordinat(POINT(m))-1)== '.');
    }
}

void MoveNorth(Peta* m){
    if (Absis(POINT(*m))-1>=0) {
        if (isValidJalan(*m,1)) {
            MoveN(&POINT(*m));
            Update(m,1);
        }
    }
}

void MoveEast(Peta* m){
    if (Ordinat(POINT(*m))+1<colEff(MAP(*m))) {
        if (isValidJalan(*m,2)) {
            MoveE(&POINT(*m));
            Update(m,2);
        }
    }
}

void MoveSouth(Peta* m){
    if (Absis(POINT(*m))+1<rowEff(MAP(*m))) {
        if (isValidJalan(*m,3)) {
            MoveS(&POINT(*m));
            Update(m,3);
        }
    }
}

void MoveWest(Peta* m){
    if (Ordinat(POINT(*m))-1>=0) {
        if (isValidJalan(*m,4)) {
            MoveW(&POINT(*m));
            Update(m,4);
        }
    }
}

void DisplayPos(Peta m) {
    printf("(%d,%d)",Absis(POINT(m)),Ordinat(POINT(m)));
}

void DisplayPeta(Peta m) {
    Matrix petatemp;
    int i,j;
    createMatrix(rowEff(PETA(m))+2,colEff(PETA(m))+2,&petatemp);
    for (i = 0;i<rowEff(petatemp);i++) {
        for (j=0;j<colEff(petatemp);j++) {
            if (i==0 || j == 0 || i == rowEff-1 || j == colEff-1) {
                ELMT(petatemp,i,j) = '*';
            }
            else {
                ELMT(petatemp,i,j) = ELMT(PETA(m),i-1,j-1);
            }
        }
    }
    displayMatrix(petatemp);
}