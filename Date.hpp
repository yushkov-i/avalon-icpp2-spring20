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
	TimeDelta countJND(Date date);

	/*
		Рассчитывает количество дней между двумя датами.
		При реализвации используйте CountJND
	*/
	TimeDelta countDistance(Date from, Date to);

	void printMonthAsString(Month month) {
		switch (month) {
		case Month::January: std::cout << "January";
			break;
		case Month::February: std::cout << "February";
			break;
		case Month::March: std::cout << "March";
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
		if (format == DateFormat::MonthAsInt){
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
	void print(TimeDelta delta);

	/*
		Возвращает сезон (зима, весна, лето, осень) передаваемой даты
	*/
	Season getSeason(Date date);
	Season getSeason(Month month);

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
	Date & max(Date & lhs, Date & rsh);

	/*
		Возвращает указатель на меньшую дату
	*/
	Date & min(Date & lhs, Date & rsh);

	/*
		Возвращает указатель на минимальную дату в переданном массиве дат
	*/
	Date & getMinDate(Date dates[], int size);

	/*
		Возвращает указатель на максимальную дату в переданном массиве дат
	*/
	Date & getMaxDate(Date dates[], int size);

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
	Date * tryFillDate(int year, int month, int day);
}
