#pragma once

//バイト数を調べる、sizeof演算子。サイズオブかな？

#include <stdio.h>

int entry() {
	int a = 10;                                                 //sizeofのあとの()には式か、型名が入る。
	size_t b = sizeof(a -= 5);                                  //sizeofの型名はsize_tである。
	printf("a=%d\naのデータサイズは%dバイト。\n", a, b);        //sizeof演算子のあとの式は評価されないらしい。
	printf("char型のデータサイズは%dバイトです。\n", sizeof(char));
	return 0;
}