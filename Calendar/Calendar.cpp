#include "Calendar.h"

Calendar::Calendar() :
	days{ new Day[365] },
	chosenDayIndex{0}
{}
Calendar::~Calendar(){
	delete[] days;
}

void Calendar::addAppointment(const Appointment& appointment) {
	if (!days[chosenDayIndex].isTimeIntervalTaken(appointment.getTimeInterval())) {
		days[chosenDayIndex].addAppointment(appointment);
	}
	std::cout << "Added appointment: ";
}
Day Calendar::getCurrentDay() const {
	return currentDay;
}
