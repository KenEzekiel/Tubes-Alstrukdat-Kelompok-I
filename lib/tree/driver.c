#include <stdio.h>
#include "tree.h"

int main()
{
	Tree t; CreateTree(1, Nil, &t);
	PrintTree(t); printf("\n");
	printf("Is empty: %d\n", HasNoChild(t));

	Tree c1 = NewTree(2, Nil);
	ConnectTree(c1, &t);
	PrintTree(t); printf("\n");
	printf("Is one element: %d\n", HasOneChild(t));

	Tree c2 = NewTree(3, Nil);
	ConnectTree(c2, &t);
	PrintTree(t); printf("\n");
	printf("Is empty: %d\n", HasNoChild(t));

	Tree c3 = NewTree(4, Nil);
	ConnectTree(c3, &t);
	PrintTree(t); printf("\n");
	printf("Is one element: %d\n", HasOneChild(t));

	Tree c4 = NewTree(5, Nil);
	ConnectTree(c4, &t);
	PrintTree(t); printf("\n");

	Tree c5 = NewTree(6, Nil);
	ConnectTree(c5, &t);
	PrintTree(t); printf("\n");

	Tree c6 = NewTree(7, Nil);
	ConnectTree(c6, &t);
	PrintTree(t); printf("\n");

	DeallocateTree(t);
}