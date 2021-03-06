// test.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

//#include "b64.h"
//#include "vigenere.h"
#include "encrypt.h"

#include <iostream>


int main()
{
	// std::string values
	std::string key = "key";
	std::string flat = "456789";

	std::cout << "flat: " << flat << std::endl;

	std::string encrypted  = encrypt::encrypt(flat, key);

	std::cout << "encrypted: " << encrypted << std::endl;

	std::string decrypted = encrypt::decrypt(encrypted, key);

	std::cout << "decrypted: " << decrypted << std::endl;

	// std::wstring values
	std::wstring wkey = L"key";
	std::wstring wflat = L"456789";

	std::wcout << L"flat: " << wflat << std::endl;

	std::wstring wencrypted = encrypt::wencrypt(wflat, wkey);

	std::wcout << L"wencrypted: " << wencrypted << std::endl;

	std::wstring wdecrypted = encrypt::wdecrypt(wencrypted, wkey);

	std::wcout << L"wdecrypted: " << wdecrypted << std::endl;



    return 0;
}

