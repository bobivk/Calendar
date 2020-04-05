#pragma once
#include"Appointment.h"


class Day
{
	Appointment* appointments;		//appointments sorted by their timeIntervals;
	size_t appointmentCount{ 0 };
	bool isHoliday{ false };

public:
	Day();
	bool isTimeIntervalTaken(TimeInterval t) const;
	void addAppointment(const Appointment&);
	void printAppointments() const;
};

