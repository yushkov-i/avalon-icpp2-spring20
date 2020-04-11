#pragma once
#include <iostream>
using namespace std;
namespace ext
{
	enum class Month
	{
		January = 1,
		February,
		March,
		April,
		May,
		June,
		July,
		August,
		September,
		October,
		November,
		December
	};

	enum class DateFormat
	{
		MonthAsInt,
		MonthAsString
	};

	enum class Season
	{
		Winter = 1,
		Spring,
		Summer,
		Autumn
	};

	enum class SortBy
	{
		Date,
		Season
	};

	struct Date
	{
		int year;
		Month month;
		int day;
	};

	struct TimeDelta
	{
		int delta;
	};

	/*----------homework-04----------*/
		/*
			Возвращает Юлианскую дату
			https://ru.wikipedia.org/wiki/%D0%AE%D0%BB%D0%B8%D0%B0%D0%BD%D1%81%D0%BA%D0%B0%D1%8F_%D0%B4%D0%B0%D1%82%D0%B0
			раздел "Вычисление номера юлианского дня (JDN) по дате григорианского календаря"
			Тестовые данные					Ожидаемый результат
			1.12.2018					2458454
			1.1.2018					2458120
			1.6.2000					2451697
			21.12.2012					2456283
		*/
	TimeDelta countJND(Date date) {
		int a = (14 - static_cast<int>(date.month)) / 12;
		int y = date.year + 4800 - a;
		int m = static_cast<int>(date.month) + (12 * a) - 3;
		TimeDelta jnd;
		jnd.delta = date.day + (((153 * m) + 2) / 5) + (365 * y) + (y / 4) - (y / 100) + (y / 400) - 32045;
		return jnd;
	}

	/*
		Рассчитывает количество дней между двумя датами.
		При реализации используйте CountJND
	*/
	TimeDelta countDistance(Date from, Date to) {
		TimeDelta days;
		days.delta = abs(countJND(to).delta - countJND(from).delta);
		return days;
	}



	/*
		Выводит в консоль
	*/
	void printString(Month month) {
		switch (month) {
		case Month::January:
			cout << "January";
		case Month::February:
			cout << "February";
		case Month::March:
			cout << "March";
		case Month::April:
			cout << "April";
		case Month::May:
			cout << "May";
		case Month::June:
			cout << "June";
		case Month::July:
			cout << "July";
		case Month::August:
			cout << "August";
		case Month::September:
			cout << "September";
		case Month::October:
			cout << "October";
		case Month::November:
			cout << "November";
		case Month::December:
			cout << "December";
		}
	}

	void print(Month month, DateFormat format = DateFormat::MonthAsInt) {
		if (format == DateFormat::MonthAsInt) {
			cout << static_cast<int>(month);
		}
		else if (format == DateFormat::MonthAsString) {
			printString(month);
		}
		else {
			cout << "nope";
		}
	}

	void print(Date data, DateFormat format = DateFormat::MonthAsInt) {
		cout << data.day << " ";
		print(data.month, format);
		cout << " " << data.year;
	}

	void print3(TimeDelta delta) {
		cout << delta.delta;
	}



	/*
		Возвращает сезон (зима, весна, лето, осень) передаваемой даты
	*/

	Season getSeason(Month month) {
		switch (static_cast<int>(month)) {
		case 1:
		case 2:
		case 12:
			return Season::Winter;
		case 3:
		case 4:
		case 5:
			return Season::Spring;
		case 6:
		case 7:
		case 8:
			return Season::Summer;
		case 9:
		case 10:
		case 11:
			return Season::Winter;
		}
	}

	Season getSeason2(Date date) {
		return getSeason(date.month);
	}

	/*
		Написать перегрузку для следующих логических операторов
	*/
	bool operator == (const Date lhs, const Date rhs) {
		return lhs.day == rhs.day && lhs.month == rhs.month && rhs.year == lhs.year;
	}
	bool operator != (const Date lhs, const Date rhs) {
		return lhs != rhs;
	}
	bool operator < (const Date lhs, const Date rhs) {
		return lhs.day < rhs.day && lhs.month < rhs.month && rhs.year < lhs.year;
	}
	bool operator <= (const Date lhs, const Date rhs) {
		return lhs.day <= rhs.day && lhs.month <= rhs.month && lhs.year <= rhs.year;
	}
	bool operator > (const Date lhs, const Date rhs) {
		return lhs.day > rhs.day && lhs.month > rhs.month && rhs.year > lhs.year;
	}
	bool operator >= (const Date lhs, const Date rhs) {
		return lhs.day >= rhs.day && lhs.month >= rhs.month && rhs.year >= lhs.year;
	}

