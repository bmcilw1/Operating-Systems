CPP=gcc
DEBUG=-g
CPPFLAGS=-Wall $(DEBUG)
LFLAGS=-Wall $(DEBUG)
EXE=$(OBJS)
OBJS=series.o
RM=rm -rf

all: $(EXE)

series.o: series.c
	$(CPP) $(CPPFLAGS) series.c -o series.o

clean:
	$(RM) *.o *.dSYM *~ *.out $(EXE)
