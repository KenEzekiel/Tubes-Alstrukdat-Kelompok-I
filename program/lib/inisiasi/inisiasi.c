#include <stdio.h>
#include "inisiasi.h"

void PrintGUI(Time* Waktu, Point* Lokasi, PrioQueueTime* Inventory, Simulator* BNMO, Peta* Peta)
/* 	Menerima input dari pengguna
	I.S. : currentChar sembarang, currentWord sembarang
   	F.S. : mencetak GUI, currentWord terdefinisi */
{
	printf("BNMO berada di posisi: "); 
	printf("Waktu: "); TulisTIME(*Waktu);
	printf("Notifikasi: ");

	DisplayPeta(*Peta);

	printf("Enter Command: "); STARTWORD();
}

Word StringToWord(char* string, int size)
/*  Mengubah array of char (string) menjadi word */
{
	Word w;
	LENGTH(w) = size;

	for (int i = 0; i < size; i++)
		WORD(w,i) = string[i];

	return w;
}

boolean IsSTART()
/* Mengecek apakah currentWord == START */
{
	Word Start; StringToWord("START", 5);

	return IsWordEqual(Start, currentWord);
}

boolean IsEXIT()
/* Mengecek apakah currentWord == EXIT */
{
	Word Exit; StringToWord("EXIT", 4);

	return IsWordEqual(Exit, currentWord);
}

boolean IsBUY()
/* Mengecek apakah currentWord == BUY */
{
	Word Buy; StringToWord("BUY", 3);

	return IsWordEqual(Buy, currentWord);
}

boolean IsDELIVERY()
/* Mengecek apakah currentWord == DELIVERY */
{
	Word Delivery; StringToWord("DELIVERY", 8);

	return IsWordEqual(Delivery, currentWord);
}

boolean IsMOVE()
/* Mengecek apakah currentWord == MOVE */
{
	Word Move; StringToWord("MOVE", 4);

	return IsWordEqual(Move, currentWord);
}

boolean IsNORTH()
/* Mengecek apakah currentWord == NORTH */
{
	Word North; StringToWord("NORTH", 5);

	return IsWordEqual(North, currentWord);
}

boolean IsEAST()
/* Mengecek apakah currentWord == EAST */
{
	Word East; StringToWord("EAST", 4);

	return IsWordEqual(East, currentWord);
}

boolean IsWEST()
/* Mengecek apakah currentWord == WEST */
{
	Word West; StringToWord("WEST", 4);

	return IsWordEqual(West, currentWord);
}

boolean IsSOUTH()
/* Mengecek apakah currentWord == SOUTH */
{
	Word South; StringToWord("SOUTH", 5);

	return IsWordEqual(South, currentWord);
}

boolean IsMIX();
/* Mengecek apakah currentWord == MIX */
{
	Word Mix; StringToWord("MIX", 3);

	return IsWordEqual(Mix, currentWord);
}

boolean IsCHOP()
/* Mengecek apakah currentWord == CHOP */
{
	Word Chop; StringToWord("CHOP", 4);

	return IsWordEqual(Chop, currentWord);
}

boolean IsFRY()
/* Mengecek apakah currentWord == FRY */
{
	Word Fry; StringToWord("FRY", 3);

	return IsWordEqual(Fry, currentWord);
}

boolean IsBOIL()
/* Mengecek apakah currentWord == BOIL */
{
	Word Boil; StringToWord("BOIL", 4);

	return IsWordEqual(Boil, currentWord);
}

boolean IsWAIT()
/* Mengecek apakah currentWord == WAIT */
{
	Word Wait; StringToWord("WAIT", 4);

	return IsWordEqual(Wait, currentWord);
}

boolean IsUNDO()
/* Mengecek apakah currentWord == UNDO */
{
	Word Undo; StringToWord("UNDO", 4);

	return IsWordEqual(Undo, currentWord);
}

boolean IsREDO()
/* Mengecek apakah currentWord == REDO */
{
	Word Redo; StringToWord("REDO", 4);

	return IsWordEqual(Redo, currentWord);
}

boolean IsCATALOG()
/* Mengecek apakah currentWord == CATALOG */
{
	Word Catalog; StringToWord("CATALOG", 7);

	return IsWordEqual(Catalog, currentWord);
}

boolean IsCOOKBOOK()
/* Mengecek apakah currentWord == COOKBOOK */
{
	Word Cookbook; StringToWord("COOKBOOK", 8);

	return IsWordEqual(Cookbook, currentWord);
}

boolean IsINVENTORY()
/* Mengecek apakah currentWord == INVENTORY */
{
	Word Inventory; StringToWord("INVENTORY", 9);

	return IsWordEqual(Inventory, currentWord);
}