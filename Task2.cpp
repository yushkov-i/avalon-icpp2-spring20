#include <iostream>
#include "Extention.hpp"
using namespace std;
using namespace ext;
const int index = 100; 

int main() {
	int marks[index], count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0, mark25, mark50, mark75, count;
	for (int i = 0; i < index; i++) {
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
	do{
		count = count1;
		if (count > index/4) {
			mark25 = 1;
			break;
		}
		if (count == index/4) {
			mark25 = 2;
			break;
		}
		count += count2;
		if (count > index/4) {
			mark25 = 2;
			break;
		}
		if (count == index/4) {
			mark25 = 3;
			break;
		}
		count += count3;
		if (count > index/4) {
			mark25 = 3;
			break;
		}
		if (count == index/4) {
			mark25 = 4;
			break;
		}
		count += count4;
		if (count > index/4) {
			mark25 = 4;
			break;
		}
		if (count == index/4) {
			mark25 = 5;
			break;
		}
		count += count5;
		if (count >= index/4) {
			mark25 = 5;
			break;
		}
	}
	count = 0;
	cout << "To be better then 25% you must get" << mark25;
	do{
		count = count1;
		if (count > index/2) {
			mark50 = 1;
			break;
		}
		if (count == index/2) {
			mark50 = 2;
			break;
		}
		count += count2;
		if (count > index/2) {
			mark50 = 2;
			break;
		}
		if (count == index/2) {
			mark50 = 3;
			break;
		}
		count += count3;
		if (count > index/2) {
			mark50 = 3;
			break;
		}
		if (count == index/2) {
			mark50 = 4;
			break;
		}
		count += count4;
		if (count > index/2) {
			mark50 = 4;
			break;
		}
		if (count == index/2) {
			mark50 = 5;
			break;
		}
		count += count5;
		if (count >= index/2) {
			mark50 = 5;
			break;
		}
	}
	count = 0;
	cout << "To be better then 50% you must get" << mark50;
	do{
		count = count1;
		if (count > index/3 * 4) {
			mark75 = 1;
			break;
		}
		if (count == index/3 * 4) {
			mark75 = 2;
			break;
		}
		count += count2;
		if (count > index/3 * 4) {
			mark75 = 2;
			break;
		}
		if (count == index/3 * 4) {
			mark75 = 3;
			break;
		}
		count += count3;
		if (count > index/3 * 4) {
			mark75 = 3;
			break;
		}
		if (count == index/3 * 4) {
			mark75 = 4;
			break;
		}
		count += count4;
		if (count > index/3 * 4) {
			mark75 = 4;
			break;
		}
		if (count == index/3 * 4) {
			mark75 = 5;
			break;
		}
		count += count5;
		if (count >= index/3 * 4) {
			mark75 = 5;
			break;
		}
	}
	cout << "To be better then 75% you must get" << mark75;
}
