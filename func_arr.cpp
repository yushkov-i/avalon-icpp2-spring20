#include <iostream>
using namespace std;
struct row
{
	const static int SIZE = 4;
	int DATA[SIZE];
};
row input_row()
{
	row row;
	for (int i = 0; i <row::SIZE; i++) { cin >> row.DATA[i]; }
	return row;
}
int* input()
{
	int *data=new int[5];
	for (int i = 0; i < 5; i++) { cin >> data[i]; }
	return data;
}
int main()
{
	row row = input_row();
	int *ptr = input();
	for (int i = 0; i < row::SIZE; i++) { cout << row.DATA[i] << endl; }
	for (int i = 0; i < 5; i++) { cout << ptr[i] << endl; }
