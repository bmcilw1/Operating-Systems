SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=)

all: $(OBJS)

% : %.c
	gcc $^ -fopenmp -lm -g -o $@.o

clean:
	$(RM) $(OBJS)
