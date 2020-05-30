#pragma once
#include"Appointment.h"
#include<iostream>
using namespace std;



Appointment::Appointment(const string in_name, const string in_comment, TimeInterval t):
	name{ in_name },
	comment{ in_comment },
	timeInterval{ t } {}

Appointment::Appointment(const Appointment& other):
	name{ other.name},
	comment{other.comment },
	timeInterval{ other.timeInterval }{}
Appointment::~Appointment() {}

Appointment& Appointment::operator=(const Appointment& other) {
	Appointment temp{ other };
	swap(temp);
	return *this;
}
void Appointment::swap(Appointment& other) {
	std::swap(name, other.name);
	std::swap(comment, other.comment);
	timeInterval.swap(other.timeInterval);
}
void Appointment::swap(Appointment& lhs, Appointment& rhs) {
	lhs.swap(rhs);
}

unsigned Appointment::getStart() const {
	return timeInterval.start;
}
unsigned Appointment::getEnd() const {
	return timeInterval.end;
}
string Appointment::getName() const {
	return name;
}
string Appointment::getComment() const {
	return comment;
}
unsigned Appointment::getLengthInMinutes() const {
	return timeInterval.end - timeInterval.start;
}
TimeInterval Appointment::getTimeInterval() const {
	return timeInterval;
}

void Appointment::print(ostream& out) const {
	timeInterval.print(out);
	out <<": " << name << " Comment: " << comment << endl;
}