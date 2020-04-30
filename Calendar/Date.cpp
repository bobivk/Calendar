#include "Date.h"
#include<cassert>

Date::Date(unsigned in_day, unsigned in_month, unsigned in_year) :
	day{ in_day },
	month {in_month},
	year{ in_year }{
	assert(in_day <= 31);
	assert(in_month <= 12);
}

bool Date::operator==(Date& other) const{
	if (day == other.day && month == other.month && year == other.year) return true;
	return false;
}