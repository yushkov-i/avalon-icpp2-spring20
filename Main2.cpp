#include <iostream>
#include "Extention.hpp"
using namespace std;
using namespace ext;
const int index = 100;
int main() {
	int marks[index], count[6], mark25, mark50, mark75, count1;
	for (int i = 1; i < 6; i++) {
		count[i] = 0;
	}
	for (int i = 0; i < index; i++) {
		marks[i] = GetRandomValue(1, 5);
		if (marks[i] == 1) count[1]++;
		if (marks[i] == 2) count[2]++;
		if (marks[i] == 3) count[3]++;
		if (marks[i] == 4) count[4]++;
		if (marks[i] == 5) count[5]++;
	}
	int moda[6], c[6];
	moda[1] = 1;
	c[1] = count[1];
	for (int i = 2; i < 6; i++) {
		c[i] = 0;
		moda[i] = 0;
	}
	for (int i = 2; i < 6; i++) {
		if (c[1] < count[i]) {
			c[1] = count[i];
			moda[1] = i;
		}
	}
	for (int i = 2; i < 6; i++) {
		if (i == moda[1]) continue;
		if (c[1] == count[i]) {
			c[i] = count[i];
			moda[i] = i;
		}
	}
	for (int i = 1; i < 6; i++) {
		if (moda[i] != 0) cout << "Moda = " << moda[i] << endl;
	}
	do {
		count1 = count[1];
		if (count1 > index / 4) {
			mark25 = 1;
			break;
		}
		if (count1 == index / 4) {
			mark25 = 2;
			break;
		}
		count1 += count[2];
		if (count1 > index / 4) {
			mark25 = 2;
			break;
		}
		if (count1 == index / 4) {
			mark25 = 3;
			break;
		}
		count1 += count[3];
		if (count1 > index / 4) {
			mark25 = 3;
			break;
		}
		if (count1 == index / 4) {
			mark25 = 4;
			break;
		}
		count1 += count[4];
		if (count1 > index / 4) {
			mark25 = 4;
			break;
		}
		if (count1 == index / 4) {
			mark25 = 5;
			break;
		}
		count1 += count[5];
		if (count1 >= index / 4) {
			mark25 = 5;
			break;
		}
	} while (count1 < index / 4);
	count1 = 0;
	cout << "To be better then 25% you must get " << mark25 << endl;;
	do {
		count1 = count[1];
		if (count1 > index / 2) {
			mark50 = 1;
			break;
		}
		if (count1 == index / 2) {
			mark50 = 2;
			break;
		}
		count1 += count[2];
		if (count1 > index / 2) {
			mark50 = 2;
			break;
		}
		if (count1 == index / 2) {
			mark50 = 3;
			break;
		}
		count1 += count[3];
		if (count1 > index / 2) {
			mark50 = 3;
			break;
		}
		if (count1 == index / 2) {
			mark50 = 4;
			break;
		}
		count1 += count[4];
		if (count1 > index / 2) {
			mark50 = 4;
			break;
		}
		if (count1 == index / 2) {
			mark50 = 5;
			break;
		}
		count1 += count[5];
		if (count1 >= index / 2) {
			mark50 = 5;
			break;
		}
	} while (count1 < index / 2);
	count1 = 0;
	cout << "To be better then 50% you must get " << mark50 << endl;
	do {
		count1 = count[1];
		if (count1 > index * 0.75) {
			mark75 = 1;
			break;
		}
		if (count1 == index * 0.75) {
			mark75 = 2;
			break;
		}
		count1 += count[2];
		if (count1 > index * 0.75) {
			mark75 = 2;
			break;
		}
		if (count1 == index * 0.75) {
			mark75 = 3;
			break;
		}
		count1 += count[3];
		if (count1 > index * 0.75) {
			mark75 = 3;
			break;
		}
		if (count1 == index * 0.75) {
			mark75 = 4;
			break;
		}
		count1 += count[4];
		if (count1 > index * 0.75) {
			mark75 = 4;
			break;
		}
		if (count1 == index * 0.75) {
			mark75 = 5;
			break;
		}
		count1 += count[5];
		if (count1 >= index * 0.75) {
			mark75 = 5;
			break;
		}
	} while (count1 < index * 0.75);
	cout << "To be better then 75% you must get " << mark75 << endl;
}