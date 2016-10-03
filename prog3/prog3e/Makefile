SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=)

all: $(OBJS)

% : %.c
	gcc $^ -fopenmp -lm -o $@.o

clean:
	$(RM) $(OBJS)
