#pragma once

//はじめてのC言語プログラム。

#include <stdio.h>

int entry() {
	int a, b;
	scanf_s("%d/%d", &a, &b);
	printf("%d/%d", a, b);
	return 0;
}