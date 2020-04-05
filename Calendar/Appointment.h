#pragma once
#include"TimeInterval.h"

class Appointment
{
	char* name;
	char* comment;
	TimeInterval timeInterval;

public:
	Appointment();
	Appointment(const char* name, const char* comment, TimeInterval t);
	Appointment(const Appointment& other);
	Appointment& operator=(const Appointment& other);
	void swap(Appointment& other);
	unsigned getStart() const;
	unsigned getEnd() const;
	void print() const;
	TimeInterval getTimeInterval() const;
	~Appointment();
};

