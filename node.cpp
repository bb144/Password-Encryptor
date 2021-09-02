#include "node.hpp"

node::node() {
	userID = "";
	password = "";
	next = nullptr;	
}

node::node(node* n) {

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
	
}

void node::setPass(std::string p) {
	
}

void node::setNext(node* n) {
	
}
