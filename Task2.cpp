﻿#include <iostream>
#include "Extention.hpp"
using namespace std;
using namespace ext;

int main() {
	int marks[100], count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0, mark25, mark50, mark75, count;
	for (int i = 0; i < 100; i++) {
		marks[i] = GetRandomValue(1, 5);
		if (marks[i] == 1) count1++;
		if (marks[i] == 2) count2++;
		if (marks[i] == 3) count3++;
		if (marks[i] == 4) count4++;
		if (marks[i] == 5) count5++;
	}
	int moda = 1;
	if (count1 < count2) moda = 2;
	if (count2 < count3) moda = 3;
	if (count3 < count4) moda = 4;
	if (count4 < count5) moda = 5;
	cout << "Moda = " << moda << endl;
	while (count < 25){

	}
}