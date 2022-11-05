#ifndef NOTIF_H
#define NOTIF_H

#include "../boolean.h"
#include "../../../lib/string/string.h"
#include "../listmakanan/listmakanan.h"
#include "../state/state.h"

/*  Kamus Umum */
#define CAPACITY_NOTIF 100
/* Kapasitas penyimpanan */
#define IDX_MIN_NOTIF 0
/* Indeks minimum list */
#define IDX_UNDEF_NOTIF -1
/* Indeks tak terdefinisi*/
#define MARK_NOTIF 0
/* Nilai elemen tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef String ELTYPE; /* type elemen List */
typedef int IdxType;
typedef struct
{
   ELTYPE contents[CAPACITY]; /* memori tempat penyimpan elemen (container) */
} Notif;
/* Indeks yang digunakan [0..CAPACITY-1] */
/* Jika l adalah ListStatik, cara deklarasi dan akses: */
/* Deklarasi : l : ListStatik */
/* Maka cara akses:
   ELMT(l,i) untuk mengakses elemen ke-i */
/* Definisi :
   List kosong: semua elemen bernilai MARK
   Definisi elemen pertama: ELMT(l,i) dengan i=0 */

/* ********** SELEKTOR ********** */
#define ELMT_N(l, i) (l).contents[(i)]

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateNotif(Notif *listNotif);
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan MARK */

int notifLength(Notif listNotif);
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */

void insertLastNotif(Notif *listNotif, ELTYPE newNotif);
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */

void printNotif(Notif listNotif);
/* Proses: Melakukan iterasi notif dan menampilkan di layar */
/* I.S. List l terdefinisi, boleh kosong */
/* F.S. val adalah elemen terakhir l yang baru */

void addDelivered(ListMakanan delivered, Notif *listNotif);
/* Proses: Menambahkan makanan yang telah terkirim ke notifikasi */
/* I.S. listNotif dan delivered terdefinisi, boleh kosong */
/* F.S. notifikasi dari makanan di delivered masuk sebagai elemen baru listNotif */

void addExpired(ListMakanan expired,  Notif *listNotif);
/* Proses: Menambahkan makanan yang telah expired ke notifikasi */
/* I.S. listNotif dan expired terdefinisi, boleh kosong */
/* F.S. notifikasi dari makanan di expired masuk sebagai elemen baru listNotif */

void updateUndoNotif(State current, State prev, Notif *listNotif);
/* Proses: Menambahkan notifikasi saat dilakukan command undo */
/* I.S. listNotif terdefinisi, boleh kosong, State current dan prev terdefinisi */
/* F.S. Melakukan perbandingan state current dan prev, menambahkan notifikasi sebagai elemen baru listNotif */

void updateRedoNotif(State current, State prev, Notif *listNotif);
/* Proses: Menambahkan notifikasi saat dilakukan command redo */
/* I.S. listNotif terdefinisi, boleh kosong, State current dan prev terdefinisi */
/* F.S. Melakukan perbandingan state current dan prev, menambahkan notifikasi sebagai elemen baru listNotif */

void updateNotif(State *curr, Notif *listNotif);
/* Proses: Menambahkan notifikasi saat dilakukan command selain undo dan redo */
/* I.S. listNotif terdefinisi, boleh kosong, State current terdefinisi */
/* F.S. Menambahkan notifikasi delivered dan expired sebagai elemen baru listNotif */

void warningNotif(Notif *listNotif);
/* Proses: Menambahkan notifikasi peringatan gagal bergerak */

#endif