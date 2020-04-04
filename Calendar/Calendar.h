#pragma once
#include"Day.h"
class Calendar
{
	Date beginDate;
	Date endDate;
	Date currentDate;
	Day* days;

public:
	Calendar();
	Date getCurrentDate();
	void addAppointment(const Appointment& appointment);
};

