#pragma once

//���̖@�����m�F�B

#include <stdio.h>

int entry() {
	int a = 4;
	double b = 7.3;
	printf("a��int�^�Bb��double�^�B���ꂼ���\n4         7.3          �ł��B\na�~b=%f\na��b�����Ba=%d\n", a*b, a = b); //�����]�������Ƃ��Ɏ����I�Ɍ^���傫�����ɕω���������B������i�グ�Ƃ����B
	return 0;                                                                        //a�ɑ�����ꂽ7.3��3�͐؂�̂Ă���Ă��܂��B
}