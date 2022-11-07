#include <stdio.h>
#include "wordmachine.h"

int main()
{
	printf("hello");
	STARTFILEWORD("test/makanan.txt");

	int len = WordToInt(currentWord);
	printf("%d\n", len);

	int i;
	for (i = 0; i < len; i++)
	{
		ADVWORD(); printf("ID: "); PrintWord();
		ADVLINE(); printf("Nama: "); PrintWord();

		ADVWORD(); printf("Lama Exp.: "); PrintWord();
		ADVWORD(); PrintWord();
		ADVWORD(); PrintWord();

		ADVWORD(); printf("Waktu pengiriman: "); PrintWord();
		ADVWORD(); PrintWord();
		ADVWORD(); PrintWord();

		ADVWORD(); printf("Aksi: "); PrintWord();
	}
}