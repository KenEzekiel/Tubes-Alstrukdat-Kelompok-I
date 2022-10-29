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
ResepTree Resep;
Peta Peta;

void InitializeVariables()
{
	// Initialize changable variables
	CreateTime(&waktu, 0, 0, 0);
	CreatePoint(&lokasi, 0, 0);
	MakeEmpty(&inventory, 100);
	CreateStartSimulator(&BNMO, "BNMO");

	// Initialize constant variables (read from file)
	ReadFromFile(&Resep, 10, "../test/resep.txt");

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
			else if (IsEXIT())
			{
				break;
			}
		}
	}

	// Keluar dari program
	printf("Terima kasih sudah menggunakan program ini!\n");
}