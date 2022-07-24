#pragma once

//‘fˆö”•ª‰ğ‚ğ‚·‚éB

#include <stdio.h>
#include <stdlib.h>

int PrimeFactorization(int value, int *PrimeFactors) {
	int factorNumber = 0;
	int factor = 2;

	while (value >= factor) {
		if (value % factor == 0) {
			value /= factor;
			PrimeFactors[factorNumber] = factor;
			factorNumber++;
		}
		else {
			bool isPrime = false;

			while (!isPrime) {
				factor++;

				isPrime = true;

				for (int i = 2; i < factor; i++) {
					if (factor % i == 0) {
						isPrime = false;
						break;
					}
				}
			}
		}
	}

	return factorNumber;
}

int entry() {
	int PrimeFactors[100];

	int factorNumber = PrimeFactorization(4528875, PrimeFactors);

	for (int i = 0; i < factorNumber; i++) {
		printf_s("%d ", PrimeFactors[i]);
	}

	printf_s("\n");

	return 0;
}