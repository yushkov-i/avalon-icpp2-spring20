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

	Date countGR(TimeDelta a) {
		TimeDelta b, c, d, e, m;
		a.delta = a.delta + 32044;
		b.delta = (4 * a.delta + 3) / 146097;
		c.delta = a.delta - (146097 * b.delta) / 4;
		d.delta = (4 * c.delta + 3) / 1461;
		e.delta = c.delta - (1461 * d.delta) / 4;
		m.delta = (5 * e.delta + 2) / 153;
		Date res;
		res.day = e.delta - (153 * m.delta + 2) / 5 + 1;
		res.month = static_cast<Month>(m.delta + 3 - 12 * (m.delta / 10));
		res.year = 100 * b.delta + d.delta - 4800 + m.delta / 10;
		return res;
	}
	TimeDelta operator - (const TimeDelta lhs, const TimeDelta rhs);
	TimeDelta operator + (const TimeDelta lhs, const TimeDelta rhs);
	TimeDelta operator * (const TimeDelta delta, int multiplier);
	TimeDelta operator * (int multiplierconst, TimeDelta delta);
	TimeDelta countJND(Date date) {
		TimeDelta res;
		int a = (14 - static_cast<int>(date.month)) / 12;
		int y = date.year + 4800 - a;
		int m = static_cast<int>(date.month) + 12 * a - 3;
		res.delta = (date.day + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045);
		return res;
	}
	TimeDelta countDistance(Date from, Date to) {
		TimeDelta a, b, c;
		a = countJND(to);
		b = countJND(from);
		c.delta = abs(a.delta - b.delta);
		return c;
	}
	void PrintSeasonAsString(Season season) {
		switch (season) {
		case Season::Winter: std::cout << "Winter";
			break;
		case Season::Spring: std::cout << "Spring";
			break;
		case Season::Summer: std::cout << "Summer";
			break;
		case Season::Autumn: std::cout << "Autumn";
			break;
		default: std::cout << "wrong month!";
			break;
		}
	}
	void printMonthAsString(Month month) {
		switch (month) {
		case Month::January: std::cout << "January";
			break;
		case Month::February: std::cout << "February";
			break;
		case Month::March: std::cout << "March";
			break;
		case Month::April: std::cout << "April";
			break;
		case Month::May: std::cout << "May";
			break;
		case Month::June: std::cout << "June";
			break;
		case Month::July: std::cout << "July";
			break;
		case Month::August: std::cout << "August";
			break;
		case Month::September: std::cout << "September";
			break;
		case Month::October: std::cout << "October";
			break;
		case Month::November: std::cout << "November";
			break;
		case Month::December: std::cout << "December";
			break;
		default: std::cout << "unknown month";
			break;
		}
	}
	void print(Date data, DateFormat format = DateFormat::MonthAsInt) {
		std::cout << data.day;
		if (format == DateFormat::MonthAsInt) {
			std::cout << "."
				<< static_cast<int>(data.month)
				<< "." << data.year << std::endl;
		}
		else if (format == DateFormat::MonthAsString) {
			std::cout << " ";
			printMonthAsString(data.month);
			std::cout << " " << data.year << std::endl;
		}
		else {
			std::cout << "wrong format!";
		}
	}
	void print(Month month, DateFormat format = DateFormat::MonthAsInt) {

		if (format == DateFormat::MonthAsInt) {
			std::cout << static_cast<int>(month);
		}
		else if (format == DateFormat::MonthAsString) {
			printMonthAsString(month);
		}
	}
	void print(TimeDelta delta) {
		std::cout << delta.delta;
	}
	Season getSeason(Month month) {
		if (static_cast<int>(month) < 3 && static_cast<int>(month) > 0 || month == Month::December) {
			return Season::Winter;
		}
		else if (static_cast<int>(month) > 2 && static_cast<int>(month) < 6) {
			return Season::Spring;
		}
		else if (static_cast<int>(month) > 5 && static_cast<int>(month) < 9) {
			return Season::Summer;
		}
		else return Season::Autumn;
	}

	Season getSeason(Date date) {
		return getSeason(date.month);
	}
	bool operator == (const Date lhs, const Date rhs) {
		return (lhs.year == rhs.year && lhs.month == rhs.month && lhs.day == rhs.day);
	}
	bool operator != (const Date lhs, const Date rhs) {
		return !(lhs == rhs);
	}
	bool operator < (const Date lhs, const Date rhs) {
		return(lhs.year < rhs.year || lhs.year == rhs.year && lhs.month < rhs.month ||
			lhs.year == rhs.year && lhs.month == rhs.month && lhs.day < rhs.day);
	}
	bool operator <= (const Date lhs, const Date rhs) {
		return (lhs < rhs || lhs == rhs);
	}
	bool operator > (const Date lhs, const Date rhs) {
		return !(lhs <= rhs);
	}
	bool operator >= (const Date lhs, const Date rhs) {
		return !(lhs < rhs);
	}
	Date operator + (const Date date, const TimeDelta delta) {
		TimeDelta a = countJND(date);
		a = a + delta;
		return countGR(a);
	}
	Date operator + (const TimeDelta delta, const Date date) {
		return date + delta;
	}
	TimeDelta operator + (const TimeDelta lhs, const TimeDelta rhs) {
		TimeDelta res;
		res.delta = lhs.delta + rhs.delta;
		return res;
	}
	TimeDelta operator - (const TimeDelta lhs, const TimeDelta rhs) {
		TimeDelta res;
		res.delta = lhs.delta - rhs.delta;
		return res;
	}



	TimeDelta operator * (const TimeDelta delta, int multiplier)
	{
		TimeDelta res;
		res.delta = delta.delta * multiplier;
		return res;
	}
	TimeDelta operator * (int multiplier, const TimeDelta delta) {
		return delta * multiplier;
	}
	/*----------homework-05----------*/

	TimeDelta operator ++ (TimeDelta& delta)
	{
		TimeDelta tmp;
		tmp.delta = 1;
		return tmp + delta;
	}
	TimeDelta operator ++ (TimeDelta& delta, int) { TimeDelta tmp = delta; delta++; return tmp; };

	TimeDelta operator -- (TimeDelta& delta) { TimeDelta tmp; tmp.delta = -1; return delta + tmp; };
	TimeDelta operator -- (TimeDelta& delta, int) { TimeDelta tmp; tmp = delta; delta--; return tmp; };

	Date operator ++ (Date& delta) { TimeDelta tmp; tmp.delta = 1; delta = delta + tmp; return delta; };
	Date operator ++ (Date& delta, int) { Date tmp = delta; delta++; return tmp; };

	Date operator -- (Date& delta) { TimeDelta tmp; tmp.delta = -1; delta = delta + tmp; return delta; };
	Date operator -- (Date& delta, int) { Date tmp = delta; delta--; return tmp; };

	/*
		Меняет даты местами
	*/
	void swap(Date& lhs, Date& rhs) { Date tmp = lhs; lhs = rhs; rhs = tmp;};

	/*
		Меняет временные интервалы местами
	*/
	void swap(TimeDelta& lhs, TimeDelta& rhs) { TimeDelta tmp = lhs; lhs = rhs; rhs = tmp;};

	/*
		Возвращает ссылку на большую дату
	*/
	Date& max(Date& lhs, Date& rsh) { Date tmp; if (lhs > rsh){tmp = lhs; }else { tmp = rsh; } return tmp;};

	/*
		Возвращает ссылку на меньшую дату
	*/
	Date& min(Date& lhs, Date& rsh) {
		Date tmp; if (lhs > rsh) { tmp = rsh; }
		else { tmp = lhs; } return tmp;
	
	};

	/*
		Возвращает ссылку на минимальную дату в переданном массиве дат
	*/
	Date& getMinDate(Date dates[], int size) { Date tmp=dates[0]; for (int i = 1; i < size; i++) {
		if (tmp > dates[i]) {
			tmp = dates[i];
		}
	}
	return tmp;
	};

	/*
		Возвращает ссылку на максимальную дату в переданном массиве дат
	*/
	Date& getMaxDate(Date dates[], int size) { Date tmp = dates[0]; for (int i = 1; i < size; i++) {
		if (tmp < dates[i]) {
			tmp = dates[i];
		}
	}
	return tmp;
	};

	/*
		Сортирует массив дат
	*/
	void sort(Date dates[], int size) { date tmp; int u = size - 1;
	bool k = 0;
	while (k == 0) {
		k = 1;
		for (int i = 0; i < u; i++) {
			if (dates[i] > dates[i + 1]) {
				tmp = dates[i];
				dates[i] = dates[i + 1];
				dates[i + 1] = tmp;
				k = 0;
			}
		}
		if (k == 0) {
			u--;
		}
	}
	};
	Date* tryFillDate(int year, int month, int day)
	{
		bool o = false;
		Date* data{ 0, Month::January, 0 };


		if (year >= 2020)
		{
			if (month % 2 == 1 && month < 8)
			{
				if (day <= 31 && day > 0) o = true;
			}
			else if (month % 2 == 0 && month < 8)
			{
				if (day <= 30 && day > 0) o = true;
			}
			else if (month == 2) if (day <= 28 && day > 0) o = true;
		}

		if (exist)
		{
			cout << "True";
			data->day = day;
			data->month = static_cast<Month>(month);
			data->year = year;
		}
		else cout << "False";

		data = nullptr;
		return data;
	}
}
