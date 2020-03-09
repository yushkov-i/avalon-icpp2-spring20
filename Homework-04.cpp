#pragma once
#include <iostream>
#include <cmath>
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
		Novemver,
		December
	};

	enum class DateFormat
	{
		MonthAsInt,
		MonthAsString
	};

	enum class Season
	{
		Winter,
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
		int A, Y, M, JDN = 0;
		A = (14 - static_cast<int>(date.month)) / 12;
		Y = date.year + 4800 - A;
		M = static_cast<int>(date.month) + 12 * A - 3;
		JDN = date.day + (153 * M + 2) / 5 + 365 * Y + Y / 4 - Y / 100 + Y / 400 - 32045;
		TimeDelta Primer;
		Primer.delta = JDN;
		return Primer;
	};

	/*
		Рассчитывает количество дней между двумя датами.
		При реализвации используйте CountJND
	*/
	TimeDelta countDistance(Date from, Date to) {
		TimeDelta Primer, First, Second;
		First = countJND(from);
		Second = countJND(to);
		Primer.delta = abs(First.delta - Second.delta);
		return Primer;
	};

	/*
		Выводит в консоль
	*/
	void print(Date data, DateFormat format = DateFormat::MonthAsInt) {
		std::cout << data.day << " ";
		print(data.month, format);
		std::cout << " " << data.year;
	};
	void print(Month month, DateFormat format = DateFormat::MonthAsInt) {
		if (format == DateFormat::MonthAsInt) {
			std::cout << static_cast<int>(month);
		}
		else if (format == DateFormat::MonthAsString) {
			switch (month)
			{
			case Month::January:
				std::cout << "January";
				break;
			case Month::February:
				std::cout << "February";
				break;
			case Month::March:
				std::cout << "March";
				break;
			case Month::April:
				std::cout << "April";
				break;
			case Month::May:
				std::cout << "May";
				break;
			case Month::June:
				std::cout << "June";
				break;
			case Month::July:
				std::cout << "July";
				break;
			case Month::August:
				std::cout << "August";
				break;
			case Month::September:
				std::cout << "September";
				break;
			case Month::October:
				std::cout << "October";
				break;
			case Month::Novemver:
				std::cout << "Novemver";
				break;
			case Month::December:
				std::cout << "December";
				break;
			default:
				std::cout << "Not found month.";
				break;
			}
		}
		else {
			std::cout << "Not found format.";
		}
	};

	void print(TimeDelta delta) {
		std::cout << delta.delta;
	};

	/*
		Возвращает сезон (зима, весна, лето, осень) передаваемой даты
	*/
	Season getSeason(Date date) {
		return getSeason(date.month);
	};

	Season getSeason(Month month) {
		if (static_cast<int>(month) == 12 || static_cast<int>(month) == 1 || static_cast<int>(month) == 2) {
			return Season::Winter;
		}
		else if (static_cast<int>(month) == 3 || static_cast<int>(month) == 4 || static_cast<int>(month) == 5) {
			return Season::Spring;
		}
		else if (static_cast<int>(month) == 6 || static_cast<int>(month) == 7 || static_cast<int>(month) == 8) {
			return Season::Summer;
		}
		else if (static_cast<int>(month) == 9 || static_cast<int>(month) == 10 || static_cast<int>(month) == 11) {
			return Season::Autumn;
		}
	};

	/*
		Написать перегрузку для следующих логических операторов
	*/
	bool operator == (const Date lhs, const Date rhs) {
		if (lhs.day == rhs.day && lhs.month == rhs.month && lhs.year == rhs.year) {
			return 1;
		}
		else return 0;
	};
	bool operator != (const Date lhs, const Date rhs) {
		return !(lhs == rhs);
	};
	bool operator < (const Date lhs, const Date rhs) {
		if (lhs.year < rhs.year) {
			return 1;
		}
		else if (lhs.year == rhs.year && lhs.month < rhs.month) {
			return 1;
		}
		else if (lhs.year == rhs.year && lhs.month == rhs.month && lhs.day < rhs.day) {
			return 1;
		}
		else return 0;
	};
	bool operator <= (const Date lhs, const Date rhs) {
		return (lhs == rhs) || (lhs < rhs);
	};
	bool operator > (const Date lhs, const Date rhs) {
		if (lhs.year > rhs.year) {
			return 1;
		}
		else if (lhs.year == rhs.year && lhs.month > rhs.month) {
			return 1;
		}
		else if (lhs.year == rhs.year && lhs.month == rhs.month && lhs.day > rhs.day) {
			return 1;
		}
		else return 0;
	};
	bool operator >= (const Date lhs, const Date rhs) {
		return (lhs == rhs) || (lhs > rhs);
	};

	Date obratno_v_date(TimeDelta delta) {
		int a, b, c, d, e, m;
		Date Primer;
		a = delta.delta + 32044;
		b = (4 * a + 3) / 146097;
		c = a - (146097 * b) / 4;
		d = (4 * c + 3) / 1461;
		e = c - (1461 * d) / 4;
		m = (5 * e + 2) / 153;
		Primer.day = e - (153 * m + 2) / 5 + 1;
		Primer.month = static_cast<Month>(m + 3 - 12 * (m / 10));
		Primer.year = 100 * b + d - 4800 + m / 10;
		return Primer;
	};

	/*
		Написать перегрузку для следующих арифметических операторов
	*/
	Date operator + (const Date date, const TimeDelta delta) {
		Date Primer;
		TimeDelta TimePrimer;
		TimePrimer = countJND(date);
		TimePrimer.delta = TimePrimer.delta + delta.delta;
		return obratno_v_date(TimePrimer);
	};

	Date operator + (const TimeDelta delta, const Date date) {
		return date + delta;
	};

	TimeDelta operator + (const TimeDelta lhs, const TimeDelta rhs) {
		TimeDelta Primer;
		Primer.delta = lhs.delta + lhs.delta;
		return Primer;
	};

	TimeDelta operator * (const TimeDelta delta, int multiplier) {
		TimeDelta Primer;
		Primer.delta = delta.delta * multiplier;
		return Primer;
	};
	TimeDelta operator * (int multiplier, const TimeDelta delta) {
		return delta * multiplier;
	};
}