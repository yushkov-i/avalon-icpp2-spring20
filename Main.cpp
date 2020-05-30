#include <iostream>
#include "Extention.h"
using namespace ext;
using namespace std;
enum Grade
{
    F = 1,   // не€вка
    D = 2,  // неудовлетворительно
    C = 3,  // удовлетворительно
    B = 4,  // хорошо
    A = 5,  // отлично      
};

struct Student
{
    int Id;
    Grade Mark;
    char Name[7];
};
void filler(Student* inp)
{
    for (int i = 0; i < 100; i++) {
        Student gener;

        gener.Id = GetRandomValue(1, 1000);
        gener.Mark = static_cast<Grade>(GetRandomValue(1, 5)); // €вное преобразование int в Grade

        int tempLength = GetRandomValue(3, 6);
        for (int i = 0; i < tempLength; ++i)
        {
            int symbol = GetRandomValue('a', 'z');  // не€вное преобразование из char в int в момент вызова функции
            gener.Name[i] = symbol; // не€вное преобразование из int в char при приравнивании
        }

        for (int i = tempLength; i < 7; ++i) // 7-ку лучше конечно заменить на константу
        {
            gener.Name[i] = '\0';
        }
        inp[i] = gener;
    }
  
}
void sorter(Student* inp, int mod) {
    Student sort, inp1, inp2;
    for (int g = 0; g < 99; g++) {
        for (int i = 0; i < 99; i++) {
            inp1 = inp[i];
            inp2 = inp[i + 1];
            switch (mod)
            {
            case 1: {
                if (inp1.Id > inp2.Id)
                {
                    sort = inp1;
                    inp1 = inp2;
                    inp2 = sort;

                }
                break;
            }
            case 2: {
                if (inp1.Mark < inp2.Mark)
                {
                    sort = inp1;
                    inp1 = inp2;
                    inp2 = sort;

                }
                break;
            }

            case 3: {
                for (int k = 0; k < 8; k++) {
                    for (int x = 0; x < 7; x++) {
                        if (static_cast<int>(inp1.Name[x]) > static_cast<int>(inp2.Name[x]))
                        {
                            sort = inp1;
                            inp1 = inp2;
                            inp2 = sort;


                        }
                    }
                }
                break;
            }
            }
            inp[i] = inp1;
            inp[i + 1] = inp2;
        }
    }
}
int main()
{

    Student list[100];
	Student* ptr =list;
    filler(ptr);
    int mod;
    cout << "Enter sort modifier \n 1)Id \n 2)Mark \n 3)Name \n";
    cin >> mod;
    sorter(ptr, mod);
    for (int i = 0; i < 100; i++) {
        cout << i + 1 << ".\n  Id=" << list[i].Id << "\n  Mark=" << list[i].Mark << "\n  Name=" << list[i].Name<<"\n";
    }
    sorter(ptr, 2);
    cout << "Better 25 %- "<< list[75].Mark << "\n";
    cout << "Better 50 %- " << list[50].Mark << "\n";
    cout << "Better 75 %- " << list[25].Mark << "\n";
}