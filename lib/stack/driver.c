#include "stack.h"
#include <stdio.h>

int main() {
    Stack S;
    stackInfotype val;

    //inisialisasi stack
    CreateEmpty(&S);

    //Menampilkan stack kosong, penuh, atau tidak keduanya
    printf("Stack kosong? %d\n", IsStackEmpty(S));
    printf("Stack penuh? %d\n", IsStackFull(S));

    //Menambahkan elemen ke dalam stack
    int EOP = -9999;
    stackInfotype N=0;
    printf("Masukkan angka ke dalam stack (-9999 jika berhenti): \n");
    while(N!=EOP && !IsStackFull(S)){
        scanf("%d", &N);
        if(N!=EOP){
            Push(&S,N);
        }
    }

    //menampilkan elemen stack
    printf("[");
    while(!IsStackEmpty(S)) {
        Pop(&S,&val);
        printf("%d",val);
        if(!IsStackEmpty(S)){
            printf(",");
        }
    }
    printf("]");

    return 0;
}