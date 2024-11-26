# Compiler
CC = gcc
CXX = g++
CFLAGS = -Wall -Wextra

# Targets
all: c_vector
test: test_assert test_gtest

# Main program
c_vector: main.o c_vector.o
	$(CC) $(CFLAGS) -o c_vector main.o c_vector.o

main.o: main.c c_vector.h
	$(CC) $(CFLAGS) -c main.c

c_vector.o: c_vector.c c_vector.h
	$(CC) $(CFLAGS) -c c_vector.c

# Target for asserts testing
test_assert: test_c_vector.o c_vector.o
	$(CC) $(CFLAGS) -o test_assert test_c_vector.o c_vector.o

test_c_vector.o: test_c_vector.c c_vector.h
	$(CC) $(CFLAGS) -c test_c_vector.c

# Target for Google Test (g++ for C++)
# Additional option to link gtest might be required here!
test_gtest: test_c_vector_gtest.o c_vector.o
	$(CXX) $(CFLAGS) -o test_gtest test_c_vector_gtest.o c_vector.o -lgtest -lgtest_main -pthread

test_c_vector_gtest.o: test_c_vector.cpp c_vector.h
	$(CXX) $(CFLAGS) -c test_c_vector.cpp -o test_c_vector_gtest.o


# Clean up
clean:
	rm -f *.o c_vector test_assert test_gtest
