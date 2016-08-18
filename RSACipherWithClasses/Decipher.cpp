#include "Decipher.h"
Decipher::Decipher() :ciphered(""), deciphered("")
{
}


bool Decipher::GetMessage(Message ciphered) {
	this->ciphered = ciphered;
	return true;
}

Message Decipher::doDecipher() {
	int length = ciphered.getLength();

	char* result = new char[length + 1];
	result[length] = '\0';

	for (int k = 0; k<length; k++) {
		result[k] = (96 + 27) - (ciphered.getMessage()[k] - 96);
	}
	this->setDeciphered(Message(result));
	return this->OutputMessage();
}

bool Decipher::setDeciphered(Message message)
{
	this->deciphered = message;
	return true;
}

Message Decipher::OutputMessage() {
	return deciphered;
}

Decipher::~Decipher(void)
{
}

Message Decipher::getCiphered()
{
	return this->ciphered;
}
