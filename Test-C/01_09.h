#pragma once

//for•¶‚ğg‚¤B

#include<stdio.h>

int entry() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			printf("i=%d,j=%d\n", i, j);
		}
		printf("___________________________________\n");
	}
}