#pragma once

//BMIを求める。

#include<stdio.h>

int entry() {
	printf("あなたの体重(Kg)は");
	double kg;
	while (1) {
		scanf_s("%lf", &kg);

		if (kg != '\n') {
			break;
		}
	}

	printf("あなたの身長(cm)は");
	double cm;
	while (1) {
		scanf_s("%lf", &cm);

		if (cm != '\n') {
			break;
		}
	}

	double m = cm / 100.0;
	double bmi = kg / (m * m);

	printf("\nあなたのBody Mass Indexは%dです。\n", (int)bmi);
	printf("ちなみに理想のBody Mass Indexは22です。\n");

	if (!(bmi < 23 && bmi > 21)) {
		printf("\nあなたの理想の体重は%dKgです。\n", (int)(m*m * 22));
	}

	return 0;
}