// test.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

//#include "b64.h"
//#include "vigenere.h"
#include "encrypt.h"

#include <iostream>


int main()
{
	std::string key = "key";
	std::string flat = "456789";

	std::cout << "flat: " << flat << std::endl;

	std::string encrypted  = encrypt::encrypt(flat, key);

	std::cout << "encrypted: " << encrypted << std::endl;

	std::string decrypted = encrypt::decrypt(encrypted, key);

	std::cout << "decrypted: " << decrypted << std::endl;

    return 0;
}

