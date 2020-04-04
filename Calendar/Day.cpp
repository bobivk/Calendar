#pragma once
#include"Day.h"

Day::Day() :
	appointments{ new Appointment[100] },
	appointmentCount{0},
	isHoliday {false}
{}

bool Day::isTimeIntervalTaken(TimeInterval t) {
	for (size_t i = 0; i < appointmentCount; ++i) {
		unsigned currentStart = appointments[i].getStart();
		unsigned currentEnd = appointments[i].getEnd();
		if ((currentStart >= t.getStart() && currentStart <= t.getEnd()) ||
			(currentEnd >= t.getStart() && currentEnd <= t.getEnd())) {
			return true;
		}
	}
	return false;
}