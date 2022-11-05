/* File: makanan.c */
/* Implementasi ADT MAKANAN */

#include "../boolean.h"
#include "../string/string.h"
#include "../time/time.h"
#include "makanan.h"
#include <stdio.h>

/* *** Konstruktor: Membentuk sebuah Makanan dari komponen-komponennya *** */
void CreateMakanan(Makanan *Food, int id, String nama, TIME exp, String aksi, TIME delivTime, TIME aksiTime, int ukBaris, int ukKolom)
{
    ID(*Food) = id;
    Nama(*Food) = nama;
    Exp(*Food) = exp;
    Aksi(*Food) = aksi;
    DelivTime(*Food) = delivTime;
    AksiTime(*Food) = aksiTime;
    SizeBaris(*Food) = ukBaris;
    SizeKolom(*Food) = ukKolom;
}
/* Membentuk sebuah Makanan dari komponen-komponennya yang valid */
/* Prekondisi : id, nama, exp, aksi, dan delivTime valid untuk membentuk Makanan */

void BacaMakanan(Makanan *Food)
{
    int id, ukBaris, ukKolom;
    String nama, aksi;
    TIME exp, delivTime, aksiTime;

    printf("Masukkan id: ");
    STARTWORD();
    id = WordToInt(currentWord);
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
    printf("Masukkan ukuran makanan (baris kolom): ");
    STARTWORD();
    ukBaris = WordToInt(currentWord);
    ADVWORD();
    ukKolom = WordToInt(currentWord);

    CreateMakanan(Food, id, nama, exp, aksi, delivTime, aksiTime, ukBaris, ukKolom);
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
    printf("Ukuran makanan: ");
    printf("\n%d x %d", SizeBaris(Food), SizeKolom(Food));
}
/* I.S. : Food sembarang */
/* F.S. : Nilai Food ditulis dg format ... */
/* Proses : menulis nilai setiap komponen Food ke layar dalam format ...*/
