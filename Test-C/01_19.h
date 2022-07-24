#pragma once

/*
567
133
502

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int entry() {
	string nStr;

	vector<int *> square;

	int n;

	int i = 0;

	while (getline(cin, nStr)) {
		n = nStr.length();
		int *line = new int[n];

		for (int i = 0; i < n; i++) {
			line[i] = nStr[i] - '0';
		}

		square.push_back(line);

		i++;

		if (i == n) {
			break;
		}
	}

	nStr.~basic_string();

	int ma = n * 2 - 1;
	vector<int *> routes;
	int *mas = new int[ma];

	for (i = 0; i < ma; i++) {
		mas[i] = 0;

		if (i < n) {
			mas[i] = i + 1;
		}
		else {
			mas[i] = n * 2 - i - 1;
		}

		int *route = new int[mas[i]];

		int j = 0;

		for (int x = 0; x < n; x++) {
			for (int y = 0; y < n && x + y <= i; y++) {
				if (x + y == i) {
					route[j] = square[x][y];

					j++;
				}
			}
		}

		routes.push_back(route);
	}

	for (i = 0; i < n; i++) {
		delete square[i];
	}

	square.~vector();

	int min = INT_MAX;

	int a, b;

	{
		a = b = 1;

		n--;

		for (i = 0; i < n; i++) {
			a *= n * 2 - i;
			b *= i + 1;
		}
	}

	int routeNumber = a / b;

	for (i = 0; i < routeNumber; i++) {
		int sum = 0;

		for (int j = 0; j < ma && sum < min; j++) {
			sum += routes[j][i%mas[j]];
		}

		if (sum < min) {
			min = sum;
		}
	}

	cout << min << endl;

	return 0;
}