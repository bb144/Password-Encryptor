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

void DataHashing::hash(node* user) {

}

void DataHashing::insert(node* user, int index) {
	table[index]->add_node(user);
}

void DataHashing::newUser(std::string ID, std::string pass) {

}

node* DataHashing::lookup(std::string ID) {
	return nullptr;
}

void DataHashing::showAll() {
	for (long unsigned int i = 0; i < table.size(); i++) {
		if (table[i]->getHead() != nullptr) {
			std::cout << i << ": \n";
			table[i]->showAll();
		}
	}
}
