#pragma once

//�|�C���^�Ŋ֐ߎQ�Ƃ�����B

#include<stdio.h>

int entry() {
	int a = 10;

	int *pa;

	pa = &a;

	int b;

	b = *pa;		//�ϐ�b�͏���������Ă��Ȃ����Apa��a���Q�Ƃ���b��a�̒l��������B

	printf("b=%d\n", b);
}