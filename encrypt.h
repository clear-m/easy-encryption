#pragma once

#ifndef _ENCRYPT_
#define _ENCRYPT_

#include "b64.h"
#include "vigenere.h"

namespace encrypt
{
	//TODO add template implementation
	std::string encrypt(std::string& msg, std::string& key)
	{
		std::string b64_str = base64_encode(msg);
		std::string vigenere_msg = encrypt_vigenere(b64_str, key);
		// std::cout << vigenere_msg << std::endl;
		return vigenere_msg;
	}


	std::string decrypt(std::string& encrypted_msg, std::string& key)
	{
		std::string newKey = extend_key(encrypted_msg, key);
		std::string b64_encoded_str = decrypt_vigenere(encrypted_msg, newKey);
		std::string b64_decode_str = base64_decode(b64_encoded_str);
		return b64_decode_str;
	}

	std::wstring wencrypt(std::wstring& msg, std::wstring& key)
	{
		std::wstring b64_str = wbase64_encode(msg);
		std::wstring vigenere_msg = wencrypt_vigenere(b64_str, key);
		// std::cout << vigenere_msg << std::endl;
		return vigenere_msg;
	}


	std::wstring wdecrypt(std::wstring& encrypted_msg, std::wstring& key)
	{
		std::wstring newKey = wextend_key(encrypted_msg, key);
		std::wstring b64_encoded_str = wdecrypt_vigenere(encrypted_msg, newKey);
		std::wstring b64_decode_str = wbase64_decode(b64_encoded_str);
		return b64_decode_str;
	}
}

#endif