#ifndef DATAREADER_H_
#define DATAREADER_H_

#include <string>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include "DataHashing.hpp"

class DataReader {
	private:
	const std::string INPUT_FILE_NAME = "names.txt";
	const std::string RAW_FILE_NAME = "rawdata.txt";
	const std::string OUTPUT_FILE_NAME = "encrypteddata.txt";
	const int PASSWORD_LENGTH = 9;
	int offsetVals[9] = {9,14,13,4,18,24,12,14,13};
	char encryptionKey[9][26];
	std::ifstream inFile;
	std::ofstream outFile;
	DataHashing* hashTable = new DataHashing();
	public:
	DataReader();
	DataReader(const DataReader& d);
	~DataReader();
	void readDataInto(std::string inFileName, std::string outFileName);
	void encryptData(std::string inFileName, std::string outFileName);
	void hashAll(std::string inFileName);
	std::string generatePassword();
	std::string encryptPassword(std::string password);
	std::string decrypt(std::string encryptedString);
	void storeData(std::string name, std::string pass);
	char encryptChar(int index, char letter);
	char decryptChar(int index, char letter);
	void login(std::string userID, std::string password);
	DataHashing* getHasher();
};

#endif
