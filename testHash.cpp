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

void testHash() {
	const int NUMTASKS = 2;
	int passedTasks = 0;

	std::cout << "Running hash test:\n";
	DataHashing* d = new DataHashing();

	if (d->hash("abc") == 553) {
		passedTasks++;
	}
	else {
		std::cout << "abc hashed to wrong index\n";
	}

	if (d->hash("xyz") == 620) {
		passedTasks++;
	}
	else {
		std::cout << "xyz hashed to wrong index\n";
	}

	std::cout << "Hash test completed. "
			<< passedTasks << " / " << NUMTASKS
			<< " tasks successful.\n";
}

void testLookup() {
	const int NUMTASKS = 1;
	int passedTasks = 0;

	std::cout << "Running lookup test:\n";
	DataHashing* d = new DataHashing();

	node* a = new node();
	a->setID("abc");
	a->setPass("easyasonetwothree");

	node* b = new node();
	b->setID("What");
	b->setPass("Whatisthis??");

	node* g = new node();
	g->setID("garbo");
	g->setPass("Thisistrash");

	d->insert(g, 64);
	d->insert(a, d->hash("abc"));
	d->insert(b, 64);

	if (d->lookup("abc") == a) {
		passedTasks++;
	}
	else {
		std::cout << "Failed to find abc.\n";
	}

	std::cout << "Lookup test completed. "
			<< passedTasks << " / " << NUMTASKS
			<< " tasks successful.\n";
}

void testHashNode() {
	const int NUMTASKS = 2;
	int passedTasks = 0;

	std::cout << "Running hash node test:\n";
	DataHashing* d = new DataHashing();
	
	node* a = new node();
	node* b = new node();

	a->setID("abc");
	a->setPass("Easyasonetwothree");
	b->setID("xyz");
	b->setPass("Howembarrassing!");

	d->hashNode(a);
	d->hashNode(b);

	if (d->lookup("abc") == a) {
		passedTasks++;
	}
	else {
		std::cout << "failed to file abc correctly.\n";
	}

	if (d->lookup("xyz") == b) {
		passedTasks++;
	}
	else {
		std::cout << "failed to file xyz correctly.\n";
	}
	
	std::cout << "Hash node test completed. "
			<< passedTasks << " / " << NUMTASKS
			<< " tasks successful.\n";
}

void testNewUser() {
	const int NUMTASKS = 1;
	int passedTasks = 0;

	std::cout << "Running added user test:\n";
	DataHashing* d = new DataHashing();

	d->newUser("abc", "easyasonetwothree");
	//could've saved a lot of time if I tested this one earlier..
	
	if (d->lookup("abc")->getID() == "abc") {
		passedTasks++;
	}

	std::cout << "Added user test completed. "
			<< passedTasks << " / " << NUMTASKS
			<< " tasks successful.\n";
}

int main() {
	testDefaultConstructor();
	testShowAll();
	testHash();
	testLookup();
	testHashNode();
	testNewUser();
}
