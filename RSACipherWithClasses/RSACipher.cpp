#include "RSACipher.h"



int RSACipher::powMod(int b, int e, int mod)
{
	int result = 1;

	for (int _e = 1; _e <= e; _e++)
	{
		result = (result*b) % mod;
	}
	return result;
}


Message RSACipher::doCipher()
{
	unsigned char* ciphered = new unsigned char[this->getSentence().getLength() + 1];
	ciphered[this->getSentence().getLength()] = '\0';
	for (int i = 0; i < this->getSentence().getLength(); i++)
	{
		ciphered[i] = powMod((((unsigned char*)this->getSentence().getMessage())[i]-96),e,n);
	}
	this->SendMessage(Message(ciphered));
	return Message((char*)ciphered);
}

RSACipher::RSACipher(Channel * channel, int e, int n):Cipher(channel),e(e),n(n)
{
}

RSACipher::~RSACipher()
{
}
