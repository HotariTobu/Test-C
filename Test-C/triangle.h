#pragma once

#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>

int mainT() {
	double x = 7;
	double y = 0;
	double angle = 5;

	const float ox = x, oy = y;
	const double chnang = (angle * M_PI / 180);
	x = (float)(ox * cos(chnang) - oy * sin(chnang));
	y = (float)(ox * sin(chnang) + oy * cos(chnang));

	FILE *f;
	errno_t t = fopen_s(&f, "temp.txt", "w");
	fwprintf_s(f, L"x = %.15f\ny = %.15f\n", x, y);
	fclose(f);

	return 0;
}