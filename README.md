# Tubes-Alstrukdat-Kelompok-I

Tugas Besar IF2110 Algoritma dan Struktur Data

BNMO is a game robot owned by Indra and Doni. Recently, Indra has been in close contact with a girl named Siska Kol and wants to invite her to dinner at his place. Indra then asked Doni and BNMO to help prepare the dinner, which BNMO is immediately interested in because he often watches cooking videos in toktok. Because BNMO is a computer, the easiest way for him to learn to cook is to make a cooking simulation program for BNMO to follow.

Cooking BNMO is a Command-Line Interface Game that is made using C, which includes a variety of Abstact Data Types and Structures, such as List, Matrix, Tree, Queue, Stack, etc.

## Running the program

Compiling the program can be done by executing run.bat on windows, or make main in the program directory, which can be done in windows or linux.

The executable, main.exe, can be run in the terminal using ./main

## Features

All features listed are 100% done and implemented.

- Inisiasi
- Simulator
- Makanan
- Resep
- Inventory
- Pemesanan Bahan Makanan dan Delivery
- Peta
- Pengolahan Makanan
- Mekanisme Waktu
- Undo, Redo, Catalog, Cookbook
- Rekomendasi Makanan
- Kulkas
- Waktu Pengolahan Makanan
- Notifikasi

## Anggota Kelompok I

| NIM      | Name                        | ADT Part                              | Feature Part                                                       |
| -------- | --------------------------- | ------------------------------------- | ------------------------------------------------------------------ |
| 13521094 | Angela Livia Arumsari       | ADT Makanan, ADT Simulator            | Simulator, List Makanan, Notifikasi, Rekomendasi                   |
| 13521089 | Kenneth Ezekiel Suprantoni  | ADT List Statik, ADT Queue            | Inventory, Pemesanan Bahan Makanan dan Delivery, Kulkas, Undo/Redo | 
| 13521092 | Frankie Huang               | ADT Tree, ADT Mesin Karakter dan Kata | Inisiasi, List Resep, Cookbook                                     |
| 13521042 | Kevin John Wesley Hutabarat | ADT Stack, ADT Time, ADT Set          | Pengolahan Makanan, Undo/Redo, Rekomendasi                         |
| 13521061 | Alex Sander                 | ADT Matrix, ADT Point                 | Peta, Mekanisme Waktu, Waktu Pengolahan Makanan                    |

## Program Structure

```
| README.md
| .gitignore
|
└─── .vscode
|
└─── doc
|       | Pedoman Tugas Besar IF2110 2022_2023.docx
|       | Spesifikasi Tugas Besar IF2110 2022-2023.pdf
|
└─── lib
|       | boolean.h
|       └─── liststatik
|       └─── makanan
|       └─── matrix
|       └─── point
|       └─── queue
|       └─── simulator
|       └─── stack
|       └─── string
|       └─── time
|       └─── tree
|       └─── wordmachine
|
└─── program
|       | main.c
|       | main.h
|       | run.bat
|       └─── lib
|               | boolean.h
|               └─── deliverylist
|               └─── inisiasi
|               └─── inventory
|               └─── listmakanan
|               └─── notifikasi
|               └─── olahmakanan
|               └─── peta
|               └─── redostack
|               └─── rekomendasi
|               └─── resep
|               └─── state
|               └─── statestack
|               └─── undostack
|               └─── utility
|               └─── waktusim
|
└─── test
        | makanan.txt
        | peta.txt
        | resep_1.txt
        | resep_2.txt

```
## Tasks Distribution

|  Names                           | Tasks                                |
| -------------------------------- | ------------------------------------ |
| Kevin John Wesley Hutabarat      | ADT Stack, ADT Time, ADT Set,        |
|                                  | Pengolahan Makanan, Undo, Redo,      |
|                                  | Rekomendasi Makanan                  |
| Kenneth Ezekiel Suprantoni       | ADT List Statik, ADT Queue,          |
|                                  | Inventory, Pemesanan Bahan Makanan,  |
|                                  | Delivery, Kulkas, Undo, Redo         |
| Frankie Huang                    | ADT Tree, ADT Mesin Karakter,        |
|                                  | Inisiasi, List Resep, Cookbook       |
| Angela Livia Arumasari           | ADT Makanan, ADT Simulator,          |
|                                  | Simulator, List Makanan, Notifikasi, |
|                                  | Rekomendasi Makanan                  |
| Alex Sander                      | ADT Matrix, ADT Point, Peta,         |
|                                  | Mekanisme Waktu, Waktu Pengolahan    |
|                                  | Makanan                              |


