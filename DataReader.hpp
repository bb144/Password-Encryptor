#ifndef DATAREADER_H_
#define DATAREADER_H_

#include <string>

class DataReader {
	private:
	const std::string INPUT_FILE_NAME = "names.txt";
	const std::string RAW_FILE_NAME = "rawdata.txt";
	const std::string OUTPUT_FILE_NAME = "encrypteddata.txt";
	const int PASSWORD_LENGTH = 9;
	char encryptionKey[9][26];
	public:
	DataReader();
	DataReader(const DataReader& d);
	~DataReader();
	void readData(std::string filename);
	void generatePassword(int passwordLength);
	std::string encryptPassword(std::string password);
	void storeData(std::string fileName);
	char encryptChar(int index, int letter);
};

#endif
