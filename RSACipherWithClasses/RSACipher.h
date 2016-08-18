#pragma once
#include "Cipher.h"
class RSACipher:
	public Cipher
{
public:
	Message doCipher();
	RSACipher(Channel* channel, int e, int n);
	~RSACipher();
private:
	int e, n;
	int powMod(int b, int e, int mod);
	RSACipher();
};

