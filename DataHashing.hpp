#ifndef DATAHASHING_H_
#define DATAHASHING_H_

#include <array>
#include <iostream>

#include "LinkedList.hpp"
#include "node.hpp"

class DataHashing {
	private:
		const int TABLE_SIZE = 100;
		std::array<LinkedList*, 100> table;
	public:
		DataHashing();
		DataHashing(DataHashing* d);
		~DataHashing();
		int hash(std::string s);
		void hashNode(node* user);
		void insert(node* user, int index);
		void newUser(std::string ID, std::string pass);
		node* lookup(std::string ID);
		void showAll();
};
#endif
