#pragma once

#ifndef _VIGENERE_H_ 
#define _VIGENERE_H_

#include "stdafx.h"

#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include <ctype.h>

namespace encrypt
{
	using namespace std;

	std::string AVAILABLE_CHARS = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	std::wstring AVAILABLE_CHARS_W = L"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

	int index(char c)
	{
		for (int ii = 0; ii < AVAILABLE_CHARS.size(); ii++) {
			if (AVAILABLE_CHARS[ii] == c) {
				// std::cout << ii << " " << c << std::endl;
				return ii;
			}
		}
		return -1;
	}

	int windex(wchar_t c)
	{
		for (int ii = 0; ii < AVAILABLE_CHARS_W.size(); ii++) {
			if (AVAILABLE_CHARS_W[ii] == c) {
				// std::cout << ii << " " << c << std::endl;
				return ii;
			}
		}
		return -1;
	}


	std::string extend_key(std::string& msg, std::string& key)
	{
		//generating new key
		int msgLen = msg.size();
		std::string newKey(msgLen, 'x');
		int keyLen = key.size(), i, j;
		for (i = 0, j = 0; i < msgLen; ++i, ++j) {
			if (j == keyLen)
				j = 0;

			newKey[i] = key[j];
		}
		newKey[i] = '\0';
		return newKey;
	}

	std::wstring wextend_key(std::wstring& msg, std::wstring& key)
	{
		//generating new key
		int msgLen = msg.size();
		std::wstring newKey(msgLen, 'x');
		int keyLen = key.size(), i, j;
		for (i = 0, j = 0; i < msgLen; ++i, ++j) {
			if (j == keyLen)
				j = 0;

			newKey[i] = key[j];
		}
		newKey[i] = '\0';
		return newKey;
	}


	std::string encrypt_vigenere(std::string& msg, std::string& key)
	{
		int msgLen = msg.size(), keyLen = key.size(), i, j;
		std::string encryptedMsg(msgLen, 'x');
		// char newKey[msgLen], encryptedMsg[msgLen], decryptedMsg[msgLen];

		std::string newKey = extend_key(msg, key);

		//encryption
		for (i = 0; i < msgLen; ++i) {
			// std::cout << msg[i] << " " << isalnum(msg[i]) << std::endl;
			if (isalnum(msg[i]) || msg[i] == ' ') {
				encryptedMsg[i] = AVAILABLE_CHARS[((index(msg[i]) + index(newKey[i])) % AVAILABLE_CHARS.size())];
			}
			else {
				encryptedMsg[i] = msg[i];
			}
		}

		encryptedMsg[i] = '\0';
		return encryptedMsg;
	}

	std::wstring wencrypt_vigenere(std::wstring& msg, std::wstring& key)
	{
		int msgLen = msg.size(), keyLen = key.size(), i, j;
		std::wstring encryptedMsg(msgLen, 'x');
		// char newKey[msgLen], encryptedMsg[msgLen], decryptedMsg[msgLen];

		std::wstring newKey = wextend_key(msg, key);

		//encryption
		for (i = 0; i < msgLen; ++i) {
			// std::cout << msg[i] << " " << isalnum(msg[i]) << std::endl;
			if (isalnum(msg[i]) || msg[i] == ' ') {
				encryptedMsg[i] = AVAILABLE_CHARS_W[((windex(msg[i]) + windex(newKey[i])) % AVAILABLE_CHARS_W.size())];
			}
			else {
				encryptedMsg[i] = msg[i];
			}
		}

		encryptedMsg[i] = '\0';
		return encryptedMsg;
	}


	std::string decrypt_vigenere(std::string& encryptedMsg, std::string& newKey)
	{
		// decryption
		int msgLen = encryptedMsg.size();
		std::string decryptedMsg(msgLen, 'x');
		int i;
		for (i = 0; i < msgLen; ++i) {
			if (isalnum(encryptedMsg[i]) || encryptedMsg[i] == ' ') {
				decryptedMsg[i] = AVAILABLE_CHARS[(((index(encryptedMsg[i]) - index(newKey[i])) + AVAILABLE_CHARS.size()) % AVAILABLE_CHARS.size())];
			}
			else {
				decryptedMsg[i] = encryptedMsg[i];
			}
		}
		decryptedMsg[i] = '\0';
		return decryptedMsg;
	}

	std::wstring wdecrypt_vigenere(std::wstring& encryptedMsg, std::wstring& newKey)
	{
		// decryption
		int msgLen = encryptedMsg.size();
		std::wstring decryptedMsg(msgLen, 'x');
		int i;
		for (i = 0; i < msgLen; ++i) {
			if (isalnum(encryptedMsg[i]) || encryptedMsg[i] == ' ') {
				decryptedMsg[i] = AVAILABLE_CHARS_W[(((windex(encryptedMsg[i]) - windex(newKey[i])) + AVAILABLE_CHARS_W.size()) % AVAILABLE_CHARS_W.size())];
			}
			else {
				decryptedMsg[i] = encryptedMsg[i];
			}
		}
		decryptedMsg[i] = '\0';
		return decryptedMsg;
	}
}


#endif