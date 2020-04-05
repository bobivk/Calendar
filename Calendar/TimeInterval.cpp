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

unsigned TimeInterval::hoursToMinutes(unsigned hours, unsigned minutes) const {
	assert(hours >= 0 && hours < 24);
	assert(minutes >= 0 && minutes < 60);
	return minutes += hours * 60;
}
Pair<unsigned, unsigned> TimeInterval::minutesToHours(unsigned minutes) const{
	assert(minutes < 1440);
	unsigned hours = minutes / 60;
	unsigned min = minutes % 60;
	Pair<unsigned, unsigned> p;
	p.first = hours;
	p.second = min;
	return p;
}
void TimeInterval::swap(TimeInterval& other) {
	std::swap(start, other.start);
	std::swap(end, other.end);
}
unsigned TimeInterval::getStart() const{
	return start;
}
unsigned TimeInterval::getEnd() const{
	return end;
}
void TimeInterval::print() const {
	Pair<unsigned, unsigned> startTime = this->minutesToHours(start);
	Pair<unsigned, unsigned> endTime = this->minutesToHours(end);
	std::cout << startTime.first << ":" << startTime.second << " - " <<
		endTime.first << " - " << endTime.second;
}