#include "Cipher.h"

bool Cipher::InputMessage(Message message) {
	sentence = message;
	return true;
}
Message Cipher::doCipher() {
	int length = sentence.getLength();

	char *ciphered = new char[length + 1];
	for (int i = 0;i<length + 1;i++)
	{
		ciphered[i] = '\0';
	}

	for (int k = 0; k < length; k++) {
		ciphered[k] = (96 + 27) - (sentence.getMessage()[k] - 96);

	}
	this->SendMessage(Message(ciphered));
	return Message(ciphered);
}


bool Cipher::SendMessage(Message ciphered)
{
	channel->GetMessage(ciphered);
	return true;
}

Cipher::Cipher(Channel * channel) :sentence(""), channel(channel)
{

}

Cipher:: ~Cipher(void)
{
}

Message Cipher::getSentence()
{
	return sentence;
}
