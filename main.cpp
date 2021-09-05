#include <iostream>

#include "DataReader.hpp"

int main ()
{
	DataReader encrypted = new DataReader();
	DataReader raw = new DataReader();

	std::cout << "Running Part 1: Encrypting and storing data\n";

	r.readDataInto("names.txt", "rawdata.txt");
	r.encryptData("rawdata.txt", "encrypteddata.txt");
	r.hashAll("encrypteddata.txt");

	std::cout << "Running Part 2: Testing userid/password combinations";
	
};
