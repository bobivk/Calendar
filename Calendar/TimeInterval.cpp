#include "TimeInterval.h"


TimeInterval::TimeInterval(unsigned in_start, unsigned in_end):
	start{ in_start },
	end{ in_end } {
	
}
TimeInterval::TimeInterval(const TimeInterval& other):
	start{other.start},
	end{ other.end }
{}
TimeInterval& TimeInterval::operator=(const TimeInterval& other) {
	start = other.start;
	end = other.end;
	return *this;
}
bool TimeInterval::operator==(const TimeInterval& other) const{
	return (start == other.start) && (end == other.end);
}

unsigned TimeInterval::hoursToMinutes(unsigned hours, unsigned minutes) const {
	assert(hours >= 0 && hours < 24);
	assert(minutes >= 0 && minutes < 60);
	return minutes += hours * 60;
}
TimePair TimeInterval::minutesToHours(unsigned minutes) const{
	assert(minutes < 1440);
	unsigned hours = minutes / 60;
	unsigned min = minutes % 60;
	TimePair p;
	p.hours = hours;
	p.minutes = min;
	return p;
}
void TimeInterval::swap(TimeInterval& other) {
	std::swap(start, other.start);
	std::swap(end, other.end);
}

void TimeInterval::print(std::ostream& out) const {
	TimePair startTime = this->minutesToHours(start);
	TimePair endTime = this->minutesToHours(end);
	if (startTime.hours < 10) out << '0';
	out << startTime.hours << ':';
	if (startTime.minutes < 10) out << '0';
	out << startTime.minutes << " - ";
	if (endTime.hours < 10) out << '0';
	out << endTime.hours << ':';
	if (endTime.minutes < 10) out << '0';
	out << endTime.minutes << " ";
}