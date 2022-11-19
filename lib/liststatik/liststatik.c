/* MODUL LIST INTEGER STATIK DENGAN ELEMEN POSITIF */
/* Berisi definisi dan semua primitif pemrosesan list integer statik dengan elemen positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori list statik */

#include "liststatik.h"
#include <stdio.h>
#include "../boolean.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListStatik(ListStatik *l)
{
    /* I.S. l sembarang */
    /* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
    /* Proses: Inisialisasi semua elemen List l dengan MARK */
    /*KAMUS LOKAL*/
    int i;
    /*ALGORITMA*/
    for (i = IDX_MIN; i < CAPACITY; i++)
    {
        ELMT_L(*l, i) = MARK;
    }
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListStatik l)
{
    /* Mengirimkan banyaknya elemen efektif List */
    /* Mengirimkan nol jika List kosong */
    /*KAMUS LOKAL*/
    int i = 0;
    /*ALGORITMA*/

    while ((i < CAPACITY) && (ELMT_L(l, i) != MARK))
    {
        i++;
    }
    return i;
}

/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListStatik l)
{
    /* Prekondisi : List l tidak kosong */
    /* Mengirimkan indeks elemen l pertama */
    return IDX_MIN;
}
IdxType getLastIdx(ListStatik l)
{
    /* Prekondisi : List l tidak kosong */
    /* Mengirimkan indeks elemen l terakhir */
    int len = listLength(l);
    if (len == 0)
    {
        return IDX_MIN;
    }
    else
    {
        return (len - 1);
    }
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListStatik l, IdxType i)
{
    /* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
    /* yaitu antara indeks yang terdefinisi utk container*/

    if ((i >= IDX_MIN) && (i <= (CAPACITY - 1)))
    {
        return true;
    }
    else
        return false;
}
boolean isIdxListEff(ListStatik l, IdxType i)
{
    /* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
    /* yaitu antara 0..length(l)-1 */
    if ((i >= getFirstIdx(l)) && (i <= getLastIdx(l)))
    {
        return true;
    }
    else
        return false;
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isListEmpty(ListStatik l)
{
    /* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
    return (listLength(l) == 0);
}
/* *** Test List penuh *** */
boolean isListFull(ListStatik l)
{
    /* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
    return (listLength(l) == CAPACITY);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readList(ListStatik *l)
{
    /* I.S. l sembarang */
    /* F.S. List l terdefinisi */
    /* Proses: membaca banyaknya elemen l dan mengisi nilainya */
    /* 1. Baca banyaknya elemen diakhiri enter, misalnya n */
    /*    Pembacaan diulangi sampai didapat n yang benar yaitu 0 <= n <= CAPACITY */
    /*    Jika n tidak valid, tidak diberikan pesan kesalahan */
    /* 2. Jika 0 < n <= CAPACITY; Lakukan n kali:
              Baca elemen mulai dari indeks 0 satu per satu diakhiri enter */
    /*    Jika n = 0; hanya terbentuk List kosong */
    /*KAMUS LOKAL*/
    int n, i;
    boolean valid = false;
    listElType element;
    /*ALGORITMA*/
    while (valid != true)
    {
        scanf("%d", &n);

        if ((n >= 0) && (n <= CAPACITY))
        {
            valid = true;
        }
    }
    CreateListStatik(l);
    for (i = 0; i <= n - 1; i++)
    {
        scanf("%d", &element);
        ELMT_L(*l, i) = element;
    }
}
void printList(ListStatik l)
{
    /* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung
       siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan
       karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
    /* I.S. l boleh kosong */
    /* F.S. Jika l tidak kosong: [e1,e2,...,en] */
    /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
    /* Jika List kosong : menulis [] */
    int i;
    int len = listLength(l);
    printf("[");
    for (i = 0; i < len; i++)
    {
        printf("%d", ELMT_L(l, i));
        if (i != len - 1)
        {
            printf(",");
        }
    }
    printf("]");
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */
ListStatik plusMinusList(ListStatik l1, ListStatik l2, boolean plus)
{
    /* Prekondisi : l1 dan l2 berukuran sama dan tidak kosong */
    /* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada
           indeks yang sama dijumlahkan */
    /* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi
           elemen l2 pada indeks yang sama */
    /*KAMUS LOKAL*/
    ListStatik LHasil;
    int i;
    /*ALGORITMA*/
    CreateListStatik(&LHasil);

    for (i = 0; i < listLength(l1); i++)
    {
        if (plus == true)
        {
            ELMT_L(LHasil, i) = ELMT_L(l1, i) + ELMT_L(l2, i);
        }
        else
        {
            ELMT_L(LHasil, i) = ELMT_L(l1, i) - ELMT_L(l2, i);
        }
    }
    return LHasil;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListEqual(ListStatik l1, ListStatik l2)
{
    /* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua
       elemennya sama */
    /*KAMUS LOKAL*/
    boolean equal = true;
    int i;
    int len1 = listLength(l1);
    int len2 = listLength(l2);
    /*ALGORITMA*/
    if (len1 == len2)
    {
        for (i = 0; i < len1; i++)
        {
            if (ELMT_L(l1, i) != ELMT_L(l2, i))
            {
                equal = false;
            }
        }
    }
    else
    {
        equal = false;
    }
    return equal;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOf(ListStatik l, listElType val)
{
    /* Search apakah ada elemen List l yang bernilai val */
    /* Jika ada, menghasilkan indeks i terkecil, dengan ELMT_L(l,i) = val */
    /* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
    /* Skema Searching yang digunakan bebas */
    /*KAMUS LOKAL*/
    int i = 0;
    boolean found = false;
    /*ALGORITMA*/
    while ((i < CAPACITY) && (found != true))
    {
        if (ELMT_L(l, i) == val)
        {
            found = true;
        }
        else
        {
            i++;
        }
    }

    if (found == true)
    {
        return i;
    }
    else
    {
        return IDX_UNDEF;
    }
}

/* ********** NILAI EKSTREM ********** */
void extremeValues(ListStatik l, listElType *max, listElType *min)
{
    /* I.S. List l tidak kosong */
    /* F.S. Max berisi nilai terbesar dalam l;
            Min berisi nilai terkecil dalam l */
    /*KAMUS LOKAL*/
    listElType maxval, minval;
    int i;
    /*ALGORITMA*/
    maxval = ELMT_L(l, 0);
    minval = ELMT_L(l, 0);
    for (i = 0; i < listLength(l); i++)
    {
        if (ELMT_L(l, i) > maxval)
        {
            maxval = ELMT_L(l, i);
        }
        if (ELMT_L(l, i) < minval)
        {
            minval = ELMT_L(l, i);
        }
    }
    *max = maxval;
    *min = minval;
}

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void insertFirst(ListStatik *l, listElType val)
{
    /* Proses: Menambahkan val sebagai elemen pertama List */
    /* I.S. List l boleh kosong, tetapi tidak penuh */
    /* F.S. val adalah elemen pertama l yang baru */
    /*KAMUS LOKAL*/
    int i;
    /*ALGORITMA*/
    if (isListFull(*l) != true)
    {
        for (i = listLength(*l); i > 0; i--)
        {
            ELMT_L(*l, i) = ELMT_L(*l, i - 1);
        }
        ELMT_L(*l, 0) = val;
    }
}
/* *** Menambahkan elemen pada index tertentu *** */
void insertAt(ListStatik *l, listElType val, IdxType idx)
{
    /* Proses: Menambahkan val sebagai elemen pada index idx List */
    /* I.S. List l tidak kosong dan tidak penuh, idx merupakan index yang valid di l */
    /* F.S. val adalah elemen yang disisipkan pada index idx l */
    /*KAMUS LOKAL*/
    int i;
    /*ALGORITMA*/
    if ((isListFull(*l) != true) && (isListEmpty(*l) != true))
    {
        for (i = listLength(*l); i > idx; i--)
        {
            ELMT_L(*l, i) = ELMT_L(*l, i - 1);
        }
        ELMT_L(*l, idx) = val;
    }
}
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListStatik *l, listElType val)
{
    /* Proses: Menambahkan val sebagai elemen terakhir List */
    /* I.S. List l boleh kosong, tetapi tidak penuh */
    /* F.S. val adalah elemen terakhir l yang baru */
    /*KAMUS LOKAL*/
    /*ALGORITMA*/
    if (isListFull(*l) != true)
    {
        ELMT_L(*l, listLength(*l)) = val;
    }
}

/* ********** MENGHAPUS ELEMEN ********** */
/* *** Menghapus elemen pertama *** */
void deleteFirst(ListStatik *l, listElType *val)
{
    /* Proses : Menghapus elemen pertama List */
    /* I.S. List tidak kosong */
    /* F.S. val adalah nilai elemen pertama l sebelum penghapusan, */
    /*      Banyaknya elemen List berkurang satu */
    /*      List l mungkin menjadi kosong */
    /*KAMUS LOKAL*/
    int i;
    /*ALGORITMA*/
    if (isListEmpty(*l) != true)
    {
        *val = ELMT_L(*l, getFirstIdx(*l));

        for (i = 0; i < getLastIdx(*l); i++)
        {
            ELMT_L(*l, i) = ELMT_L(*l, i + 1);
        }
        ELMT_L(*l, getLastIdx(*l)) = MARK;
    }
}
/* *** Menghapus elemen pada index tertentu *** */
void deleteAt(ListStatik *l, listElType *val, IdxType idx)
{
    /* Proses : Menghapus elemen pada index idx List */
    /* I.S. List tidak kosong, idx adalah index yang valid di l */
    /* F.S. val adalah nilai elemen pada index idx l sebelum penghapusan, */
    /*      Banyaknya elemen List berkurang satu */
    /*      List l mungkin menjadi kosong */

    /*KAMUS LOKAL*/
    int i;
    /*ALGORITMA*/
    if (isListEmpty(*l) != true)
    {
        *val = ELMT_L(*l, idx);

        for (i = idx; i < getLastIdx(*l); i++)
        {
            ELMT_L(*l, i) = ELMT_L(*l, i + 1);
        }
        ELMT_L(*l, getLastIdx(*l)) = MARK;
    }
}
/* *** Menghapus elemen terakhir *** */
void deleteLast(ListStatik *l, listElType *val)
{
    /* Proses : Menghapus elemen terakhir List */
    /* I.S. List tidak kosong */
    /* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
    /*      Banyaknya elemen List berkurang satu */
    /*      List l mungkin menjadi kosong */
    /*KAMUS LOKAL*/
    /*ALGORITMA*/
    if (isListEmpty(*l) != true)
    {
        *val = ELMT_L(*l, getLastIdx(*l));

        ELMT_L(*l, getLastIdx(*l)) = MARK;
    }
}

/* ********** SORTING ********** */
void sortList(ListStatik *l, boolean asc)
{
    /* I.S. l boleh kosong */
    /* F.S. Jika asc = true, l terurut membesar */
    /*      Jika asc = false, l terurut mengecil */
    /* Proses : Mengurutkan l dengan salah satu algoritma sorting,
       algoritma bebas */
    /*Menggunakan Insertion Sort*/
    /*KAMUS LOKAL*/
    int i;
    listElType temp;
    IdxType idx;
    int len = listLength(*l);
    /*ALGORITMA*/
    if (asc == true)
    {
        for (i = 1; i < len; i++)
        {
            temp = ELMT_L(*l, i);
            idx = i - 1;
            while ((temp < ELMT_L(*l, idx)) && (idx > 0))
            {
                ELMT_L(*l, idx + 1) = ELMT_L(*l, idx);
                idx--;
            }
            if (temp >= ELMT_L(*l, idx))
            {
                ELMT_L(*l, idx + 1) = temp;
            }
            else
            {
                ELMT_L(*l, idx + 1) = ELMT_L(*l, idx);
                ELMT_L(*l, idx) = temp;
            }
        }
    }
    else
    {
        for (i = 1; i < len; i++)
        {
            temp = ELMT_L(*l, i);
            idx = i - 1;
            while ((temp > ELMT_L(*l, idx)) && (idx > 0))
            {
                ELMT_L(*l, idx + 1) = ELMT_L(*l, idx);
                idx--;
            }
            if (temp <= ELMT_L(*l, idx))
            {
                ELMT_L(*l, idx + 1) = temp;
            }
            else
            {
                ELMT_L(*l, idx + 1) = ELMT_L(*l, idx);
                ELMT_L(*l, idx) = temp;
            }
        }
    }
}
