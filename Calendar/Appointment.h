#pragma once
#include"TimeInterval.h"
#include<string>
using namespace std;

class Appointment
{
private:
	string name;
	string comment;
	TimeInterval timeInterval;
	void swap(Appointment& other);

public:
	Appointment() = default;
	Appointment(const string name, const string comment, TimeInterval t);
	Appointment(const Appointment& other);
	Appointment& operator=(const Appointment& other);
	void swap(Appointment&, Appointment&);
	unsigned getStart() const;
	unsigned getEnd() const;
	string getName() const;
	string getComment() const;
	void print() const;
	TimeInterval getTimeInterval() const;
};

