#include "Parser.h"

						
Date Parser::parseDate(istream& input) {
	string dateStr;
	input >> dateStr;	//12.04.2020  
	return parseDate(dateStr);
}
Date Parser::parseDate(const string& dateStr) {
	unsigned day = 0;
	day += (dateStr[0] - '0') * 10;
	day += (dateStr[1] - '0');
	unsigned month = 0;
	month += (dateStr[3] - '0') * 10;
	month += (dateStr[4] - '0');
	unsigned year = 0;
	year += (dateStr[6] - '0') * 1000;
	year += (dateStr[7] - '0') * 100;
	year += (dateStr[8] - '0') * 10;
	year += (dateStr[9] - '0');

	return Date(day, month, year);
}

TimeInterval Parser::parseTimeInterval(istream& input) {
	string startTimeStr, endTimeStr;
	input >> startTimeStr >> endTimeStr;	//12:15, 16:15
	return parseTimeInterval(startTimeStr, endTimeStr);
}
TimeInterval Parser::parseTimeInterval(const string& startTimeStr, const string& endTimeStr) {
	unsigned startMinutes = 0;
	startMinutes += (startTimeStr[0] - '0') * 600;
	startMinutes += (startTimeStr[1] - '0') * 60;
	startMinutes += (startTimeStr[3] - '0') * 10;
	startMinutes += (startTimeStr[4] - '0');
	unsigned endMinutes = 0;
	endMinutes += (endTimeStr[0] - '0') * 600;
	endMinutes += (endTimeStr[1] - '0') * 60;
	endMinutes += (endTimeStr[3] - '0') * 10;
	endMinutes += (endTimeStr[4] - '0');

	return TimeInterval(startMinutes, endMinutes);
}
unsigned Parser::parseTime(istream& input) {
	string timeStr;
	input >> timeStr;
	unsigned result = 0;
	if (timeStr.length() == 5) { // 04:10
		result += (timeStr[0] - '0') * 600;
		result += (timeStr[1] - '0') * 60;
		result += (timeStr[3] - '0') * 10;
		result += (timeStr[4] - '0');
	}
	if (timeStr.length() == 4) { // 4:10
		result += (timeStr[0] - '0') * 60;
		result += (timeStr[2] - '0') * 10;
		result += (timeStr[3] - '0');
	}
	return result;
}