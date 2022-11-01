#include <stdio.h>
#include "main.h"

/***** Global Variable *****/
// Changable variables
// TIME Waktu;
// POINT Lokasi;
// Inventory Inv;
// Masuk kedalam Simulator.State
Simulator BNMO;
UndoStack US;
RedoStack RS;

// Constant variables
ListMakanan Makanan;
ResepTree Resep;
Peta Map;
String user;

void InitializeVariables()
{
	// Initialize changable variables

	readString(&user);
	CreateStartSimulator(&BNMO, user);

	CreateUndoStackEmpty(&US);
	CreateRedoStackEmpty(&RS);

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
			PrintGUI(TimeState(State(BNMO)), Position(State(BNMO)), InventoryState(State(BNMO)), BNMO, Map);

			if (IsBUY())
			{
				PushUndoStack(&US, State(BNMO));
			}
			else if (IsDELIVERY())
			{
				// PushUndoStack(&US, State(BNMO));
				// mengubah state ga?
			}
			else if (IsMOVE())
			{
				PushUndoStack(&US, State(BNMO));
			}
			else if (IsMIX())
			{
				PushUndoStack(&US, State(BNMO));
			}
			else if (IsCHOP())
			{
				PushUndoStack(&US, State(BNMO));
			}
			else if (IsFRY())
			{
				PushUndoStack(&US, State(BNMO));
			}
			else if (IsBOIL())
			{
				PushUndoStack(&US, State(BNMO));
			}
			else if (IsWAIT())
			{
				PushUndoStack(&US, State(BNMO));
			}
			else if (IsUNDO())
			{
				State temp;
				PopUndoStack(&US, &temp);
				State(BNMO) = temp;
				PushRedoStack(&RS, temp);
			}
			else if (IsREDO())
			{
				State temp;
				PopRedoStack(&RS, &temp);
				State(BNMO) = temp;
				PushUndoStack(&US, temp);
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