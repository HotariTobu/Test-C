#pragma once

//データを完全に消去したいときに使えるファイルを生成する。

#include <iostream>
#include <fstream>

using namespace std;

int entry() {
	ofstream ws("file", ios::binary);
	if (!ws) {
		return -1;
	}

	uint64_t d = 0;
	streamsize s = sizeof(uint64_t);
	/*
	for (int i = 0; i < 0x20000000; i++) {
		ws.write((const char*)&d, s);
	}
	*/
	for (int i = 0; i < 0x10000000; i++) {
		ws.write((const char*)&d, s);
	}

	ws.close();

	return 0;
}