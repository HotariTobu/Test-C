#pragma once

//\�`�����B

#include <stdio.h>

int entry() {
	printf("��Ж�\t�I�l\t����\t���v\n");
	printf("-------------------------------\n");
	printf("NEC\t%d\t%d\t%d\n", 200, 100, 200 * 100);        //%d�Ɍォ�琔�l�����ĕ\��������B
	printf("TDK\t%d\t%d\t%d\n", 6000, 20, 6000 * 20);        //java�̂悤�ɂ��������_�u���N�I�[�e�[�V�����ƕ����邱�Ƃ��Ȃ�����֗��ł����邵�A
	printf("-------------------------------\n");        //�l����������Ƃ킩��Â炢�Ƃ����̂�����B
	printf("���v\t\t\t%d\n", (200 * 100) + (6000 * 20));

	return 0;
}