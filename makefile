use_msg := use the command "make file" to compile the respective driver in the folder, ex: "make main" will compile the main.c file.

all: 
	@echo $(use_msg)

extension := .out

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
rekomendasi := $(modul_path)/rekomendasi/
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

compile_msg = @echo -e "$(1) file compiled succesfully.\n"

liststatik: $(liststatik)$(wildcard *.c)
	@gcc $(liststatik)liststatik.c $(liststatik)driver.c -lm -Wall -o $(liststatik)liststatik$(extension)
	$(call compile_msg,liststatik)

makanan: $(makanan)$(wildcard *.c)
	@gcc $(makanan)makanan.c $(string)string.c $(time)time.c $(wordmachine)wordmachine.c $(wordmachine)charmachine.c $(makanan)driver.c -lm -Wall -o $(makanan)makanan$(extension)
	$(call compile_msg,makanan)

matrix: $(matrix)$(wildcard *.c)
	@gcc $(matrix)matrix.c $(matrix)driver.c -lm -Wall -o $(matrix)matrix$(extension)
	$(call compile_msg,matrix)

point: $(point)$(wildcard *.c)
	@gcc $(point)point.c $(point)driver.c -lm -Wall -o $(point)point$(extension)
	$(call compile_msg,point)

queue: $(queue)$(wildcard *.c)
	@gcc $(queue)prioqueuetime.c $(utility)utility.c $(makanan)makanan.c $(queue)queue.c $(wordmachine)wordmachine.c $(wordmachine)charmachine.c $(time)time.c $(string)string.c $(queue)driver.c -lm -Wall -o $(queue)queue$(extension)
	$(call compile_msg,queue)

set: $(set)$(wildcard *.c)
	@gcc $(set)set.c $(set)driver.c -o $(set)set$(extension)
	$(call compile_msg,set)

simulator: $(simulator)$(wildcard *.c)
	@gcc $(simulator)simulator.c $(string)string.c $(point)point.c $(queue)prioqueuetime.c $(makanan)makanan.c $(time)time.c $(wordmachine)wordmachine.c $(wordmachine)charmachine.c $(listmakanan)listmakanan.c $(utility)utility.c $(inventory)inventory.c $(deliverylist)deliverylist.c $(state)state.c $(olahmakanan)olahmakanan.c $(resep)resep.c $(tree)tree.c $(simulator)driver.c -lm -Wall -o $(simulator)simulator$(extension)
	$(call compile_msg,simulator)

stack: $(stack)$(wildcard *.c)
	@gcc $(stack)stack.c $(stack)driver.c -lm -Wall -o $(stack)stack$(extension)
	$(call compile_msg,stack)

string: $(string)$(wildcard *.c)
	@gcc $(string)string.c $(wordmachine)wordmachine.c $(wordmachine)charmachine.c $(string)driver.c -lm -Wall -o $(string)string$(extension)
	$(call compile_msg,string)

time: $(time)$(wildcard *.c)
	@gcc $(time)time.c $(string)string.c $(wordmachine)wordmachine.c $(wordmachine)charmachine.c $(time)driver.c -lm -Wall -o $(time)time$(extension)
	$(call compile_msg,time)

tree: $(tree)$(wildcard *.c)
	@gcc $(tree)tree.c $(tree)driver.c -lm -Wall -o $(tree)tree$(extension)
	$(call compile_msg,tree)

wordmachine: $(wordmachine)$(wildcard *.c)
	@gcc $(wordmachine)wordmachine.c $(wordmachine)charmachine.c $(wordmachine)driver.c -lm -Wall -o $(wordmachine)wordmachine$(extension)
	$(call compile_msg,wordmachine)

deliverylist: $(deliverylist)$(wildcard *.c)
	@gcc $(deliverylist)deliverylist.c $(queue)prioqueuetime.c $(inventory)inventory.c $(olahmakanan)olahmakanan.c $(time)time.c $(makanan)makanan.c $(string)string.c $(liststatik)liststatik.c $(wordmachine)wordmachine.c $(wordmachine)charmachine.c $(utility)utility.c $(tree)tree.c $(resep)resep.c $(listmakanan)listmakanan.c $(deliverylist)driver.c -lm -Wall -o $(deliverylist)deliverylist$(extension)
	$(call compile_msg,deliverylist)

inventory: $(inventory)$(wildcard *.c)
	@gcc $(inventory)inventory.c $(makanan)makanan.c $(wordmachine)wordmachine.c $(wordmachine)charmachine.c $(time)time.c $(string)string.c $(queue)prioqueuetime.c $(tree)tree.c $(resep)resep.c $(listmakanan)listmakanan.c $(utility)utility.c $(inventory)driver.c -lm -Wall -o $(inventory)inventory$(extension)
	$(call compile_msg,inventory)

