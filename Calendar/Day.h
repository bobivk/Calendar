#pragma once
#include"Appointment.h"
#include"Date.h"

class Day: Date
{
	Appointment* appointments;		//appointments sorted by their timeIntervals;
	size_t appointmentCount{ 0 };
	bool isHoliday{ false };

public:
	Day();
	bool isTimeIntervalTaken(TimeInterval t);
};

