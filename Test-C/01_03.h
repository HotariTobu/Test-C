#pragma once

//変数を使う。

#include <stdio.h>

int entry() {
	int x = 9, y;           //int型の変数の宣言とxに対する9の初期化。
	y = 9;                 //yに対する9の代入。
	printf("x=%d\ny=%d\nxとyの違いはない。\n", x, y);
	return 0;
}