#pragma once

//構造体を作る。

#include<stdio.h>
#include<string.h>

typedef struct human {						//構造体のテンプレート。structは構造体のパラメータ。
	char name[32];							//名前を表すメンバ。
	int age;								//年齢を表すメンバ。
} human;									//typedsfでhumanという新しい型humanという構造体をもとにしてを定義した。
											//そうしないとhumanという構造体を宣言するには struct human 変数名 ; と宣言しなければならず、面倒くさいためである。

int entry() {
	human Tom;

	strcpy_s(Tom.name, "トム");
	Tom.age = 45;

	printf("%s(%d)\n", Tom.name, Tom.age);

	human TomClone = Tom;							//構造体をコピーする。

	printf("%s(%d)\n", TomClone.name, TomClone.age);

	human Ken = { "ケン",12 };						//構造体の変数を初期化する。

	printf("%s(%d)\n", Ken.name, Ken.age);

	human Mary = { "メアリー" };					//構造体の変数を一部のメンバでしか初期化しなかったら・・・？

	printf("%s(%d)\n", Mary.name, Mary.age);		//構造体のメンバは初期値で初期化されていた。例えばintなら0であるように。
}