#pragma once

//ポインタのアドレスを確認する。

#include<stdio.h>

int entry() {
	char a = 'r';
	int b = 12;
	long c = 10000004;
	double d = 0.45464544;

	printf("char\t&a=%p\n", &a);
	printf("int\t&b=%p\n", &b);
	printf("long\t&c=%p\n", &c);
	printf("double\t&d=%p\n", &d);
}