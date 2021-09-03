#include "DataHashing.hpp"

DataHashing::DataHashing() {
	for (long unsigned int i = 0; i < table.size(); i++) {
		table[i] = new LinkedList();
	}
}

DataHashing::DataHashing(DataHashing* d) {
	
}

DataHashing::~DataHashing() {

}

int DataHashing::hash(std::string s) {
	long unsigned int hashValue = 1;
	for (long unsigned int i = 0; i < s.size(); i++) {
		hashValue *= s.at(i) * (i + 1);
	}
	hashValue %= TABLE_SIZE;
	return hashValue;
}

void DataHashing::hashNode(node* user) {
	insert(user, hash(user->getID()));
}

void DataHashing::insert(node* user, int index) {
	table[index]->add_node(user);
}

void DataHashing::newUser(std::string ID, std::string pass) {

}

node* DataHashing::lookup(std::string ID) {
	node* curr = table[hash(ID)]->getHead();
	node* target = nullptr;
	while (curr != nullptr) {
		if (curr->getID() == ID) {
			target = curr;
			curr = nullptr;
		}
		else {
			curr = curr->getNext();
		}
	}
	return target;
}

void DataHashing::showAll() {
	for (long unsigned int i = 0; i < table.size(); i++) {
		if (table[i]->getHead() != nullptr) {
			std::cout << i << ": \n";
			table[i]->showAll();
		}
	}
}
