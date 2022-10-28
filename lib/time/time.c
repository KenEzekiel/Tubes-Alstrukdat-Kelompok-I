#include "../boolean.h"
#include "time.h"
#include <stdio.h>

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsTIMEValid(int H, int M, int S)
{
   /* Mengirim true jika H,M,S dapat membentuk T yang valid */
   /* dipakai untuk mentest SEBELUM membentuk sebuah Jam */
   return (H >= 0 && H <= 23 && M >= 0 && M <= 59 && S >= 0 && S <= 59);
}

/* *** Konstruktor: Membentuk sebuah TIME dari komponen-komponennya *** */
void CreateTime(TIME *T, int HH, int MM, int SS)
{
   /* Membentuk sebuah TIME dari komponen-komponennya yang valid */
   /* Prekondisi : HH, MM, SS valid untuk membentuk TIME */
   Hour(*T) = HH;
   Minute(*T) = MM;
   Second(*T) = SS;
}
/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */

void BacaTIME(TIME *T)
{
   /* I.S. : T tidak terdefinisi */
   /* F.S. : T terdefinisi dan merupakan jam yang valid */
   /* Proses : mengulangi membaca komponen HH, MM, SS sehingga membentuk T */
   /* yang valid. Tidak mungkin menghasilkan T yang tidak valid. */
   /* Pembacaan dilakukan dengan mengetikkan komponen HH, MM, SS
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
   /* Jika TIME tidak valid maka diberikan pesan: "Jam tidak valid", dan pembacaan
   diulangi hingga didapatkan jam yang valid. */
   /* Contoh:
   60 3 4
   Jam tidak valid
   1 3 4
   --> akan terbentuk TIME <1,3,4> */
   int HH, MM, SS;

   scanf("%d %d %d", &HH, &MM, &SS);
   while (IsTIMEValid(HH, MM, SS) == false)
   {
      printf("Jam tidak valid\n");
      scanf("%d %d %d", &HH, &MM, &SS);
   }
   CreateTime(T,HH,MM,SS);
}

void TulisTIME(TIME T)
{
   /* I.S. : T sembarang */
   /* F.S. : Nilai T ditulis dg format HH:MM:SS */
   /* Proses : menulis nilai setiap komponen T ke layar dalam format HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/
   int HH, MM, SS;
   HH = Hour(T);
   MM = Minute(T);
   SS = Second(T);
   printf("%d:%d:%d", HH, MM, SS);
   printf("\n");
}

void PrintTime(TIME T)
{
   /* I.S. : T sembarang */
   /* F.S. : Nilai T ditulis dg format HH jam MM menit SS detik */
   int HH, MM, SS;
   HH = Hour(T);
   MM = Minute(T);
   SS = Second(T);
   if (HH > 0) {
      printf("%d jam", HH);
   }
   if (MM > 0) {
      if (HH > 0) {
         printf(" ");
      }
      printf("%d menit", MM);
   }
   if (SS > 0) {
      if (HH > 0 || MM > 0) {
         printf(" ");
      }
      printf("%d detik", SS);
   }
   if (HH == 0 && MM == 0 && SS == 0){
      printf("0");
   }
}

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long TIMEToDetik(TIME T)
{
   /* Diberikan sebuah TIME, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
   /* Rumus : detik = 3600*HH + 60*MM + SS */
   /* Nilai maksimum = 3600*23+59*60+59 */
   int jam, menit, detik;
   int jlhdetik;

   jam = Hour(T);
   menit = Minute(T);
   detik = Second(T);

   jlhdetik = 3600 * jam + 60 * menit + detik;

   return jlhdetik;
}

TIME DetikToTIME(long N)
{
   /* Mengirim  konversi detik ke TIME */
   /* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang
      mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus:
      N1 = N mod 86400, baru N1 dikonversi menjadi TIME */
   int second, h, m, s;
   TIME T;
   while(N<0){
      N += 86400;
   }
   while(N>= 86400) {
      N -= 86400;
   }
   second = N % 86400;
   h = second / 3600;
   m = (second % 3600) / 60;
   s = (second % 3600) % 60;

   Hour(T) = h;
   Minute(T) = m;
   Second(T) = s;
   return T;
}

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean TEQ(TIME T1, TIME T2)
{
   /* Mengirimkan true jika T1=T2, false jika tidak */
   int detik1, detik2;
   detik1 = TIMEToDetik(T1);
   detik2 = TIMEToDetik(T2);

   return(detik1 == detik2);
}

boolean TNEQ(TIME T1, TIME T2)
{
   /* Mengirimkan true jika T1 tidak sama dengan T2 */
   int detik1, detik2;
   detik1 = TIMEToDetik(T1);
   detik2 = TIMEToDetik(T2);

   return(detik1!=detik2);
}

boolean TLT(TIME T1, TIME T2)
{
   /* Mengirimkan true jika T1<T2, false jika tidak */
   return (TIMEToDetik(T1) < TIMEToDetik(T2));
}

boolean TGT(TIME T1, TIME T2)
{
   /* Mengirimkan true jika T1>T2, false jika tidak */

   return (TIMEToDetik(T1) > TIMEToDetik(T2));
}

/* *** Operator aritmatika TIME *** */
TIME NextDetik(TIME T)
{
   /* Mengirim 1 detik setelah T dalam bentuk TIME */
   int second;

   second = TIMEToDetik(T);
   second += 1;
   T = DetikToTIME(second);
   return T;
}

TIME NextNDetik(TIME T, int N)
{
   /* Mengirim N detik setelah T dalam bentuk TIME */
   int second;

   second = TIMEToDetik(T);
   second += N;
   T = DetikToTIME(second);
   return T;
}

TIME PrevDetik(TIME T)
{
   /* Mengirim 1 detik sebelum T dalam bentuk TIME */
   int second;

   second = TIMEToDetik(T);
   second = second - 1;
   T = DetikToTIME(second);
   return T;
}
TIME PrevNDetik(TIME T, int N)
{
   /* Mengirim N detik sebelum T dalam bentuk TIME */
   /* *** Kelompok Operator Aritmetika *** */
   int second;

   second = TIMEToDetik(T);
   second -= N;
   T = DetikToTIME(second);
   return T;
}
long Durasi(TIME TAw, TIME TAkh)
{
   /* Mengirim TAkh-TAw dlm Detik, dengan kalkulasi */
   /* Jika TAw > TAkh, maka TAkh adalah 1 hari setelah TAw */
   int durasi, time1, time2;

   time1 = TIMEToDetik(TAw);
   time2 = TIMEToDetik(TAkh);
   if (time1 > time2)
   {
      time2 = time2 + 86400;
   }
   durasi = time2 - time1;
   return durasi;
}