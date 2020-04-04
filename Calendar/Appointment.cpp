#pragma once
#include"Appointment.h"

unsigned strlength(const char* string) {
	size_t i = 0;
	while (string[i]!=0) {
		++i;
	}
	return i;
}
void strcopy(char* destination, const char* source) {
	size_t length = strlength(source);
	for (size_t i = 0; i < length; ++i) {
		destination[i] = source[i];
	}
}


Appointment::Appointment() :
	name{ new char[200] },
	comment{ new char[200] }  {}

Appointment::Appointment(const char* in_name, const char* in_comment, TimeInterval t):
	name{ new char[200] },
	comment{ new char[200] },
	timeInterval{ t } {
	strcopy(name, in_name);
	strcopy(comment, in_comment);
}
Appointment::~Appointment() {
	delete[] name;
	delete[] comment;
}

Appointment::Appointment(const Appointment& other):
	name{ new char[200] },
	comment{ new char[200] },
	timeInterval{ other.timeInterval }{
	strcopy(name, other.name);
	strcopy(comment, other.comment);
}

unsigned Appointment::getStart() const {
	return timeInterval.getStart();
}
unsigned Appointment::getEnd() const {
	return timeInterval.getEnd();
}