#include "stack.h"
#include <stdio.h>

int main() {
    Stack S;
    infotype val;

    //inisialisasi stack
    CreateEmpty(&S);

    //Menampilkan stack kosong, penuh, atau tidak keduanya
    printf("Stack kosong? %d\n", IsEmpty(S));
    printf("Stack penuh? %d\n", IsFull(S));

    //Menambahkan elemen ke dalam stack
    int EOP = -9999;
    infotype N=0;
    printf("Masukkan angka ke dalam stack (-9999 jika berhenti): \n");
    while(N!=EOP && !IsFull(S)){
        scanf("%d", &N);
        if(N!=EOP){
            Push(&S,N);
        }
    }

    //menampilkan elemen stack
    printf("[");
    while(!IsEmpty(S)) {
        Pop(&S,&val);
        printf("%d",val);
        if(!IsEmpty(S)){
            printf(",");
        }
    }
    printf("]");

    return 0;
}