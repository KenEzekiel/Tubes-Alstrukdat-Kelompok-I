# BUG
1. ayam mentah di chop ayam mentahnya ga ilang, ayam potong nambah di inventory
2. BUY ngecrash kalo input karakter
3. ayam potong di mix ayam potongnya ga ilang, ayam tepung nambah di inventory
4. bisa buy dimana aja(ga harus dkt telpun)
5. ayam tepung dan minyak goreng di FRY bahannya ga ilang, ayam goreng nambah di inventory stlh selesai
6. (dari no 1,3,5 diasumsikan) boil jg punya masalah serupa
7. stlh ayam goreng di FRY, pas di UNDO ayam gorengnya masih ada  
8. KOK S NYA BISA NIMPA T AWOKAOWKOAKW + INI KENAPA TELEPORT???
```
BNMO berada di posisi: (1,3)
Waktu: 2.17
Notifikasi: - 
* * * * * * * * * * * *
* . . . . . . . . . . *
* . . . S T . . X . . *
* . M . . . . . X . . *
* . . . . . . . X . . *
* . . . . X X X X . . *
* . X . . . . . . . . *
* . X . . . . . . C . *
* . X X X . . F . . . *
* . . . . . . . . . . *
* . . . . . . B . . . *
* * * * * * * * * * * *
Enter Command: MOVE NORTH

BNMO berada di posisi: (0,3)
Waktu: 2.18
Notifikasi: 
1. Ayam Mentah sudah diterima oleh Cooking BNMO! :D
2. Ayam Potong kedaluwarsa ... :(
* * * * * * * * * * * *
* . . . S . . . . . . *
* . . . . T . . X . . *
* . M . . . . . X . . *
* . . . . . . . X . . *
* . . . . X X X X . . *
* . X . . . . . . . . *
* . X . . . . . . C . *
* . X X X . . F . . . *
* . . . . . . . . . . *
* . . . . . . B . . . *
* * * * * * * * * * * *
Enter Command: UNDO

BNMO berada di posisi: (1,4)
Waktu: 2.17
Notifikasi: 
1. Ayam Potong dikembalikan ke inventory
2. Ayam Mentah dikeluarkan dari inventory
* * * * * * * * * * * *
* . . . . . . . . . . *
* . . . . S . . X . . *
* . M . . . . . X . . *
* . . . . . . . X . . *
* . . . . X X X X . . *
* . X . . . . . . . . *
* . X . . . . . . C . *
* . X X X . . F . . . *
* . . . . . . . . . . *
* . . . . . . B . . . *
* * * * * * * * * * * *
```
9. SAMA KAYA DI ATAS, PAS DI REDO T NYA ILANG (masih bisa BUY sih di 1,3)
BNMO berada di posisi: (1,4)
Waktu: 2.17
Notifikasi: - 
```
* * * * * * * * * * * *
* . . . . . . . . . . *
* . . . . S . . X . . *
* . M . . . . . X . . *
* . . . . . . . X . . *
* . . . . X X X X . . *
* . X . . . . . . . . *
* . X . . . . . . C . *
* . X X X . . F . . . *
* . . . . . . . . . . *
* . . . . . . B . . . *
* * * * * * * * * * * *
Enter Command: REDO
BNMO berada di posisi: (0,4)
Waktu: 2.18
Notifikasi: 
1. Ayam Mentah sudah diterima oleh Cooking BNMO! :D
2. Ayam Potong kedaluwarsa ... :(
* * * * * * * * * * * *
* . . . . S . . . . . *
* . . . . . . . X . . *
* . M . . . . . X . . *
* . . . . . . . X . . *
* . . . . X X X X . . *
* . X . . . . . . . . *
* . X . . . . . . C . *
* . X X X . . F . . . *
* . . . . . . . . . . *
* . . . . . . B . . . *
* * * * * * * * * * * *
Enter Command: INVENTORY
```

10. kalo buy pas ada item yg kadaluwarsa, BUY otomatis ter-exit (trus next move segmentation fault?)

