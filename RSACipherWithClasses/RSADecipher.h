#pragma once
#include "Decipher.h"
class RSADecipher:
	public Decipher
{
public:
	RSADecipher(int d, int n);
	Message doDecipher();
	~RSADecipher();
private:
	int d, n;
	int powMod(int b, int e, int mod);
	RSADecipher();
};

