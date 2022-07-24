#pragma once

//for•¶‚Ì•ªŠò®‚ÌŠm”F

#include<stdio.h>

int count;

int D(int num) {
	count++;
	return (1 + num) * num / 2;
}

int entry() {
	int i;

	count = 0;

	for (i = 0; i < D(10); i++) {

	}

	printf("i = %d\n", i);
	printf("count = %d\n", count);

	return 0;
}