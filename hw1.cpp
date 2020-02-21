// hw1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
int main()
{
    int N = 0, lastnum = 0, temp=0 ;
    long num = 0;
    cout << "Введите кол-во вводимых ISBN-13: ";
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> num;
        lastnum = num % 10;
        num /= 10;
        for (int j = 1; j <= 12; j++) {
            j % 2 == 0 ? temp += (num % 10) * 1 : temp += (num % 10) * 3;
            num /= 10;
        }
        if (lastnum == 10 - (temp % 10)) {
            cout << "valid" << endl;
        }
        else cout << "invalid" << endl;
        temp = 0;
        num = 0;
        lastnum = 0;
    }
    system("pause");
    return 0;
}
