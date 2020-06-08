#pragma once
#include <iostream>
#include <string>

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
	
	TimeDelta countJND(Date date);

	Date countGk(TimeDelta delta);

	TimeDelta operator - (const TimeDelta lhs, const TimeDelta rhs);
	TimeDelta countDistance(Date from, Date to);

	void print(Month month, DateFormat format= DateFormat::MonthAsString);
	void print(Date data, DateFormat format= DateFormat::MonthAsString);
	void print(TimeDelta delta);

	Season getSeason(Month month);
	Season getSeason(Date date);

	bool operator == (const Date lhs, const Date rhs);
	bool operator != (const Date lhs, const Date rhs);
	bool operator < (const Date lhs, const Date rhs);
	bool operator > (const Date lhs, const Date rhs);
	bool operator <= (const Date lhs, const Date rhs);
	bool operator >= (const Date lhs, const Date rhs);

	TimeDelta operator + (const TimeDelta lhs, const TimeDelta rhs);
	Date operator + (const Date date, const TimeDelta delta);
	Date operator + (const TimeDelta delta, const Date date);

	TimeDelta operator * (const TimeDelta delta, int multiplier);
	TimeDelta operator * (int multiplier, const TimeDelta delta);

	/*----------homework-05----------*/

	TimeDelta operator ++ (TimeDelta& delta);
	TimeDelta operator ++ (TimeDelta& delta, int);

	TimeDelta operator -- (TimeDelta& delta);
	TimeDelta operator -- (TimeDelta& delta, int);

	Date operator ++ (Date& delta);
	Date operator ++ (Date& delta, int);

	Date operator -- (Date& delta);
	Date operator -- (Date& delta, int);

	void swap(Date& lhs, Date& rhs);

	void swap(TimeDelta& lhs, TimeDelta& rhs);

	Date& max(Date& lhs, Date& rhs);

	Date* min(Date& lhs, Date& rhs);

	
	Date* getMinDate(Date dates[], int size);

	Date* getMaxDate(Date dates[], int size);

	void sort(Date dates[], int size, SortBy sortBy = SortBy::Date);

	Date* tryFillDate(int year, int month, int day);

}
