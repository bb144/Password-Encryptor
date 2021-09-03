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
	user->setNext(head);
	head = user;
}

void LinkedList::showAll() {
	node* curr = head;
	while(curr != nullptr) {
		std::cout << curr->getID() << " " << curr->getPass() << "\n";
		curr = curr->getNext();
	}
}

node* LinkedList::getHead() {
	return head;
}

void LinkedList::setHead(node* h) {

}
