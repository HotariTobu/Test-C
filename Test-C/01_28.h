#pragma once

//総和の関数

#include <iostream>
#include <math.h>

using namespace std;

using I = long long;
using F = long double;

F sum(F start, F stop, int digit, F(*typicalelement)(F)) {
	if (start > stop) {
		return 0;
	}

	if (!typicalelement) {
		return 0;
	}

	F result = 0;

	F factor = (F)pow(10, digit);

	I limit = stop * factor;
	for (I i = start * factor; i <= limit; i++) {
		F k = i / factor;
		result += typicalelement(k);
	}

	return result;
}

int entry() {
	int accuracy = 0;
	cout << "精度は小数点" << flush;
	cin >> accuracy;
	cout << "桁まで" << endl;

	F a = 0;
	cout << "[1] = " << flush;
	cin >> a;
	cout << endl;

	F b = 0;
	cout << "[2] = " << flush;
	cin >> b;
	cout << endl;

	F re = sum(a, b, accuracy, [](F k) { return k; });
	cout << "結果は" << re << "です。" << endl;

	return 0;
}