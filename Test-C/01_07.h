#pragma once

//�o�C�g���𒲂ׂ�Asizeof���Z�q�B�T�C�Y�I�u���ȁH

#include <stdio.h>

int entry() {
	int a = 10;                                                 //sizeof�̂��Ƃ�()�ɂ͎����A�^��������B
	size_t b = sizeof(a -= 5);                                  //sizeof�̌^����size_t�ł���B
	printf("a=%d\na�̃f�[�^�T�C�Y��%d�o�C�g�B\n", a, b);        //sizeof���Z�q�̂��Ƃ̎��͕]������Ȃ��炵���B
	printf("char�^�̃f�[�^�T�C�Y��%d�o�C�g�ł��B\n", sizeof(char));
	return 0;
}