/* File : string.h */
/* Definisi ADT String */

#include "../boolean.h"
#include "string.h"
#include <stdio.h>

/* ********* AKSES (Selektor) ********* */
/* Jika s adalah String, maka : */
//#define LENGTH(s) (s).length
//#define ELMT(s, i) (s).buffer[(i)]

/* *** Kreator *** */
/* I.S. sembarang */
/* F.S. Sebuah s kosong terbentuk dengan kondisi length = 0 */
/* Proses : Melakukan alokasi, membuat sebuah string kosong */
void CreateString(String *s)
{
    LENGTH(*s) = 0;
}

/* ********* Prototype ********* */
/* Mengirim true jika s kosong */
boolean isStringEmpty(String s)
{
    return LENGTH(s) == 0;
}

/* Mengirim true jika tabel penampung elemen s sudah penuh */
boolean isStringFull(String s)
{
    return LENGTH(s) == CAPACITY;
}

/* Mengirimkan banyaknya elemen string. Mengirimkan 0 jika q kosong. */
int length(String s)
{
    return LENGTH(s);
}

/* *** Primitif Konstruktor *** */

/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. s mungkin kosong, tabel penampung elemen s TIDAK penuh */
/* F.S. s diisi oleh input string */
void readString(String *s)
{
    // KAMUS LOKAL
    int n, i = 0;
    char string[CAPACITY];
    char *c;
    // ALGORITMA
    CreateString(s);
    printf("Masukkan string: ");
    scanf("%s", string);
    for (c = &string[0]; *c != '\0'; c++)
    {
        s->buffer[i] = *c;
        i++;
    }
    LENGTH(*s) = i;
}

/* *** Display *** */

/* Proses : Menuliskan isi String dengan traversal, */
/* I.S. s boleh kosong */
/* F.S. Jika s tidak kosong: "s1s2s3" */
/* Jika String kosong : menulis "" */
void displayString(String s)
{
    // KAMUS LOKAL
    int i;
    // ALGORITMA
    if (LENGTH(s) == 0)
    {
        printf("String kosong\n");
    }
    else
    {
        for (i = 0; i < LENGTH(s); i++)
        {
            printf("%c", ELMT(s, i));
        }
        printf("\n");
    }
}

/* *** Operator lain *** */

/* mengembalikan reverse dari String s */
String reverse(String s)
{
    // KAMUS LOKAL
    String temp;
    int i, j = 0;
    // ALGORITMA
    CreateString(&temp);
    LENGTH(temp) = LENGTH(s);
    for (i = LENGTH(s) - 1; i >= 0; i--)
    {
        temp.buffer[j] = ELMT(s, i);
        j++;
    }
    return temp;
}

/* Mengembalikan hasil perbandingan s1 dan s2 */
boolean isStringEqual(String s1, String s2)
{
    // KAMUS LOKAL
    boolean eq = true;
    int i = 0;
    // ALGORITMA
    if (LENGTH(s1) != LENGTH(s2))
    {
        eq = false;
    }
    else
    {
        while (eq && i < LENGTH(s1))
        {
            if (ELMT(s1, i) != ELMT(s2, i))
            {
                eq = false;
            }
            i++;
        }
    }
    return eq;
}

/* ********** MENAMBAH ELEMEN ********** */

/* Proses: Menambahkan c sebagai elemen pertama List */
/* I.S. String s boleh kosong, tetapi tidak penuh */
/* F.S. c adalah elemen pertama s yang baru */
void insertSFirst(String *s, ElType c)
{
    // KAMUS LOKAL
    int i;
    // ALGORITMA
    if (isStringFull(*s) != true)
    {
        for (i = LENGTH(*s); i > 0; i--)
        {
            s->buffer[i] = ELMT(*s, i - 1);
        }
        s->buffer[0] = c;
        LENGTH(*s)
        ++;
    }
}

