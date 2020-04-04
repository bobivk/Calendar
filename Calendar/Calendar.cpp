#include "Calendar.h"

Calendar::Calendar():
	days{ new Day[365] }
{
}
Calendar::~Calendar(){
	delete[] days;
}

void Calendar::addAppointment(const Appointment& appointment) {
	
}
Date Calendar::getCurrentDate() {
	return currentDate;
}
