#pragma once

//�֐����g���B

#include<stdio.h>

int plus(int, int);				//�v���g�^�C�v�`���̊֐��錾�B

int minus(int a, int b) {		//�{�g���A�b�v�`���̊֐��錾�B
	return a - b;
}

int entry() {
	int a = 10;
	int b = 5;

	printf("%d + %d =%d\n", a, b, plus(a, b));
	printf("%d - %d =%d\n", a, b, minus(a, b));
}

int plus(int a, int b) {
	return a + b;
}