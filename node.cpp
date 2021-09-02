#include "node.hpp"

node::node() {
	userID = "";
	password = "";
	next = nullptr;	
}

node::node(node* n) {
	userID = n->getID();
	password = n->getPass();
	next = n->getNext();
}

node::~node () {

}

std::string node::getID() {
	return userID;
}

std::string node::getPass() {
	return password;
}

node* node::getNext() {
	return next;
}

void node::setID(std::string s) {
	userID = s;
}

void node::setPass(std::string p) {
	password = p;
}

void node::setNext(node* n) {
	next = n;
}
