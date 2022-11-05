#ifndef PETA_H
#define PETA_H

#include "../../../lib/matrix/matrix.h"
#include "../../../lib/point/point.h"
typedef struct
{
    Matrix map;
    MatrixElType N;
    MatrixElType S;
    MatrixElType E;
    MatrixElType W;
    POINT pos;
} Peta;

#define PETA(P) (P).map
#define POINT(P) (P).pos
#define NORTH(P) (P).N
#define SOUTH(P) (P).S
#define EAST(P) (P).E
#define WEST(P) (P).W

void Update(Peta *m, int P);
POINT cariSimul(Peta m);

void MoveNorth(Peta *m,boolean *gerak);
void MoveEast(Peta *m,boolean *gerak);
void MoveSouth(Peta *m,boolean *gerak);
void MoveWest(Peta *m,boolean *gerak);

void DisplayPos(Peta m);
void DisplayPeta(Peta m);

void fileToPeta(char *dir, Matrix *m);
void CreatePeta(Peta *m);
void StartPeta(Peta *m,char* dir);

boolean CanOrder(Peta m);
boolean CanMix(Peta m);
boolean CanCut(Peta m);
boolean CanFry(Peta m);
boolean CanBoil(Peta m);

void NotifTidakGerak(int x);
#endif