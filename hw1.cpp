// hw1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
int main()
{
    long num = 0;
    cout << "Введите кол-во вводимых ISBN-13: ";
    cin >> N;
    for (int i = 0; i < N; i++) {
        int N = 0, lastnum = 0, temp=0 ;
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
    }
    system("pause");
    return 0;
}
