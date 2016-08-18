#include "Channel.h"

bool Channel::GetMessage(Message ciphered)
{
	this->SendMessage(ciphered);
	return true;
}

bool Channel::SendMessage(Message ciphered)
{
	decipher->GetMessage(ciphered);
	return true;
}

Channel::Channel(Decipher * decipher):decipher(decipher)
{
}


