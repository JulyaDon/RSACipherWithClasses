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

	unsigned char* newMessage = new unsigned char[this->getSentence().getLength() + 1];
	newMessage[this->getSentence().getLength()] = '\0';

	newMessage[0] = this->getSentence().getMessage()[0]-96;

	for (int i = 1; i < this->getSentence().getLength(); i++)
	{
		newMessage[i] = ((this->getSentence().getMessage()[i] + newMessage[i - 1]-96) % n);
	}

	for (int i = 0; i < this->getSentence().getLength(); i++) {
		ciphered[i] = powMod((newMessage[i]), e, n);
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
