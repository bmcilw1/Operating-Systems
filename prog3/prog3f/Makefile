SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=)

all: $(OBJS)

% : %.c
	gcc $^ -fopenmp -Werror -lm -o $@.o

clean:
	$(RM) $(OBJS)
