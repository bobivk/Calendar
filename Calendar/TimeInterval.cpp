#include "TimeInterval.h"

TimeInterval::TimeInterval(unsigned in_start, unsigned in_end):
	start{ in_start },
	end{ in_end } {}
TimeInterval::TimeInterval(const TimeInterval& other):
	start{other.start},
	end{ other.end }
{}
TimeInterval& TimeInterval::operator=(const TimeInterval& other) {
	start = other.start;
	end = other.end;
	return *this;
}
unsigned TimeInterval::getStart() const{
	return start;
}
unsigned TimeInterval::getEnd() const{
	return end;
}