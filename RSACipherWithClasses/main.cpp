#include "RSACipher.h"
#include "RSADecipher.h"
#include <iostream>
#include <conio.h>

using namespace std;

int getE(int p, int q, int n) {
	int f, e;
	f = (p - 1)*(q - 1);

	for (e = 3; e < n; e++) {
		if (f%e == 0) {
			continue;
		}

		for (int i = 2; i < e; i++) {
			if (e%i == 0) {
				if (f%i == 0) {
					break;
				}
			}
		}
		break;
	}
	return e;
}

int getD(int p, int q, int e) {
	int f, d;
	f = (p - 1)*(q - 1);
	for (d = 1; (d * e) % f != 1; d++);
	return d;
}

int main()
{
	int p = 0, q = 0, n = 0, length = 0;

	unsigned char* sentence=new unsigned char[201];

	sentence = new unsigned char[201];
	
	cout << "Enter first simple number:" << endl;
	cin >> p;
	cout << "Enter second simple number:" << endl;
	cin >> q;

	

	cout << "Enter the sentence you want to cipher:" << endl;
	cin >> sentence;
		
	n = p * q;
	
	int e = getE(p, q, n);
	int d = getD(p, q, e);
	RSADecipher decipher(d,n);
	Channel channel(&decipher);
	RSACipher cipher(&channel,e,n);
	cipher.InputMessage(Message(sentence));
	cout << cipher.doCipher().getUMessage() << endl;
	decipher.doDecipher();
	cout << decipher.OutputMessage().getMessage() << endl;

	_getch();
	return 0;
}