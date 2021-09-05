#include "DataReader.hpp"

DataReader::DataReader() {
	for (int j = 0; j < 9; j++) {
		int currAscii;
		for (int i = 0; i < 26; i++) {
			currAscii = (('a' + i) + offsetVals[j]);
			if (currAscii > 'z') {
				currAscii -= 26;
			}
			encryptionKey[j][i] = currAscii;
		}
	}

	srand(time(NULL));
}

DataReader::DataReader(const DataReader& d) {

}

DataReader::~DataReader() {

}

void DataReader::readDataInto(std::string inFileName, std::string outFileName) {
	std::string currName = "";
	
	inFile.open(inFileName);
	outFile.open(outFileName);

	if (inFile.is_open()) {
		inFile >> currName;
		storeData(currName, generatePassword());

		while (!inFile.eof()) {
//		for (int j = 0; j < 10; j++) {
			for (int i = 0; i < 3; i++) {
				inFile >> currName;
			}
			if (!inFile.eof()) {
				inFile >> currName;
				if (currName != "88799") {
					storeData(currName, generatePassword());
				}
			}
		}
	}
	inFile.close();
	outFile.close();
}

void DataReader::encryptData(std::string inFileName, std::string outFileName) {
	std::string currName = "";
	std::string currPass = "";
	std::string prevName;
	
	inFile.open(inFileName);
	outFile.open(outFileName);

	if(inFile.is_open()) {
		while (!inFile.eof()) {
			currName = prevName;
			inFile >> currName;
			inFile >> currPass;
			if (currName != prevName) {
				storeData(currName, encryptPassword(currPass));
			}
		}
	}
	inFile.close();
	outFile.close();
}

void DataReader::hashAll(std::string inFileName) {
	std::string currName = "";
	std::string currPass = "";
	std::string prevName;

	inFile.open(inFileName);
	if (inFile.is_open()) {
		while(!inFile.eof()) {
			currName = prevName;
                        inFile >> currName;
                        inFile >> currPass;
                        if (currName != prevName) {
				hashTable->newUser(currName, currPass);
			}
		}
	}
	else {
		std::cout << "Error, " << inFileName << "failed to open!\n";
	}
}

std::string DataReader::generatePassword() {
	std::string password = "";
	std::string currChar;
	for (int i = 0; i < PASSWORD_LENGTH; i++) {
		currChar = (rand() % 25 + 97);
		password.append(currChar);
	}	
	return password;
}

std::string DataReader::encryptPassword(std::string password) {
	for (unsigned long int i = 0; i < password.length(); i++) {
		password.at(i) = encryptChar(i, password.at(i));
	}
	return password;
}

std::string DataReader::decrypt(std::string encryptedString) {
	for (unsigned long int i = 0; i < encryptedString.length(); i++) {
		encryptedString.at(i) = decryptChar(i, encryptedString.at(i));
	}
	return encryptedString;
}

void DataReader::storeData(std::string name, std::string pass) {
	if (outFile.is_open()) {
		outFile << name << " " << pass << "\n";
	}
}

char DataReader::encryptChar(int index, char letter) {
	return encryptionKey[index][letter - 'a'];
}

char DataReader::decryptChar(int index, char letter) {
	letter -= offsetVals[index];

	if (letter < 'a') {
		letter += 26;
	}

	return letter;
}

void DataReader::login(std::string userID, std::string password) {
	std::string encryptedPass = encryptPassword(password);
	if (encryptedPass == hashTable->lookup(userID)->getPass()) {
		std::cout << userID << "\t" << password << "\tmatch\n";
	}
	else {
		std::cout << userID << "\t" << password << "\tno match\n";
	}
}

DataHashing* DataReader::getHasher() {
	return hashTable;
}
