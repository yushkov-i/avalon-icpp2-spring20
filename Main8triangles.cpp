#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

struct Triangle {
	int number;
	int length1;
	int length2;
	int length3;
	int colour;
};

const string TRIANGLE_FILE_NAME = "triangle.txt";
const string COLOURS_FILE_NAME = "colours.txt";
const string WHITE_FILE_NAME = "triangle-white.txt";
const string RED_FILE_NAME = "triangle-red.txt";
const string GREEN_FILE_NAME = "triangle-green.txt";
const string BLUE_FILE_NAME = "triangle-blue.txt";
const string BLACK_FILE_NAME = "triangle-black.txt";

int main() {
	ifstream triangleFile;
	ifstream coloursFile;
	ofstream whiteFile;
	ofstream redFile;
	ofstream greenFile;
	ofstream blueFile;
	ofstream blackFile;
	triangleFile.open(TRIANGLE_FILE_NAME);
	coloursFile.open(COLOURS_FILE_NAME);
	whiteFile.open(WHITE_FILE_NAME);
	redFile.open(RED_FILE_NAME);
	greenFile.open(GREEN_FILE_NAME);
	blueFile.open(BLUE_FILE_NAME);
	blackFile.open(BLACK_FILE_NAME);
	if (!triangleFile.is_open()) {
		cerr << TRIANGLE_FILE_NAME << " didn't open\n";
		return 1;
	}
	if (!coloursFile.is_open()) {
		cerr << COLOURS_FILE_NAME << " didn't open\n";
		return 2;
	}
	if (!whiteFile.is_open()) {
		cerr << WHITE_FILE_NAME << " didn't open\n";
		return 3;
	}
	if (!redFile.is_open()) {
		cerr << RED_FILE_NAME << " didn't open\n";
		return 4;
	}
	if (!greenFile.is_open()) {
		cerr << GREEN_FILE_NAME << " didn't open\n";
		return 5;
	}
	if (!blueFile.is_open()) {
		cerr << BLUE_FILE_NAME << " didn't open\n";
		return 6;
	}
	if (!blackFile.is_open()) {
		cerr << BLACK_FILE_NAME << " didn't open\n";
		return 7;
	}

	int numberOfTriangles, numberOfColors;
	coloursFile >> numberOfColors;
	triangleFile >> numberOfTriangles;

	Triangle *triangles = new Triangle[numberOfTriangles];
	for (int i = 0; i < numberOfTriangles; ++i) {
		triangleFile >> triangles[i].number;
		triangleFile >> triangles[i].length1;
		triangleFile >> triangles[i].length2;
		triangleFile >> triangles[i].length3;
		triangleFile >> triangles[i].colour;
		triangleFile.ignore(std::numeric_limits<int>::max(), '\n');
	}
	int *colours = new int[numberOfColors];
	for (int i = 0; i < numberOfColors; ++i) {
		coloursFile >> colours[i];
		coloursFile.ignore(std::numeric_limits<int>::max(), '\n');
	}
	triangleFile.close();
	coloursFile.close();

	for (int i = 0; i < numberOfTriangles; ++i) {
		if (triangles[i].colour == 1) {
			whiteFile << triangles[i].number << " " << triangles[i].length1 << " " << triangles[i].length2 << " " << triangles[i].length3 << " " << triangles[i].length1 + triangles[i].length2 + triangles[i].length3 << endl;
		}
		else if (triangles[i].colour == 2) {
			redFile << triangles[i].number << " " << triangles[i].length1 << " " << triangles[i].length2 << " " << triangles[i].length3 << " " << triangles[i].length1 + triangles[i].length2 + triangles[i].length3 << endl;
		}
		else if (triangles[i].colour == 3) {
			greenFile << triangles[i].number << " " << triangles[i].length1 << " " << triangles[i].length2 << " " << triangles[i].length3 << " " << triangles[i].length1 + triangles[i].length2 + triangles[i].length3 << endl;
		}
		else if (triangles[i].colour == 4) {
			blueFile << triangles[i].number << " " << triangles[i].length1 << " " << triangles[i].length2 << " " << triangles[i].length3 << " " << triangles[i].length1 + triangles[i].length2 + triangles[i].length3 << endl;
		}
		else if (triangles[i].colour == 5) {
			blackFile << triangles[i].number << " " << triangles[i].length1 << " " << triangles[i].length2 << " " << triangles[i].length3 << " " << triangles[i].length1 + triangles[i].length2 + triangles[i].length3 << endl;
		}
	}
	whiteFile.close();
	redFile.close();
	greenFile.close();
	blueFile.close();
	blackFile.close();
}