/* File: charmachine.c */
/* Implementasi Mesin Karakter */

#include "charmachine.h"
#include <stdio.h>

char currentChar;
int retval;

static FILE *pita;

void START()
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
   		 Jika retval != EOF maka mesin akan tetap berjalan
   		 Jika retval = EOF maka mesin akan berhenti */
{
	pita = stdin;
	ADV();
}

void ADV()
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, retval != EOF
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          retval baru mungkin EOF
          Jika retval != EOF maka mesin akan tetap berjalan */
{
	retval = fscanf(pita, "%c", &currentChar);
}

void STARTFILE(char* dir)
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : dir terdefinisi, yaitu direktori file yang ingin dibaca.
   F.S. : currentChar adalah karakter pertama pada pita
   		 Jika retval != EOF maka mesin akan tetap berjalan
   		 Jika retval = EOF maka mesin akan berhenti
		    Jika file tidak bisa dibaca maka mesin akan berhenti dan file akan ditutup */
{
	pita = fopen(dir, "r");
	if (pita == NULL)
	{
		printf("Pita tidak bisa dibaca.");
		fclose(pita);
	}
	else
	{
		ADV();
	}
}