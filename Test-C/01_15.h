#pragma once

//�t�@�C����ǂݏ�������B

#include<stdio.h>

int entry() {
	FILE *pf;

	fopen_s(&pf, "test.txt", "w");		//�t�@�C�����J���ăt�@�C���I�u�W�F�N�g�̃|�C���^��Ԃ��B
										//��ڂ̈������p�X�œ�ڂ̈����̓��[�h�B
										//���[�h��w�Aa�Aw+�Aa+�̓t�@�C�������݂��Ȃ��ꍇ�A�����I�ɐ������Ă����B

	if (pf != NULL) {
		fprintf_s(pf, "���߂Ẵt�@�C������ł��B\n");
	}

	fclose(pf);

	fopen_s(&pf, "test.txt", "r");		//�t�@�C�������݂��Ȃ��ꍇ�ANULL��Ԃ��B

	char a[64];

	fscanf_s(pf, "%s\n", a);

	printf("%s", a);

	fclose(pf);
}