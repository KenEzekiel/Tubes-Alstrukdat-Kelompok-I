#ifndef PROCESS_H
#define PROCESS_H

#include "../../../lib/simulator/simulator.h"
#include "../undostack/undostack.h"
#include "../redostack/redostack.h"
#include "../notifikasi/notifikasi.h"
#include "../resep/resep.h"

void buyMechanism(State *S, ListMakanan LM, stackaddr US, Notif *listNotif);

void olahMechanism(String aksi, State *S, ListMakanan LM, ResepTree Resep,stackaddr US, Notif *listNotif);

#endif