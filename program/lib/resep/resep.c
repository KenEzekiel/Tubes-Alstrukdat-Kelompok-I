#include "resep.h"

void CreateResepTree(ResepTree* Resep, int size)
/*  I.S. : Sembarang
	F.S. : Menghasilkan sebuah pohon resep Resep dengan alokasi size */
{
	LIST(*Resep) = (Tree*) malloc(size * sizeof(Tree*));
	RESEPCOUNT(*Resep) = 0;
	RESEPCAPACITY(*Resep) = size;
}

void DeleteTree(ResepTree* Resep, Tree t)
/*  Menghapus Tree yang terdapat dalam ResepTree
	I.S. : t terdefinisi, t terdapat dalam Resep
	F.S. : t terhapus dalam Resep, RESEPCOUNT berkurang 1 */
{
	int i = 0;
	while (i < RESEPCOUNT(*Resep))
	{
		if (TREE(*Resep, i) == t)
		{
			RESEPCOUNT(*Resep)--;

			for (int j = i; j < RESEPCOUNT(*Resep); j++)
			{
				TREE(*Resep, j) = TREE(*Resep, j+1);
			}

			break;
		}
		i++;
	}
}

void ReadFromFile(ResepTree* Resep, int size, char* dir)
/* 	Membaca konfigurasi resep dari dir
	I.S. : Resep sembarang, dir terdefinisi
	F.S. : Terbentuk pohon resep */
{
	CreateResepTree(Resep, size);

	STARTFILEWORD(dir);

	int len = WordToInt(currentWord);

	int i = 0;
	while (i < len)
	{
		ADVWORD();
		int id = WordToInt(currentWord);
		ADVWORD();
		int childCount = WordToInt(currentWord);

		int value[childCount];

		int j = 0;
		while (j < childCount)
		{
			ADVWORD();
			value[j] = WordToInt(currentWord);
			j++;
		}

		if (DoesIDExist(*Resep, id))
		{
			Address temp = FindID(*Resep, id);

			for (int k = 0; k < j; k++)
			{
				Address newNode = NewTree(value[k], Nil);
				ConnectChild(newNode, &temp);
			}
		}
		else
		{
			boolean hasExisted = false;

			for (int k = 0; k < j; k++)
				if (DoesIDExist (*Resep, value[k]))
					hasExisted = true;

			Address temp = NewTree(id, Nil);
			if (hasExisted)
			{
				for (int k = 0; k < j; k++)
				{
					if (DoesIDExist(*Resep, value[k]))
					{
						Address find = FindID(*Resep, value[k]);

						ConnectChild(find, &temp);

						DeleteTree(Resep, find);
					}
					else
					{
						Address newNode = NewTree(value[k], Nil);

						ConnectChild(newNode, &temp);
					}
				}
			}
			else
			{
				for (int k = 0; k < j; k++)
				{
					Address newNode = NewTree(value[k], Nil);
					ConnectChild(newNode, &temp);
				}
			}

			TREE(*Resep, RESEPCOUNT(*Resep)) = temp;
			RESEPCOUNT(*Resep)++;
		}

		i++;
	}
}

void DisplayCookbook(ListMakanan* Makanan, Tree* t)
/*  Menampilkan list resep pada layar
	I.S. : Makanan dan Resep terdefinisi
	F.S. : Cookbook tercetak pada layar */
{
	int idx = indexOfID(*Makanan, ROOT(*t));
   
   displayString(Nama(*Makanan[idx])); printf("\n");
   displayString(Aksi(*Makanan[idx])); printf(" - ")

   for (int i = 0; i < COUNT(*t); i++)
   {
   	int childIdx = indexOfID(*Makanan, ROOT(SUBTREE(*t,i)));

	   displayString(Nama(*Makanan[childIdx])); printf(" - ");
   }
   printf("\n");

   for (int i = 0; i < COUNT(*t); i++)
   	if (!HasNoChild(SUBTREE(*t,i)))
   		DisplayCookbook(*Makanan, SUBTREE(*t,i));
}

void PrintResep(ListMakanan* Makanan, ResepTree* Resep)
/* I.S. : Resep terdefinisi
   F.S. : ResepTree tercetak, tiap tree dipisahkan dengan enter */
{
	for (int i = 0; i < RESEPCOUNT(*Resep); i++)
	{
		DisplayCookbook(Makanan, &TREE(*Resep,i));
		PrintTree(TREE(*Resep,i));
	}
}

boolean TraverseTree(Tree t, int ID)
/* Mengirimkan true jika ID terdapat pada Tree */
{
	if (ROOT(t) == ID)
		return true;

	boolean retValue = false;

	int i = 0;
	while (i < COUNT(t) && !retValue)
	{
		retValue |= TraverseTree(SUBTREE(t,i), ID);
		i++;
	}

	return retValue;
}

boolean DoesIDExist(ResepTree Resep, int ID)
/*  Mengirimkan true jika ID terdapat pada ResepTree */
{
	boolean retValue = false;

	int i = 0;
	while (i < RESEPCOUNT(Resep) && !retValue)
	{
		retValue = TraverseTree(TREE(Resep, i), ID);
		i++;
	}

	return retValue;
}

Address FindTreeNode(Tree t, int ID)
/* Mengirimkan Address pada Tree dengan nilai ID */
{
	if (ROOT(t) == ID)
		return t;

	Address temp = NULL;

	int i = 0;
	while (i < COUNT(t) && temp == NULL)
	{
		temp = FindTreeNode(SUBTREE(t,i), ID);
		i++;
	}

	return temp;
}

Address FindID(ResepTree Resep, int ID)
/* Mengirimkan Address pada ResepTree dengan nilai ID */
{
	Address temp = NULL;

	int i = 0;
	while (i < RESEPCOUNT(Resep) && temp == NULL)
	{
		temp = FindTreeNode(TREE(Resep, i), ID);
		i++;
	}

	return temp;
}