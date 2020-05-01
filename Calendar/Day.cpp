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


void Day::removeAppointment(TimeInterval time) {
	
	for (size_t i = 0; i < appointments.size(); ++i) {
		if (appointments[i].getTimeInterval() == time) {
			appointments.erase(appointments.begin() + i);
			cout << "Removed appointment in interval ";
			time.print();
			return;
		}
	}
	cout << "Could not find appointment.\n";
}
void Day::findAppointment(string nameOrComment) {
	for (size_t i = 0; i < appointments.size(); ++i) {
		if (appointments[i].getName() == nameOrComment
			|| appointments[i].getComment() == nameOrComment) {
			appointments[i].print();
		}
	}
}
void Day::printAppointments() const{
	for (size_t i = 0; i < appointments.size(); ++i) {
		appointments[i].print();
	}
}
void Day::setAsHoliday() {
	isHoliday = true;
}
Date Day::getDate() {
	return date;
}
unsigned Day::getAppointmentCount() {
	return appointments.size();
}