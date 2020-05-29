#include "Date.h"
#include<cassert>

Date::Date(unsigned in_day, unsigned in_month, unsigned in_year) :
	day{ in_day },
	month {in_month},
	year{ in_year }{
	assert(in_day <= 31);
	assert(in_month <= 12);
}
Date::Date(const Date& other):
	day{ other.day },
	month{ other.month },
	year{ other.year } {}

bool Date::operator==(Date& other) const{
	if (day == other.day && month == other.month && year == other.year) return true;
	return false;
}

void Date::operator++() {
	bool peakYear = false;
	if (year % 4 == 0) peakYear = true;
	unsigned daysOfMonth = 30;
	if (month == 2) { //February
		daysOfMonth = 28 + peakYear;
	}
	if (month % 2 == 1 || month == 8) daysOfMonth = 31; //long months
	
	if (day == daysOfMonth) {
		if (month < 12)
		{
			++month;
		}
		else {
			month = 1;
			++year;
		}
		day = 1;
	}
	else {
		++day;

	}
}
void Date::operator--() {
	if (day != 1) {
		--day;
		return;
	}
	else{
		bool peakYear = false;
		unsigned previousMonth = month - 1;
		if (month == 1) previousMonth = 12;
		if (year % 4 == 0) peakYear = true;
		unsigned daysOfPreviousMonth = 30;
		if (previousMonth == 2) { //February
			daysOfPreviousMonth = 28 + peakYear;
		}
		if (previousMonth % 2 == 1 || previousMonth == 8) daysOfPreviousMonth = 31; //long months
		
		if (month > 1)
		{
			--month;
		}
		else {
			month = 12;
			--year;
		}
		day = daysOfPreviousMonth;
	}
	
	
}
void Date::print(std::ostream& out) const {
	out << day << '.' << month << '.' << year << ' ';
}