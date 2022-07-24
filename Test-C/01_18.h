#pragma once

#include <stdio.h>

int entry() {
	for (int i = 0; i < 100; i++) {
		printf("%03d\n", i);
	}

	return 0;
}