/* File: point.h */
/* Tanggal: 3 September 2022 */
/* *** Definisi ABSTRACT DATA TYPE POINT *** */

#include <stdio.h>
#include "../boolean.h"
#include <math.h>
#include "point.h"

#define PI 3.14159265
/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
void CreatePoint (POINT * P, float X, float Y) {
    Absis(*P) = X;
    Ordinat(*P) = Y;
}
/* Membentuk sebuah POINT dari komponen-komponennya */

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */                                                               

void MoveN(POINT* p){
    Ordinat(*p)--;
}
void MoveE(POINT* p){
    Absis(*p)++;
}
void MoveS(POINT* p){
    Ordinat(*p)++;
}
void MoveW(POINT* p){
    Absis(*p)--;
}