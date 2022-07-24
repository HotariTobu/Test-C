#pragma once

#include <stdio.h>

int entry() {
	const char *str = "abcdefgh";

	printf(str);
	printf("\n");

	str += 4;										//配列の先頭を進ませる（変える）。

	printf(str);
	printf("\n");

	return 0;
}