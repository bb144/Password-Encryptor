#include <iostream>

#include "node.cpp"
#include "LinkedList.cpp"

void testDefaultConstructor() {
	const int NUMTASKS = 1;
	int passedTasks = 0;

	std::cout << "Running default constructor test:\n";
	LinkedList* l = new LinkedList;

	if (l->getHead() == nullptr) {
		passedTasks++;
	}
	else {
		std::cout << "Default constructor Head test failed\n";
	}

	std::cout << "Default Constructor Test completed. " 
			<< passedTasks << " / " << NUMTASKS 
			<< " tasks successful.\n";
}

void testAddNode() {
	const int NUMTASKS = 3;
        int passedTasks = 0;

        std::cout << "Running Add Node test:\n";

	node* n = new node();
	n->setID("barbera");
	n->setPass("meettheflinstones");
	LinkedList* a = new LinkedList();

	a->add_node(n);

	if (a->getHead() == n) {
		passedTasks++;
	}
	else {
		std::cout << "Failure to repoint head to added node.\n";
	}

	node* m = new node();
	m->setID("nick");
	m->setPass("spongebob");
	a->add_node(m);

	if (a->getHead() == m) {
		passedTasks++;
	}
	else {
		std::cout << "Failure to update head after additional node.\n";
	}

	if (a->getHead()->getNext() == n) {
		passedTasks++;
	}
	else {
		std::cout << "Failure to link nodes together.\n";
	}

	std::cout << "Add Node Test completed. "
                        << passedTasks << " / " << NUMTASKS
                        << " tasks successful.\n";
}

void testShowAll() {

        std::cout << "Running Show All test:\n";

        node* n = new node();
        n->setID("barbera");
        n->setPass("meettheflinstones");
	node* m = new node();
        m->setID("nick");
        m->setPass("spongebob");
        LinkedList* a = new LinkedList();

        a->add_node(n);
	a->add_node(m);

	a->showAll();
	std::cout << "Should be:\n" 
		<< "nick spongebob\nbarbera meettheflinstones\n";
	std::cout << "completed Show All test.\n";
}

int main() {
	testDefaultConstructor();
	testAddNode();
	testShowAll();
	return 0;
}
