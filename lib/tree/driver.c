#include <stdio.h>
#include "tree.h"

int main()
{
	Tree t; CreateTree(1, Nil, &t); 
	PrintTree(t); printf("\n");
	printf("Is empty: %d\n", HasNoChild(t));

	Tree c1 = NewTree(2, Nil);
	ConnectChild(c1, &t);
	PrintTree(t); printf("\n");
	printf("Is one element: %d\n", HasOneChild(t));

	Tree c2 = NewTree(3, Nil);
	ConnectParent(c2, &t);
	PrintTree(t); printf("\n");

	// Tree c2 = NewTree(3, Nil);
	// ConnectChild(c2, &t);
	// PrintTree(t); printf("\n");
	// printf("Is empty: %d\n", HasNoChild(t));

	// Tree c3 = NewTree(4, Nil);
	// ConnectChild(c3, &t);
	// PrintTree(t); printf("\n");
	// printf("Is one element: %d\n", HasOneChild(t));

	// Tree c4 = NewTree(5, Nil);
	// ConnectChild(c4, &t);
	// PrintTree(t); printf("\n");

	// Tree c5 = NewTree(6, Nil);
	// ConnectChild(c5, &t);
	// PrintTree(t); printf("\n");

	// Tree c6 = NewTree(7, Nil);
	// ConnectChild(c6, &t);
	// PrintTree(t); printf("\n");

	DeallocateTree(t);
}