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
}

DataReader::DataReader(const DataReader& d) {

}

DataReader::~DataReader() {

}

void DataReader::readData(std::string filename) {

}

void DataReader::generatePassword(int passwordLength) {

}

std::string DataReader::encryptPassword(std::string password) {
	return "";
}

void DataReader::storeData(std::string fileName) {

}

char DataReader::encryptChar(int index, int letter) {
	return encryptionKey[index][letter];
}
