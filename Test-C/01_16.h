#pragma once

#include <stdio.h>

int entry() {
	const char *str = "abcdefgh";

	printf(str);
	printf("\n");

	str += 4;										//�z��̐擪��i�܂���i�ς���j�B

	printf(str);
	printf("\n");

	return 0;
}