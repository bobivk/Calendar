#pragma once
#include<cassert>
#include"Date.h"

class TimeInterval:Date
{
	unsigned start{ 0 }; //time in minutes from 00:00
	unsigned end{ 0 };

	//appointment or timeinterval member function?
	unsigned hoursToMinutes(unsigned hours, unsigned minutes) {
		assert(hours >= 0 && hours < 24);
		assert(minutes >= 0 && minutes < 60);
		return minutes += hours * 60;
	}
public:
	TimeInterval() = default;
	TimeInterval(unsigned begin, unsigned end);
	TimeInterval(const TimeInterval& other);
	TimeInterval& operator=(const TimeInterval&);

	unsigned getStart() const;
	unsigned getEnd() const;
};