#pragma once

//%*の埋め込み。

#include <stdio.h>

int entry() {
	char a = '年';
	printf("1%cは%d日ですが、今日の室温は%f℃です。\n", a, 365, 30.7);
	return 0;    //%のあとのアルファベットによって置きかけるものが違う。cは文字リテラル(char)。dは整数。f実数。
}