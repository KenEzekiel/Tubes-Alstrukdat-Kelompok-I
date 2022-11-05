/* File: drivernotif.c */
/* Mengecek fungsionalitas notifikasi */

#include "notifikasi.h"
#include <stdio.h>

int main() {
    Notif listNotif;
    String newNotif;
    State prev, current;
    CreateNotif(&listNotif);

    printf("Tampilan saat notifikasi kosong\n");
    printNotif(listNotif);

    printf("Tampilan print notifikasi\n");
    charToString("Bawang sudah diterima oleh BNMO! :D", &newNotif, 35);
    insertLastNotif(&listNotif, newNotif);
    printNotif(listNotif);

    return 0;
}