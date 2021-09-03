#ifndef DATAHASHING_H_
#define DATAHASHING_H_

#include <array>

#include "LinkedList.hpp"
#include "node.hpp"

class DataHashing {
	private:
		std::array<LinkedList*, 100> table;
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
