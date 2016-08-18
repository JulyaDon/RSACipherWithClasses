#pragma once
#include "Message.h"
#include "Decipher.h"
class Channel
{
	Decipher* decipher;
public:
	bool GetMessage(Message ciphered);
	bool SendMessage(Message ciphered);
	Channel(Decipher* decipher);

};

