#include <iostream>

#include "node.cpp"

void testDefaultConstructor();

	int main() {
		testDefaultConstructor();
		return 0;
	}

	void testDefaultConstructor() {
		const int NUMTASKS = 3;
		int passedTasks = 0;

		node* n = new node();

		std::cout << "Running default constructor test:\n";

		if (n->getID() == "") {
			passedTasks++;
		}
		else {
			std::cout << "Default constructor ID test failed\n";
		}

		if (n->getPass() == "") {
			passedTasks++;
		}
		else {
			std::cout << "Default constructor Pass test failed\n";
		}

		if (n->getNext() == nullptr) {
			passedTasks++;
		}
		else {
			std::cout << "Default constructor next test failed\n";
		}

		std::cout << "Default Constructor Test completed. " 
			<< passedTasks << " / " << NUMTASKS 
			<< " tasks successful.\n";
	}