11. insert enter buy langsung keluar?

12. UNDO kalau stack kosong dan REDO kalau stack kosong segmentation fault

13. ngga punya ayam potong+tepung bisa buat ayam tepung???

14. di MIX (dan yg lain) input > 1 "Enter command: " keulang, ga ada error msg, input 0 segmentation fault

15. NVM, gapunya barang masih bisa mix chop boil fry

16. ga ngerti lagi ini salah peta apa undo
```
* * * * * * * * * * * *
* . . . . . . . . . . *
* . . . . T . . X . . *
* . M . . . . . X . . *
* . . . . . . . X . . *
* . . . . X X X X . . *
* . X . . . . . . . . *
* . X . . . . . . C . *
* . X X X . . F . . . *
* . . . . . . . . . . *
* . . . . . . B S . . *
* * * * * * * * * * * *
Enter Command: UNDO
BNMO berada di posisi: (7,59)
Waktu: 23
Notifikasi: - 
* * * * * * * * * * * *
* . . . . . . . . . . *
* . . . . T . . X . . *
* . M . . . . . X . . *
* . . . . . . . X . . *
* . . . . X X X X . . *
* . X . . . . . . . . *
* . X . . . . . . C . *
* . X X X . . F . . . *
* . . . . . . . . . . *
* . . . . . . B . . . *
* * * * * * * * * * * *
```

17. input MOVE yg ga valid (kaya MOVEAMONGUS) keluar msg error

18. misal punya 2 ayam goreng, pas di insert di kulkas 22nya terinsert, tapi yg ada di kulkas cuma 1

19. 

# maybe bug?
1. beli makanan > 1 waktu cuma bertambah 1
2. durasi kadaluwarsa di CATALOG ga ngurang?
3. ngga buy apa2 waktu nambah (BUY trus 0)
4. fry, mix, chop, boil emg ga ada waktunya?
5. ini emang display kulkasnya ada ABCDE di bawahnya?
```
INVENTORY: 
List Makanan di Inventory
 (nama -- waktu sisa kedaluarsa) 
1. (21) Ayam Potong - 56 menit

Mapping Kulkas: 
X X O O O O O O O O O O O O O O O O O O O O O O O O O O O O
X X O O O O O O O O O O O O O O O O O O O O O O O O O O O O
O O O O O O O O O O O O O O O O O O O O O O O O O O O O O O
O O O O O O O O O O O O O O O O O O O O O O O O O O O O O O
O O O O O O O O O O O O O O O O O O O O O O O O O O O O O O
O O O O O O O O O O O O O O O O O O O O O O O O O O O O O O
O O O O O O O O O O O O O O O O O O O O O O O O O O O O O O
O O O O O O O O O O O O O O O O O O O O O O O O O O O O O O
O O O O O O O O O O O O O O O O O O O O O O O O O O O O O O
O O O O O O O O O O O O O O O O O O O O O O O O O O O O O O
O O O O O O O O O O O O O O O O O O O O O O O O O O O O O O
O O O O O O O O O O O O O O O O O O O O O O O O O O O O O O
O O O O O O O O O O O O O O O O O O O O O O O O O O O O O O
O O O O O O O O O O O O O O O O O O O O O O O O O O O O O O
O O O O O O O O O O O O O O O O O O O O O O O O O O O O O O
O O O O O O O O O O O O O O O O O O O O O O O O O O O O O O
O O O O O O O O O O O O O O O O O O O O O O O O O O O O O O
O O O O O O O O O O O O O O O O O O O O O O O O O O O O O O
O O O O O O O O O O O O O O O O O O O O O O O O O O O O O O
O O O O O O O O O O O O O O O O O O O O O O O O O O O O O O
Isi Kulkas: 
[

id kulkas : 38
Ayam Goreng
0, 0 

]
Masukkan id makanan di kulkas yang ingin diambil dari kulkas: 38
A
B
C
D
E
```

# mungkin kelupaan
1. gabisa liat isi kulkas?

# emang kelupaan
1. output error kalo command yg dimasukkin ga valid