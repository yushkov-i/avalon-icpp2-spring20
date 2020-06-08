#include "Extention.hpp"
using namespace std;
using namespace ext;

namespace ext
{

	/*----------homework-04----------*/

	TimeDelta countJND(Date date)
	{
		int a = (14 - static_cast<int>(date.month)) / 12;
		int m = static_cast<int>(date.month) + 12 * a - 3;
		int y = date.year + 4800 - a;
		return { date.day + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045 };
	}
	Date countGk(TimeDelta delta)
	{
		int a = delta.delta + 32044;
		int b = (4 * a + 3) / 146097;
		int c = a - (146097 * b)/4;
		int d = (4 * c + 3) / 1461;
		int e = c - (1461 * d) / 4;
		int m = (5 * e + 2) / 153;

		Date Gkdata;
		Gkdata.day = e - (153 * m + 2) / 5 + 1;
		Gkdata.month =static_cast<Month>(m + 3 - 12 * (m / 10));
		Gkdata.year = 100 * b+d - 4800 + m / 10;
		
		return Gkdata;
	}

	TimeDelta countDistance(Date from, Date to)
	{
		return { abs((countJND(from) - countJND(to)).delta)};
	}

	void print(Month month, DateFormat format)
	{
		if (format == DateFormat::MonthAsString)
		{
			switch (month)
			{
			case Month::January:
				cout << "january";
				break;
			case Month::February:
				cout << "february";
				break;
			case Month::March:
				cout << "march";
				break;
			case Month::April:
				cout << "april";
				break;
			case Month::May:
				cout << "may";
				break;
			case Month::June:
				cout << "june";
				break;
			case Month::July:
				cout << "july";
				break;
			case Month::August:
				cout << "august";
				break;
			case Month::September:
				cout << "september";
				break;
			case Month::October:
				cout << "october";
				break;
			case Month::Novemver:
				cout << "novemver";
				break;
			case Month::December:
				cout << "december";
				break;
			default:
				cout << "unknown month";
			}
		}
		else cout << static_cast<int>(month);
	}

	void print(Date data, DateFormat format)
	{
		cout << data.year << '.'; print(data.month, format); cout<<'.'<< data.day<<endl;
	}

	void print(TimeDelta delta)
	{
		cout << delta.delta;
	}

	Season getSeason(Month month)
	{
		switch (month)
		{
		case Month::December:
		case Month::January:
		case Month::February:
			return Season::Winter;
		case Month::March:
		case Month::April:
		case Month::May:
			return Season::Spring;
		case Month::June:
		case Month::July:
		case Month::August:
			return Season::Autumn;
		case Month::September:
		case Month::October:
		case Month::Novemver:
			return Season::Winter;
		default:
			cout << "unknown season";
		}
	}

	Season getSeason(Date date)
	{
		return getSeason(date.month);
	}

	bool operator == (const Date lhs, const Date rhs)
	{
		if (lhs.day == rhs.day && lhs.month == rhs.month && lhs.year == rhs.year) return true;
		else return false;
	}
	bool operator != (const Date lhs, const Date rhs)
	{
		if (lhs == rhs) return false;
		else return true;
	}
	bool operator < (const Date lhs, const Date rhs)
	{
		if (countJND(lhs).delta < countJND(rhs).delta) return true;
		else return false;
	}
	bool operator > (const Date lhs, const Date rhs)
	{
		if (countJND(lhs).delta > countJND(rhs).delta) return true;
		else return false;
	}
	bool operator <= (const Date lhs, const Date rhs)
	{
		if (lhs > rhs) return false;
		else return true;
	}
	bool operator >= (const Date lhs, const Date rhs)
	{
		if (lhs < rhs) return false;
		else return true;
	}

	TimeDelta operator + (const TimeDelta lhs, const TimeDelta rhs)
	{
		return { lhs.delta + rhs.delta };
	}
	
	TimeDelta operator - (const TimeDelta lhs, const TimeDelta rhs)
	{
		return { lhs.delta - rhs.delta };
	}

	Date operator + (const Date date, const TimeDelta delta)
	{
		return countGk(countJND(date) + delta);
	}
	Date operator + (const TimeDelta delta, const Date date)
	{
		return date + delta;
	}

	TimeDelta operator * (const TimeDelta delta, int multiplier) 
	{
		return { delta.delta * multiplier };
	}
	TimeDelta operator * (int multiplier, const TimeDelta delta)
	{
		return delta * multiplier;
	}

	/*----------homework-05----------*/

	TimeDelta operator ++ (TimeDelta& delta)
	{
		++delta.delta;
		return delta;
	}

	TimeDelta operator ++ (TimeDelta& delta, int)
	{
		int temp = delta.delta;
		++delta.delta;
		return { temp };
	}

	TimeDelta operator -- (TimeDelta& delta)
	{
		--delta.delta;
		return delta;
	}

	TimeDelta operator -- (TimeDelta& delta, int)
	{
		int temp = delta.delta;
		--delta.delta;
		return { temp };
	}

	Date operator ++ (Date& delta)
	{
		delta = countGk({ countJND(delta).delta + 1 });
		return delta;
	}
	Date operator ++ (Date& delta, int)
	{
		Date redate = delta;//не уверен
		delta = countGk({countJND(delta).delta + 1});
		return redate;
	}

	Date operator -- (Date& delta)
	{
		delta = countGk({ countJND(delta).delta - 1 });
		return delta;
	}
	Date operator -- (Date& delta, int)
	{
		Date redate = delta;
		delta = countGk({ countJND(delta).delta - 1 });
		return redate;
	}

	void swap(Date& lhs, Date& rhs)
	{
		std::swap(lhs.day, rhs.day);
		std::swap(lhs.month, rhs.month);
		std::swap(lhs.year, rhs.year);
	}

	void swap(TimeDelta& lhs, TimeDelta& rhs)
	{
		std::swap(lhs.delta, rhs.delta);
	}

	
	Date& max(Date& lhs, Date& rhs)
	{
		if (lhs > rhs) return lhs;
		else return rhs;
	}

	Date* min(Date& lhs, Date& rhs)
	{
		if (lhs < rhs) return &lhs;
		else return &rhs;
	}

	
	Date* getMinDate(Date dates[], int size)
	{
		Date* ukMinDate = &dates[0];
		for (int i = 0; i < size; i++)
		{
			ukMinDate = min(*ukMinDate,dates[i]);
		}
		return ukMinDate;
	}

	Date* getMaxDate(Date dates[], int size)
	{
		int indexMax = 0;
		for (int i = 0; i < size; i++)
		{
			if  (dates[i]==max(dates[indexMax], dates[i])) indexMax=i;
		}
		return &dates[indexMax];
	}

	void sort(Date dates[], int size, SortBy sortBy)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size - i - 1; j++)
			{
				switch (sortBy)
				{
				case SortBy::Date:
					if (dates[j] > dates[j + 1])
						swap(dates[j], dates[j + 1]);
					break;
				case SortBy::Season:
					if (getSeason(dates[j]) > getSeason(dates[j+1]))
						swap(dates[j], dates[j + 1]);
				
				}
			}
		}
		for (int i = 0; i < size; i++)
			print(dates[i]);		

	}

	Date* tryFillDate(int year, int month, int day)
	{
		Date* fillDate = new Date;
		*fillDate={ year, static_cast<Month>(month), day };
		if (*fillDate==countGk(countJND(*fillDate))) return fillDate;
		else
		{
			delete fillDate;
			return nullptr;
		}
	}
}