	/*
		Написать перегрузку для следующих арифметических операторов
	*/

	Date countDate(TimeDelta delta) {
		int a = delta.delta + 32044,
			b = (4 * a + 3) / 146097,
			c = a - (146097 * b) / 4,
			d = (4 * c + 3) / 1461,
			e = c - (1461 * d) / 4,
			m = (5 * e + 2) / 153;
		Date fin;
		fin.day = e - (153 * m + 2) / 5 + 1;
		fin.month = static_cast<Month>(m + 3 - 12 * (m / 10));
		fin.year = 100 * b + d - 4800 + (m / 10);
		return fin;
	}

	Date operator + (const Date date, const TimeDelta delta) {
		TimeDelta returned{ countJND(date).delta + delta.delta };
		return countDate(returned);

	}
	Date operator + (const TimeDelta delta, const Date date) {
		return { date + delta };
	}
	TimeDelta operator + (const TimeDelta lhs, const TimeDelta rhs) {
		return { lhs.delta + rhs.delta };
	}

	TimeDelta operator * (const TimeDelta delta, int multiplier) {
		return { delta.delta * multiplier };
	}
	TimeDelta operator * (int multiplier, const TimeDelta delta) {
		return { multiplier * delta.delta };
	}


















	/*----------homework-05----------*/

	TimeDelta operator ++ (TimeDelta& delta) {
		++delta.delta;
		return delta;
	}
	TimeDelta operator ++ (TimeDelta& delta, int) {
		++delta;
		TimeDelta t = delta;
		return t;
	}

	TimeDelta operator -- (TimeDelta& delta) {
		--delta.delta;
		return delta;
	}

	TimeDelta operator -- (TimeDelta& delta, int) {
		--delta;
		TimeDelta t = delta;
		return t;
	}

	Date operator ++ (Date& delta);

	Date operator ++ (Date& delta, int) {
		TimeDelta t = countJND(delta);
		++t;
		return countDate(t);

	}

	Date operator -- (Date& delta);

	Date operator -- (Date& delta, int) {
		TimeDelta t = countJND(delta);
		++t;
		return countDate(t);
	}


	/*
		Меняет даты местами
	*/
	void swap(Date& lhs, Date& rhs) {
		Date t = lhs;
		lhs = rhs;
		rhs = t;
	}

	/*
		Меняет временные интервалы местами
	*/
	void swap(TimeDelta& lhs, TimeDelta& rhs) {
		TimeDelta t = {};
		rhs = lhs;
		rhs = t;
	}

	/*
		Возвращает ссылку на большую дату
	*/
	Date & max(Date & lhs, Date & rhs) {
		Date max;
		if (countJND(lhs).delta > countJND(rhs).delta) {
			max = lhs;
		}
		else {
			max = rhs;
		}
		return max;
	}

	/*
		Возвращает указатель на меньшую дату
	*/
	Date & min(Date & lhs, Date & rhs) {
		Date min;
		if (countJND(lhs).delta < countJND(rhs).delta) {
			min = lhs;
		}
		else {
			min = rhs;
		}
		return min;
	}

	/*
		Возвращает указатель на минимальную дату в переданном массиве дат
	*/
	Date & getMinDate(Date dates[], int size) {
		Date min = dates[0];
		for (int i = 0; i < size - 1; ++i) {
			for (int j = i; j < size - 1; ++j) {
				if (countJND(dates[j]).delta < countJND(min).delta) {
					min = dates[j];
				}
			}
		}
		return min;
	}

	/*
		Возвращает указатель на максимальную дату в переданном массиве дат
	*/
	Date & getMaxDate(Date dates[], int size) {
		Date max = dates[0];
		for (int i = 0; i < size - 1; ++i) {
			for (int j = i; j < size - 1; ++j) {
				if (countJND(dates[j]).delta > countJND(max).delta) {
					max = dates[j];
				}
			}
		}
		return max;
	}

	/*
		Сортирует массив дат по указанному критерию
	*/
	void sort(Date dates[], SortBy sortBy = SortBy::Date) {
		Date t;
		for (int i = 0; i < sizeof(dates) - 1; ++i) {
			for (int j = i; j < sizeof(dates) - 1; ++j) {
				if (countJND(dates[i]).delta > countJND(dates[j]).delta) {
					t = dates[j];
					dates[j] = dates[i];
					dates[i] = t;
				}
			}
		}
	}

	/*
		Проверяет может ли существовать дата с передаваемыми значениями.
		В случае успеха возвращает true, и заполняет дату по переданному адресу.
		Если дата с переданными параметрами существовать не может,
		возвращает пустой указатель.
	*/
	Date * tryFillDate(int year, int month, int day);
}