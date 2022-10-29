#ifndef RESEP
#define RESEP

#include "../../../lib/tree/tree.h"
#include "../../../lib/wordmachine/wordmachine.h"

/* Selektor */
#define LIST(t) (t).T
#define TREE(t,i) (t).T[i]
#define RESEPCOUNT(t) (t).Count
#define RESEPCAPACITY(t) (t).Capacity

typedef struct
{
	Tree* T;
	int Count;
	int Capacity;
} ResepTree;

void CreateResepTree(ResepTree* rt, int size);
/*  I.S. : Sembarang
	F.S. : Menghasilkan sebuah pohon resep rt dengan alokasi size */

void ReadFromFile(ResepTree* Resep, int size, char* dir);
/* 	Membaca konfigurasi resep dari dir
	I.S. : Resep sembarang, dir terdefinisi
	F.S. : Terbentuk pohon resep */

void PrintResep(ResepTree Resep);
/* I.S. : Resep terdefinisi
   F.S. : ResepTree tercetak, tiap tree dipisahkan dengan enter */

boolean TraverseTree(Tree t, int ID);
/* Mengirimkan true jika ID terdapat pada Tree */

boolean DoesIDExist(ResepTree Resep, int ID);
/*  Mengirimkan true jika ID terdapat pada ResepTree */

Address FindTreeNode(Tree t, int ID);
/* Mengirimkan Address pada Tree dengan nilai ID */

Address FindID(ResepTree Resep, int ID);
/* Mengirimkan Address dengan nilai ID */

int FindResepCount(ResepTree Resep, int ID);

void DeleteTree(ResepTree* Resep, Tree t);
/*  Menghapus Tree yang terdapat dalam ResepTree
	I.S. : t terdefinisi, t terdapat dalam Resep
	F.S. : t terhapus dalam Resep, RESEPCOUNT berkurang 1 */

#endif