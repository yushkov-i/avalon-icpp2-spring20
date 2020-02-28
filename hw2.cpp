// hw2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include "Debug/Extention.hpp"
#include <iostream>
#include <ctime>
using namespace std;
using namespace ext;
int main()
{
   
    enum Grade
    {
        F = 1, // неявка
        D = 2, // неудовлетворительно
        C = 3, // удовлетворительно
        B = 4, // хорошо
        A = 5, // отлично 
    };

    struct Student
    {
        int Id;
        Grade Mark;
        char Name[7];
    };
    const int N = 100;
    int prop;
    bool bubble = true; //для сортировки по условию.


    Student pers[N];
    for (int i = 0; i < N; i++) {
        MakeId: 
        pers[i].Id = GetRandomValue(1, 1000);
        for(int j=0; j<i; j++){
            if (pers[j].Id == pers[i].Id) goto MakeId;  //делаем разные id
        }
        pers[i].Mark = static_cast<Grade>(GetRandomValue(1, 5));
        int tempLength = GetRandomValue(3, 6);
        for (int k = 0; k < tempLength; k++)
        {
            int symbol = GetRandomValue('a', 'z');  
            pers[i].Name[k] = symbol; 
        }

        for (int k = tempLength; k < 7; k++) 
        {
            pers[i].Name[k] = '\0';
        }
    }
    cout << "Select a property for sorting: Id, Mark or Name (enter 1,2 or 3): ";    //трудность: при дальнейшем сравнении не воспринимаются переменные типа char... =(
    cin >> prop;
    for (int i = 0; i < N; i++) {
        bool hasSwamp = false;
        for (int j = 0; j < N-1; j++) {
            bubble = false;
            if (prop == 1) pers[j].Id > pers[j + 1].Id ? bubble = true : not bubble;
            if (prop == 2) pers[j].Mark > pers[j + 1].Mark ? bubble = true : not bubble;
            if (prop == 3) strcmp(pers[j].Name, pers[j + 1].Name) == 1 ? bubble = true : not bubble;
            if (bubble) {
                Student temp = pers[j];
                pers[j] = pers[j + 1];
                pers[j + 1] = temp;
                hasSwamp = true;
            }
        }
        if (!hasSwamp) break;
    }








    for (int i = 0; i < N; i++) {
        cout << pers[i].Id << "\t" << pers[i].Name << "\t" << pers[i].Mark << endl;
    }
   







    system("pause");
    return 0;
}
