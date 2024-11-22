CC = gcc
CFLAGS = -std=gnu99 -pedantic -Wall
TARGET = home_task_7

all: $(TARGET)

$(TARGET): dynamic_2d_array.o main.o
	$(CC) $(CFLAGS) -o $(TARGET) dynamic_2d_array.o main.o

dynamic_2d_array.o: dynamic_2d_array.c dynamic_2d_array.h
	$(CC) $(CFLAGS) -c dynamic_2d_array.c

main.o: main.c dynamic_2d_array.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f *.o $(TARGET)
