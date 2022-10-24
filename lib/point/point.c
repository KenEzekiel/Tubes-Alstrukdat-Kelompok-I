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
void BacaPOINT (POINT * P){
    float X,Y;
    scanf("%f %f", &X, &Y);
    CreatePoint(P, X, Y);
}
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk 
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2 
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
void TulisPOINT (POINT P){
    printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}

/* Nilai P ditulis ke layar dengan format "(X,Y)" 
   tanpa spasi, enter, atau karakter lain di depan, belakang, 
   atau di antaranya 
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */                

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2){
    return ((Absis(P1)==Absis(P2)) && (Ordinat(P1)==(Ordinat(P2))));
}
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
boolean NEQ (POINT P1, POINT P2){
    return (!(EQ(P1,P2)));
}
/* Mengirimkan true jika P1 tidak sama dengan P2 */

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P){
    return (Absis(P) == 0 && Ordinat(P)==0);
}
/* Menghasilkan true jika P adalah titik origin */
boolean IsOnSbX (POINT P){
    return (Ordinat(P)== 0);
}
/* Menghasilkan true jika P terletak Pada sumbu X */
boolean IsOnSbY (POINT P){
    return (Absis(P)==0);
}
/* Menghasilkan true jika P terletak pada sumbu Y */
int Kuadran (POINT P){
    if (Absis(P)>0) {
        if (Ordinat(P)>0) {printf("Kuadran dari P: 1");}
        else {printf("Kuadran dari P: 4");}
    }
    else {
        if (Ordinat(P)>0) {printf("Kuadran dari P: 2");}
        else {printf("Kuadran dari P: 3");}
    }
}
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */                           
POINT NextX (POINT P){
    CreatePoint(&P, Absis(P)+1, (Ordinat(P)));
    return P;
}
/* Mengirim salinan P dengan absis ditambah satu */              
POINT NextY (POINT P){
    CreatePoint(&P, Absis(P), (Ordinat(P)+1));
    return P;
}
/* Mengirim salinan P dengan ordinat ditambah satu */
POINT PlusDelta (POINT P, float deltaX, float deltaY){
    CreatePoint(&P, (Absis(P)+deltaX), (Ordinat(P)+deltaY));
    return P;
}
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
POINT MirrorOf (POINT P, boolean SbX){
    if (SbX) {
        CreatePoint(&P, (Absis(P)), (-1*Ordinat(P)));
        return P;
    }
    else {
        CreatePoint(&P, (-1*Absis(P)), (Ordinat(P)));
        return P;
    }
}
/* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
/* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
/* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */
float Jarak0 (POINT P){
    return (sqrt(pow(Absis(P),2)+pow(Ordinat(P),2)));
}
/* Menghitung jarak P ke (0,0) */
float Panjang (POINT P1, POINT P2){
    return (sqrt(pow((Absis(P1)-Absis(P2)),2)+pow((Ordinat(P1)-Ordinat(P2)),2)));
}
/* Menghitung panjang garis yang dibentuk P1 dan P2 */
/* Perhatikanlah bahwa di sini spec fungsi kurang baik sebab menyangkut ADT Garis. */
/* Tuliskan spec fungsi yang lebih tepat. */
void Geser (POINT *P, float deltaX, float deltaY){
    Absis(*P) = Absis(*P) + deltaX;
    Ordinat(*P) = Ordinat(*P) + deltaY;
}
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
void GeserKeSbX (POINT *P){
    Ordinat(*P) = 0;
}
/* I.S. P terdefinisi */
/* F.S. P berada pada sumbu X dengan absis sama dengan absis semula. */
/* Proses : P digeser ke sumbu X. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (9,0) */
void GeserKeSbY (POINT *P){
    Absis(*P) = 0;
}
/* I.S. P terdefinisi*/
/* F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. */
/* Proses : P digeser ke sumbu Y. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (0,9) */
void Mirror (POINT *P, boolean SbX){
    if (SbX) {
        Ordinat(*P) = -1 * Ordinat(*P);
    }
    else {
        Absis(*P) = -1 * Absis(*P);
    }
}

/* I.S. P terdefinisi */
/* F.S. P dicerminkan tergantung nilai SbX atau SbY */
/* Jika SbX true maka dicerminkan terhadap sumbu X */
/* Jika SbX false maka dicerminkan terhadap sumbu Y */
void Putar (POINT *P, float Sudut){
    float tempX, tempY;
    tempX = Absis(*P) * cos(PI*Sudut/180) - Ordinat(*P) * sin(PI*Sudut/180);
    tempY = Absis(*P) * sin(PI*Sudut/180) + Ordinat(*P) * cos(PI*Sudut/180);
    Absis(*P) = tempX;
    Ordinat(*P) = tempY;
}
/* I.S. P terdefinisi */
/* F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) */