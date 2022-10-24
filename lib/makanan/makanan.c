/* File: makanan.c */
/* Implementasi ADT MAKANAN */

#include "../boolean.h"
#include "../string/string.h"
#include "../time/time.h"
#include "makanan.h"
#include <stdio.h>

boolean IsMakananValid (int id, String nama, TIME exp, String aksi, TIME delivTime) {

}
/* Mengirim true jika id, nama, exp, aksi, dan delivTime dapat membentuk Makanan yang valid */

/* *** Konstruktor: Membentuk sebuah Makanan dari komponen-komponennya *** */
void CreateMakanan (Makanan * Food, int id, String nama, TIME exp, String aksi, TIME delivTime) {
    ID(*Food) = id;
    Nama(*Food) = nama;
    Exp(*Food) = exp;
    Aksi(*Food) = aksi;
    DelivTime(*Food) = delivTime;
}
/* Membentuk sebuah Makanan dari komponen-komponennya yang valid */
/* Prekondisi : id, nama, exp, aksi, dan delivTime valid untuk membentuk Makanan */

void BacaMakanan (Makanan * Food) {
    int id;
    String nama, aksi;
    TIME exp, delivTime;
    
    do {
        scanf("%d\n", id);
        readString(&nama);
        BacaTIME(&exp);
        readString(&aksi);
        BacaTIME(&delivTime);
    } while (IsMakananValid(id, nama, exp, aksi, delivTime));
    
    CreateMakanan(Food, id, nama, exp, aksi, delivTime);

}
/* I.S. : Food tidak terdefinisi */
/* F.S. : Food terdefinisi dan merupakan makanan yang valid */
/* Proses : mengulangi membaca komponen id, nama, exp, aksi, delivTime sehingga membentuk Food */
/* yang valid. Tidak mungkin menghasilkan Food yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen id, nama, exp, aksi, delivTime
   berbeda baris, masing-masing dipisahkan dan diakhiri enter. */
   
void TulisMakanan (Makanan Food){
    printf("%d\n", ID(Food));
    displayString(Nama(Food));
    TulisTIME(Exp(Food));
    displayString(Aksi(Food));
    TulisTIME(DelivTime(Food));
}
/* I.S. : Food sembarang */
/* F.S. : Nilai Food ditulis dg format ... */
/* Proses : menulis nilai setiap komponen Food ke layar dalam format ...*/ 

