#include <stdio.h>
#include "main.h"

/***** Global Variable *****/
// Changable variables
TIME Waktu;
POINT Lokasi;
Inventory Inv;
Simulator BNMO;

// Constant variables
ListMakanan Makanan;
ResepTree Resep;
Peta Map;
String user;

void InitializeVariables()
{
	// Initialize changable variables
	CreateTime(&Waktu, 0, 0, 0);
	CreatePoint(&Lokasi, 0, 0);
	MakeEmpty(&Inv, 100);
	readString(&user);
	CreateStartSimulator(&BNMO, user);

	// Initialize constant variables (read from file)
	ReadFromFile(&Resep, 10, "../test/resep.txt");
	Makanan = readListMakanan("../../test/makanan.txt");
}

int main()
{
	STARTWORD();

	if (IsSTART())
	{
		displaySplashScreen();

		/* Menginisiasi nilai variable konstan/global */
		InitializeVariables();

		/* Jalan hingga game over(?) */
		boolean isRunning = true;
		while (isRunning)
		{
			PrintGUI(Waktu, Lokasi, Inv, BNMO, Map);

			if (IsBUY())
			{
			}
			else if (IsDELIVERY())
			{
			}
			else if (IsMOVE())
			{
			}
			else if (IsMIX())
			{
			}
			else if (IsCHOP())
			{
			}
			else if (IsFRY())
			{
			}
			else if (IsBOIL())
			{
			}
			else if (IsWAIT())
			{
			}
			else if (IsUNDO())
			{
			}
			else if (IsREDO())
			{
			}
			else if (IsCATALOG())
			{
			}
			else if (IsCOOKBOOK())
			{
			}
			else if (IsINVENTORY())
			{
			}
			else if (IsEXIT())
			{
				break;
			}
		}
	}

	// Keluar dari program
	printf("Terima kasih sudah menggunakan program ini!\n");
}