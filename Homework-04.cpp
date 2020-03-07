#pragma once

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
		Primer.delta = First.delta + Second.delta;
		return Primer;
	};

	/*
		Выводит в консоль
	*/
	void print(Date data, DateFormat format = DateFormat::MonthAsInt){


	};
	void print(Month month, DateFormat format = DateFormat::MonthAsInt);

	void print(TimeDelta delta);

	/*
		Возвращает сезон (зима, весна, лето, осень) передаваемой даты
	*/
	Season getSeason(Date date);
	Season getSeason(Month month);

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
	bool operator <= (const Date lhs, const Date rhs){
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

	/*
		Написать перегрузку для следующих арифметических операторов
	*/
	Date operator + (const Date date, const TimeDelta delta) {
		Date Primer;
		Primer.day = date.day + delta.delta;
		Primer.month = date.month;
		Primer.year = date.year;
		return Primer;
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