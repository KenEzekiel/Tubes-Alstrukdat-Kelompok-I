#ifndef SET_H
#define SET_H

#include "../boolean.h"

#define CAPACITY_SET 100

typedef int Eltype_SET;
typedef struct {
    Eltype_SET buffer[CAPACITY_SET];
    int length;
} Set;

#define ELMT_S(S,i) (S).buffer[i]
#define lengthS(S) (S).length

void CreateSet(Set *S);
/*I.S. Set tidak terdefinisi*/
/*F.S. Terbentuk Set kosong*/

boolean isEmptySet(Set S);
/*Memeriksa apakah set kosong atau tidak*/

int lengthSet(Set S);
/*Menghasilkan panjang dari Set*/

boolean isIn(Set S, Eltype_SET val);
/*Mengembalikan nilai true apabila val ada di dalam set*/

void add (Set *S, Eltype_SET val);
/*I.S. Sebuah Set, boleh kosong*/
/*F.S. Set yang telah ditambahkan elemen val*/

void copy(Set *S1,Set*S2);
/*I.S. S1 sembarang, S2 terdefinisi*/
/*F.S. Menghasilkan S1 yang sama seperti S2*/

boolean isSubset(Set S1,Set S2);
/*Menghasilkan true apabila S1 adalah subset dari S2*/

#endif