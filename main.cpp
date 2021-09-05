#include <iostream>

#include "DataReader.hpp"

int main ()
{
	DataReader* encrypted = new DataReader();
	DataReader* raw = new DataReader();

	std::cout << "Running Part 1: Encrypting and storing data\n";

	encrypted->readDataInto("names.txt", "rawdata.txt");
	encrypted->encryptData("rawdata.txt", "encrypteddata.txt");
	encrypted->hashAll("encrypteddata.txt");

	std::cout << "Running Part 2: Testing userid/password combinations\n";
	raw->hashAll("rawdata.txt");
	std::cout << "5 successful logins: \n";
	encrypted->login("SMITH", raw->getHasher()->lookup("SMITH")->getPass());
	encrypted->login("AIAVA", raw->getHasher()->lookup("AIAVA")->getPass());
	encrypted->login("CLARK", raw->getHasher()->lookup("CLARK")->getPass());
	encrypted->login("MAXWELL", 
			raw->getHasher()->lookup("MAXWELL")->getPass());
	encrypted->login("DODSON", 
			raw->getHasher()->lookup("DODSON")->getPass());
	std::cout << "5 unsuccesful logins: \n";
	std::string badPass;
	badPass = raw->getHasher()->lookup("GUY")->getPass();
	badPass.at(0)++;
	encrypted->login("GUY", badPass);
	badPass = raw->getHasher()->lookup("LUTZ")->getPass();
        badPass.at(0)++;
        encrypted->login("LUTZ", badPass);
	badPass = raw->getHasher()->lookup("BUTTS")->getPass();
        badPass.at(0)++;
        encrypted->login("BUTTS", badPass);
	badPass = raw->getHasher()->lookup("BOSWELL")->getPass();
        badPass.at(0)++;
        encrypted->login("BOSWELL", badPass);
	badPass = raw->getHasher()->lookup("LOCKWOOD")->getPass();
        badPass.at(0)++;
        encrypted->login("LOCKWOOD", badPass);
};
