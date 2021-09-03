#ifndef DATAHASHING_H_
#define DATAHASHING_H_

#include "LinkedList.hpp"
#include "node.hpp"

class DataHashing {
	private:
		const int TABLE_SIZE = 100;
		LinkedList*[TABLE_SIZE] table;
	public:
		DataHashing();
		DataHashing(DataHashing* d);
		~DataHashing();
		void hash(node* user);
		void insert(node* user, int index);
		void newUser(std::string ID, std::string pass);
		node* lookup(std::string ID);
		void showAll();
};
#endif
