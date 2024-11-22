CC = gcc
CFLAGS = -Wall -Wextra -g

all: c_vector

c_vector: c_vector.o main.o
	$(CC) $(CFLAGS) -o c_vector c_vector.o main.o

c_vector.o: c_vector.c c_vector.h
	$(CC) $(CFLAGS) -c c_vector.c

main.o: main.c c_vector.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f *.o c_vector
