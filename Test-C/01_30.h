#pragma once

//席替え関数のテスト。

#include <stdio.h>
#include <time.h>
#include <math.h>
#include <vector>

double s(double x) {
	return x / pow(10.0, floor(log10(x)));
}

int entry() {
	int maxA = 9;
	int maxB = 9;
	int hits = 0;

	bool heep[100];
	for (int i = 0; i < 100; i++) {
		heep[i] = false;
	}

	std::vector<int> stock;
	srand((unsigned int)time(NULL));

	int m = 11;
	//int m = getchar() - (int)'0';
	double f = 0;

#define PA

#ifdef PA
	for (int Z = 11; Z < 100; Z++) {
		int n = Z;
#else
	for (int Z = 0; Z < 22; Z++) {
		int n = 0;
		do {
			n = rand() % 89 + 11;
		} while (heep[n]);
		heep[n] = true;
#endif // PA

		printf("%d", n);
		int a = n / 10;
		int b = n % 10;

		f = s(log(a * 1000.0 + b * 100.0 + m));
		double g = 0;
		for (int i = 0; i <= abs(a - b); i++) {
			switch ((i * a * b * m) % 8) {
			case 0:
				g += f = s((f + b) / a);
				break;
			case 1:
				g += f = s((f + a) / b);
				break;
			case 2:
				g += f = s(fabs(f - b) / a);
				break;
			case 3:
				g += f = s(fabs(f - a) / b);
				break;
			case 4:
				g += f = s((f + b) * a);
				break;
			case 5:
				g += f = s((f + a) * b);
				break;
			case 6:
				g += f = s(fabs(f - b) * a);
				break;
			case 7:
				g += f = s(fabs(f - a) * b);
				break;
			}
		}

		g = s(g);

		int r = (int)(sqrt(f * g) * 100) % 22;

		printf("\t");

		bool hit = false;
		auto pos = stock.begin();
		auto end = stock.end();
		for (auto ite = pos; ite != end; ite++) {
			if (*ite < r) {
				pos = ite + 1;
			}
			else if (*ite == r) {
				hit = true;
			}
		}

		if (hit) {
			printf("hit");
			hits++;
		}

		if (pos == end) {
			stock.push_back(r);
		}
		else {
			stock.insert(pos, r);
		}

		if (r < 0) {
			__asm int 3;
		}

		printf("\t%02d\n", r);
	}

	printf("\n");

	for (auto ite = stock.begin(); ite != stock.end(); ite++) {
		printf("%02d\n", *ite);
	}

	printf("\n");

	printf("%dhits\n", hits);

	getchar();

	return 0;

	for (int n = 11; n < 100; n++) {
		printf("%d", n);
		int a = n / 10;
		int b = n % 10;

		f = s(log(a * 1000.0 + b * 100.0 + m));
		double g = 0;
		for (int i = 0; i <= abs(a - b); i++) {
			switch ((i * a * b * m) % 8) {
			case 0:
				g += f = s((f + b) / a);
				break;
			case 1:
				g += f = s((f + a) / b);
				break;
			case 2:
				g += f = s(fabs(f - b) / a);
				break;
			case 3:
				g += f = s(fabs(f - a) / b);
				break;
			case 4:
				g += f = s((f + b) * a);
				break;
			case 5:
				g += f = s((f + a) * b);
				break;
			case 6:
				g += f = s(fabs(f - b) * a);
				break;
			case 7:
				g += f = s(fabs(f - a) * b);
				break;
			}
		}

		g = s(g);

		int r = (int)(sqrt(f * g) * 100) % 22;

		printf("\t");
		if (heep[r]) {
			printf("hit");
			hits++;
		}
		else {
			heep[r] = true;
		}

		if (r < 0) {
			__asm int 3;
		}

		printf("\t%02d\n", r);
	}

	printf("\n");

	for (int i = 0; i < 100; i++) {
		if (heep[i]) {
			printf("%02d\n", i);
		}
	}

	printf("\n");

	printf("%dhits\n", hits);

	getchar();

	return 0;

	for (int a = 1; a <= maxA; a++) {
		for (int b = 1; b <= maxB; b++) {
			printf("(%d, %d)", a, b);

			f = s(log(a * 1000.0 + b * 100.0 + m));
			double g = 0;
			for (int i = 0; i <= abs(a - b); i++) {
				switch ((i * a * b * m) % 8) {
				case 0:
					g += f = s((f + b) / a);
					break;
				case 1:
					g += f = s((f + a) / b);
					break;
				case 2:
					g += f = s(fabs(f - b) / a);
					break;
				case 3:
					g += f = s(fabs(f - a) / b);
					break;
				case 4:
					g += f = s((f + b) * a);
					break;
				case 5:
					g += f = s((f + a) * b);
					break;
				case 6:
					g += f = s(fabs(f - b) * a);
					break;
				case 7:
					g += f = s(fabs(f - a) * b);
					break;
				}
			}

			g = s(g);

			int cc = (int)((f + g) / 2 * 100) % 6;
			int dd = (int)(sqrt(f * g) * 100) % 7;

			printf("\t");
			if (heep[cc + dd * 10]) {
				printf("hit");
				hits++;
			}
			else {
				heep[cc + dd * 10] = true;
			}

			if (cc + dd * 10 < 0) {
				__asm int 3;
			}

			printf("\t%02d\n", cc + dd * 10);

			continue;

			double ab = a * b;
			for (int i = a; i <= b; i++) {
				if (i % 2 == 0) {
					ab = (ab + a) * b;
				}
				else {
					ab = fabs(ab - (double)b) / a;
				}
			}

			f = (log((double)a + 1) / log((double)m+1)) * pow((double)b, (double)m /*/ (double)a*/);
			//printf("%f, %f\n", f, (f / a / b));

			double bsa = (double)b / (double)a * (double)m;
			//double fd = f * ab;
			double fd = f / a / b;

			for (int i = a; i <= b; i++) {
				/*if (i % 2 == 0) {
					fd = (fd + a) / b;
				}
				else {
					fd = fabs(fd - (double)b) * a;
				}*/

				//int id = i * a * b * 1 / m;
				int id = i * (a + m) * (b + m);
				switch (id % 6) {
				case 0:
					fd = (fd + a) / b;
					break;
				case 1:
					fd = fabs(fd - (double)b) * a;
					break;
				case 2:
					fd = (fd + b) / m;
					break;
				case 3:
					fd = fabs(fd - (double)a) * b;
					break;
				case 4:
					fd = (fd + m) / a;
					break;
				}
			}

			int c = (int)((fd + bsa) / 2.0) % 6;
			int d = (int)sqrt(fd * bsa) / 10 % 7;

			printf("\t");
			if (heep[c + d * 10]) {
				printf("hit");
				hits++;
			}
			else {
				heep[c + d * 10] = true;
			}

			if (c + d * 10 < 0) {
				__asm int 3;
			}

			printf("\t%02d\n", c + d * 10);

		}
	}

	printf("\n");

	for (int i = 0; i < 100; i++) {
		if (heep[i]) {
			printf("%02d\n", i);
		}
	}

	printf("\n");

	printf("%dhits, %.3f\%", hits, ((float)hits / maxA / maxB * 100));

	//scanf_s("");
	getchar();

	return 0;
}