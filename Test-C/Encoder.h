#pragma once

#include <string>
using namespace std;

void Encoder(string text) {

	int shift[32]{ -58,-18,-127,10,2,77,62,-97,6,-44,-20,-10,-80,72,-113,-18,-109,120,108,38,-7,-63,107,48,69,-87,-12,-49,93,68,-97,-34, };
	int length = text.length();

	string result = "decode(new int[";

	char lenstr[32];
	sprintf_s(lenstr, "%d", length);
	result.append(lenstr);

	result.append("]{");

	for (int i = 0; i < length; i++) {
		char buf[8];
		sprintf_s(buf, "%d,", (text[i] ^ shift[i % 32]));
		result.append(buf);
	}

	result.append("},");
	result.append(lenstr);
	result.append(")");

	return;
}