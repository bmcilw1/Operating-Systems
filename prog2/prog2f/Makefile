CPP=gcc
DEBUG=-g
CPPFLAGS=-Wall $(DEBUG)
LFLAGS=-Wall $(DEBUG)
EXE=$(OBJS)
OBJS=pony.o carrot.o execute.o
RM=rm -rf

all: $(EXE)

pony.o: pony.c
	$(CPP) $(CPPFLAGS) pony.c -o pony.o

carrot.o: carrot.c
	$(CPP) $(CPPFLAGS) carrot.c -o carrot.o

execute.o: execute.c
	$(CPP) $(CPPFLAGS) execute.c -o execute.o

clean:
	$(RM) *.o *.dSYM *~ *.out $(EXE)
