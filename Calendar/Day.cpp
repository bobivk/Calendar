#pragma once
#include"Day.h"
#include"Appointment.h"
#include<algorithm> //std::remove


Day::Day(unsigned day, unsigned month, unsigned year) :
	date(day, month, year) 
{}

bool Day::isTimeIntervalFree(TimeInterval t) const{
	for (size_t i = 0; i < appointments.size(); ++i) {
		unsigned currentStart = appointments[i].getStart();
		unsigned currentEnd = appointments[i].getEnd();
		if ((currentStart >= t.start && currentStart <= t.end) ||
			(currentEnd >= t.start && currentEnd <= t.end)) {
			return false;
		}
	}
	return true;
}

void Day::sortAppointments() {	//bubble sort
	for (size_t i = 0; i < appointments.size(); ++i) {
		for (size_t j = i; j < appointments.size(); ++j) {
			if (appointments[j].getStart() < appointments[i].getStart()) {
				swap(appointments[i], appointments[j]);
			}
		}
	}
}
void Day::addAppointment(const Appointment& appointment) {
	if (isTimeIntervalFree(appointment.getTimeInterval()))
	{
		appointments.push_back(appointment);
		sortAppointments();
	}
	else cout << "This time interval is already taken.\n";
}
bool isTimeIntervalEqual(Appointment& a, Appointment& b) {
	return a.getTimeInterval() == b.getTimeInterval();
}
void Day::removeAppointment(TimeInterval time) {
	//std::remove_if(appointments.begin(), appointments.end(), isTimeIntervalEqual);

	cout << "Removed appointment in interval ";
	time.print();
}

void Day::printAppointments() const{
	for (size_t i = 0; i < appointments.size(); ++i) {
		appointments[i].print();
	}
}
Date Day::getDate() {
	return date;
}