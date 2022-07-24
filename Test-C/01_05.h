#pragma once

//式の法則を確認。

#include <stdio.h>

int entry() {
	int a = 4;
	double b = 7.3;
	printf("aはint型。bはdouble型。それぞれは\n4         7.3          です。\na×b=%f\naにbを代入。a=%d\n", a*b, a = b); //式が評価されるときに自動的に型が大きい方に変化させられる。これを格上げという。
	return 0;                                                                        //aに代入された7.3の3は切り捨てされてしまう。
}