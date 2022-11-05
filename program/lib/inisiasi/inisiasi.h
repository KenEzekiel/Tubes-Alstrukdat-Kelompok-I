#ifndef INISIASI
#define INISIASI

#include "../../../lib/wordmachine/wordmachine.h"
#include "../inventory/inventory.h"
#include "../notifikasi/notifikasi.h"
#include "../peta/peta.h"
#include "../../../lib/simulator/simulator.h"
#include "../../../lib/time/time.h"
#include "../../../lib/point/point.h"

void PrintGUI(TIME Waktu, POINT Lokasi, Inventory Inventory, Simulator BNMO, Peta Peta, Notif listNotif);

void ScanWord();
/* 	Menerima input dari pengguna
	I.S. : currentChar sembarang 
   	F.S. : mencetak GUI, currentWord terdefinisi */

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