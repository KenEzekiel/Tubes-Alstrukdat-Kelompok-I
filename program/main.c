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
Notif listNotif;

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
	// CreateNotif(&listNotif);
	CreateUndoStackEmpty(&US);
	CreateRedoStackEmpty(&RS);

	// Initialize constant variables (read from file)
	ReadFromFile(&Resep, 10, "../test/resep.txt");
	StartPeta(&Map);
	DaftarMakanan = readListMakanan("../../test/makanan.txt");
}

int main()
{
	// displaySplashScreen();
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
				boolean gerak=false;
				if (IsNORTH()){
					MoveNorth(&Map,&gerak);
				}
				else if (IsEAST()) {
					MoveNorth(&Map,&gerak);
				} 
				else if (IsSOUTH()){
					MoveSouth(&Map,&gerak);
				}
				else if (IsWEST()) {
					MoveWest(&Map,&gerak);
				}

				if (gerak) {
				PushUndoStack(&US, State(BNMO));
				updateNotif(State(BNMO), &listNotif);
				}
				else {
					
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
}