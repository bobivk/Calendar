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
	void addAppointment(const Appointment&);
	void removeAppointment(TimeInterval t);
	void findAppointment(string nameOrComment);
	void printAppointments() const;
	void setAsHoliday();
	Date getDate();
	unsigned getAppointmentCount();
};
