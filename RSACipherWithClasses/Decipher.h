#pragma once
#include "Message.h"
class Decipher
{
private:
	Message ciphered;
	Message deciphered;
public:
	Message getCiphered();
	bool GetMessage(Message ciphered);
	virtual Message doDecipher() = 0;
	Message OutputMessage();
	Decipher(void);
	~Decipher(void);
protected:
	bool setDeciphered(Message message);
};

