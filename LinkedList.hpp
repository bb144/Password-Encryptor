#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "node.hpp"

class LinkedList {
	private:
		node* head;
	
	public:
		LinkedList();
		LinkedList(LinkedList* l);
		~LinkedList();
		void add_node(node* user);
		void showAll();
		node* getHead();
		void setHead(node* h);
};
#endif
