#pragma once

//�\���̂����B

#include<stdio.h>
#include<string.h>

typedef struct human {						//�\���̂̃e���v���[�g�Bstruct�͍\���̂̃p�����[�^�B
	char name[32];							//���O��\�������o�B
	int age;								//�N���\�������o�B
} human;									//typedsf��human�Ƃ����V�����^human�Ƃ����\���̂����Ƃɂ��Ă��`�����B
											//�������Ȃ���human�Ƃ����\���̂�錾����ɂ� struct human �ϐ��� ; �Ɛ錾���Ȃ���΂Ȃ炸�A�ʓ|���������߂ł���B

int entry() {
	human Tom;

	strcpy_s(Tom.name, "�g��");
	Tom.age = 45;

	printf("%s(%d)\n", Tom.name, Tom.age);

	human TomClone = Tom;							//�\���̂��R�s�[����B

	printf("%s(%d)\n", TomClone.name, TomClone.age);

	human Ken = { "�P��",12 };						//�\���̂̕ϐ�������������B

	printf("%s(%d)\n", Ken.name, Ken.age);

	human Mary = { "���A���[" };					//�\���̂̕ϐ����ꕔ�̃����o�ł������������Ȃ�������E�E�E�H

	printf("%s(%d)\n", Mary.name, Mary.age);		//�\���̂̃����o�͏����l�ŏ���������Ă����B�Ⴆ��int�Ȃ�0�ł���悤�ɁB
}