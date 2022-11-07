#include <stdio.h>
#include "makanan.h"

int main() {
    Makanan Food1;

    printf("Mengetes pembentukan tipe makanan\n");
    printf("Masukkan id, nama makanan, tanggal kadaluwarsa, aksi, dan lama pengiriman\n");
    BacaMakanan(&Food1);
    TulisMakanan(Food1);

    return 0;
}