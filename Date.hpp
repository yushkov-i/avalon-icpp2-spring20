#pragma once

#include <iostream>

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
	TimeDelta countJND(Date date);

	/*
		Рассчитывает количество дней между двумя датами.
		При реализвации используйте CountJND
	*/
	TimeDelta countDistance(Date from, Date to);

	/*
		Выводит в консоль
	*/
	void print(Date data, DateFormat format = DateFormat::MonthAsInt);
	void print(Month month, DateFormat format = DateFormat::MonthAsInt)
	{
		if (format == DateFormat::MonthAsInt)
		{
			std::cout << static_cast<int>(month);
		}
		else if (format == DateFormat::MonthAsString)
		{
			switch (month)
			{
			case ext::Month::January:
				std::cout << "January";
				break;
			case ext::Month::February:
				break;
			case ext::Month::March:
				break;
			case ext::Month::April:
				break;
			case ext::Month::May:
				break;
			case ext::Month::June:
				break;
			case ext::Month::July:
				break;
			case ext::Month::August:
				break;
			case ext::Month::September:
				break;
			case ext::Month::October:
				break;
			case ext::Month::Novemver:
				break;
			case ext::Month::December:
				break;
			default:
				break;
			}
		}
	}
	void print(TimeDelta delta);

	/*
		Возвращает сезон (зима, весна, лето, осень) передаваемой даты
	*/
	Season getSeason(Month month)
	{
		switch (month)
		{
		case Month::December:
		case Month::January:
		case Month::February:
			return Season::Winter;
		case Month::March:
		case Month::April:
		case Month::May:
			return Season::Spring;
		default:
			std::cout << "unknown season" << std::endl;
			break;
		}
	}

	Season getSeason(Date date)
	{
		return getSeason(date.month);
	}

	

	/*
		Написать перегрузку для следующих логических операторов
	*/
	bool operator == (const Date lhs, const Date rhs);
	bool operator != (const Date lhs, const Date rhs);
	bool operator < (const Date lhs, const Date rhs);
	bool operator <= (const Date lhs, const Date rhs);
	bool operator > (const Date lhs, const Date rhs);
	bool operator >= (const Date lhs, const Date rhs);

	/*
		Написать перегрузку для следующих арифметических операторов
	*/
	Date operator + (const Date date, const TimeDelta delta);
	Date operator + (const TimeDelta delta, const Date date);
	TimeDelta operator + (const TimeDelta lhs, const TimeDelta rhs);

	TimeDelta operator * (const TimeDelta delta, int multiplier);
	TimeDelta operator * (int multiplier, const TimeDelta delta);	
}