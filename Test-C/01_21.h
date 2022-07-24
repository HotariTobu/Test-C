#pragma once

//テキストを特定の文字の後に改行文字列を入れる。

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
		fprintf_s(pf, "初めてのファイル操作です。\n");
	}

	fclose(pf);
}