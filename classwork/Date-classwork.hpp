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
			Âîçâðàùàåò Þëèàíñêóþ äàòó
			https://ru.wikipedia.org/wiki/%D0%AE%D0%BB%D0%B8%D0%B0%D0%BD%D1%81%D0%BA%D0%B0%D1%8F_%D0%B4%D0%B0%D1%82%D0%B0
			ðàçäåë "Âû÷èñëåíèå íîìåðà þëèàíñêîãî äíÿ (JDN) ïî äàòå ãðèãîðèàíñêîãî êàëåíäàðÿ"
			Òåñòîâûå äàííûå					Îæèäàåìûé ðåçóëüòàò
			1.12.2018					2458454
			1.1.2018					2458120
			1.6.2000					2451697
			21.12.2012					2456283
		*/
	TimeDelta countJND(Date date);

	/*
		Ðàññ÷èòûâàåò êîëè÷åñòâî äíåé ìåæäó äâóìÿ äàòàìè.
		Ïðè ðåàëèçâàöèè èñïîëüçóéòå CountJND
	*/
	TimeDelta countDistance(Date from, Date to);

	void printMonthAsString(Month month)
	{
		switch (month)
		{
		case Month::January:
			std::cout << "january";
			break;
		case Month::February:
			std::cout << "february";
			break;
		case Month::March:
			std::cout << "march";
			break;
		default:
			std::cout << "unknown month";
			break;
		}
	}

	/*
		Âûâîäèò â êîíñîëü
	*/
	void print(Month month, DateFormat format = DateFormat::MonthAsInt)
	{
		if (format == DateFormat::MonthAsInt)
		{
			std::cout << static_cast<int>(month);
		}
		else if (format == DateFormat::MonthAsString)
		{
			printMonthAsString(month);
		}
		else
		{
			std::cout << "Wrong format!";
		}
	}

	void print(Date data, DateFormat format = DateFormat::MonthAsInt)
	{
		std::cout << data.day << " ";
		print(data.month, format);
		std::cout << " " << data.year;
	}

	void print(TimeDelta delta);

	/*
		Âîçâðàùàåò ñåçîí (çèìà, âåñíà, ëåòî, îñåíü) ïåðåäàâàåìîé äàòû
	*/
	Season getSeason(Date date);
	Season getSeason(Month month);

	/*
		Íàïèñàòü ïåðåãðóçêó äëÿ ñëåäóþùèõ ëîãè÷åñêèõ îïåðàòîðîâ
	*/
	bool operator == (const Date lhs, const Date rhs);
	bool operator != (const Date lhs, const Date rhs);
	bool operator < (const Date lhs, const Date rhs);
	bool operator <= (const Date lhs, const Date rhs);
	bool operator > (const Date lhs, const Date rhs);
	bool operator >= (const Date lhs, const Date rhs);

	/*
		Íàïèñàòü ïåðåãðóçêó äëÿ ñëåäóþùèõ àðèôìåòè÷åñêèõ îïåðàòîðîâ
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
