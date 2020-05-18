#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Triangles {
	int id;
	int a;
	int b;
	int c;
	int colour;
};

const string TRIANGLES_NAME_FILE = "triangles.txt";
const string COLOURS_NAME_FILE = "colours.txt";

int main()
{
	ifstream trian;
	trian.open("triangles.txt", ios::in);
	if (!trian.is_open())
	{
		cerr << TRIANGLES_NAME_FILE << " did not open\n";
		return 1;
	}
	ifstream colours;
	colours.open("colours.txt", ios::in);
	if (!colours.is_open())
	{
		cerr << COLOURS_NAME_FILE << " did not open\n";
		return 2;
	}
	int num_of_colours, num_trian;
	colours >> num_of_colours;
	string *colours_list = new string[num_of_colours];
	trian >> num_trian;
	Triangles *trian_list = new Triangles[num_trian];
	ofstream *trian_col = new ofstream[num_of_colours];
	string tmp;
	for (int i = 0; i < num_of_colours; i++) {
		colours.ignore();
		colours.ignore();
		colours >> colours_list[i];
		colours.ignore();
		tmp = "triangle-" + colours_list[i] + ".txt";
		trian_col[i].open(tmp, ios::out);
	}	
	for (int i = 0; i < num_trian; i++) {
		trian >> trian_list[i].id;
		trian >> trian_list[i].a;
		trian >> trian_list[i].b;
		trian >> trian_list[i].c;
		trian >> trian_list[i].colour;
		trian_col[trian_list[i].colour - 1] << trian_list[i].id << ' ' << trian_list[i].a << ' ' << trian_list[i].b << ' ' << trian_list[i].c << ' ' << trian_list[i].a + trian_list[i].b + trian_list[i].c << endl;
	}
	trian_col->close();
	trian.close();
	colours.close();
	delete[] trian_col;
	delete[] trian_list;
	delete[] colours_list;
	trian_col = nullptr;
	trian_list = nullptr;
	colours_list = nullptr;
	cout << "Готово! Проверьте созданные файлы в корневой папке проекта.";
}
