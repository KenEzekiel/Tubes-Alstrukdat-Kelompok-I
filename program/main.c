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

	PushUndoStack(&US, State(BNMO));
}

int main()
{
	displaySplashScreen("lib/utility/SplashScreen.txt");
	printf("User input: ");
	STARTWORD();

	if (IsSTART())
	{

		/* Menginisiasi nilai variable konstan/global */
		InitializeVariables();

		/* Jalan hingga game over(?) */
		boolean isRunning = true;
		while (isRunning)
		{
			PrintGUI(TimeState(State(BNMO)), Position(State(BNMO)), InventoryState(State(BNMO)), BNMO, Map, listNotif);
			CreateNotif(&listNotif);

			if (IsBUY())
			{
				buy(&DeliveryListState(State(BNMO)), DaftarMakanan);
				UpdateActionTime(&State(BNMO));
				PushUndoStack(&US, State(BNMO));
				updateNotif(&State(BNMO), &listNotif);
			}
			else if (IsDELIVERY())
			{
				displayDeliveryList(DeliveryListState(State(BNMO)));
			}
			else if (IsMOVE())
			{
				ADVWORD();
				boolean gerak = false;
				if (IsNORTH())
				{
					MoveNorth(&Map, &gerak);
					MoveN(&Position(State(BNMO)));
				}
				else if (IsEAST())
				{
					MoveEast(&Map, &gerak);
					MoveE(&Position(State(BNMO)));
				}
				else if (IsSOUTH())
				{
					MoveSouth(&Map, &gerak);
					MoveS(&Position(State(BNMO)));
				}
				else if (IsWEST())
				{
					MoveWest(&Map, &gerak);
					MoveW(&Position(State(BNMO)));
				}

				if (gerak)
				{
					UpdateActionTime(&State(BNMO));
					PushUndoStack(&US, State(BNMO));
					updateNotif(&State(BNMO), &listNotif);
				}
				else
				{
					warningNotif(&listNotif);
				}
			}
			else if (IsMIX())
			{

				if (CanMix(Map))
				{
					ListMakanan lfiltered;
					String aksi = wordToString(currentWord);
					displayFilteredAksi(aksi, DaftarMakanan, &lfiltered);
					int i;
					do
					{
						printf("Enter command: ");
						STARTWORD();
						i = WordToInt(currentWord);
					} while (i < 0 || i > listMakananLength(lfiltered));
					process(aksi, i, &DaftarMakanan, InventoryState(State(BNMO)), &lfiltered, &ProcessedList(State(BNMO)), Resep);
					UpdateActionTime(&State(BNMO));
					PushUndoStack(&US, State(BNMO));
					updateNotif(&State(BNMO), &listNotif);
				}
				else
				{
					String aksi = wordToString(currentWord);
					printf("BNMO tidak berada pada area ");
					displayString(aksi);
					printf("!\n");
				}
			}
			else if (IsCHOP())
			{
				if (CanChop(Map))
				{
					ListMakanan lfiltered;
					String aksi = wordToString(currentWord);
					displayFilteredAksi(aksi, DaftarMakanan, &lfiltered);
					int i;
					do
					{
						printf("Enter command: ");
						STARTWORD();
						i = WordToInt(currentWord);
					} while (i < 0 || i > listMakananLength(lfiltered));
					process(aksi, i, &DaftarMakanan, InventoryState(State(BNMO)), &lfiltered, &ProcessedList(State(BNMO)), Resep);
					UpdateActionTime(&State(BNMO));
					PushUndoStack(&US, State(BNMO));
					updateNotif(&State(BNMO), &listNotif);
				}
				else
				{
					String aksi = wordToString(currentWord);
					printf("BNMO tidak berada pada area ");
					displayString(aksi);
					printf("!\n");
				}
			}
			else if (IsFRY())
			{
				if (CanFry(Map))
				{
					ListMakanan lfiltered;
					String aksi = wordToString(currentWord);
					displayFilteredAksi(aksi, DaftarMakanan, &lfiltered);
					int i;
					do
					{
						printf("Enter command: ");
						STARTWORD();
						i = WordToInt(currentWord);
						printf("\n");
					} while (i < 0 || i > listMakananLength(lfiltered));
					process(aksi, i, &DaftarMakanan, InventoryState(State(BNMO)), &lfiltered, &ProcessedList(State(BNMO)), Resep);
					UpdateActionTime(&State(BNMO));
					PushUndoStack(&US, State(BNMO));
					updateNotif(&State(BNMO), &listNotif);
				}
				else
				{
					String aksi = wordToString(currentWord);
					printf("BNMO tidak berada pada area ");
					displayString(aksi);
					printf("!\n");
				}
			}
			else if (IsBOIL())
			{
				if (CanBoil(Map))
				{
					ListMakanan lfiltered;
					String aksi = wordToString(currentWord);
					displayFilteredAksi(aksi, DaftarMakanan, &lfiltered);
					int i;
					do
					{
						printf("Enter command: ");
						STARTWORD();
						i = WordToInt(currentWord);
					} while (i < 0 || i > listMakananLength(lfiltered));
					process(aksi, i, &DaftarMakanan, InventoryState(State(BNMO)), &lfiltered, &ProcessedList(State(BNMO)), Resep);
					UpdateActionTime(&State(BNMO));
					PushUndoStack(&US, State(BNMO));
					updateNotif(&State(BNMO), &listNotif);
				}
				else
				{
					String aksi = wordToString(currentWord);
					printf("BNMO tidak berada pada area ");
					displayString(aksi);
					printf("!\n");
				}
			}
			else if (IsWAIT())
			{
				TIME temptime;
				int X, Y;
				ADVWORD();
				X = WordToInt(currentWord);
				ADVWORD();
				Y = WordToInt(currentWord);
				CreateTime(&temptime, 0, X, Y);
				UpdateWaitTime(&State(BNMO), temptime);

				PushUndoStack(&US, State(BNMO));
				updateNotif(&State(BNMO), &listNotif);
			}
			else if (IsINSERTKULKAS())
			{
				procInsertToKulkas(&K, &InventoryState(State(BNMO)));
			}
			else if (IsGETKULKAS())
			{
				procGetFromKulkas(&K, &InventoryState(State(BNMO)));
			}
			else if (IsUNDO())
			{
				State temp;
				PopUndoStack(&US, &temp);
				State(BNMO) = StateTop(US);
				PushRedoStack(&RS, temp);
				Teleport(&Map, Position(State(BNMO)));
				updateUndoNotif(State(BNMO), temp, &listNotif);
			}
			else if (IsREDO())
			{
				State temp;
				PopRedoStack(&RS, &temp);
				State(BNMO) = temp;
				updateRedoNotif(State(BNMO), StateTop(US), &listNotif);
				PushUndoStack(&US, temp);
				Teleport(&Map, Position(State(BNMO)));
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