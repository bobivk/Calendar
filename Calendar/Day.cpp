#pragma once
#include"Day.h"
#include"Appointment.h"
#include<algorithm> //std::remove


Day::Day(unsigned day, unsigned month, unsigned year) :
	date(day, month, year) 
{}
Day::Day(Date date_) : date{ date_ } {}
Day::~Day() {}

bool Day::isTimeIntervalFree(TimeInterval t) const{
	for (size_t i = 0; i < appointments.size(); ++i) {
		unsigned currentStart = appointments[i].getStart();
		unsigned currentEnd = appointments[i].getEnd();
		if ((t.start <= currentStart && t.end > currentStart) ||
			(t.start < currentEnd && t.end > currentEnd) ||
			(t.start >= currentStart && t.end < currentEnd)) {
			return false;
		}
	}
	return true;
}
unsigned Day::getBusyMinutes() const {
	unsigned result = 0;
	for (size_t i = 0; i < appointments.size(); ++i) {
		result += appointments[i].getLengthInMinutes();
	}
	return result;
}

bool compareAppointments(Appointment a, Appointment b){
	return a.getStart() < b.getStart();
}
void Day::sortAppointments() {
	std::sort(appointments.begin(), appointments.end(), compareAppointments);
}
void Day::addAppointment(Appointment appointment) { 
	if (!isTimeIntervalFree(appointment.getTimeInterval())) //iskame li da moje da se pripokrivat?
	{
		cout << "This time interval is already taken.\n";
	}
	appointments.push_back(appointment);
	sortAppointments();
}


void Day::removeAppointment(TimeInterval time) {
	for (size_t i = 0; i < appointments.size(); ++i) {
		if (appointments[i].getTimeInterval() == time) {
			appointments.erase(appointments.begin() + i);
			cout << "Removed appointment in interval ";
			time.print(cout);
			cout << endl;
			return;
		}
	}
	cout << "Could not find appointment.\n";
}
void Day::findAndPrintAppointment(string nameOrComment) {
	for (size_t i = 0; i < appointments.size(); ++i) {
		if (appointments[i].getName() == nameOrComment
			|| appointments[i].getComment() == nameOrComment) {
			date.print(cout);
			appointments[i].print(cout);
		}
	}
}

TimeInterval Day::findFreeInterval(unsigned lengthInMinutes) {
	unsigned i = 0;
	TimeInterval toCheck(480, 480 + lengthInMinutes); //starting from 08:00, which is 480 minutes

	while (i < appointments.size()) {
		if (toCheck.end > 1020 || isHoliday) {// if we reach 17:00 (1020 minutes), advance to the next day
			return TimeInterval(0, 0);
		}
		if (isTimeIntervalFree(toCheck)) {
			return toCheck;
		}
		else {
			toCheck.start = appointments[i].getEnd();
			toCheck.end = toCheck.start + lengthInMinutes;
			++i;
		}
	}
	if (isTimeIntervalFree(toCheck) && toCheck.end <= 1020) {
		return toCheck;
	}
	return TimeInterval(0, 0);	//return an empty interval
}

void Day::printAppointments(std::ostream& out) const {
	for (size_t i = 0; i < appointments.size(); ++i) {
		appointments[i].print(out);
	}
}
void Day::print(std::ostream& out) const {
	if (appointments.size() > 0 || isHoliday) {
		date.print(out);
		if (isHoliday) out << "holiday, ";
		else out << "workday, ";
		out << appointments.size() <<  " appointments:\n";
		printAppointments(out);
	}
}
void Day::logAppointments() const {
	if (isHoliday) cout << "This day is a holiday.\n";
	if (appointments.size() == 0) cout << "No appointments for this day.\n";
	printAppointments(cout);
}
void Day::setAsHoliday() {
	isHoliday = true;
}
Date Day::getDate() const {
	return date;
}
size_t Day::getAppointmentCount() {
	return appointments.size();
}
bool Day::appointmentExists(Appointment appointment) const {
	for (size_t i = 0; i < appointments.size(); ++i) {
		if (appointments[i] == appointment) {
			cout << "This appointment already exists.\n";
			return true;
		}
	}
	return false;
}