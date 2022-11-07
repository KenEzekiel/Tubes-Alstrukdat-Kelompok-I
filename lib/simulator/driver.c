#include <stdio.h>
#include "simulator.h"
#include "../string/string.h"

int main() {
    Simulator Sim1, Sim2;
    String user1;

    printf("Mengetes pembentukan simulator awal\n");
    printf("Masukkan nama user: ");
    readString(&user1);
    CreateStartSimulator(&Sim1, user1);
    printf("Simulator saat ini: \n");
    TulisSimulator(Sim1);

    printf("Mengetes pembentukan simulator\n");
    printf("Masukkan nama user dan lokasi saat ini\n");
    BacaSimulator(&Sim2);
    printf("Simulator saat ini: \n");
    TulisSimulator(Sim2);

    return 0;
}