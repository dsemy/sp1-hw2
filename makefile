CC = gcc
CFLAGS = -Wall -L.

all: connections

connections: main.o libmy_mat.a
	$(CC) $(CFLAGS) $< -lmy_mat -o $@

main.c: my_mat.h

libmy_mat.a: my_mat.o
	ar rcs $@ $^

my_mat.o: my_mat.h

clean: # Note: *~ are temporary files created by my editor.
	rm -f *.o *.a *~ connections

.PHONY: all clean
