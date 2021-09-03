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

int main() {
	testDefaultConstructor();
	return 0;
}
