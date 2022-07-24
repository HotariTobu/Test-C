#pragma once

//思いついた関数を並べていく。

#include <stdio.h>
#include <vector>

using namespace std;

#define SqrtLimit 7
float incrementer[20]{
	1.f,
	0.1f,
	0.01f,
	0.001f,
	0.0001f,
	0.00001f,
	0.000001f,
	0.0000001f,
	0.00000001f,
	0.000000001f,
	0.0000000001f,
	0.00000000001f,
	0.000000000001f,
	0.0000000000001f,
	0.00000000000001f,
	0.000000000000001f,
	0.0000000000000001f,
	0.00000000000000001f,
	0.000000000000000001f,
	0.0000000000000000001f,
};
/*
平方根を求める。
*/
float GetSqrt(int value) {
	if (value <= 0) {
		return 0;
	}

	float re = 0;

	for (int i = 0; i < SqrtLimit; i++) {
		while (true) {
			float temp = re + incrementer[i];
			if (temp * temp <= value) {
				re = temp;
			}
			else {
				break;
			}
		}

		if (re * re == value) {
			break;
		}
	}

	return re;
}

/*
平方を求める。
*/
float Square(float value) {
	return value * value;
}

float GetSqrt(float value, int digit) {
	if (value <= 0) {
		return 0;
	}

	float re = 0;

	float factor = 1;
	for (int i = 0; i < digit; i++) {
		factor *= 10;
	}

	float incrementer = factor;

	for (int i = 0; i < digit; i++) {
		while (Square(re / factor) < value) {
			re += incrementer;
		}

		if (Square(re / factor) == value) {
			break;
		}

		re -= incrementer;

		incrementer /= 10;
	}

	return re / factor;
}

/*
素数の配列。
共有する。
*/
vector<int> pns;

/*
PNはPrime Numberの略。
valueが素数かどうかを判定する。
*/
bool IsPN(int value) {
	if (value < 2) {
		return false;
	}

	for (int i = 2; i < value; i++) {
		if (value % i == 0) {
			return false;
		}
	}

	return true;
}

/*
PNSはPrime Numbersの略。
value以下の素数を求める。
*/
void GetPNS(int value) {
	int limit = (int)sqrtf(value) + 1;

	pns.clear();

	for (int i = 2; i < limit; i++) {
		if (IsPN(i)) {
			pns.push_back(i);
		}
	}

	int size = pns.size();
	int* pnsa = new int[size];
	for (int i = 0; i < size; i++) {
		pnsa[i] = pns[i];
	}

	vector<int> re;

	for (int i = limit; i <= value; i++) {
		bool pn = true;

		for (int j = 0; j < size; j++) {
			if (i % pnsa[j] == 0) {
				pn = false;
				break;
			}
		}

		if (pn) {
			re.push_back(i);
		}
	}

	delete[] pnsa;

	auto end = re.end();
	for (auto ite = re.begin(); ite != end; ite++) {
		pns.push_back((*ite));
	}

	/*pns.clear();
	
	for (int i = 2; i <= value; i++) {
		bool pn = true;

		auto end = pns.end();
		for (auto ite = pns.begin(); ite != end; ite++) {
			if (i % (*ite) == 0) {
				pn = false;
				break;
			}
		}

		if (pn && IsPN(i)) {
			pns.push_back(i);
		}
	}*/
}

/*
素因数分解をする。
*/
vector<int> Factoring(int value) {
	vector<int> re;

	int ipns = 0;
	while (value > 1) {
		int pn = pns[ipns];
		if (value % pn == 0) {
			value /= pn;
			re.push_back(pn);
		}
		else {
			ipns++;
		}
	}

	return re;
}

/*
GCFはGreatest Common Factorの略。
ユークリッドの互除法で2つの整数の最大公約数を求める。
*/
int GetGCF(int a, int b) {
	if (a < 1) {
		return b;
	}

	if (b < 1) {
		return a;
	}

	if (a < b) {
		return GetGCF(a, b % a);
	}
	else {
		return GetGCF(b, a % b);
	}
}

/*
LCMはLeast Common Multipleの略。
ql = abから最小公倍数を求める。
*/
int GetLCM(int a, int b) {
	return a * b / GetGCF(a, b);
}

//約数の個数を求める
int GetNumOfDivisors(int value) {
	vector<int> factors = Factoring(value);

	if (factors.size() == 0) {
		return 0;
	}

	int re = 1;
	int pn = factors[0];
	int count = 1;
	auto end = factors.end();
	for (auto ite = factors.begin(); ite != end; ite++) {
		if (pn == (*ite)) {
			count++;
		}
		else {
			re *= count;
			count = 2;
			pn = (*ite);
		}
	}

	return re * count;
}

//約数の総和を求める。
int GetSumOfDivisors(int value) {
	vector<int> factors = Factoring(value);

	if (factors.size() == 0) {
		return 0;
	}

	int re = 1;
	int pn = factors[0];
	int po = 1;
	int su = 1;
	auto end = factors.end();
	for (auto ite = factors.begin(); ite != end; ite++) {
		if (pn == (*ite)) {
			po *= pn;
			su += po;
		}
		else {
			re *= su;
			pn = (*ite);
			po = pn;
			su = 1 + po;
		}
	}

	return re * su;
}

void ShowArray(vector<int> &data) {
	auto end = data.end();
	for (auto ite = data.begin(); ite != end; ite++) {
		printf("%d, ", (*ite));
	}
	printf("\b\b");
}

int entry() {
	/*for (int i = 0; i < 10; i++) {
		int fg = rand() % 100;
		printf("%3d\t%f\n\t%f\n\t%f\n\n", fg, sqrtf((float)fg),GetSqrt(fg),GetSqrt((float)fg, 7));
		
	}*/

	int a, b;

	printf("何らかの計算をするので整数a, bを入力してください。\n");
	printf("a = ");
	scanf_s("%d", &a);
	printf("b = ");
	scanf_s("%d", &b);
	printf("\n");

	printf("%dと%dの最大公約数は%dです。\n", a, b, GetGCF(a, b));
	printf("%dと%dの最小公倍数は%dです。\n", a, b, GetLCM(a, b));

	printf("\n");

	if (a < b) {
		printf("a < b\n");
		printf("%dの平方根は%fです。\n", b, sqrtf(b));
		GetPNS(b);
		printf("%d以下の素数は", b);
		ShowArray(pns);
		printf("の%d個です。\n", pns.size());
	}
	else {
		printf("a >= b\n");
		printf("%dの平方根は%fです。\n", a, sqrtf(a));
		GetPNS(a);
		printf("%d以下の素数は", a);
		ShowArray(pns);
		printf("の%d個です。\n", pns.size());
	}

	printf("\n");

	vector<int> factorsOfA = Factoring(a);
	vector<int> factorsOfB = Factoring(b);

	printf("%dを素因数分解すると", a);
	ShowArray(factorsOfA);
	printf("になります。\n");
	printf("%dを素因数分解すると", b);
	ShowArray(factorsOfB);
	printf("になります。\n");

	printf("\n");

	printf("%dの約数の個数は%d個で、その総和は%dで、さらに自身を引いた数は%dです。\n", a, GetNumOfDivisors(a), GetSumOfDivisors(a), (GetSumOfDivisors(a) - a));
	printf("%dの約数の個数は%d個で、その総和は%dで、さらに自身を引いた数は%dです。\n", b, GetNumOfDivisors(b), GetSumOfDivisors(b), (GetSumOfDivisors(b) - b));

	//system("pause");

	return 0;
}