#pragma once

//ファイルを読み書きする。

#include<stdio.h>

int entry() {
	FILE *pf;

	fopen_s(&pf, "test.txt", "w");		//ファイルを開いてファイルオブジェクトのポインタを返す。
										//一つ目の引数がパスで二つ目の引数はモード。
										//モードのw、a、w+、a+はファイルが存在しない場合、自動的に生成してくれる。

	if (pf != NULL) {
		fprintf_s(pf, "初めてのファイル操作です。\n");
	}

	fclose(pf);

	fopen_s(&pf, "test.txt", "r");		//ファイルが存在しない場合、NULLを返す。

	char a[64];

	fscanf_s(pf, "%s\n", a);

	printf("%s", a);

	fclose(pf);
}