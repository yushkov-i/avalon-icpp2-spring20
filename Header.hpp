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
		int a = (14 - static_cast<int>(date.month)) / 12, y = date.year + 4800 - a, m = static_cast<int>(date.month) + 12 * a - 3;
		TimeDelta JND;
		JND.delta = date.day + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045;
		return JND;
	}

	/*
		Рассчитывает количество дней между двумя датами.
		При реализвации используйте CountJND
	*/
	TimeDelta countDistance(Date from, Date to) {
		TimeDelta a, b, dist;
		a = countJND(from);
		b = countJND(to);
		dist.delta = b.delta - a.delta;
		return dist;
	}

	/*
		Выводит в консоль
	*/
	void print(Month month, DateFormat format = DateFormat::MonthAsInt) {
		if (format == DateFormat::MonthAsInt) {
			std::cout << static_cast<int>(month);
		}
		else if (format == DateFormat::MonthAsString) {
			switch (month) {
			case Month::January:
				std::cout << "january";
				break;
			case Month::February:
				std::cout << "february";
				break;
			case Month::March:
				std::cout << "march";
				break;
			case Month::April:
				std::cout << "april";
				break;
			case Month::May:
				std::cout << "may";
				break;
			case Month::June:
				std::cout << "june";
				break;
			case Month::July:
				std::cout << "july";
				break;
			case Month::August:
				std::cout << "august";
				break;
			case Month::September:
				std::cout << "september";
				break;
			case Month::October:
				std::cout << "october";
				break;
			case Month::December:
				std::cout << "december";
				break;
			case Month::Novemver:
				std::cout << "november";
				break;
			default:
				std::cout << "unknown month";
				break;
			}
		}
		else
		{
			std::cout << "Wrong format!";
		}
	}

	void print(Date data, DateFormat format = DateFormat::MonthAsInt) {
		std::cout << data.day << " ";
		print(data.month, format);
		std::cout << " " << data.year;
	}
	void print(TimeDelta delta) {
		std::cout << delta.delta << std::endl;
	}

	/*
		Возвращает сезон (зима, весна, лето, осень) передаваемой даты
	*/

	Season getSeason(Month month) {
		if ((static_cast<int>(month) <= 2) || (static_cast<int>(month) == 12)) {
			return Season::Winter;
		}
		if (static_cast<int>(month) <= 5) {
			return Season::Spring;
		}
		if (static_cast<int>(month) <= 8) {
			return Season::Summer;
		}
		if (static_cast<int>(month) <= 11) {
			return Season::Autumn;
		}
	}
	
	Season getSeason(Date date) {
		return getSeason(date.month);		
	} 
	

	/*
		Написать перегрузку для следующих логических операторов
	*/
    bool operator == (const Date lhs, const Date rhs) {
		return lhs.year == rhs.year 
			&& lhs.month == rhs.month 
			&& lhs.day == rhs.day;

		
		if (lhs.year == rhs.year) {
			if ((static_cast<int>(lhs.month) == (static_cast<int>(rhs.month)))) {
				if (lhs.day == rhs.day) {
					return true;
				}
				else {
					return false;
				}
			}
			else {
				return 0;
			}
		}
		else {
			return 0;
		}
	}
	bool operator != (const Date lhs, const Date rhs) {	
		if (!(lhs == rhs)) {
			return 1;
		}
		else {
			return 0;
		}
	}
	bool operator < (const Date lhs, const Date rhs) {
		if (lhs.year < rhs.year) {
			if ((static_cast<int>(lhs.month) < (static_cast<int>(rhs.month)))) {
				if (lhs.day < rhs.day) {
					return 1;
				}
				else {
					return 0;
				}
			}
			else {
				return 0;
			}
		}
		else {
			return 0;
		}
	}
	bool operator <= (const Date lhs, const Date rhs) {
		if (lhs.year <= rhs.year) {
			if ((static_cast<int>(lhs.month) <= (static_cast<int>(rhs.month)))) {
				if (lhs.day <= rhs.day) {
					return 1;
				}
				else {
					return 0;
				}
			}
			else {
				return 0;
			}
		}
		else {
			return 0;
		}
	}
	bool operator > (const Date lhs, const Date rhs) {
		if (!(lhs <= rhs)) {
			return 1;
		}
		else {
			return 0;
		}
	}
	bool operator >= (const Date lhs, const Date rhs) {
		if (!(lhs < rhs)) {
			return 1;
		}
		else {
			return 0;
		}
	} 

	Date countGrig(TimeDelta delta) {
		int a = delta.delta + 32044,
		b = (4 * a + 3) / 146097,
		c = a - (146097 * b) / 4,
		d = (4 * c + 3) / 1461,
		e = c - (1461 * d) / 4,
		m = (5 * e + 2) / 153;
		Date x{};
		x.day = e - (153 * m + 2) / 5 + 1;
		x.month = static_cast<Month>(m + 3 - 12 * (m / 10));
		x.year = 100 * b + d - 4800 + m / 10;
		return x;
	}
	/*
		Написать перегрузку для следующих арифметических операторов
	*/
	Date operator + (const Date date, const TimeDelta delta) {
		TimeDelta j_year = countJND(date);
		j_year.delta += delta.delta;
		return countGrig(j_year);
	}

	Date operator + (const TimeDelta delta, const Date date) {
		return date + delta;
	}

	TimeDelta operator + (const TimeDelta lhs, const TimeDelta rhs) {
		return TimeDelta{ lhs.delta + rhs.delta };
	} 

	TimeDelta operator * (const TimeDelta delta, int multiplier) {
		TimeDelta num = delta;
		num.delta *= multiplier;
		return num;
	}
	TimeDelta operator * (int multiplier, const TimeDelta delta) {
		return delta * multiplier;
	}
	/*----------homework-05----------*/

	TimeDelta operator ++ (TimeDelta& delta) {
		TimeDelta x = delta;
		x.delta++;
		return x;
	}

	TimeDelta operator ++ (TimeDelta& delta, int);

	TimeDelta operator -- (TimeDelta& delta) {
		TimeDelta x = delta;
		x.delta--;
		return x;
	}
	TimeDelta operator -- (TimeDelta& delta, int);

	Date operator ++ (Date& delta);
	Date operator ++ (Date& delta, int);

	Date operator -- (Date& delta);
	Date operator -- (Date& delta, int);

	/*
		Меняет даты местами
	*/
	void swap(Date& lhs, Date& rhs) {
		Date tmp;
		tmp = lhs;
		lhs = rhs;
		rhs = tmp;
	}

	/*
		Меняет временные интервалы местами
	*/
	void swap(TimeDelta& lhs, TimeDelta& rhs) {
		TimeDelta tmp;
		tmp = lhs;
		lhs = rhs;
		rhs = tmp;
	}

	/*
		Возвращает ссылку на большую дату
	*/
	Date& max(Date& lhs, Date& rhs) {
		if (lhs > rhs) {
			Date& tmp = lhs;
			return tmp;
		}
		else {
			Date& tmp = rhs;
			return tmp;
		}
	}

	/*
		Возвращает ссылку на меньшую дату
	*/
	Date& min(Date& lhs, Date& rhs) {
		if (lhs < rhs) {
			Date& tmp = lhs;
			return tmp;
		}
		else {
			Date& tmp = rhs;
			return tmp;
		}
	}

	/*
		Возвращает ссылку на минимальную дату в переданном массиве дат
	*/
	Date& getMinDate(Date dates[], int size) {
		Date tmp = dates[0];
		for (int i = 1; i < size; i++) {
			if (tmp > dates[i]) {
				tmp = dates[i];
			}
		}
		Date& tm = tmp;
		return tm;
	}

	/*
		Возвращает ссылку на максимальную дату в переданном массиве дат
	*/
	Date& getMaxDate(Date dates[], int size) {
		Date tmp = dates[0];
		for (int i = 1; i < size; i++) {
			if (tmp < dates[i]) {
				tmp = dates[i];
			}
		}
		Date& tm = tmp;
		return tm;
	}

	/*
		Сортирует массив дат
	*/
	void sort(Date dates[], int size) {
		Date tmp{};
		int u = size - 1;
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
	}
}