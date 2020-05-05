#pragma once
#include"Appointment.h"
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
	bool isTimeIntervalFree(TimeInterval t) const;
	unsigned getBusyMinutes() const;
	void addAppointment(const Appointment&);
	void removeAppointment(TimeInterval t);
	void findAndPrintAppointment(string nameOrComment);
	TimeInterval findFreeInterval(unsigned LengthInMinutes);
	void printAppointments() const;
	void setAsHoliday();
	Date getDate();
	size_t getAppointmentCount();
};
