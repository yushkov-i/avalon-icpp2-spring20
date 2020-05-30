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
			Âîçâðàùàåò Þëèàíñêóþ äàòó
			https://ru.wikipedia.org/wiki/%D0%AE%D0%BB%D0%B8%D0%B0%D0%BD%D1%81%D0%BA%D0%B0%D1%8F_%D0%B4%D0%B0%D1%82%D0%B0
			ðàçäåë "Âû÷èñëåíèå íîìåðà þëèàíñêîãî äíÿ (JDN) ïî äàòå ãðèãîðèàíñêîãî êàëåíäàðÿ"
			Òåñòîâûå äàííûå					Îæèäàåìûé ðåçóëüòàò
			1.12.2018					2458454
			1.1.2018					2458120
			1.6.2000					2451697
			21.12.2012					2456283
		*/
	TimeDelta countJND(Date date) {
		int ans;
		int years;
		date.year = date.year - 1;
		ans = 1721426;
		years = date.year - ((date.year / 4) - date.year / 400);
		ans -= 11;
		ans += years * 365;
		if (years * 4 == date.year) {
			ans++;
		}
		ans += (date.year - years) * 366;
		for (int i = 1; i < static_cast<int>(date.month); i++) {
			switch (i) {
			case 1: {
				ans += 31;
				break; };
			case 3: {
				ans += 31;
				break; };
			case 5: {
				ans += 31;
				break; };
			case 7: {
				ans += 31;
				break; };
			case 8: {
				ans += 31;
				break; };
			case 10: {
				ans += 31;
				break; };
			case 12: {
				ans += 31;
				break; };

			case 2: {ans += 28;
				break; }
			default: {
				ans += 30;
				break; }

			}
		}
		ans += date.day;

		return TimeDelta{ ans };
	};

	/*
		Ðàññ÷èòûâàåò êîëè÷åñòâî äíåé ìåæäó äâóìÿ äàòàìè.
		Ïðè ðåàëèçâàöèè èñïîëüçóéòå CountJND
	*/
	TimeDelta countDistance(Date from, Date to) {
		int fr, top;
		fr = countJND(from).delta;
		top = countJND(to).delta;
		TimeDelta ret;
		ret.delta = top - fr;
		return ret;
	};

	/*
		Âûâîäèò â êîíñîëü
	*/
	void print(Date data, DateFormat format = DateFormat::MonthAsInt) {
		if (format == DateFormat::MonthAsInt) {
			std::cout << data.day << "." << int(data.month) << "." << data.year;
		}
		else {
			std::cout << data.day << " ";
			switch (int(data.month)) {
			case(1): {
				std::cout << "Jaunary";
				break;
			}
			case 2: {
				std::cout << "February";
				break;
			}
			case 3: {
				std::cout << "March";
				break;
			}
			case 4: {
				std::cout << "April";
				break;
			}
			case 5: {

				std::cout << "May";
				break;
			}
			case 6: {
				std::cout << "June";
				break;
			}
			case 7: {
				std::cout << "JUlie";
				break;
			}
			case 8: {
				std::cout << "August";
				break;
			}
			case 9: {
				std::cout << "September";
				break;
			}
			case 10: {
				std::cout << "Octobre";
				break;
			}
			case 11: {
				std::cout << "Novembre";
				break;
			}
			case 12: {
				std::cout << "Novembre";
				break;
			}
			}
			std::cout << data.day;

		}
	};
	void print(Month month, DateFormat format = DateFormat::MonthAsInt) {
		std::cout << int(month);
	};
	void print(TimeDelta delta) {
		std::cout << int(delta.delta);
	};

	/*
		Âîçâðàùàåò ñåçîí (çèìà, âåñíà, ëåòî, îñåíü) ïåðåäàâàåìîé äàòû
	*/
	Season getSeason(Month month) {
		int inp;
		inp = int(month);
		if (inp < 3 || inp == 12) {
			return Season::Winter;
		}
		else if (inp < 7) {
			return Season::Spring;
		}
		else if (inp < 9) {
			return Season::Summer;
		}
		else if (inp < 12) {
			return Season::Autumn;
		}
	};



	Season getSeason(Date date) {
		return getSeason(date.month);
	};

	/*
		Íàïèñàòü ïåðåãðóçêó äëÿ ñëåäóþùèõ ëîãè÷åñêèõ îïåðàòîðîâ
	*/
	bool operator == (const Date lhs, const Date rhs) {
		return lhs.year == rhs.year
			&& lhs.month == rhs.month
			&& lhs.day == rhs.day;
	};
	bool operator != (const Date lhs, const Date rhs) {
		return !(lhs == rhs);
	};

	bool operator < (const Date lhs, const Date rhs) {
		bool flag = true;
		flag = lhs.year < rhs.year;
		if (flag) {
			flag = int(lhs.month) < int(rhs.month);
			if (flag) {
				flag = lhs.day < rhs.day;
			}
		}
		return flag;
	};;
	bool operator <= (const Date lhs, const Date rhs)
	{
		bool flag = true;
		flag = lhs.year <= rhs.year;
		if (flag) {
			flag = int(lhs.month) <= int(rhs.month);
			if (flag) {
				flag = lhs.day <= rhs.day;
			}
		}
		return flag;
	};;
	bool operator > (const Date lhs, const Date rhs) {
		bool flag = true;
		flag = lhs.year > rhs.year;
		if (flag) {
			flag = int(lhs.month) > int(rhs.month);
			if (flag) {
				flag = lhs.day > rhs.day;
			}
		}
		return flag;
	};
	bool operator >= (const Date lhs, const Date rhs) {
		bool flag = true;
		flag = lhs.year >= rhs.year;
		if (flag) {
			flag = int(lhs.month) >= int(rhs.month);
			if (flag) {
				flag = lhs.day >= rhs.day;
			}
		}
		return flag;
	};;

	TimeDelta operator + (const TimeDelta lhs, const TimeDelta rhs) {
		TimeDelta ret;
		ret.delta = lhs.delta + rhs.delta;
		return ret;
	};

	TimeDelta operator * (const TimeDelta delta, int multiplier) {
		TimeDelta ret;
		ret.delta = delta.delta * multiplier;
		return ret;
	};
	TimeDelta operator * (int multiplier, const TimeDelta delta) {
		TimeDelta ret;
		ret.delta = delta.delta * multiplier;
		return ret;
	};

	/*
		Íàïèñàòü ïåðåãðóçêó äëÿ ñëåäóþùèõ àðèôìåòè÷åñêèõ îïåðàòîðîâ
	*/
	Date JNDToDate(TimeDelta inpT) {
		int a, b, c, d, e, m, inp;
		inp = inpT.delta;
		a = inp + 32044;
		b = (4 * a + 3) / 146097;
		c = a - (146097 * b / 4);
		d = (4 * c + 3) / 1461;
		e = c - (1461 * d / 4);
		m = (5 * e + 2) / 153;
		Date outp;
		outp.year = 100 * b + d - 4800 + (m / 10);
		outp.month = Month(m + 3 - 12 * (m / 10));
		outp.day = e - ((153 * m + 2) / 5) + 1;
		return outp;
	};
	Date operator + (const Date date, const TimeDelta delta) {
		TimeDelta begin = countJND(date);
		begin = begin + delta;
		return JNDToDate(begin);


	};
	Date operator + (const TimeDelta delta, const Date date) {
		return(date + delta);
	};
}