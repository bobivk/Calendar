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
	Appointment(const Appointment&);
	~Appointment();
	Appointment& operator=(const Appointment&);
	bool operator==(const Appointment&) const;
	void swap(Appointment&, Appointment&);
	unsigned getStart() const;
	unsigned getEnd() const;
	string getName() const;
	string getComment() const;
	unsigned getLengthInMinutes() const;
	void print(ostream& out) const;
	TimeInterval getTimeInterval() const;
};

