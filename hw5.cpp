// hw5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "Date.h"
#include <iostream>
#include <random>
using namespace std;
using namespace ext;
int GetRandomValue(int min, int max, bool isDebugMode = false)
{
	static auto randomEngine = [isDebugMode]() { return isDebugMode ? std::mt19937{} : std::mt19937(std::random_device{}()); }();
	auto distribution = std::uniform_int_distribution<int>(min, max);
	return distribution(randomEngine);
} 
int main()
{
    setlocale(LC_ALL, "RU");
    Date dates[100], maindate, minDistDate, maxDistDate;
    int tempm; //для ввода месяца



    cout << "Введите день, месяц, годЫ:";
    cin >> maindate.day >> tempm >> maindate.year;
    maindate.month = static_cast<Month>(tempm);
    for (int i = 0; i < 100; i++) {
        dates[i].day = GetRandomValue(1, 28);
        dates[i].month = static_cast<Month>(GetRandomValue(1, 12));
        dates[i].year = GetRandomValue(1, 3000);
    }
    sort(dates, sizeof(dates));
    cout << endl;
    for (int i = 0; i < 100; i++) {
        print(dates[i]);
    }
    cout << endl;
    for (int i = 1; i < 100; i++) {
        if (dates[i] >= maindate) {
            minDistDate = (countDistance(maindate, dates[i]).delta < countDistance(maindate, dates[i - 1]).delta 
                ? dates[i] : dates[i - 1]);
            break;
        }
    }
    maxDistDate = (countDistance(maindate, dates[0]).delta > countDistance(maindate, dates[sizeof(dates) / 12 - 1]).delta
        ? dates[0] : dates[sizeof(dates) / 12 - 1]);
    cout << "ближайшая и наиболее удаленная даты: ";
    print(minDistDate);
    print(maxDistDate);



   /* print(getMinDate(dates, sizeof(dates)));
    print(getMaxDate(dates, sizeof(dates)));*/
}
