#include <stdio.h>
// #include "lib/utility/utility.h"
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
Notif listNotif;
Kulkas K;

// Constant variables
ListMakanan DaftarMakanan;
ResepTree Resep;
Peta Map;
String user;

void InitializeVariables()
{
	// Initialize changable variables
	printf("Input user: ");
	readString(&user);
	CreateStartSimulator(&BNMO, user);
	;
	CreateUndoStackEmpty(&US);
	CreateRedoStackEmpty(&RS);
	CreateKulkas(&K, 20, 30);

	// // Initialize constant variables (read from file)
	ReadFromFile(&Resep, 10, "../test/resep_2.txt");
	StartPeta(&Map, "../test/peta.txt");
	CreateListMakanan(&DaftarMakanan);
	DaftarMakanan = readListMakanan("../test/makanan.txt");
}

int main()
{
	displaySplashScreen("lib/utility/SplashScreen.txt");
	STARTWORD();

	if (IsSTART())
	{

		/* Menginisiasi nilai variable konstan/global */
		InitializeVariables();

		/* Jalan hingga game over(?) */
		boolean isRunning = true;
		while (isRunning)
		{
			CreateNotif(&listNotif);
			PrintGUI(TimeState(State(BNMO)), Position(State(BNMO)), InventoryState(State(BNMO)), BNMO, Map, listNotif);

			if (IsBUY())
			{
				PushUndoStack(&US, State(BNMO));
				updateNotif(State(BNMO), &listNotif);
			}
			else if (IsDELIVERY())
			{
				PushUndoStack(&US, State(BNMO));
				updateNotif(State(BNMO), &listNotif);
			}
			else if (IsMOVE())
			{
				ADVWORD();
				boolean gerak = false;
				if (IsNORTH())
				{
					MoveNorth(&Map, &gerak);
				}
				else if (IsEAST())
				{
					MoveEast(&Map, &gerak);
				}
				else if (IsSOUTH())
				{
					MoveSouth(&Map, &gerak);
				}
				else if (IsWEST())
				{
					MoveWest(&Map, &gerak);
				}

				if (gerak)
				{
					PushUndoStack(&US, State(BNMO));
					updateNotif(State(BNMO), &listNotif);
					UpdateActionTime(&DeliveryListState(State(BNMO)), &InventoryState(State(BNMO)), &TimeState(State(BNMO)), &ExpListState(State(BNMO)), &DeliveredListState(State(BNMO)), &ProcessedList(State(BNMO)));
				}
				else
				{
				}
			}
			else if (IsMIX())
			{
				PushUndoStack(&US, State(BNMO));
				updateNotif(State(BNMO), &listNotif);
			}
			else if (IsCHOP())
			{
				PushUndoStack(&US, State(BNMO));
				updateNotif(State(BNMO), &listNotif);
			}
			else if (IsFRY())
			{
				PushUndoStack(&US, State(BNMO));
				updateNotif(State(BNMO), &listNotif);
			}
			else if (IsBOIL())
			{
				PushUndoStack(&US, State(BNMO));
				updateNotif(State(BNMO), &listNotif);
			}
			else if (IsWAIT())
			{
				PushUndoStack(&US, State(BNMO));
				updateNotif(State(BNMO), &listNotif);
			}
			else if (IsUNDO())
			{
				State temp;
				PopUndoStack(&US, &temp);
				State(BNMO) = StateTop(US);
				PushRedoStack(&RS, temp);
				updateUndoNotif(State(BNMO), temp, &listNotif);
			}
			else if (IsREDO())
			{
				State temp;
				PopRedoStack(&RS, &temp);
				State(BNMO) = temp;
				updateRedoNotif(State(BNMO), StateTop(US), &listNotif);
				PushUndoStack(&US, temp);
			}
			else if (IsCATALOG())
			{
				printCatalog(DaftarMakanan);
			}
			else if (IsCOOKBOOK())
			{
				PrintResep(&DaftarMakanan, &Resep);
			}
			else if (IsINVENTORY())
			{
				displayInventory(InventoryState(State(BNMO)));
			}
			else if (IsEXIT())
			{
				isRunning = false;
			}
		}
	}

	// Keluar dari program
	printf("Terima kasih sudah menggunakan program ini!\n");

	return 0;
}

// gcc main.c lib/deliverylist/deliverylist.c lib/inisiasi/inisiasi.c lib/inventory/inventory.c lib/listmakanan/listmakanan.c lib/notifikasi/notifikasi.c lib/olahmakanan/olahmakanan.c lib/peta/peta.c lib/redostack/redostack.c lib/resep/resep.c lib/state/state.c lib/statestack/statestack.c lib/undostack/undostack.c lib/utility/utility.c lib/waktusim/mekawaktu.c ../lib/liststatik/liststatik.c ../lib/makanan/makanan.c ../lib/matrix/matrix.c ../lib/point/point.c ../lib/queue/queue.c ../lib/simulator/simulator.c ../lib/stack/stack.c ../lib/string/string.c ../lib/time/time.c ../lib/tree/tree.c ../lib/wordmachine/wordmachine.c ../lib/wordmachine/charmachine.c ../lib/queue/prioqueuetime.c -lm; ./a.out