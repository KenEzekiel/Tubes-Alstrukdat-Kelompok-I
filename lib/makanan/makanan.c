/* File: makanan.c */
/* Implementasi ADT MAKANAN */

#include "../boolean.h"
#include "../string/string.h"
#include "../time/time.h"
#include "makanan.h"
#include <stdio.h>

/* *** Konstruktor: Membentuk sebuah Makanan dari komponen-komponennya *** */
void CreateMakanan(Makanan *Food, int id, String nama, TIME exp, String aksi, TIME delivTime, TIME aksiTime)
{
    ID(*Food) = id;
    Nama(*Food) = nama;
    Exp(*Food) = exp;
    Aksi(*Food) = aksi;
    DelivTime(*Food) = delivTime;
    AksiTime(*Food) = aksiTime;
}
/* Membentuk sebuah Makanan dari komponen-komponennya yang valid */
/* Prekondisi : id, nama, exp, aksi, dan delivTime valid untuk membentuk Makanan */

void BacaMakanan(Makanan *Food)
{
    int id;
    String nama, aksi;
    TIME exp, delivTime, aksiTime;

    printf("Masukkan id: ");
    scanf("%d", &id);
    printf("Masukkan nama makanan: ");
    readString(&nama);
    printf("Masukkan waktu kadaluwarsa: ");
    BacaTIME(&exp);
    printf("Masukkan aksi yang bisa dilakukan: ");
    readString(&aksi);
    printf("Masukkan lama pengiriman: ");
    BacaTIME(&delivTime);
    printf("Masukkan waktu pengolahan makanan: ");
    BacaTIME(&aksiTime);

    CreateMakanan(Food, id, nama, exp, aksi, delivTime, aksiTime);
}
/* I.S. : Food tidak terdefinisi */
/* F.S. : Food terdefinisi dan merupakan makanan yang valid */
/* Proses : mengulangi membaca komponen id, nama, exp, aksi, delivTime sehingga membentuk Food */
/* yang valid. Tidak mungkin menghasilkan Food yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen id, nama, exp, aksi, delivTime
   berbeda baris, masing-masing dipisahkan dan diakhiri enter. */

void TulisMakanan(Makanan Food)
{
    printf("ID: %d\n", ID(Food));
    printf("Nama makanan: ");
    displayString(Nama(Food));
    printf("\nWaktu kadaluwarsa: ");
    TulisTIME(Exp(Food));
    printf("Lokasi aksi: ");
    displayString(Aksi(Food));
    printf("\nLama pengiriman: ");
    TulisTIME(DelivTime(Food));
    printf("Waktu pengolahan makanan: ");
    TulisTIME(AksiTime(Food));
}
/* I.S. : Food sembarang */
/* F.S. : Nilai Food ditulis dg format ... */
/* Proses : menulis nilai setiap komponen Food ke layar dalam format ...*/