/* Proses: Menambahkan c sebagai elemen pada index idx String */
/* I.S. String s tidak kosong dan tidak penuh, idx merupakan index yang valid di s */
/* F.S. val adalah elemen yang disisipkan pada index idx l */
void insertSAt(String *s, ElType c, int idx)
{
    // KAMUS LOKAL
    int i;
    // ALGORITMA
    if ((isStringFull(*s) != true) && (isStringEmpty(*s) != true))
    {
        for (i = LENGTH(*s); i > idx; i--)
        {
            s->buffer[i] = ELMT(*s, i - 1);
        }
        s->buffer[idx] = c;
        LENGTH(*s)
        ++;
    }
}

/* Proses: Menambahkan c sebagai elemen terakhir String */
/* I.S. String s boleh kosong, tetapi tidak penuh */
/* F.S. c adalah elemen terakhir s yang baru */
void insertSLast(String *s, ElType c)
{
    // KAMUS LOKAL
    // ALGORITMA
    if (isStringFull(*s) != true)
    {
        s->buffer[LENGTH(*s)] = c;
        LENGTH(*s)
        ++;
    }
}

/* Proses: Menambahkan s2 sebagai substring dari s1 pada indeks terakhir */
/* I.S. String s1 tidak penuh, String s2 tidak kosong , length s1 + length s2 <= CAPACITY */
/* F.S. String s2 menjadi substring dari String s1 */
void insertSubstring(String *s1, String s2)
{
    // KAMUS LOKAL
    int i;
    // ALGORITMA

    if (!isStringFull(*s1) && !isStringEmpty(s2) && LENGTH(*s1) + LENGTH(s2) <= CAPACITY)
    {
        for (i = 0; i < LENGTH(s2); i++)
        {
            s1->buffer[LENGTH(*s1)] = ELMT(s2, i);
            LENGTH(*s1)
            ++;
        }
    }
}

/* ********** MENGHAPUS ELEMEN ********** */

/* *** Menghapus elemen pertama *** */
/* Proses : Menghapus elemen pertama String */
/* I.S. String tidak kosong */
/* F.S. c adalah nilai char pertama s sebelum penghapusan, */
/*      Banyaknya elemen String berkurang satu */
/*      String s mungkin menjadi kosong */
void deleteSFirst(String *s, ElType *c)
{
    // KAMUS LOKAL
    int i;
    // ALGORITMA
    if (isStringEmpty(*s) != true)
    {
        *c = ELMT(*s, 0);

        for (i = 0; i < LENGTH(*s) - 1; i++)
        {
            s->buffer[i] = ELMT(*s, i + 1);
        }
        LENGTH(*s)
        --;
    }
}

/* *** Menghapus elemen pada index tertentu *** */
/* Proses : Menghapus elemen pada index idx String */
/* I.S. List tidak kosong, idx adalah index yang valid di l */
/* F.S. val adalah nilai elemen pada index idx l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
void deleteSAt(String *s, ElType *c, int idx)
{
    // KAMUS LOKAL
    int i;
    // ALGORITMA
    if (isStringEmpty(*s) != true)
    {
        *c = ELMT(*s, idx);

        for (i = idx; i < LENGTH(*s) - 1; i++)
        {
            s->buffer[i] = ELMT(*s, i + 1);
        }
        LENGTH(*s)
        --;
    }
}

/* *** Menghapus elemen terakhir *** */
/* Proses : Menghapus elemen terakhir String */
/* I.S. String tidak kosong */
/* F.S. c adalah nilai elemen terakhir s sebelum penghapusan, */
/*      Banyaknya elemen String berkurang satu */
/*      String s mungkin menjadi kosong */
void deleteSLast(String *s, ElType *c)
{
    // KAMUS LOKAL

    // ALGORITMA
    if (isStringEmpty(*s) != true)
    {
        *c = ELMT(*s, LENGTH(*s) - 1);

        LENGTH(*s)
        --;
    }
}
