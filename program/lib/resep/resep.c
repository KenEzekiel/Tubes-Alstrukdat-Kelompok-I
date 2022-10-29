#include "resep.h"

boolean DoesIDExist(Tree* Resep, int id)
{

}

Address FindAddress

void ReadFromFile(Tree** Resep, char* dir)
/* 	Membaca konfigurasi resep dari dir
	I.S. : Resep sembarang, dir terdefinisi
	F.S. : Terbentuk pohon resep */
{
	*Resep = (Address) malloc(10*sizeof(Node));
	int index = 0;


	STARTFILEWORD("../../../test/resep.txt");

	int len = WordToInt(currentWord);

	int i = 0;
	while (i < len)
	{
		ADVWORD();
		int id = WordToInt(currentWord);

		if (DoesIDExist(Resep, id))
		{
			ConnectChild(FindAddress(Resep, id), Resep);
		}
		else
		{
			Resep[index] = newTree(id, Nil);
		}
			

		ADVWORD();
		int childCount = WordToInt(currentWord);

		int j = 0;
		while (j < childCount)
		{
			ADVWORD();
			int childID = WordToInt(currentWord);

			ConnectChild(FindAddress(Resep, id), Resep);
		}
		i++;
	}
}