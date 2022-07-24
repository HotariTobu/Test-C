#pragma once

//インクリメントとデクリメントを利用。

#include <stdio.h>

int entry() {
	int a = 10, b = 10, c = 10, d = 10;
	printf("最初の値は全部10です。\n");
	printf("前置インクリメント %d\n", ++a);
	printf("その後 %d\n", a);
	printf("後置インクリメント %d\n", b++);
	printf("その後 %d\n", b);
	printf("前置デクリメント %d\n", --c);
	printf("その後 %d\n", c);
	printf("後置デクリメント %d\n", d--);
	printf("その後 %d\n", d);
	return 0;
}