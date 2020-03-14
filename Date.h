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


		/*
			Âîçâðàùàåò Þëèàíñêóþ äàòó
			https://ru.wikipedia.org/wiki/%D0%AE%D0%BB%D0%B8%D0%B0%D0%BD%D1%81%D0%BA%D0%B0%D1%8F_%D0%B4%D0%B0%D1%82%D0%B0
			ðàçäåë "Âû÷èñëåíèå íîìåðà þëèàíñêîãî äíÿ (JDN) ïî äàòå ãðèãîðèàíñêîãî êàëåíäàðÿ"
			Òåñòîâûå äàííûå					Îæèäàåìûé ðåçóëüòàò
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
		Ðàññ÷èòûâàåò êîëè÷åñòâî äíåé ìåæäó äâóìÿ äàòàìè.
		Ïðè ðåàëèçâàöèè èñïîëüçóéòå CountJND
	*/
	TimeDelta countDistance(Date from, Date to) {
		return countJND(to) - countJND(from);
	}

	/*
		Âûâîäèò â êîíñîëü
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
		Âûâîäèò â êîíñîëü
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
		Âîçâðàùàåò ñåçîí (çèìà, âåñíà, ëåòî, îñåíü) ïåðåäàâàåìîé äàòû
	*/

	Season getSeason(Month month) {
		if (static_cast<int>(month) < 3 && static_cast<int>(month) > 0 || month == Month::December) {
			return Season::Winter;
		}
		else if (static_cast<int>(month) > 2 && static_cast<int>(month) < 6) {
			return Season::Spring;
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
		Íàïèñàòü ïåðåãðóçêó äëÿ ñëåäóþùèõ ëîãè÷åñêèõ îïåðàòîðîâ
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
		Íàïèñàòü ïåðåãðóçêó äëÿ ñëåäóþùèõ àðèôìåòè÷åñêèõ îïåðàòîðîâ
	*/

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

	TimeDelta operator ++ (TimeDelta& delta);
	TimeDelta operator ++ (TimeDelta& delta, int);

	TimeDelta operator -- (TimeDelta& delta);
	TimeDelta operator -- (TimeDelta& delta, int);

	Date operator ++ (Date& delta);
	Date operator ++ (Date& delta, int);

	Date operator -- (Date& delta);
	Date operator -- (Date& delta, int);

	/*
		Ìåíÿåò äàòû ìåñòàìè
	*/
	void swap(Date& lhs, Date& rhs);

	/*
		Ìåíÿåò âðåìåííûå èíòåðâàëû ìåñòàìè
	*/
	void swap(TimeDelta& lhs, TimeDelta& rhs);

	/*
		Âîçâðàùàåò ññûëêó íà áîëüøóþ äàòó
	*/
	Date& max(Date& lhs, Date& rsh);

	/*
		Âîçâðàùàåò óêàçàòåëü íà ìåíüøóþ äàòó
	*/
	Date& min(Date& lhs, Date& rsh);

	/*
		Âîçâðàùàåò óêàçàòåëü íà ìèíèìàëüíóþ äàòó â ïåðåäàííîì ìàññèâå äàò
	*/
	Date& getMinDate(Date dates[], int size);

	/*
		Âîçâðàùàåò óêàçàòåëü íà ìàêñèìàëüíóþ äàòó â ïåðåäàííîì ìàññèâå äàò
	*/
	Date& getMaxDate(Date dates[], int size);

	/*
		Ñîðòèðóåò ìàññèâ äàò ïî óêàçàííîìó êðèòåðèþ
	*/
	void sort(Date dates[], SortBy sortBy = SortBy::Date);

	/*
		Ïðîâåðÿåò ìîæåò ëè ñóùåñòâîâàòü äàòà ñ ïåðåäàâàåìûìè çíà÷åíèÿìè.
		Â ñëó÷àå óñïåõà âîçâðàùàåò true, è çàïîëíÿåò äàòó ïî ïåðåäàííîìó àäðåñó.
		Åñëè äàòà ñ ïåðåäàííûìè ïàðàìåòðàìè ñóùåñòâîâàòü íå ìîæåò,
		âîçâðàùàåò ïóñòîé óêàçàòåëü.
	*/
	Date* tryFillDate(int year, int month, int day);
}
