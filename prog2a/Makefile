CPP=gcc
DEBUG=-g
CPPFLAGS=-Wall $(DEBUG)
LFLAGS=-Wall $(DEBUG)
EXE=$(OBJS)
OBJS=echo.o
RM=rm -rf

all: $(EXE)

echo.o: echo.c
	$(CPP) $(CPPFLAGS) echo.c -o echo.o

clean:
	$(RM) *.o *.dSYM *~ *.out $(EXE)