kulkas: $(kulkas)$(wildcard *.c)
	@gcc $(kulkas)kulkas.c $(matrix)matrix.c $(makanan)makanan.c $(string)string.c $(inventory)inventory.c $(wordmachine)wordmachine.c $(wordmachine)charmachine.c $(time)time.c $(queue)prioqueuetime.c $(listmakanan)listmakanan.c $(utility)utility.c $(kulkas)driver.c -lm -Wall -o $(kulkas)kulkas$(extension)
	$(call compile_msg,kulkas)

listmakanan: $(listmakanan)$(wildcard *.c)
	@gcc $(listmakanan)listmakanan.c $(makanan)makanan.c $(wordmachine)wordmachine.c $(wordmachine)charmachine.c $(time)time.c $(string)string.c $(resep)resep.c $(tree)tree.c $(utility)utility.c $(listmakanan)driver.c -lm -Wall -o $(listmakanan)listmakanan$(extension)
	$(call compile_msg,listmakanan)

notifikasi: $(notifikasi)$(wildcard *.c)
	@gcc $(notifikasi)notifikasi.c $(makanan)makanan.c $(wordmachine)wordmachine.c $(wordmachine)charmachine.c $(listmakanan)listmakanan.c $(deliverylist)deliverylist.c $(state)state.c $(inventory)inventory.c $(time)time.c $(string)string.c $(queue)prioqueuetime.c $(utility)utility.c $(tree)tree.c $(resep)resep.c $(olahmakanan)olahmakanan.c $(notifikasi)driver.c -lm -Wall -o $(notifikasi)notifikasi$(extension)
	$(call compile_msg,notifikasi)

olahmakanan: $(olahmakanan)$(wildcard *.c)
	@gcc $(olahmakanan)olahmakanan.c $(makanan)makanan.c $(queue)queue.c $(string)string.c $(matrix)matrix.c $(liststatik)liststatik.c $(point)point.c $(listmakanan)listmakanan.c $(inventory)inventory.c $(resep)resep.c $(deliverylist)deliverylist.c $(wordmachine)wordmachine.c $(wordmachine)charmachine.c $(time)time.c $(queue)prioqueuetime.c $(tree)tree.c $(utility)utility.c $(olahmakanan)driver.c -lm -Wall -o $(olahmakanan)olahmakanan$(extension)
	$(call compile_msg,olahmakanan)

peta: $(peta)$(wildcard *.c)
	@gcc $(peta)peta.c $(matrix)matrix.c $(point)point.c $(wordmachine)wordmachine.c $(wordmachine)charmachine.c $(peta)driver.c -lm -Wall -o $(peta)peta$(extension)
	$(call compile_msg,peta)

redostack: $(redostack)$(wildcard *.c)
	@gcc $(redostack)redostack.c $(stack)stack.c $(time)time.c $(inventory)inventory.c $(deliverylist)deliverylist.c $(utility)utility.c $(queue)prioqueuetime.c $(makanan)makanan.c $(olahmakanan)olahmakanan.c $(queue)queue.c $(listmakanan)listmakanan.c $(state)state.c $(statestack)statestack.c $(wordmachine)wordmachine.c $(wordmachine)charmachine.c $(string)string.c $(point)point.c $(resep)resep.c $(tree)tree.c $(redostack)driver.c -lm -Wall -o $(redostack)redostack$(extension)
	$(call compile_msg,redo)

resep: $(resep)$(wildcard *.c)
	@gcc $(resep)resep.c $(makanan)makanan.c $(string)string.c $(time)time.c $(wordmachine)wordmachine.c $(wordmachine)charmachine.c $(tree)tree.c $(utility)utility.c $(listmakanan)listmakanan.c $(resep)driver.c -lm -Wall -o $(resep)resep$(extension)
	$(call compile_msg,resep)

rekomendasi: $(rekomendasi)$(wildcard *.c)
	@gcc $(listmakanan)listmakanan.c $(utility)utility.c $(tree)tree.c $(resep)resep.c $(set)set.c $(inventory)inventory.c $(makanan)makanan.c $(wordmachine)wordmachine.c $(wordmachine)charmachine.c $(queue)prioqueuetime.c $(time)time.c $(string)string.c $(rekomendasi)rekomendasi.c $(rekomendasi)driver.c -o $(rekomendasi)rekomendasi$(extension)
	$(call compile_msg,rekomendasi)

state: $(state)$(wildcard *.c)
	@gcc $(state)state.c $(makanan)makanan.c $(time)time.c $(string)string.c $(tree)tree.c $(resep)resep.c $(utility)utility.c $(queue)queue.c $(queue)prioqueuetime.c $(point)point.c $(inventory)inventory.c $(deliverylist)deliverylist.c $(listmakanan)listmakanan.c $(olahmakanan)olahmakanan.c $(wordmachine)wordmachine.c $(wordmachine)charmachine.c $(matrix)matrix.c $(peta)peta.c $(state)driver.c -lm -Wall -o $(state)state$(extension)
	$(call compile_msg,state)

