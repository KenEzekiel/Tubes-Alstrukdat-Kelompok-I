#ifndef PETA_H
#define PETA_H

#include "matrix.h"
#include "../point/point.h"
typedef struct
{
    Matrix map;
    ElType N;
    ElType S;
    ElType E;
    ElType W;
    POINT pos;
} Peta;

#define PETA(P) (P).map
#define POINT(P) (P).pos
#define NORTH(P) (P).N
#define SOUTH(P) (P).S
#define EAST(P) (P).E
#define WEST(P) (P).W

void Update(Peta *m,int P);
POINT cariSimul(Peta m);

void MoveNorth(Peta* m);
void MoveEast(Peta* m);
void MoveSouth(Peta* m);
void MoveWest(Peta* m);

void DisplayPos(Peta m);
void DisplayPeta(Peta m);

void fileToPeta(char* dir, Matrix *m);
#endif