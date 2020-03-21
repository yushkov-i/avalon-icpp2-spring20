#include <iostream>
#include<limits>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    printf("Тип переменной\t\t|\tРазмер,\t  |\t\t    Значение\t\t       |  Количество\n");
    printf("\t\t\t|\tбайт\t  |\tМинимальное     |      Максимальное    | значимых бит\n");
    for (int i = 0; i < 107; i++) cout << "-";
    cout << endl;
    printf("bool\t\t\t|\t\t %d|\t\t       %d|\t\t      %d|\t\t %d|\n", sizeof(bool), numeric_limits<bool>::min(), numeric_limits<bool>::max(), sizeof(bool));
    printf("unsigned short\t\t|\t\t %d|\t\t       %d|\t\t  %d|\t\t%d|\n", sizeof(unsigned short), numeric_limits<unsigned short>::min(), numeric_limits<unsigned short>::max(), sizeof(unsigned short) * 8);
    printf("short\t\t\t|\t\t %d|\t\t  %d|\t\t  %d|\t\t%d|\n", sizeof(short), numeric_limits<short>::min(), numeric_limits<short>::max(), sizeof(short) * 8);
    printf("unsigned int\t\t|\t\t %d|\t\t       %d|\t     %u|\t\t%d|\n", sizeof(unsigned int), numeric_limits<unsigned int>::min(), numeric_limits<unsigned int>::max(), sizeof(unsigned int) * 8);
    printf("int\t\t\t|\t\t %d|\t     %d|\t     %u|\t\t%d|\n", sizeof(int), numeric_limits<int>::min(), numeric_limits<int>::max(), sizeof(int) * 8);
    printf("unsigned long\t\t|\t\t %d|\t\t       %d|\t     %u|\t\t%d|\n", sizeof(unsigned long), numeric_limits<unsigned long>::min(), numeric_limits<unsigned long>::max(), sizeof(unsigned long) * 8);
    printf("long\t\t\t|\t\t %d|\t     %d|\t     %u|\t\t%d|\n", sizeof(long), numeric_limits<long>::min(), numeric_limits<long>::max(), sizeof(long) * 8);
    printf("unsigned long long\t|\t\t %d|\t\t       %d|  %llu|\t\t", sizeof(unsigned long long), numeric_limits<unsigned long long>::min(), numeric_limits<unsigned long long>::max());
    printf("%u|\n", sizeof(unsigned long long) * 8);
    printf("long long\t\t|\t\t %d| %lli|   %llu|\t\t%u|\n", sizeof(long long), numeric_limits<long long>::min(), numeric_limits<long long>::max(), sizeof(long long) * 8);
    printf("char\t\t\t|\t\t %d|\t\t    %d|\t\t    %d|\t\t %d|\n", sizeof(char), numeric_limits<char>::min(), numeric_limits<char>::max(), sizeof(char) * 8);
    printf("float\t\t\t|\t\t %d|\t    %e|\t   %e|\t\t%u|\n", sizeof(float), numeric_limits<float>::min(), numeric_limits<float>::max(), sizeof(float) * 8);
    printf("double\t\t\t|\t\t %d|\t   %e|\t  %e|\t\t%u|\n", sizeof(double), numeric_limits<double>::min(), numeric_limits<double>::max(), sizeof(double) * 8);
    system("pause");
    return 0;
}
