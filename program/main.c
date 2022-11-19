#include <stdio.h>
#include "main.h"

/***** Global Variable *****/
// Changable variables
// Masuk kedalam Simulator.State
Simulator BNMO;
stackaddr US;
stackaddr RS;
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
	print_yellow("Masukkan nama user: ");
	readString(&user);
	CreateStartSimulator(&BNMO, user);

	US = CreateUndoStackEmpty();
	RS = CreateRedoStackEmpty();
	CreateKulkas(&K, 20, 30);

	// Initialize constant variables (read from file)
	ReadFromFile(&Resep, 10, "test/resep_2.txt");
	StartPeta(&Map, "test/peta.txt");
	CreateListMakanan(&DaftarMakanan);
	DaftarMakanan = readListMakanan("test/makanan.txt");
	Position(State(BNMO)) = cariSimul(Map);
}

int main()
{
	displaySplashScreen("program/lib/utility/SplashScreen.txt");
	print_cyan("Enter Command: ");
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
				if (CanBuy(Map))
				{
					buyMechanism(&State(BNMO), DaftarMakanan, US, &listNotif);
					ClearRedoStack(RS);
					RS = CreateRedoStackEmpty();
				}
				else
				{
					String aksi = wordToString(currentWord);
					printf("BNMO tidak berada pada area ");
					displayString(aksi);
					printf("!\n");
				}
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
					if (gerak)
					{
						PushUndoStack(US, State(BNMO));
						initializeNotif(&State(BNMO));
						ClearRedoStack(RS);
						RS = CreateRedoStackEmpty();
						UpdateActionTime(&State(BNMO));
						updateNotif(&State(BNMO), &listNotif);
						MoveN(&Position(State(BNMO)));
					}
					else
					{
						warningNotif(&listNotif);
					}
				}
				else if (IsEAST())
				{
					MoveEast(&Map, &gerak);
					if (gerak)
					{
						PushUndoStack(US, State(BNMO));
						initializeNotif(&State(BNMO));
						ClearRedoStack(RS);
						RS = CreateRedoStackEmpty();
						UpdateActionTime(&State(BNMO));
						updateNotif(&State(BNMO), &listNotif);
						MoveE(&Position(State(BNMO)));
					}
					else
					{
						warningNotif(&listNotif);
					}
				}
				else if (IsSOUTH())
				{
					MoveSouth(&Map, &gerak);
					if (gerak)
					{
						PushUndoStack(US, State(BNMO));
						initializeNotif(&State(BNMO));
						ClearRedoStack(RS);
						RS = CreateRedoStackEmpty();
						UpdateActionTime(&State(BNMO));
						updateNotif(&State(BNMO), &listNotif);
						MoveS(&Position(State(BNMO)));
					}
					else
					{
						warningNotif(&listNotif);
					}
				}
				else if (IsWEST())
				{
					MoveWest(&Map, &gerak);
					if (gerak)
					{
						PushUndoStack(US, State(BNMO));
						initializeNotif(&State(BNMO));
						ClearRedoStack(RS);
						RS = CreateRedoStackEmpty();
						UpdateActionTime(&State(BNMO));
						updateNotif(&State(BNMO), &listNotif);
						MoveW(&Position(State(BNMO)));
					}
					else
					{
						warningNotif(&listNotif);
					}
				}
				else 
				{
					print_red("Masukan tidak valid! Silahkan ulangi...\n");
				}
			}
			else if (IsMIX())
			{

				if (CanMix(Map))
				{
					String aksi = wordToString(currentWord);
					olahMechanism(aksi, &State(BNMO), DaftarMakanan, Resep, US, &listNotif);
					ClearRedoStack(RS);
					RS = CreateRedoStackEmpty();
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
					String aksi = wordToString(currentWord);
					olahMechanism(aksi, &State(BNMO), DaftarMakanan, Resep, US, &listNotif);
					ClearRedoStack(RS);
					RS = CreateRedoStackEmpty();
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
					String aksi = wordToString(currentWord);
					olahMechanism(aksi, &State(BNMO), DaftarMakanan, Resep, US, &listNotif);
					ClearRedoStack(RS);
					RS = CreateRedoStackEmpty();
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
					String aksi = wordToString(currentWord);
					olahMechanism(aksi, &State(BNMO), DaftarMakanan, Resep, US, &listNotif);
					ClearRedoStack(RS);
					RS = CreateRedoStackEmpty();
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
				PushUndoStack(US, State(BNMO));
				initializeNotif(&State(BNMO));
				ClearRedoStack(RS);
				RS = CreateRedoStackEmpty();
				UpdateWaitTime(&State(BNMO), temptime);
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
			else if (IsDISPLAYKULKAS())
			{
				displayKulkas(K);
			}
			else if (IsUNDO())
			{
				State temp;
				if (!IsUndoStackEmpty(US))
				{
					PushRedoStack(RS, State(BNMO));
					PopUndoStack(US, &temp);
					updateUndoNotif(temp, State(BNMO), &listNotif);
					State(BNMO) = temp;
					Teleport(&Map, Position(State(BNMO)));
				}
				else
				{
					print_red("Undo stack kosong!\n");
				}
			}
			else if (IsREDO())
			{
				if (!IsRedoStackEmpty(RS))
				{
					State temp;
					PopRedoStack(RS, &temp);
					PushUndoStack(US, State(BNMO));
					updateRedoNotif(temp, State(BNMO), &listNotif);
					State(BNMO) = temp;

					Teleport(&Map, Position(State(BNMO)));
				}
				else
				{
					print_red("Redo stack kosong!\n");
				}
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
			else if (IsREKOMENDASI())
			{
				printRekomendasiMakanan(DaftarMakanan, &InventoryState(State(BNMO)), Resep);
			}
			else if (IsEXIT())
			{
				isRunning = false;
			}
			else 
			{
				print_red("Masukan tidak valid! Silahkan ulangi...\n");
			}
		}
	}

	// Keluar dari program
	print_green("Terima kasih sudah menggunakan program ini!\n");

	return 0;
}