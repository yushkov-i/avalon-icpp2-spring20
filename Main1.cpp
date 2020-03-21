#include<iostream>
#include"Extention.hpp"
using namespace std;
using namespace ext;
int* initialization(int mas[][12]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 12; j++) {
			mas[i][j] = GetRandomValue(1000, 100000);
		}
	}
	return mas[12];
}
int* init(int mas[][12]) {
	for (int i = 0; i < 10; i++) {
		int n = GetRandomValue(0, 4);
		for (int j = 0; j < n; j++) {
			int k = GetRandomValue(0, 11);
			mas[i][k] = -1;
		}
	}
	return mas[12];
}
double median(int mas[12]) {
	double mediana;
	int n = 0;
	for (int i = 0; i < 12; i++) {
		if (mas[i] != -1) n++;
	}
	int* mas1 = new int[n];
	int k = 0;
	for (int i = 0; i < 12; i++) {
		if (mas[i] != -1) {
			mas1[k] = mas[i];
			k++;
		}
	}
	if ((n % 2) == 1) {
		mediana = mas1[(n + 1) / 2 - 1];
	}
	if ((n % 2) == 0) {
		mediana = (mas1[n / 2 - 1] + mas1[n/ 2]) / 2.;
	}
	return mediana;
}
int main() {
	int salary[10][12];
	initialization(salary);
	init(salary);
	cout << "Revenues of agents by months:" << endl;
	for (int i = 0; i < 10; i++) {
		cout << i + 1 << " agent: ";
		for (int j = 0; j < 12; j++) {
			cout << salary[i][j] << "; ";
		}
		cout << endl;
	}
	cout << endl;
	double mediana[10], max_mediana = 0;
	int max_i = 0;
	for (int i = 0; i < 10; i++) {
		mediana[i] = median(salary[i]);
		cout << "Median of " << i + 1 << " agent: " << mediana[i] << endl;
	}
	for (int i = 0; i < 10; i++) {
		if (mediana[i] > max_mediana) {
			max_mediana = mediana[i];
			max_i = i;
		}
	}
	cout << "\nThe highest median of monthly revenue value has agent number " << max_i + 1 << ", it is " << max_mediana;
	return 0;
}