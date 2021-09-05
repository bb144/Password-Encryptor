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

void testGeneratePassword() {
	std::cout << "Running password generation test.\n";
	DataReader* g = new DataReader();
	std::cout << g->generatePassword() << "\n";
	std::cout << g->generatePassword() << "\n";
	std::cout << "Should generate 9 random characters a-z twice.\n";
}

void testReadDataInto() {
	std::cout << "Running read data test.\n";
	DataReader* r = new DataReader();
	r->readDataInto("names.txt", "rawdata.txt");
	std::cout << "Read data test completed. Check output files.\n";
}

void testEncryptData() {
	std::cout << "Running encrypt data test.\n";
	DataReader* r = new DataReader();
	r->encryptData("rawdata.txt", "encrypteddata.txt");
	std::cout << "Encrypt data test completed. Check output files.\n";
}

int main () {
	testDefaultConstructor();
	testEncryptPassword();
	testGeneratePassword();
	testReadDataInto();
	testEncryptData();

	return 0;
};
