#pragma once

#include <stdio.h>
#include <vector>

using namespace std;

int entry() {
	vector<int> abc;

	for (int i = 1; i <= 5; i++) {
		for (int j = i; j <= 5; j++) {
			for (int k = j; k <= 5; k++) {
				abc.push_back(i * 100 + j * 10 + k);
			}
		}
	}

	auto end = abc.end();

	for (auto i = abc.begin(); i != end; ++i) {
		printf("a = %d , b = %d , c = %d\n", *i / 100, *i / 10 % 10, *i % 10);

		if (find(i + 1, end, *i) != end) {
			return 100;
		}
	}

	printf("count : %d\n", abc.size());

	return 0;
}