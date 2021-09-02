#include "node.hpp"

node::node() {
		
}

node::node(node* n) {

}

node::~node () {

}

std::string node::getID() {
	return "temp";
}

std::string node::getPass() {
	return "temp";
}

node* node::getNext() {
	node* n = new node();
	return n;
}

void node::setID(std::string s) {
	
}

void node::setPass(std::string p) {
	
}

void node::setNext(node* n) {
	
}
