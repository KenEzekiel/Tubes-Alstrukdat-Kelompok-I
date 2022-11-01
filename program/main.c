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

void InitializeVariables()
{
	// Initialize changable variables
	CreateTime(&Waktu, 0, 0, 0);
	CreatePoint(&Lokasi, 0, 0);
	MakeEmpty(&Inv, 100);
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
				DisplayCatalog(&Makanan);
			}
			else if (IsCOOKBOOK())
			{
				PrintResep(&Makanan, &Resep);
			}
			else if (IsINVENTORY())
			{
			}
			else if (IsEXIT())
			{
				isRunning = false;
			}
		}
	}

	// Keluar dari program
	printf("Terima kasih sudah menggunakan program ini!\n");
}