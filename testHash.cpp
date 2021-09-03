#include <iostream>

#include "node.cpp"
#include "LinkedList.cpp"
#include "DataHashing.cpp"

void testDefaultConstructor() {

	std::cout << "Running default constructor test:\n";
	DataHashing* d = new DataHashing();

	d->showAll();

	std::cout << "Display should be empty.\n";

	std::cout << "Default constructor test completed.\n";
}

void testShowAll() {

	std::cout << "Running Show All test:\n";
	DataHashing* d = new DataHashing;
	node* b = new node();
	b->setID("barbera");
	b->setPass("meettheflinstones");
	node* n = new node();
	n->setID("nick");
	n->setPass("spongebob");
	node* l = new node();
	l->setID("Bugs");
	l->setPass("Whatsupdoc");
	node* m = new node();
	m->setID("Roadrunner");
	m->setPass("Meepmeep");
	node* h = new node();
	h->setID("Naruto");
	h->setPass("Believeit");

	d->insert(b,25);
	d->insert(n,25);
	d->insert(l,59);
	d->insert(m,59);
	d->insert(h,99);

	d->showAll();

	std::cout << "Should show info on barbera and nick | "
		<< "bugs and roadrunner | and naruto\n";
}

int main() {
	testDefaultConstructor();
	testShowAll();
}
