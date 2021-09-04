#include <iostream>

#include "DataReader.cpp"

void testDefaultConstructor() {
	const int NUMTASKS = 3;
	int passedTasks = 0;

	std::cout << "Running Default Constructor Test:\n";
	DataReader* d = new DataReader();

	if(d->encryptChar(0,0) == 'j') {
		passedTasks++;
	}
	else {
		std::cout << "first row returned " << d->encryptChar(0,0) 
			<< " instead of j\n";
	}
	if (d->encryptChar(0,25) == 'i') {
		passedTasks++;
	}
	else {
		std::cout << "end of first row returned " 
			<< d->encryptChar(0,25) << " instead of i\n";
;
	}
	if (d->encryptChar(8,25) == 'm') {
		passedTasks++;
	}
	else {
		std::cout << "final row returned " << d->encryptChar(8,25)
                        << " instead of m\n";

	}

	std::cout << "Default constructor test completed. "
			<< passedTasks << " / " << NUMTASKS
			<< " tasks successful.\n";
}

int main () {
	testDefaultConstructor();
//	testEncryptPassword();

	return 0;
};
