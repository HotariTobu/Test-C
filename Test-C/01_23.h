#pragma once

//•Ï”‚Ì’l‚ªŸè‚É•Ï‚í‚éŒ»Û‚ÌŒŸØ

#include<stdio.h>

int entry() {
	int before[2];
	int x;
	int after[2];

	printf("%x\n", before);
	printf("%x\n", &x);
	printf("%x\n", after);

	x = 666;
	printf("x = %d\n", x);

	before[0] = 100;
	before[1] = 101;
	before[2] = 102;
	before[3] = 103;
	before[4] = 104;

	printf("x = %d\n", x);

	after[0] = 200;
	after[1] = 201;
	after[2] = 202;
	after[3] = 203;
	after[4] = 204;

	printf("x = %d\n", x);

	return 0;
}