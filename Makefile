CC=g++
CFLAGS=-Wall

main: main.cpp DataReader.cpp DataHashing.cpp LinkedList.cpp node.cpp
	$(CC) $(CFLAGS) main.cpp DataReader.cpp DataHashing.cpp LinkedList.cpp node.cpp -o main

test-node: testNode.cpp node.cpp
	$(CC) $(CFLAGS) testNode.cpp -o test-node

test-list: testList.cpp node.cpp LinkedList.cpp
	$(CC) $(CFLAGS) testList.cpp -o test-list

test-hash: testHash.cpp node.cpp LinkedList.cpp DataHashing.cpp
	$(CC) $(CFLAGS) testHash.cpp -o test-hash

test-data: testData.cpp DataReader.cpp DataHashing.cpp LinkedList.cpp node.cpp
	$(CC) $(CFLAGS) testData.cpp DataReader.cpp DataHashing.cpp LinkedList.cpp node.cpp -o test-data

clean:
	rm -rf *.o
