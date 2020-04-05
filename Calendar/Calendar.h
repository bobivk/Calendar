#pragma once
#include"Day.h"
class Calendar
{
	Day beginDay;
	Day endDay;
	Day currentDay;
	unsigned chosenDayIndex;
	Day* days;

public:
	Calendar();
	~Calendar();
	Day getCurrentDay() const;
	void addAppointment(const Appointment& appointment);
};

