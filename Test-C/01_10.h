#pragma once

//BMI�����߂�B

#include<stdio.h>

int entry() {
	printf("���Ȃ��̑̏d(Kg)��");
	double kg;
	while (1) {
		scanf_s("%lf", &kg);

		if (kg != '\n') {
			break;
		}
	}

	printf("���Ȃ��̐g��(cm)��");
	double cm;
	while (1) {
		scanf_s("%lf", &cm);

		if (cm != '\n') {
			break;
		}
	}

	double m = cm / 100.0;
	double bmi = kg / (m * m);

	printf("\n���Ȃ���Body Mass Index��%d�ł��B\n", (int)bmi);
	printf("���Ȃ݂ɗ��z��Body Mass Index��22�ł��B\n");

	if (!(bmi < 23 && bmi > 21)) {
		printf("\n���Ȃ��̗��z�̑̏d��%dKg�ł��B\n", (int)(m*m * 22));
	}

	return 0;
}