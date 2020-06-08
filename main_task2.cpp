
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Triangle
{
	int id;
	int len[3];
	int color;
};

const string colorsFileName = "colours.txt";
const string trianglesFileName = "triangles.txt";

int main()
{
	ifstream colorsFile;
	colorsFile.open(colorsFileName);

	int sumColor;
	colorsFile >> sumColor;

	string* colorString = new string[sumColor + 1];

	int id;
	for (int i = 1; i <= sumColor; i++)
		colorsFile >> id >>colorString[i];

	colorsFile.close();

	ifstream trianglesFile;
	ofstream variousTrianFile;
	int sumTrian;
	
	Triangle curTriangle;	
	for (int col = 1; col <= sumColor; col++)
	{
		trianglesFile.open(trianglesFileName);
		trianglesFile >> sumTrian;
		variousTrianFile.open("triangle-" + colorString[col] + ".txt");
		for (int i = 0; i < sumTrian; i++)
		{
			trianglesFile >> curTriangle.id >> curTriangle.len[0] >> curTriangle.len[1] >> curTriangle.len[2] >> curTriangle.color;
			if (curTriangle.color==col) variousTrianFile << curTriangle.id<<' ' << curTriangle.len[0] <<' '<< curTriangle.len[1] <<' '<< curTriangle.len[2] << '\n';
			
		}
		variousTrianFile.close();
		trianglesFile.close();
	}
}