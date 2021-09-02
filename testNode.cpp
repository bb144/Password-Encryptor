#include <iostream>

#include "node.cpp"

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

	void testCopyConstructor() {
                const int NUMTASKS = 3;
                int passedTasks = 0;

		node* c = new node();
		node* d = new node();
		
		c->setID("barbera");
		c->setPass("meettheflinstones");
		c->setNext(d);

		node* n = new node(c);


                std::cout << "Running copy constructor test:\n";
		if (n->getID() == "barbera") {
                        passedTasks++;
                }
                else {
                        std::cout << "Copy constructor ID test failed\n";
                }

                if (n->getPass() == "meettheflinstones") {
                        passedTasks++;
                }
                else {
                        std::cout << "Copy constructor Pass test failed\n";
                }

                if (n->getNext() == d) {
                        passedTasks++;
                }
                else {
			std::cout << "Copy constructor Next test failed\n";
		}

		std::cout << "Copy Constructor Test completed. "
                        << passedTasks << " / " << NUMTASKS
                        << " tasks successful.\n";
	}

	int main() {
                testDefaultConstructor();
                testCopyConstructor();
                return 0;
        }

