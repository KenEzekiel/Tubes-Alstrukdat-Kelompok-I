/* File : tree.h */
/* ADT pohon N-Ary */
/* Representasi Address dengan pointer */
/* ElType adalah Makanan */

#include "tree.h"

Address NewTreeNode(Infotype root)
/* Mengalokasikan sebuah Address t, bernilai Nil jika tidak berhasil */
/* Mengirimkan Address hasil alokasi sebuah elemen bernilai root
   Jika alokasi berhasil, maka Address tidak Nil dan menghasilkan t
   ROOT(t) = val, SUBADDRESS(t) terdefinisi dengan ukuran INITIAL,
   COUNT(t) = 0, dan CAPACITY(t) = INITIAL 
   Jika alokasi gagal, maka mengirimkan Nil */
{
	Address t = (Address) malloc(sizeof(Node));

	if (t != Nil)
	{
		ROOT(t) = root;
		SUBADDRESS(t) = (Address*) malloc(INITIAL * sizeof(Address*));
		COUNT(t) = 0;
		CAPACITY(t) = INITIAL;
	}

	return t;
}

Tree NewTree(Infotype root, Tree child)
/* Jika alokasi berhasil, menghasilkan sebuah pohon dari root dan child;
   dan count bertambah satu jika child bukan Nil
/* Jika alokasi gagal, menghasilkan pohon kosong (Nil) */
{
	Address t = NewTreeNode(root);
	if (t != Nil)
	{
		SUBTREE(t, COUNT(t)) = child;

		if (child != Nil)
			COUNT(t)++;
	}
	return t;
}

void CreateTree(Infotype root, Tree child, Tree *t)
/* I.S. : Sembarang
   F.S. : Menghasilkan sebuah pohon t
   		  Jika alokasi berhasil, menghasilkan sebuah pohon dari root dan child;
   		  dan count bertambah satu jika child bukan Nil
   		  Jika alokasi gagal, menghasilkan pohon kosong (Nil) */
{
	*t = NewTreeNode(root);
	if (*t != Nil)
	{
		SUBTREE(*t, COUNT(*t)) = child;

		if (child != Nil)
			COUNT(*t)++;
	}
}

void ConnectTree(Tree child, Tree *t)
/* I.S. : t dan child terdefinisi
   F.S. : t terhubung dengan child dan count bertambah satu jika child bukan Nil */
{
	// kalau udah penuh
	SUBTREE(*t, COUNT(*t)) = child;

	if (child != Nil)
		COUNT(*t)++;
}

void DeallocateTree(Address t)
/* I.S. : t terdefinisi
   F.S. : t dikembalikan ke sistem
   Melakukan dealokasi/pengembalian Address t */
{
	free(t);
}

boolean HasNoChild(Tree t)
/* Mengirimkan true jika t tidak memiliki child */
{
	if (COUNT(t) == 0)
		return true;
	return false;
}

boolean HasOneChild(Tree t)
/* Mengirimkan true jika t hanya memiliki 1 child */
{
	if (COUNT(t) == 1)
		return true;
	return false;
}

/***** Display Tree *****/
void PrintTree(Tree t)
/* I.S. : t terdefinisi
   F.S. : Semua simpul t sudah dicetak secara preorder: root dan child(ren)
   		  Setiap pohon ditandai dengan tanda kurung buka dan tanda kurung tutup ()
   		  Pohon kosong ditandai dengan () */
{
	if (t == Nil)
	{
		printf("()");
	}
	else
	{
		printf("(");
		printf("%d", ROOT(t));
		int i;
		for (i = 0; i < COUNT(t); i++)
			PrintTree(SUBTREE(t,i));
		printf(")");
	}
}

void ExpandCapacity(Tree *t)
/* Proses: Memperbesar dua kali lipat capacity t */
/* I.S. : t terdefinisi */
/* F.S. : Ukuran SubTree menjadi dua kali lipat ukuran semula */
{
	CAPACITY(*t) *= 2;

	Address *temp = SUBADDRESS(*t);

	SUBADDRESS(*t) = (Address*) malloc(CAPACITY(*t) * sizeof(Address*));
	COUNT(*t) = 0;
	
	int i;
	for (i = 0; i < CAPACITY(*temp); i++)
		SUBTREE(*t,i) = SUBTREE(*temp,i);
}