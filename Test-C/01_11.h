#pragma once

//関数を使う。

#include<stdio.h>

int plus(int, int);				//プロトタイプ形式の関数宣言。

int minus(int a, int b) {		//ボトムアップ形式の関数宣言。
	return a - b;
}

int entry() {
	int a = 10;
	int b = 5;

	printf("%d + %d =%d\n", a, b, plus(a, b));
	printf("%d - %d =%d\n", a, b, minus(a, b));
}

int plus(int a, int b) {
	return a + b;
}