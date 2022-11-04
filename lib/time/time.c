#include "../boolean.h"
#include "time.h"
#include <stdio.h>

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsTIMEValid(int D, int H, int M)
{
   /* Mengirim true jika H,M,S dapat membentuk T yang valid */
   /* dipakai untuk mentest SEBELUM membentuk sebuah Jam */
   return (H >= 0 && H <= 23 && M >= 0 && M <= 59 && D >= 0 && D <= 59);
}

/* *** Konstruktor: Membentuk sebuah TIME dari komponen-komponennya *** */
void CreateTime(TIME *T, int DD, int HH, int MM)
{
   /* Membentuk sebuah TIME dari komponen-komponennya yang valid */
   /* Prekondisi : HH, MM, SS valid untuk membentuk TIME */
   Day(*T) = DD;
   Hour(*T) = HH;
   Minute(*T) = MM;
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
   int DD, HH, MM;

   scanf("%d %d %d", &DD, &HH, &MM);
   while (IsTIMEValid(DD,HH, MM) == false)
   {
      printf("Jam tidak valid\n");
      scanf("%d %d %d", &DD, &HH, &MM);
   }
   CreateTime(T,DD,HH,MM);
}

void TulisTIME(TIME T)
{
   /* I.S. : T sembarang */
   /* F.S. : Nilai T ditulis dg format HH:MM:SS */
   /* Proses : menulis nilai setiap komponen T ke layar dalam format HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/
   int DD, MM, HH;
   DD = Day(T);
   HH = Hour(T);
   MM = Minute(T);
   
   printf("%d:%d:%d", DD, HH, MM);
   printf("\n");
}

void PrintTime(TIME T)
{
   /* I.S. : T sembarang */
   /* F.S. : Nilai T ditulis dg format HH jam MM menit SS detik */
   int DD, HH, MM;
   DD = Day(T);
   HH = Hour(T);
   MM = Minute(T);
   
   if (DD > 0) {
      printf("%d hari", DD);
   }
   if (HH > 0) {
      if (DD > 0) {
         printf(" ");
      }
      printf("%d jam", HH);
   }
   if (MM > 0) {
      if (DD > 0 || HH > 0) {
         printf(" ");
      }
      printf("%d menit", MM);
   }
   if (HH == 0 && MM == 0 && DD == 0){
      printf("0");
   }
}

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long TIMEToMenit(TIME T)
{
   /* Diberikan sebuah TIME, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
   /* Rumus : detik = 3600*HH + 60*MM + SS */
   /* Nilai maksimum = 3600*23+59*60+59 */
   int hari, jam, menit;
   int jlhmenit;
   
   hari = Day(T);
   jam = Hour(T);
   menit = Minute(T);
   
   jlhmenit = 1440*hari + 60*jam + menit;

   return jlhmenit;
}

TIME MenitToTIME(long N)
{
   /* Mengirim  konversi detik ke TIME */
   /* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang
      mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus:
      N1 = N mod 86400, baru N1 dikonversi menjadi TIME */
   int minute, h, m, d;
   TIME T;
   while(N<0){
      N += 86400;
   }
   /*while(N>= 86400) {
      N -= 86400;
   }*/
   minute = N % 10080;
   d = minute / 3600;
   h = (minute % 3600) / 60;
   m = (minute % 3600) % 60;

   Day(T) = d;
   Hour(T) = h;
   Minute(T) = m;
   
   return T;
}

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean TEQ(TIME T1, TIME T2)
{
   /* Mengirimkan true jika T1=T2, false jika tidak */
   int menit1, menit2;
   menit1 = TIMEToMenit(T1);
   menit2 = TIMEToMenit(T2);

   return(menit1 == menit2);
}

boolean TNEQ(TIME T1, TIME T2)
{
   /* Mengirimkan true jika T1 tidak sama dengan T2 */
   int menit1, menit2;
   menit1 = TIMEToMenit(T1);
   menit2 = TIMEToMenit(T2);

   return(menit1 != menit2);
}

boolean TLT(TIME T1, TIME T2)
{
   /* Mengirimkan true jika T1<T2, false jika tidak */
   return (TIMEToMenit(T1) < TIMEToMenit(T2));
}

boolean TGT(TIME T1, TIME T2)
{
   /* Mengirimkan true jika T1>T2, false jika tidak */

   return (TIMEToMenit(T1) > TIMEToMenit(T2));
}

/* *** Operator aritmatika TIME *** */
TIME NextMenit(TIME T)
{
   /* Mengirim 1 detik setelah T dalam bentuk TIME */
   int minute;

   minute = TIMEToMenit(T);
   minute += 1;
   T = MenitToTIME(minute);
   return T;
}

TIME NextNMenit(TIME T, int N)
{
   /* Mengirim N detik setelah T dalam bentuk TIME */
   int minute;

   minute = TIMEToMenit(T);
   minute += N;
   T = MenitToTIME(minute);
   return T;
}

TIME PrevDetik(TIME T)
{
   /* Mengirim 1 detik sebelum T dalam bentuk TIME */
   int minute;

   minute = TIMEToMenit(T);
   minute += 1;
   T = MenitToTIME(minute);
   return T;
}
TIME PrevNMenit(TIME T, int N)
{
   /* Mengirim N detik sebelum T dalam bentuk TIME */
   /* *** Kelompok Operator Aritmetika *** */
   int minute;

   minute = TIMEToMenit(T);
   minute -= N;
   T = MenitToTIME(minute);
   return T;
}
long Durasi(TIME TAw, TIME TAkh)
{
   /* Mengirim TAkh-TAw dlm Detik, dengan kalkulasi */
   /* Jika TAw > TAkh, maka TAkh adalah 1 hari setelah TAw */
   int durasi, time1, time2;

   time1 = TIMEToMenit(TAw);
   time2 = TIMEToMenit(TAkh);
   if (time1 > time2)
   {
      time2 = time2 + 10800;
   }
   durasi = time2 - time1;
   return durasi;
}