#pragma once

//�e�L�X�g�����̕����̌�ɉ��s�����������B

#include<stdio.h>
#include<string>

int entry() {
	FILE *pf;
	std::string text;

	fopen_s(&pf, "out01_21.txt", "r");
	
	while (true) {
		char a[64];

		fscanf_s(pf, "%s\n", a);

		
	}
	
	

	printf("%s", a);

	fclose(pf);

	fopen_s(&pf, "in01_21.txt", "w");

	if (pf != NULL) {
		fprintf_s(pf, "���߂Ẵt�@�C������ł��B\n");
	}

	fclose(pf);
}