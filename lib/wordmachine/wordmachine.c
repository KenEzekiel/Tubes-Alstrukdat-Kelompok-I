/* File: wordmachine.c */
/* Implementasi Word Machine: Model Akuisisi Versi III */

#include <stdio.h>
#include "wordmachine.h"

Word currentWord;

void IgnoreBlanks()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK */
{
   while (currentChar == BLANK)
      ADV();
}

void IgnoreEnters()
/* Mengabaikan satu atau beberapa ENTER
   I.S. : currentChar sembarang
   F.S. : currentChar != BLANK */
{
   while (currentChar == ENTER)
      ADV();
}

void STARTWORD()
/* I.S. : currentChar sembarang
   F.S. : retval = EOF dan mesin berhenti;
          atau retval != EOF, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah kata terakhir kata */
{
   START();
   IgnoreBlanks();
   CopyWord();
}

void STARTFILEWORD(char* dir)
/* I.S. : currentChar sembarang
   F.S. : retval = EOF dan mesin berhenti;
          atau retval != EOF, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah kata terakhir kata */
{
   STARTFILE(dir);
   IgnoreBlanks();
   CopyWord();
}

void ADVWORD()
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, retval mungkin EOF
          Jika retval = EOF, mesin berhenti.
   Proses : Akuisisi kata menggunakan procedure CopyWord */
{
   IgnoreEnters();
   IgnoreBlanks();
   CopyWord();
}

void ADVLINE()
/* I.S. : currentChar adalah karakter pertama baris yang akan diakuisisi
   F.S. : currentWord adalah kumpulan kata pada baris terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, retval mungkin EOF
          Jika retval = EOF, mesin berhenti.
   Proses : Akuisisi kata menggunakan procedure CopyLine */
{
   IgnoreEnters();
   IgnoreBlanks();
   CopyLine();
}

void CopyWord()
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = ENTER, currentChar = BLANK, atau retval = EOF;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
   int i = 0;
   while ((currentChar != ENTER) && (currentChar != BLANK) && (retval != EOF))
   {
      if (i == NMax)
         break;
      currentWord.TabWord[i] = currentChar;
      ADV();
      i++;
   }
   currentWord.Length = i;
}

void CopyLine()
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kumpulan kata pada baris yang sudah diakuisisi;
          currentChar = ENTER atau retval = EOF;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
   int i = 0;
   while ((currentChar != ENTER) && (retval != EOF))
   {
      if (i == NMax)
         break;
      currentWord.TabWord[i] = currentChar;
      ADV();
      i++;
   }
   currentWord.Length = i;
}

void PrintWord()
/* I.S. : currentWord terdefinisi
   F.S. : currentWord tercetak pada layar */
{
   int i;
   for (i = 0; i < currentWord.Length; i++)
      printf("%c", currentWord.TabWord[i]);
   printf("\n");
}

boolean IsWordEqual(Word w1, Word w2)
/* Mengecek apakah w1 sama dengan w2 */
{
   if (w1.Length != w2.Length)
      return false;

   int i = 0;
   while (i < w1.Length)
   {
      if (w1.TabWord[i] != w2.TabWord[i])
         return false;
      i++;
   }

   return true;
}

int WordToInt(Word w)
/* Mengubah array char integer ('0', '1', '2', dst.) menjadi integer */
{
   int sum = 0;

   int i;
   for (i = 0; i < w.Length; i++)
   {
      sum *= 10;
      sum += (w.TabWord[i]-48);
   }

   return sum;
}