msg := use the command "make file" to compile the respective driver in the folder, ex: "make main" will compile the main.c file.

all: 
	$(msg)

testing:
	cd lib/
	ls

adt_path := lib/
modul_path = program/lib/
liststatik := $(adt_path)liststatik/
makanan := $(adt_path)makanan/
matrix := $(adt_path)matrix/
point := $(adt_path)point/
queue := $(adt_path)queue/
set := $(adt_path)set/
simulator := $(adt_path)simulator/
stack := $(adt_path)stack/
string := $(adt_path)string/
time := $(adt_path)time/
tree := $(adt_path)tree/
wordmachine := $(adt_path)wordmachine/
deliverylist := $(modul_path)/deliverylist/
inisiasi := $(modul_path)/inisiasi/
inventory := $(modul_path)/inventory/
kulkas := $(modul_path)/kulkas/
listmakanan := $(modul_path)/listmakanan/
notifikasi := $(modul_path)/notifikasi/
olahmakanan := $(modul_path)/olahmakanan/
peta := $(modul_path)/peta/
redostack := $(modul_path)/redostack/
resep := $(modul_path)/resep/
state := $(modul_path)/state/
statestack := $(modul_path)/statestack/
undostack := $(modul_path)/undostack/
utility := $(modul_path)/utility/
mekawaktu := $(modul_path)/waktusim/

liststatik: $(liststatik)$(wildcard *.c)
	gcc $(liststatik)liststatik.c $(liststatik)driver.c -lm -Wall -o $(liststatik)liststatik

makanan: $(makanan)$(wildcard *.c)
	gcc $(makanan)makanan.c $(string)string.c $(time)time.c $(makanan)driver.c -lm -Wall -o $(makanan)makanan

matrix: $(matrix)$(wildcard *.c)
	gcc $(matrix)matrix.c $(matrix)driver.c -lm -Wall -o $(matrix)matrix

point: $(point)$(wildcard *.c)
	gcc $(point)point.c $(point)driver.c -lm -Wall -o $(point)point

queue: $(queue)queuedriver.c $(queue)$(wildcard *.c)
	gcc $(queue)queue.c $(queue)queuedriver.c -o $(queue)queue
	gcc $(queue)prioqueuetime.c $(queue)priodriver.c -lm -Wall -o $(queue)prio

set: $(set)$(wildcard *.c)
	gcc $(set)set.c $(set)driver.c -o $(set)set

simulator: $(simulator)$(wildcard *.c)
	gcc $(simulator)simulator.c $(string)string.c $(point)point.c $(queue)prioqueuetime.c $(makanan)makanan.c $(time)time.c $(simulator)driver.c -lm -Wall -o $(simulator)simulator

stack: $(stack)$(wildcard *.c)
	gcc $(stack)stack.c $(stack)driver.c -lm -Wall -o $(stack)stack

string: $(string)$(wildcard *.c)
	gcc $(string)string.c $(wordmachine)wordmachine.c $(wordmachine)charmachine.c $(string)driver.c -lm -Wall -o $(string)string

time: $(time)$(wildcard *.c)
	gcc $(time)time.c $(string)string.c $(wordmachine)wordmachine.c $(wordmachine)charmachine.c $(time)driver.c -lm -Wall -o $(time)time

tree: $(tree)$(wildcard *.c)
	gcc $(tree)tree.c $(tree)driver.c -lm -Wall -o $(tree)tree

wordmachine: $(wordmachine)$(wildcard *.c)
	gcc $(wordmachine)wordmachine.c $(wordmachine)charmachine.c $(wordmachine)driver.c -lm -Wall -o $(wordmachine)wordmachine

deliverylist: $(deliverylist)$(wildcard *.c)
	gcc $(deliverylist)deliverylist.c $(queue)prioqueuetime.c $(inventory)inventory.c $(time)time.c $(makanan)makanan.c $(string)string.c $(liststatik)liststatik.c $(listmakanan)listmakanan.c $(deliverylist)driver.c -lm -Wall -o $(deliverylist)deliverylist

inisiasi: $(inisiasi)$(wildcard *.c)
	gcc $(inisiasi)inisiasi.c $(wordmachine)wordmachine.c $(inventory)inventory.c $(notifikasi)notifikasi.c $(peta)peta.c $(simulator)simulator.c $(time)time.c $(point)point.c $(inisiasi)driver.c -lm -Wall -o $(inisiasi)inisiasi

inventory: $(inventory)$(wildcard *.c)
	gcc $(inventory)inventory.c $(makanan)makanan.c $(wordmachine)wordmachine.c $(wordmachine)charmachine.c $(time)time.c $(string)string.c $(queue)prioqueuetime.c $(listmakanan)listmakanan.c $(inventory)driver.c -lm -Wall -o $(inventory)inventory

