#ifndef DATAREADER_H_
#define DATAREADER_H_

#include <string>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>

class DataReader {
	private:
	const std::string INPUT_FILE_NAME = "names.txt";
	const std::string RAW_FILE_NAME = "rawdata.txt";
	const std::string OUTPUT_FILE_NAME = "encrypteddata.txt";
	const int PASSWORD_LENGTH = 9;
	char encryptionKey[9][26];
	std::ifstream inFile;
	std::ofstream outFile;
	public:
	DataReader();
	DataReader(const DataReader& d);
	~DataReader();
	void readDataInto(std::string inFileName, std::string outFileName);
	std::string generatePassword();
	std::string encryptPassword(std::string password);
	void storeData(std::string name, std::string pass);
	char encryptChar(int index, char letter);
};

#endif
