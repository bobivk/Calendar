#pragma once
#include<cassert>
#include<iostream>

template<typename T, typename V>
struct Pair {
	T first;
	V second;
};


class TimeInterval
{
	unsigned start{ 0 }; //time in minutes from 00:00
	unsigned end{ 0 };

	//appointment or timeinterval member function?
	unsigned hoursToMinutes(unsigned hours, unsigned minutes) const;
	Pair<unsigned, unsigned> minutesToHours(unsigned minutes) const;


public:
	TimeInterval() = default;
	TimeInterval(unsigned begin, unsigned end);
	TimeInterval(const TimeInterval& other);
	TimeInterval& operator=(const TimeInterval&);
	void swap(TimeInterval& other);
	unsigned getStart() const;
	unsigned getEnd() const;
	void print() const;
};