statestack: $(statestack)$(wildcard *.c)
	@gcc $(statestack)statestack.c $(stack)stack.c $(time)time.c $(inventory)inventory.c $(deliverylist)deliverylist.c $(string)string.c $(queue)queue.c $(queue)prioqueuetime.c $(makanan)makanan.c $(olahmakanan)olahmakanan.c $(listmakanan)listmakanan.c $(utility)utility.c $(wordmachine)wordmachine.c $(wordmachine)charmachine.c $(state)state.c $(tree)tree.c $(resep)resep.c $(point)point.c $(statestack)driver.c -lm -Wall -o $(statestack)statestack$(extension)
	$(call compile_msg,statestack)

undostack: $(undostack)$(wildcard *.c)
	@gcc $(undostack)undostack.c $(stack)stack.c $(time)time.c $(inventory)inventory.c $(tree)tree.c $(resep)resep.c $(olahmakanan)olahmakanan.c $(point)point.c $(makanan)makanan.c $(listmakanan)listmakanan.c $(deliverylist)deliverylist.c $(string)string.c $(queue)queue.c $(queue)prioqueuetime.c $(utility)utility.c $(wordmachine)wordmachine.c $(wordmachine)charmachine.c $(state)state.c $(statestack)statestack.c $(undostack)driver.c -lm -Wall -o $(undostack)undostack$(extension)
	$(call compile_msg,undostack)

utility: $(utility)$(wildcard *.c) $(utility)$(wildcard *.txt)
	@gcc $(utility)utility.c $(utility)driver.c -lm -Wall -o $(utility)utility$(extension)
	$(call compile_msg,utility)

main: lib/ program/ makefile
	@gcc program/main.c $(liststatik)liststatik.c $(makanan)makanan.c $(matrix)matrix.c $(point)point.c $(queue)prioqueuetime.c $(queue)queue.c $(set)set.c $(simulator)simulator.c $(stack)stack.c $(string)string.c $(time)time.c $(tree)tree.c $(wordmachine)wordmachine.c $(wordmachine)charmachine.c $(deliverylist)deliverylist.c $(inisiasi)inisiasi.c $(inventory)inventory.c $(kulkas)kulkas.c $(listmakanan)listmakanan.c $(notifikasi)notifikasi.c $(olahmakanan)olahmakanan.c $(peta)peta.c $(redostack)redostack.c $(resep)resep.c $(state)state.c $(statestack)statestack.c $(undostack)undostack.c $(rekomendasi)rekomendasi.c $(utility)process.c $(utility)utility.c $(mekawaktu)mekawaktu.c -Wall -lm -o main$(extension)
	$(call compile_msg,main)
	@./main$(extension)

compile: liststatik makanan matrix point queue set simulator stack string time tree wordmachine deliverylist inventory kulkas rekomendasi listmakanan notifikasi olahmakanan peta redostack resep state statestack undostack utility main
	@echo -e "All file compiled succesfully.\n\n"


run_msg = @echo -e Running file $(1)\n\n.
run_command = @$($(1))$(1)$(extension)

run: compile
	@echo -e "==============================\n\n\nRunning all programs.\n"

	$(call run_msg,liststatik)
	$(call run_command,liststatik)
	$(call run_msg,makanan)
	$(call run_command,makanan)
	$(call run_msg,matrix)
	$(call run_command,matrix)
	$(call run_msg,point)
	$(call run_command,point)
	$(call run_msg,queue)
	$(call run_command,queue)
	$(call run_msg,set)
	$(call run_command,set)
	$(call run_msg,simulator)
	$(call run_command,simulator)
	$(call run_msg,stack)
	$(call run_command,stack)
	$(call run_msg,string)
	$(call run_command,string)
	$(call run_msg,time)
	$(call run_command,time)
	$(call run_msg,tree)
	$(call run_command,tree)
	$(call run_msg,wordmachine)
	$(call run_command,wordmachine)
	$(call run_msg,deliverylist)
	$(call run_command,deliverylist)
	$(call run_msg,inventory)
	$(call run_command,inventory)
	$(call run_msg,kulkas)
	$(call run_command,kulkas)
	$(call run_msg,rekomendasi)
	$(call run_command,rekomendasi)
	$(call run_msg,listmakanan)
	$(call run_command,listmakanan)
	$(call run_msg,notifikasi)
	$(call run_command,notifikasi)
	$(call run_msg,olahmakanan)
	$(call run_command,olahmakanan)
	$(call run_msg,peta)
	$(call run_command,peta)
	$(call run_msg,redostack)
	$(call run_command,redostack)
	$(call run_msg,resep)
	$(call run_command,resep)
	$(call run_msg,state)
	$(call run_command,state)
	$(call run_msg,statestack)
	$(call run_command,statestack)
	$(call run_msg,undostack)
	$(call run_command,undostack)
	$(call run_msg,utility)
	$(call run_command,utility)

	@echo All program ran succesfully.