#pragma once

//�C���N�������g�ƃf�N�������g�𗘗p�B

#include <stdio.h>

int entry() {
	int a = 10, b = 10, c = 10, d = 10;
	printf("�ŏ��̒l�͑S��10�ł��B\n");
	printf("�O�u�C���N�������g %d\n", ++a);
	printf("���̌� %d\n", a);
	printf("��u�C���N�������g %d\n", b++);
	printf("���̌� %d\n", b);
	printf("�O�u�f�N�������g %d\n", --c);
	printf("���̌� %d\n", c);
	printf("��u�f�N�������g %d\n", d--);
	printf("���̌� %d\n", d);
	return 0;
}