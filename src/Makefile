CC = g++ 			#compiler
CFLAGS = -g -c -Wall -I../include/ 	#flags
WXWFLAG = `wx-config --cxxflags`
WXWLIB =  `wx-config --libs`
BINDIR = ../bin
OUTFILE = ptatool.bin
OUTPUT = -o $(BINDIR)/$(OUTFILE)

all: ptatool 

ptatool: main.o Attack.o Attackdex.o functions.o Master.o parsers.o Pkmn.o Pokedex.o Pokemon.o Visual.o
	mkdir -p $(BINDIR)
	@echo "Compiling PTA Tool Executable"
	$(CC) $(WXWFLAG) main.o Attack.o Attackdex.o functions.o Master.o parsers.o Pkmn.o Pokedex.o Pokemon.o Visual.o $(OUTPUT) $(WXWLIB)
	@echo "Compilation Complete :)"

main.o: main.cpp
	@echo "Compiling main.cpp"
	$(CC) $(CFLAGS) main.cpp 

Attack.o: ../include/Attack.h
	@echo "Compiling Attack.cpp"
	$(CC) $(CFLAGS) Attack.cpp 

Attackdex.o: ../include/Attackdex.h
	@echo "Compiling Attackdex.cpp"
	$(CC) $(CFLAGS) Attackdex.cpp 

functions.o: ../include/functions.h
	@echo "Compiling functions.cpp"
	$(CC) $(CFLAGS) functions.cpp 

Master.o: ../include/Master.h
	@echo "Compiling Master.cpp"
	$(CC) $(CFLAGS) Master.cpp 

parsers.o: 
	@echo "Compiling parsers.cpp"
	$(CC) $(CFLAGS) parsers.cpp 

Pkmn.o: ../include/Pkmn.h
	@echo "Compiling Pkmn.cpp"
	$(CC) $(CFLAGS) Pkmn.cpp 

Pokedex.o: ../include/Pokedex.h
	@echo "Compiling Pokedex.cpp"
	$(CC) $(CFLAGS) Pokedex.cpp 

Pokemon.o: ../include/Pokemon.h
	@echo "Compiling Pokemon.cpp"
	$(CC) $(CFLAGS) Pokemon.cpp 

Visual.o: 
	@echo "Compiling Visual.cpp"
	$(CC) $(CFLAGS) Visual.cpp 


clean: #cleaning
	@echo "Cleaning objects"
	rm -rf *.o ptatool
	@echo "Cleaning binary"
	rm -rf $(BINDIR)/$(OUTFILE)

ca: clean all
