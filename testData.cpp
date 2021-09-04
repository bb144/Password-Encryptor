#include <iostream>

#include "DataReader.cpp"

void testDefaultConstructor() {
	const int NUMTASKS = 3;
	int passedTasks = 0;

	std::cout << "Running Default Constructor Test:\n";
	DataReader* d = new DataReader();

	if(d->encryptChar(0,'a') == 'j') {
		passedTasks++;
	}
	else {
		std::cout << "first row returned " << d->encryptChar(0,0) 
			<< " instead of j\n";
	}
	if (d->encryptChar(0,'z') == 'i') {
		passedTasks++;
	}
	else {
		std::cout << "end of first row returned " 
			<< d->encryptChar(0,25) << " instead of i\n";
;
	}
	if (d->encryptChar(8,'z') == 'm') {
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

void testEncryptPassword() {
	const int NUMTASKS = 1;
	int passedTasks = 0;

	std::cout << "Running Password Encryption Test:\n";
	DataReader* e = new DataReader();
	std::string pass = "passwords";

	if (e->encryptPassword(pass) == "yofwomdrf") {
		passedTasks++;
	}
	else {
		std::cout << "encryptPassword returned " 
			<< e->encryptPassword(pass)
			<< " instead of yofwomdrf\n";
	}

	std::cout << "Password encryption test completed. "
                        << passedTasks << " / " << NUMTASKS
                        << " tasks successful.\n";
}

int main () {
	testDefaultConstructor();
	testEncryptPassword();

	return 0;
};
