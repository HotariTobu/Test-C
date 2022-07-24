#pragma once

//論理演算子の評価の挙動の確認

#include <iostream>

using namespace std;

bool a() {
	return true;
}

bool b() {
	return false;
}

int entry() {
	bool t1 = a() && b();
	bool t2 = a() || b();
	bool t3 = b() && a();
	bool t4 = b() || a();

	return 0;
}