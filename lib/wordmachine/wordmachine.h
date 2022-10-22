/* File: wordmachine.h */
/* Definisi Word Machine: Model Akuisisi Versi III */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "boolean.h"
#include "charmachine.h"

#define NMax 50
#define BLANK ' '
#define ENTER '\n'

typedef struct
{
   char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Word;

/* State Mesin Word */
extern Word currentWord;

void IgnoreBlanks();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK */

void IgnoreEnters();
/* Mengabaikan satu atau beberapa ENTER
   I.S. : currentChar sembarang
   F.S. : currentChar != BLANK */

void STARTWORD();
/* I.S. : currentChar sembarang
   F.S. : retval = EOF dan mesin berhenti;
          atau retval != EOF, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah kata terakhir kata */

void STARTFILEWORD();
/* I.S. : currentChar sembarang
   F.S. : retval = EOF dan mesin berhenti;
          atau retval != EOF, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah kata terakhir kata */

void ADVWORD();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, retval mungkin EOF
          Jika retval = EOF, mesin berhenti.
   Proses : Akuisisi kata menggunakan procedure CopyWord */

void ADVLINE();
/* I.S. : currentChar adalah karakter pertama baris yang akan diakuisisi
   F.S. : currentWord adalah kumpulan kata pada baris terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, retval mungkin EOF
          Jika retval = EOF, mesin berhenti.
   Proses : Akuisisi kata menggunakan procedure CopyLine */

void CopyWord();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = ENTER, currentChar = BLANK, atau retval = EOF;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void CopyLine();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kumpulan kata pada baris yang sudah diakuisisi;
          currentChar = ENTER atau retval = EOF;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void PrintWord();
/* I.S. : currentWord terdefinisi
   F.S. : currentWord tercetak pada layar */

boolean IsWordEqual(Word w1, Word w2);
/* Mengecek apakah w1 sama dengan w2 */

int WordToInt(Word w);
/* Mengubah array char integer ('0', '1', '2', dst.) menjadi integer */

#endif