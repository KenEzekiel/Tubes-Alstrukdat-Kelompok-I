#include <stdio.h>
#include "main.h"

/***** Global Variable *****/
// Changable variables
TIME Waktu;
Point Lokasi;
Inventory Inventory;
Simulator BNMO;

// Constant variables
ListStatik Makanan;
Tree Resep;
Peta Peta;

void InitializeVariables()
{
	// Initialize changable variables
	TIME waktu;
	CreateTime(&waktu, 0, 0, 0);
	Point lokasi;
	CreatePoint(&lokasi, 0, 0);
	Inventory inventory;
	MakeEmpty(&inventory, 100);
	Simulator BNMO;
	CreateStartSimulator(&BNMO, "BNMO");

	// Initialize constant variables (read from file)
}

int main()
{
	STARTWORD();

	if (IsSTART())
	{
		// PrintASCII();

		/* Menginisiasi nilai variable konstan/global */
		InitializeVariables();

		/* Jalan hingga game over(?) */
		boolean isRunning = true;
		while (isRunning)
		{
			PrintGUI(Waktu, Lokasi, Inventory, BNMO, Peta);

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
		}
	}

	// Keluar dari program
	printf("Terima kasih sudah menggunakan program ini!\n");
}