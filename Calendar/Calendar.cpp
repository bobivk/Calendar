#include "Calendar.h"

Calendar::Calendar() {
	for (unsigned year = 2000; year <= 2222; ++year) {
		bool peakYear = false;
		if (year % 4 == 0) peakYear = true;
		for (unsigned month = 1; month <= 12; ++month) {
			int daysOfMonth = 30;
			if (month == 2) { //February
				daysOfMonth = 28 + peakYear;
			}
			if (month % 2 == 1 || month == 8) daysOfMonth = 31; //long months
			for (unsigned day = 1; day <= daysOfMonth; ++day) {
				Day currentDay(day, month, year);
				days.push_back(currentDay);
			}
		}
	}
}

void Calendar::book() {
	string name, comment, dateString, startTimeString, endTimeString;
	cin >> name >> comment >> dateString >> startTimeString >> endTimeString;

	Date date = Parser::parseDate(dateString);
	TimeInterval time = Parser::parseTimeInterval(startTimeString, endTimeString);

	Appointment appointment(name, comment, time);

	Day* chosenDay = searchDay(date);
	if (chosenDay != nullptr) {
		chosenDay->addAppointment(appointment);
		cout << "Booked appointment ";
		appointment.print();
	}
}

void Calendar::unbook() {
	string dateString, startTimeString, endTimeString;
	cin >> dateString >> startTimeString, endTimeString;
	Date date = Parser::parseDate(dateString);
	TimeInterval time = Parser::parseTimeInterval(startTimeString, endTimeString);

	Day* chosenDay = searchDay(date);
	if (chosenDay != nullptr) {
	//	chosenDay->removeAppointment(time);
	}
}
Day* Calendar::searchDay(Date date) {
	for (size_t i = 0; i < days.size(); ++i) {
		if (days[i].getDate() == date) {
			return &days[i];
		}
	}
	cout << "Day not found in calendar with this date.\n";
	return nullptr;
}
