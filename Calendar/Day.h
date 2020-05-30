#pragma once
#include"Appointment.h"
#include"TimeInterval.h"
#include"Date.h"
#include<vector>

class Day
{
	Date date;
	vector<Appointment> appointments;		//appointments sorted by their timeIntervals;
	bool isHoliday{ false };
	void sortAppointments();
public:
	Day(unsigned day, unsigned month, unsigned year);
	Day(Date);
	~Day();
	bool isTimeIntervalFree(TimeInterval t) const;
	unsigned getBusyMinutes() const;
	void addAppointment(Appointment);
	void removeAppointment(TimeInterval t);
	void findAndPrintAppointment(string nameOrComment);
	TimeInterval findFreeInterval(unsigned LengthInMinutes);
	void printAppointments(std::ostream& out) const;
	void print(std::ostream& out) const;
	void logAppointments() const;
	void setAsHoliday();
	Date getDate() const;
	size_t getAppointmentCount();
};
