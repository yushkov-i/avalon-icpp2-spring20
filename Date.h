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

	/*
		Рассчитывает количество дней между двумя датами.
		При реализвации используйте CountJND
	*/
	TimeDelta countDistance(Date from, Date to) {
		TimeDelta a = countJND(to);
		TimeDelta b = countJND(from);
		TimeDelta c = a - b;
		return c;
	}

	/*
		Выводит в консоль
	*/
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
	/*
		Выводит в консоль
	*/
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

	/*
		Возвращает сезон (зима, весна, лето, осень) передаваемой даты
	*/
	
	Season getSeason(Month month) {
		if (static_cast<int>(month) < 3 && static_cast<int>(month) > 0 || static_cast<int>(month) == 12) {
			return static_cast<Season>(0);
		}
		else if (static_cast<int>(month) > 2 && static_cast<int>(month) < 6) {
			return static_cast<Season>(1);
		}
		else if (static_cast<int>(month) > 5 && static_cast<int>(month) < 9) {
			return static_cast<Season>(2);
		}
		else if (static_cast<int>(month) > 8 && static_cast<int>(month) < 12) {
			return static_cast<Season>(3);
		}
	}
	Season getSeason(Date date) {
		return getSeason(date.month);
	}

	/*
		Написать перегрузку для следующих логических операторов
	*/
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

	/*
		Написать перегрузку для следующих арифметических операторов
	*/
	Date operator + (const Date date, const TimeDelta delta) {
		TimeDelta a, b, c, d, e, m;
		a = countJND(date);

		a.delta = a.delta + 32044 + delta.delta;
		b.delta = (4 * a.delta + 3) / 146097;
		c.delta = a.delta - (146097 * b.delta) / 4;
		d.delta = (4 * c.delta + 3) / 1461;
		e.delta = c.delta - (1461 * d.delta) / 4;
		m.delta = (5 * e.delta + 2) / 153;

		Date res;
		res.day = e.delta - (153 * m.delta + 2) / 5 + 1;
		int temp = m.delta + 3 - 12 * (m.delta / 10);
		res.month = static_cast<Month>(m.delta + 3 - 12 * (m.delta / 10));
		//res.month = Month::January;
		res.year = 100 * b.delta + d.delta - 4800 + m.delta / 10;
		return res;
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

	TimeDelta operator ++ (TimeDelta& delta);
	TimeDelta operator ++ (TimeDelta& delta, int);

	TimeDelta operator -- (TimeDelta& delta);
	TimeDelta operator -- (TimeDelta& delta, int);

	Date operator ++ (Date& delta);
	Date operator ++ (Date& delta, int);

	Date operator -- (Date& delta);
	Date operator -- (Date& delta, int);

	/*
		Меняет даты местами
	*/
	void swap(Date& lhs, Date& rhs);

	/*
		Меняет временные интервалы местами
	*/
	void swap(TimeDelta& lhs, TimeDelta& rhs);

	/*
		Возвращает ссылку на большую дату
	*/
	Date& max(Date& lhs, Date& rsh);

	/*
		Возвращает указатель на меньшую дату
	*/
	Date& min(Date& lhs, Date& rsh);

	/*
		Возвращает указатель на минимальную дату в переданном массиве дат
	*/
	Date& getMinDate(Date dates[], int size);

	/*
		Возвращает указатель на максимальную дату в переданном массиве дат
	*/
	Date& getMaxDate(Date dates[], int size);

	/*
		Сортирует массив дат по указанному критерию
	*/
	void sort(Date dates[], SortBy sortBy = SortBy::Date);

	/*
		Проверяет может ли существовать дата с передаваемыми значениями.
		В случае успеха возвращает true, и заполняет дату по переданному адресу.
		Если дата с переданными параметрами существовать не может,
		возвращает пустой указатель.
	*/
	Date* tryFillDate(int year, int month, int day);
}