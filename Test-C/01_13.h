#pragma once

//ポインタで関節参照をする。

#include<stdio.h>

int entry() {
	int a = 10;

	int *pa;

	pa = &a;

	int b;

	b = *pa;		//変数bは初期化されていないが、paがaを参照してbにaの値を代入する。

	printf("b=%d\n", b);
}