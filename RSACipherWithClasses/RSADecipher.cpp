#include "RSADecipher.h"



int RSADecipher::powMod(int b, int e, int mod)
{
	int result = 1;
	for (int _e = 1; _e <= e; _e++) {
		result = (result*b) % mod;
	}
	return result;
}

RSADecipher::RSADecipher()
{
}


RSADecipher::RSADecipher(int d, int n) :Decipher(),n(n), d(d)
{
}

Message RSADecipher::doDecipher()
{
	unsigned char* result = new unsigned char[this->getCiphered().getLength()+1];
	result[this->getCiphered().getLength()] = '\0';
	unsigned char* newResult = new unsigned char[this->getCiphered().getLength() + 1];
	newResult[this->getCiphered().getLength()] = '\0';

	for (int i = 0; i < this->getCiphered().getLength(); i++)
	{
		result[i] = powMod((((unsigned char*)this->getCiphered().getMessage())[i]), d, n)+96;
	}

	newResult[0] = result[0];

	for (int i = 1; i < this->getCiphered().getLength(); i++) {
		newResult[i] = (result[i] - newResult[i - 1]) % n;
	}
	this->setDeciphered(Message((char*)newResult));
	return Message((char*)newResult);
}

RSADecipher::~RSADecipher()
{
}
