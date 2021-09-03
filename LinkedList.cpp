#include "LinkedList.hpp"

LinkedList::LinkedList() {
	head = nullptr;
}

LinkedList::LinkedList(LinkedList* l) {
	head = l->getHead();
}

LinkedList::~LinkedList() {
	
}

void LinkedList::add_node(node* user) {
	
}

void LinkedList::showAll() {

}

node* LinkedList::getHead() {
	return head;
}

void LinkedList::setHead(node* h) {

}