kulkas: $(kulkas)$(wildcard *.c)
	gcc $(kulkas)kulkas.c $(matrix)matrix.c $(makanan)makanan.c $(string)string.c $(inventory)inventory.c $(wordmachine)wordmachine.c $(wordmachine)charmachine.c $(time)time.c $(queue)prioqueuetime.c $(listmakanan)listmakanan.c $(kulkas)driver.c -lm -Wall -o $(kulkas)kulkas

listmakanan: $(listmakanan)$(wildcard *.c)
	gcc $(listmakanan)listmakanan.c $(makanan)makanan.c $(wordmachine)wordmachine.c $(wordmachine)charmachine.c $(time)time.c $(string)string.c $(listmakanan)driver.c -lm -Wall -o $(listmakanan)listmakanan

notifikasi: $(notifikasi)$(wildcard *.c)
	gcc $(notifikasi)notifikasi.c $((makanan)makanan.c $(wordmachine)wordmachine.c $(wordmachine)charmachine.c $(listmakanan)listmakanan.c $(deliverylist)deliverylist.c $(state)state.c $(inventory)inventory.c $(time)time.c $(string)string.c $(queue)prioqueuetime.c $(notifikasi)driver.c -lm -Wall -o $(notifikasi)notifikasi

olahmakanan: $(olahmakanan)$(wildcard *.c)
	gcc $(olahmakanan)olahmakanan.c $(queue)queue.c $(string)string.c $(matrix)matrix.c $(liststatik)liststatik.c $(point)point.c $(listmakanan)listmakanan.c $(inventory)inventory.c $(resep)resep.c $(deliverylist)deliverylist.c $(olahmakanan)driver.c -lm -Wall -o $(olahmakanan)olahmakanan

peta: $(peta)$(wildcard *.c)
	gcc $(peta)peta.c $(matrix)matrix.c $(point)point.c $(wordmachine)wordmachine.c $(charmachine)charmachine.c $(peta)driver.c -lm -Wall -o $(peta)peta

redostack: $(redostack)$(wildcard *.c)
	gcc $(redostack)redostack.c $(stack)stack.c $(time)time.c $(inventory)inventory.c $(deliverylist)deliverylist.c $(statestack)statestack.c $(redostack)driver.c -lm -Wall -o $(redostack)redostack

resep: $(resep)$(wildcard *.c)
	gcc $(resep)resep.c $(wordmachine)wordmachine.c $(wordmachine)charmachine.c $(tree)tree.c $(listmakanan)listmakanan.c $(resep)driver.c -lm -Wall -o $(resep)resep

state: $(state)$(wildcard *.c)
	gcc $(state)state.c $(time)time.c $(point)point.c $(inventory)inventory.c $(deliverylist)deliverylist.c $(listmakanan)listmakanan.c $(olahmakanan)olahmakanan.c $(peta)peta.c $(driver)driver.c -lm -Wall -o $(state)state

statestack: $(statestack)$(wildcard *.c)
	gcc $(statestack)statestack.c $(stack)stack.c $(time)time.c $(inventory)inventory.c $(deliverylist)deliverylist.c $(state)state.c $(statestack)driver.c -lm -Wall -o $(statestack)statestack

undostack: $(undostack)$(wildcard *.c)
	gcc $(undostack)undostack.c $(stack)stack.c $(time)time.c $(inventory)inventory.c $(deliverylist)deliverylist.c $(statestack)statestack.c $(undostack)driver.c -lm -Wall -o $(undostack)undostack

utility: $(utility)$(wildcard *.c) $(utility)$(wildcard *.txt)
	gcc $(utility)utility.c $(utility)driver.c -lm -Wall -o $(utility)utility

mekawaktu: $(mekawaktu)$(wildcard *.c)
	gcc $(mekawaktu)mekawaktu.c $(inventory)inventory.c $(deliverylist)deliverylist.c $(listmakanan)listmakanan.c $(olahmakanan)olahmakanan.c $(state)state.c $(mekawaktu)driver.c -lm -Wall -o $(mekawaktu)waktusim

main: lib/ program/ makefile
	gcc program/main.c $(liststatik)liststatik.c $(makanan)makanan.c $(matrix)matrix.c $(point)point.c $(queue)prioqueuetime.c $(queue)queue.c $(simulator)simulator.c $(stack)stack.c $(string)string.c $(time)time.c $(tree)tree.c $(wordmachine)wordmachine.c $(wordmachine)charmachine.c $(deliverylist)deliverylist.c $(inisiasi)inisiasi.c $(inventory)inventory.c $(kulkas)kulkas.c $(listmakanan)listmakanan.c $(notifikasi)notifikasi.c $(olahmakanan)olahmakanan.c $(peta)peta.c $(redostack)redostack.c $(resep)resep.c $(state)state.c $(statestack)statestack.c $(undostack)undostack.c $(utility)utility.c $(mekawaktu)mekawaktu.c -Wall -lm -o main

rmmain:
	rm -rf main 