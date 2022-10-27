#ifndef INISIASI
#define INISIASI

#include "../main.h"

/* Selektor */
#define LENGTH(w) (w).Length
#define WORD(w,i) (w).TabWord[i]

void ScanWord();
/* 	Menerima input dari pengguna
	I.S. : currentChar sembarang 
   	F.S. : mencetak GUI, currentWord terdefinisi */

Word StringToWord(char* string);
/*  Mengubah array of char (string) menjadi word */

boolean IsSTART();
/* Mengecek apakah currentWord == START */

boolean IsEXIT();
/* Mengecek apakah currentWord == EXIT */

boolean IsBUY();
/* Mengecek apakah currentWord == BUY */

boolean IsDELIVERY();
/* Mengecek apakah currentWord == DELIVERY */

boolean IsMOVE();
/* Mengecek apakah currentWord == MOVE */

boolean IsNORTH();
/* Mengecek apakah currentWord == NORTH */

boolean IsEAST();
/* Mengecek apakah currentWord == EAST */

boolean IsWEST();
/* Mengecek apakah currentWord == WEST */

boolean IsSOUTH();
/* Mengecek apakah currentWord == SOUTH */

boolean IsMIX();
/* Mengecek apakah currentWord == MIX */

boolean IsCHOP();
/* Mengecek apakah currentWord == CHOP */

boolean IsFRY();
/* Mengecek apakah currentWord == FRY */

boolean IsBOIL();
/* Mengecek apakah currentWord == BOIL */

boolean IsWAIT();
/* Mengecek apakah currentWord == WAIT */

boolean IsUNDO();
/* Mengecek apakah currentWord == UNDO */

boolean IsREDO();
/* Mengecek apakah currentWord == REDO */

boolean IsCATALOG();
/* Mengecek apakah currentWord == CATALOG */

boolean IsCOOKBOOK();
/* Mengecek apakah currentWord == COOKBOOK */

boolean IsINVENTORY();
/* Mengecek apakah currentWord == INVENTORY */

#endif