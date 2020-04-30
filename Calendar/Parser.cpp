#include "Parser.h"

						//12.04.2020  
Date Parser::parseDate(string dateStr) {
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

												//12:15, 16:15
TimeInterval Parser::parseTimeInterval(string startTimeStr, string endTimeStr) {
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
	TimeInterval t(startMinutes, endMinutes);
	return t;
}