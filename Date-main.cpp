#include "Date.hpp"

using namespace ext;

int main()
{
	Date date{ 2020, Month::March, 15 };
	Season season = getSeason(date); // Spring
	
	Month month = Month::February;
	Season season2 = getSeason(month); // Winter
}