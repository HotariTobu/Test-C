#pragma once

//���䕶���g���B

#include <stdio.h>
#include <string>

using namespace std;

void println(string a) {										//�֐��̐錾�͂͂��̊֐����g���֐��̑O�ɐ錾���Ȃ���΂Ȃ�Ȃ��B
	printf("%s\n", a.c_str());									//�{�g���A�b�v�`���̊֐��錾�B
}

int entry() {
	println("�N��ɑ΂���펯�̖��̂�Ԃ��܂��B");
	printf("���Ȃ��̔N��������Ă��������B---");

	int age;

	scanf_s("%d", &age);											//���͂�ǂݍ��ށB�Z�L�����e�B�����ł̐V�����֐����g���B

	printf("���Ȃ���");

	if (age < 0) {
		printf("�َ�");
	}
	else if (age == 0) {
		printf("����");
	}
	else if (age < 6) {
		printf("�c��");
	}
	else if (age < 12) {
		printf("���w��");
	}
	else if (age < 15) {
		printf("���w��");
	}
	else if (age < 18) {
		printf("���Z��");
	}
	else if (age < 22) {
		printf("��w��");
	}
	else {
		printf("��l");
	}

	println("�ł��ˁB");

	system("pause");

	return 0;
}