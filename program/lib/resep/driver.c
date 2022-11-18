#include "resep.h"

int main()
{
	ListMakanan lm;
    CreateListMakanan(&lm);
    lm = readListMakanan("test/makanan.txt");

	ResepTree Resep;
	ReadFromFile(&Resep, 10, "test/resep_2.txt");
	PrintResep(&lm, &Resep);

	// CreateResepTree(Resep, size);
	
	// STARTFILEWORD("../../../test/resep.txt");

	// int len = WordToInt(currentWord);

	// int i = 0;
	// while (i < len)
	// {
	// 	ADVWORD();
	// 	int id = WordToInt(currentWord);
	// 	ADVWORD();
	// 	int childCount = WordToInt(currentWord);

	// 	int treeList[childCount];

	// 	int j = 0;
	// 	while (j < childCount)
	// 	{
	// 		ADVWORD();
	// 		treeList[j] = WordToInt(currentWord);
	// 		j++;
	// 	}

	// 	boolean hasExisted = false;

	// 	if (DoesIDExist(rt, id))
	// 		hasExisted = true;

	// 	for (int k = 0; k < childCount; k++)
	// 		if (DoesIDExist(rt, treeList[k]))
	// 			hasExisted = true;


	// 	if (hasExisted)
	// 	{
	// 		if (DoesIDExist(rt, id))
	// 		{
	// 			Address temp = FindID(rt, id);

	// 			for (int k = 1; k < childCount; k++)
	// 			{
	// 				Address newNode = NewTree(treeList[k], Nil);
	// 				ConnectChild(newNode, &temp);
	// 			}
	// 		}
	// 		else
	// 		{
	// 			Address temp = NewTree(id, Nil);

	// 			for (int k = 0; k < childCount; k++)
	// 			{
	// 				if (DoesIDExist(rt, treeList[k]))
	// 				{
	// 					Address find = FindID(rt, treeList[k]);

	// 					ConnectChild(find, &temp);

	// 					DeleteTree(&rt, find);
	// 				}
	// 				else
	// 				{
	// 					Address newNode = NewTree(treeList[k], Nil);

	// 					ConnectChild(newNode, &temp);
	// 				}
	// 			}

	// 			TREE(rt, RESEPCOUNT(rt)) = temp;
	// 			RESEPCOUNT(rt)++;
	// 		}
	// 	}
	// 	else
	// 	{
	// 		Address temp = NewTree(id, Nil);

	// 		for (int k = 0; k < childCount; k++)
	// 		{
	// 			Address newNode = NewTree(treeList[k], Nil);
	// 			ConnectChild(newNode, &temp);
	// 		}

	// 		TREE(rt, RESEPCOUNT(rt)) = temp;
	// 		RESEPCOUNT(rt)++;
	// 	}
	// 	i++;
	// }

	// PrintResep(rt);
}