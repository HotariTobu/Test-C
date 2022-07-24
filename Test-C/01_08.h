#pragma once

//制御文を使う。

#include <stdio.h>
#include <string>

using namespace std;

void println(string a) {										//関数の宣言ははその関数を使う関数の前に宣言しなければならない。
	printf("%s\n", a.c_str());									//ボトムアップ形式の関数宣言。
}

int entry() {
	println("年齢に対する常識の名称を返します。");
	printf("あなたの年齢を教えてください。---");

	int age;

	scanf_s("%d", &age);											//入力を読み込む。セキュリティ強化版の新しい関数を使う。

	printf("あなたは");

	if (age < 0) {
		printf("胎児");
	}
	else if (age == 0) {
		printf("乳児");
	}
	else if (age < 6) {
		printf("幼児");
	}
	else if (age < 12) {
		printf("小学生");
	}
	else if (age < 15) {
		printf("中学生");
	}
	else if (age < 18) {
		printf("高校生");
	}
	else if (age < 22) {
		printf("大学生");
	}
	else {
		printf("大人");
	}

	println("ですね。");

	system("pause");

	return 0;
}