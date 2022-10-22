/* File: charmachine.h */
/* Definisi Mesin Karakter */

#ifndef __MESIN_KAR_H_
#define __MESIN_KAR_H_

#include "boolean.h"

/* State Mesin */
extern char currentChar;
extern int retval;

void START();
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika retval != EOF maka mesin akan tetap berjalan
          Jika retval = EOF maka mesin akan berhenti */

void ADV();
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, retval != EOF
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          retval baru mungkin EOF
          Jika retval != EOF maka mesin akan tetap berjalan */

void STARTFILE(char* dir);
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : dir terdefinisi, yaitu direktori file yang ingin dibaca.
   F.S. : currentChar adalah karakter pertama pada pita
          Jika retval != EOF maka mesin akan tetap berjalan
          Jika retval = EOF maka mesin akan berhenti
          Jika file tidak bisa dibaca maka mesin akan berhenti dan file akan ditutup */

#endif