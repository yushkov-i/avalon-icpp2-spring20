#include <fstream>
#include <iostream>
#include <string>
using namespace std;
struct triangle
{
	int id;
	int a;
	int b;
	int c;
	int colour_id;
};
struct colour
{
	int id;
	string name;
};
const string COLOURS_FILE_NAME = "colours.txt";
const string TRIANGLE_FILE_NAME = "triangle.txt";
int main()
{
	ifstream coloursFile;
	coloursFile.open(COLOURS_FILE_NAME);
	ifstream triangleFile;
	triangleFile.open(TRIANGLE_FILE_NAME);
	if (!coloursFile.is_open())
	{
		cerr << COLOURS_FILE_NAME << " did not open\n";
		return 1;
	}
	if (!triangleFile.is_open())
	{
		cerr << TRIANGLE_FILE_NAME << " did not open\n";
		return 2;
	}
	int colours_count, triangles_count;
	coloursFile >> colours_count;
	triangleFile >> triangles_count;
	colour* colours = new colour[colours_count];
	triangle* triangles = new triangle[triangles_count];
	for (int i = 0; i < colours_count; i++)
	{
		coloursFile >> colours[i].id >> colours[i].name;
	}
	for (int i = 0; i < triangles_count; i++)
	{
		triangleFile >> triangles[i].id >> triangles[i].a >> triangles[i].b >> triangles[i].c >> triangles[i].colour_id;
	}
	coloursFile.close();
	triangleFile.close();
	ofstream* coloursFiles = new ofstream[colours_count];
	for (int i = 0; i < colours_count; i++) {
		coloursFiles[i].open("triangle-" + colours[i].name + ".txt");
		if (!coloursFiles[i].is_open()) {
			cout << "File triangle-" << colours[i].name << ".txt" << " didn't open!";
			return 3;
		}
	}
	for (int i = 0; i < triangles_count; i++)
	{
		coloursFiles[triangles[i].colour_id - 1] << triangles[i].id << " " << triangles[i].a << " " << triangles[i].b << " " << triangles[i].c << " " << triangles[i].a + triangles[i].b + triangles[i].c << endl;
	}
	for (int i = 0; i < colours_count; i++) {
		coloursFiles[i].close();
	}
}
