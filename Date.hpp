#pragma once
#include<math.h>
using namespace std;
namespace ext
{
	enum class Month
	{
		January = 1,
		February = 2,
		March = 3,
		April = 4,
		May = 5,
		June = 6,
		July = 7,
		August = 8,
		September = 9,
		October = 10,
		Novemver = 11,
		December = 12
	};

	enum class DateFormat
	{
		MonthAsInt,
		MonthAsString
	};

	enum class Season
	{
		Winter = 1,
		Spring = 2,
		Summer = 3,
		Autumn = 4
	};

	enum class SortBy
	{
		Date,
		Season
	};

	struct Date
	{
		int year;
		int month;
		int day;
	};

	struct TimeDelta
	{
		int delta;
	};

	TimeDelta countJND(Date date) {
		int a, y, m;
		TimeDelta jdn;
		a = (14 - date.month) / 12;
		y = date.year + 4800 - a;
		m = date.month + 12 * a - 3;
		jdn.delta = date.day + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045;
		return jdn;
	};

	TimeDelta countDistance(Date from, Date to) {
		TimeDelta Distance;
		Distance.delta = countJND(to).delta - countJND(from).delta;
		return Distance;
	};

	void print(Date data, DateFormat format = DateFormat::MonthAsInt) {
		cout << data.day << " ";
		cout << data.month;
		cout << " " << data.year;
	};

	void print(Month month, DateFormat format = DateFormat::MonthAsInt) {
		if (format == DateFormat::MonthAsString) {
			switch (month)
			{
			case Month::January:
				std::cout << "January";
				break;
			case Month::February:
				std::cout << "February";
				break;
			case Month::April:
				std::cout << "April";
				break;
			case Month::March:
				std::cout << "March";
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
			}
		}
		else if (format == DateFormat::MonthAsInt) {
			cout << static_cast<int>(month);
		}
		else {
			cout << "error";
		}
	};

	void print(TimeDelta delta) {
		cout << delta.delta;
	};

	Season getSeason(Month month) {
		Season season;
		switch (static_cast<int>(month))
		{
		case 1:
		case 2:
		case 12:
			season = static_cast<Season>(1);
			break;
		case 3:
		case 4:
		case 5:
			season = static_cast<Season>(2);
			break;
		case 6:
		case 7:
		case 8:
			season = static_cast<Season>(3);
			break;
		case 9:
		case 10:
		case 11:
			season = static_cast<Season>(4);
			break;

		}
		return season;
	};

	Season getSeason(Date date) {
		return getSeason(static_cast<Month>(date.month));
	};

	bool operator == (const Date lhs, const Date rhs)
	{
		return lhs.day == rhs.day && lhs.month == rhs.month && rhs.year == lhs.year;
	}

	bool operator != (const Date lhs, const Date rhs) {
		return !(lhs == rhs);
	}

	bool operator < (const Date lhs, const Date rhs) {
		return lhs.day < rhs.day&& lhs.month <rhs.month&& rhs.year> lhs.year;
	}

	bool operator <= (const Date lhs, const Date rhs)
	{
		return lhs.day <= rhs.day && lhs.month <= rhs.month && lhs.year <= rhs.year;
	}

	bool operator > (const Date lhs, const Date rhs)
	{
		return!(lhs < rhs);
	}

	bool operator >= (const Date lhs, const Date rhs) {
		return !(lhs <= rhs);
	}


	Date JNDToDate(const TimeDelta delta)
	{
		int a, b, c, d, e, m;
		a = delta.delta + 32044;
		b = (4 * a + 3) / 146097;
		c = a - (146097 * b) / 4;
		d = (4 * c + 3) / 1461;
		e = c - (1461 * d) / 4;
		m = (5 * e + 2) / 153;
		Date date;
		date.day = e - (153 * m + 2) / 5 + 1;
		date.month = m + 3 - 12 * (m / 10);
		date.year = 100 * b + d - 4800 + m / 10;
		return date;
	}
	
	Date operator + (const Date date, const TimeDelta delta)
	{
		TimeDelta JDN = countJND(date) + delta;
		return JNDToDate(JDN);
	}

	Date operator + (const TimeDelta delta, const Date date)
	{
		return date + delta;
	}

	TimeDelta operator + (const TimeDelta lhs, const TimeDelta rhs)
	{
		TimeDelta result;
		result.delta = lhs.delta + rhs.delta;
		return result;
	}

	TimeDelta operator * (const TimeDelta delta, int multiplier)
	{
		TimeDelta result;
		result.delta = delta.delta * multiplier;
		return result;
	}

	TimeDelta operator * (int multiplier, const TimeDelta delta)
	{
		return delta * multiplier;
	}
}