CC=g++
CFLAGS=-Wall

main: main.cpp
	$(CC) $(CFLAGS) main.cpp -o main

test-node: testNode.cpp node.cpp
	$(CC) $(CFLAGS) testNode.cpp -o test-node

clean:
	rm -rf *.o
