CC = gcc
CFLAGS = -Wall -Wextra -std=c99

PROGRAM = minishell
OBJECTS = main.o parser.o executor.o

.PHONY: all run clean

all: $(PROGRAM)

$(PROGRAM): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(PROGRAM) $(OBJECTS)

%.o: %.c shell.h
	$(CC) $(CFLAGS) -c $<

run: $(PROGRAM)
	./$(PROGRAM)

clean:
	rm -f $(OBJECTS) $(PROGRAM)
