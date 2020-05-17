#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Tringle_struct {
	int id;
	int a;
	int b;
	int c;
	int colour;
};

struct Colour_Info {
	int id_colour;
	string name_colour;
};

const string TRIANGLE_FILE = "triangle";
const string COLOURS_FILE_INFO = "colours.txt";
const int KOL_VO_TRIANGLE = 100;
const int KOL_VO_COLOUR = 5;

int main() {
	ifstream Triangle_ifstream;
	Triangle_ifstream.open(TRIANGLE_FILE + "s.txt");
	if (!Triangle_ifstream.is_open()) {
		cout << "File " << TRIANGLE_FILE + ".txt" << " didn't open!";
		return 1;
	}
	int Num;
	Triangle_ifstream >> Num;
	const int Kol_vo_triangle = Num;   // -не сработало
	Tringle_struct *Triangle = new Tringle_struct[KOL_VO_TRIANGLE];
	for (int i = 0; i < Num; i++) {
		Triangle_ifstream >> Triangle[i].id;
		Triangle_ifstream >> Triangle[i].a;
		Triangle_ifstream >> Triangle[i].b;
		Triangle_ifstream >> Triangle[i].c;
		Triangle_ifstream >> Triangle[i].colour;
	}
	Triangle_ifstream.close();
	ifstream Colours_ifstream;
	Colours_ifstream.open(COLOURS_FILE_INFO);
	if (!Colours_ifstream.is_open()) {
		cout << "File " << COLOURS_FILE_INFO << " didn't open!";
		return 2;
	}
	Colours_ifstream >> Num;
	//const int NUMBER_OF_COLOUR = Num; // -не сработало
	Colour_Info *Colour = new Colour_Info[KOL_VO_COLOUR];
	for (int i = 0; i < KOL_VO_COLOUR; i++) {
		Colours_ifstream >> Colour[i].id_colour;
		Colours_ifstream >> Colour[i].name_colour;
	}
	Colours_ifstream.close();
	ofstream Colour_Triangle[KOL_VO_COLOUR];
	for (int i = 0; i < KOL_VO_COLOUR; i++) {
		Colour_Triangle[i].open(TRIANGLE_FILE + "-" + Colour[i].name_colour + ".txt");
		if (!Colour_Triangle[i].is_open()) {
			cout << "File " << TRIANGLE_FILE + "-" + Colour[i].name_colour + ".txt" << " didn't open!";
			return 3;
		}
	}
	for (int i = 0; i < Kol_vo_triangle; i++) {
		for (int j = 0; j < KOL_VO_COLOUR; j++) {
			if (Triangle[i].colour - 1 == Colour[j].id_colour - 1) {
				Colour_Triangle[j] << Triangle[i].id << ' ' << Triangle[i].a << ' ' << Triangle[i].b << ' ' << Triangle[i].c << ' ' << Triangle[i].a + Triangle[i].b + Triangle[i].c << '\n';
				break;
			}
		}
	}
	delete[] Triangle;
	delete[] Colour;
}