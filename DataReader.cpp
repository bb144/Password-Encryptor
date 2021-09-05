#include "DataReader.hpp"

DataReader::DataReader() {
	for (int j = 0; j < 9; j++) {
		int offsetVals[9] = {9,14,13,4,18,24,12,14,13};
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

void DataReader::storeData(std::string name, std::string pass) {
	if (outFile.is_open()) {
		outFile << name << " " << pass << "\n";
	}
}

char DataReader::encryptChar(int index, char letter) {
	return encryptionKey[index][letter - 'a'];
}
