SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=)

all: $(OBJS)

% : %.c
	gcc $^ -lm -g -o $@.o

clean:
	$(RM) $(OBJS)
