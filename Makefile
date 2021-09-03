CC=g++
CFLAGS=-Wall

main: main.cpp
	$(CC) $(CFLAGS) main.cpp -o main

test-node: testNode.cpp node.cpp
	$(CC) $(CFLAGS) testNode.cpp -o test-node

test-list: testList.cpp node.cpp LinkedList.cpp
	$(CC) $(CFLAGS) testList.cpp -o test-list

clean:
	rm -rf *.o
