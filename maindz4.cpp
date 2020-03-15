#include <cstdio>
#include <limits>
#include "Date.hpp"
using namespace ext;
int main() {
	Date date{ 2020, Month::March, 15 };

	Season season = getSeason(date);
}