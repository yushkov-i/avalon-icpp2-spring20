#include<iostream>
#include<fstream>

using namespace std;

struct Triangle
{
	int a;
	int b;
	int c;
	double thickness;
};

int main()
{
	cout << "Input the Triangle number: ";
	int trg =0;
	cin >> trg;
	cout << endl;
	ifstream TrigIn;
	TrigIn.open("triangle.bin", ios::binary);
	Triangle triangl;
	TrigIn.seekg(trg * sizeof(Triangle));
	TrigIn.read(reinterpret_cast<char*>(&triangl), sizeof(Triangle));
	TrigIn.close();
	cout << "Your Triangle date is : " << endl;
	cout << "Fs : " << triangl.a << endl;
	cout << "Ss : " << triangl.b << endl;
	cout << "Ts : " << triangl.c << endl;
	cout << "Triangle thickness : " << triangl.thickness << endl;
}
