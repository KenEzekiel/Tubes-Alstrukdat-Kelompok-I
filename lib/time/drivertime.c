#include "time.h"
#include <stdio.h>

int main() {
    TIME T1,T2, T3;
    int n;

    //Membuat ADT Time dari elemen jam, menit, detik
    int HH,MM,SS;
    printf("Masukkan nilai jam: ");
    scanf("%d", &HH);
    printf("Masukkan nilai menit: ");
    scanf("%d", &MM);
    printf("Masukkan nilai detik: ");
    scanf("%d", &SS);
    printf("Apakah waktu valid? %d\n", IsTIMEValid(HH,MM,SS));
    CreateTime(&T1,HH,MM,SS);
    printf("T1: ");
    TulisTIME(T1);
    printf("\n");

    //Membuat ADT Time dari elemen jam, menit, detik
    printf("Masukkan jam, menit, dan detik T2 (format: hh mm ss): ");
    BacaTIME(&T2);
    printf("T2: ");
    TulisTIME(T2);
    //Menampilkan jumlah detik dari TIME
    int jam = TIMEToDetik(T2);
    printf("Total detik T2 = %d\n", jam);
    printf("\n");

    //Menampilkan TIME dari jumlah detik
    printf("Total detik T3: ");
    scanf("%d", &n);
    T3 = DetikToTIME(n);
    printf("T3: ");
    TulisTIME(T3);
    printf("\n");

    //Menampilkan apakah antara kedua TIME ekuivalen atau tidak
    printf("Apakah T2 dan T3 sama? %d\n", TEQ(T2,T3));

    //Menampilkan apakah antara kedua TIME tidak ekuivalen atau tidak
    printf("Apakah T2 dan T3 berbeda? %d\n", TNEQ(T2,T3));

    //Menampilkan apakah T2>T3
    printf("Apakah T2 lebih besar dari T3? %d\n", TGT(T2,T3));

    //Menampilkan apakah T1<T2
    printf("Apakah T2 lebih kecil dari T3? %d\n", TLT(T2,T3));

    //Mengirimkan 1 detik setelah T
    printf("\n");
    T2 = NextDetik(T2);
    printf("T2 setelah dimajukan 1 detik: ");
    TulisTIME(T2);

    //Mengirimkan X detik setelah T
    int k;
    printf("\n");
    printf("Masukkan berapa detik setelah T: ");
    scanf("%d", &k);
    T3 = NextNDetik(T3,k);
    printf("T3 setelah dimajukan %d detik: ", k);
    TulisTIME(T3);

    //Mengirimkan 1 detik sebelum T
    printf("\n");
    T3 = PrevDetik(T3);
    printf("T3 setelah dimundurkan 1 detik: ");
    TulisTIME(T3);

    //Mengirimkan X detik sebelum T
    int a;
    printf("\n");
    printf("Masukkan berapa detik sebelum T: ");
    scanf("%d", &a);
    T2 = PrevNDetik(T2,a);
    printf("T2 setelah dimundurkan %d detik: ", a);
    TulisTIME(T2);

    //Durasi dari T2 ke T3
    printf("\n");
    printf("Durasi T2 ke T3: ");
    printf("%d detik\n", Durasi(T2,T3));

    return 0;

}