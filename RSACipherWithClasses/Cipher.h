#pragma once
#include "Message.h"
#include "Channel.h"
class Cipher
{
private:
	Channel* channel;
	Message sentence;
public:
	bool InputMessage(Message message);
	virtual Message doCipher() = 0;
	bool SendMessage(Message ciphered);
	Cipher(Channel * channel);
	Cipher(void);
	~Cipher(void);
protected:
	Message getSentence();
};

