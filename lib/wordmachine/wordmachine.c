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


/*
USER INPUT:
START
   Memulai aplikasi dan menginisasi aplikasi dengan membaca file eksternal yang berisi konfigurasi aplikasi
EXIT
   Keluar dari aplikasi
BUY
   Membeli makanan jika berada di lokasi yang sesuai (adjacent dengan "telepon" di peta). 
DELIVERY
   Mencetak semua pemesanan makanan. Barang yang dibeli akan memiliki countdown, jika countdown sudah 0 maka akan masuk ke inventory pemain dan terhapus pada DELIVERY. Notifikasi akan muncul ketika barang telah sampai.
   [Nama - Waktu sisa delivery]
MOVE NORTH
   Menggerakkan pemain ke utara
MOVE EAST
   Menggerakkan pemain ke timur
MOVE WEST
   Menggerakkan pemain ke barat
MOVE SOUTH
   Menggerakkan pemain ke selatan
MIX
   Mencampurkan dua atau lebih makanan menjadi satu. Hanya bisa dilakukan di lokasi mix (M) pada peta.
CHOP
   Memotong satu bahan makanan menjadi bahan yang sudah terpotong. Hanya bisa dilakukan di lokasi chop (C) pada peta.
FRY
   Menggoreng satu atau lebih bahan makanan, selalu memerlukan minyak goreng (atau bahan lain yang didefinisikan pada tree). Hanya bisa dilakukan di lokasi fry (F) pada peta.
BOIL
   Merebus satu bahan makanan. Hanya bisa dilakukan di lokasi boil (B) pada peta.
WAIT x y
   Setiap command yang dijalankan akan berlangsung selama 1 menit. Digunakan untuk mempercepat waktu selama x jam dan y menit.
UNDO
   Membatalkan command yang dilakukan dan mengembalikan ke state sebelumnya.
REDO
   Membatalkan command UNDO.
CATALOG
   Menampilkan bahan dan makanan yang tersedia pada aplikasi termasuk info detailnya. 
   [Nama - Durasi kadaluwarsa - Aksi - Delivery]
COOKBOOK
   Menampilkan resep-resep pada sistem.
   [Nama
    Aksi - Bahan]
INVENTORY
   Menampilkan semua bahan makanan milik pemain. Notifikasi akan muncul ketika barang telah kadaluwarsa.
   [Nama - Waktu sisa kadaluwarsa]

FILE INPUT:
MAKANAN
   - Baris pertama N, jumlah makanan
   - Baris selanjutnya, ID, Judul, Lama Exp., Waktu Pengiriman, Aksi
   - ID bersifat unik, tidak perlu urut, tidak perlu validasi. Jika ganda maka makanan lama akan diganti.
   - Jika didapat bukan dari BUY, waktu pengiriman dibuat menjadi 0 0 0

RESEP
   - Baris pertama N, jumlah resep
   - Baris selanjutnya, ID parent, M child, M buah ID child

PETA
   - Baris pertama N M, dimensi peta. Konfig:
      - '#' kosong
      - 'S' : Simulator/pemain
      - 'T' : Telepon
      - 'M' : Mix
      - 'C' : Chop
      - 'F' : Fry
      - 'B' : Boil
      - 'X' : Tembok/pembatas
*/