#include <stdio.h>
#include "inisiasi.h"

void PrintGUI(TIME Waktu, POINT Lokasi, Inventory Inventory, Simulator BNMO, Peta Peta, Notif listNotif)
/* 	Menerima input dari pengguna
	I.S. : currentChar sembarang, currentWord sembarang
	F.S. : mencetak GUI, currentWord terdefinisi */
{
	printf("BNMO berada di posisi: ");
	DisplayPos(Peta);
	printf("Waktu: ");
	TulisTIME(Waktu);

	printNotif(listNotif);

	DisplayPeta(Peta);

	printf("Enter Command: ");
	STARTWORD();
}

boolean IsSTART()
/* Mengecek apakah currentWord == START */
{
	Word Start = StringToWord("START", 5);

	return IsWordEqual(Start, currentWord);
}

boolean IsEXIT()
/* Mengecek apakah currentWord == EXIT */
{
	Word Exit = StringToWord("EXIT", 4);

	return IsWordEqual(Exit, currentWord);
}

boolean IsBUY()
/* Mengecek apakah currentWord == BUY */
{
	Word Buy = StringToWord("BUY", 3);

	return IsWordEqual(Buy, currentWord);
}

boolean IsDELIVERY()
/* Mengecek apakah currentWord == DELIVERY */
{
	Word Delivery = StringToWord("DELIVERY", 8);

	return IsWordEqual(Delivery, currentWord);
}

boolean IsMOVE()
/* Mengecek apakah currentWord == MOVE */
{
	Word Move = StringToWord("MOVE", 4);

	return IsWordEqual(Move, currentWord);
}

boolean IsNORTH()
/* Mengecek apakah currentWord == NORTH */
{
	Word North = StringToWord("NORTH", 5);

	return IsWordEqual(North, currentWord);
}

boolean IsEAST()
/* Mengecek apakah currentWord == EAST */
{
	Word East = StringToWord("EAST", 4);

	return IsWordEqual(East, currentWord);
}

boolean IsWEST()
/* Mengecek apakah currentWord == WEST */
{
	Word West = StringToWord("WEST", 4);

	return IsWordEqual(West, currentWord);
}

boolean IsSOUTH()
/* Mengecek apakah currentWord == SOUTH */
{
	Word South = StringToWord("SOUTH", 5);

	return IsWordEqual(South, currentWord);
}

boolean IsMIX()
/* Mengecek apakah currentWord == MIX */
{
	Word Mix = StringToWord("MIX", 3);

	return IsWordEqual(Mix, currentWord);
}

boolean IsCHOP()
/* Mengecek apakah currentWord == CHOP */
{
	Word Chop = StringToWord("CHOP", 4);

	return IsWordEqual(Chop, currentWord);
}

boolean IsFRY()
/* Mengecek apakah currentWord == FRY */
{
	Word Fry = StringToWord("FRY", 3);

	return IsWordEqual(Fry, currentWord);
}

boolean IsBOIL()
/* Mengecek apakah currentWord == BOIL */
{
	Word Boil = StringToWord("BOIL", 4);

	return IsWordEqual(Boil, currentWord);
}

boolean IsWAIT()
/* Mengecek apakah currentWord == WAIT */
{
	Word Wait = StringToWord("WAIT", 4);

	return IsWordEqual(Wait, currentWord);
}

boolean IsKULKAS()
/* Mengecek apakah currentWord == KULKAS */
{
	Word Kulkas = StringToWord("KULKAS", 6);

	return IsWordEqual(Kulkas, currentWord);
}

boolean IsINSERTKULKAS()
/* Mengecek apakah currentWord == INSERT */
{
	Word InsertKulkas = StringToWord("INSERTKULKAS", 12);

	return IsWordEqual(InsertKulkas, currentWord);
}

boolean IsGETKULKAS()
/* Mengecek apakah currentWord == GET */
{
	Word GetKulkas = StringToWord("GETKULKAS", 9);

	return IsWordEqual(GetKulkas, currentWord);
}

boolean IsDISPLAYKULKAS()
/* Mengecek apakah currentWord == DISPLAYKULKAS */
{
	Word DisplayKulkas = StringToWord("DISPLAYKULKAS", 13);

	return IsWordEqual(DisplayKulkas, currentWord);
}

boolean IsUNDO()
/* Mengecek apakah currentWord == UNDO */
{
	Word Undo = StringToWord("UNDO", 4);

	return IsWordEqual(Undo, currentWord);
}

boolean IsREDO()
/* Mengecek apakah currentWord == REDO */
{
	Word Redo = StringToWord("REDO", 4);

	return IsWordEqual(Redo, currentWord);
}

boolean IsCATALOG()
/* Mengecek apakah currentWord == CATALOG */
{
	Word Catalog = StringToWord("CATALOG", 7);

	return IsWordEqual(Catalog, currentWord);
}

boolean IsCOOKBOOK()
/* Mengecek apakah currentWord == COOKBOOK */
{
	Word Cookbook = StringToWord("COOKBOOK", 8);

	return IsWordEqual(Cookbook, currentWord);
}

boolean IsINVENTORY()
/* Mengecek apakah currentWord == INVENTORY */
{
	Word Inventory = StringToWord("INVENTORY", 9);

	return IsWordEqual(Inventory, currentWord);
}

boolean IsREKOMENDASI()
/* Mengecek apakah currentWord == REKOMENDASI */
{
	Word Rekomendasi = StringToWord("REKOMENDASI", 11);

	return IsWordEqual(Rekomendasi, currentWord);
}