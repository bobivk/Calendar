#include "Calendar.h"

Calendar::Calendar() {
	for (unsigned year = 1900; year <= 2222; ++year) {
		bool peakYear = false;
		if (year % 4 == 0) peakYear = true;
		for (unsigned month = 1; month <= 12; ++month) {
			unsigned daysOfMonth = 30;
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
	string name, comment;
	cin >> name >> comment;
	Date date = Parser::parseDate(cin);
	TimeInterval time = Parser::parseTimeInterval(cin);
	Appointment appointment(name, comment, time);

	Day* chosenDay = searchDay(date);
	if (chosenDay != nullptr) {
		chosenDay->addAppointment(appointment);
		cout << "Booked appointment ";
		appointment.print();
	}
}

void Calendar::unbook() {
	Date date = Parser::parseDate(cin);
	TimeInterval time = Parser::parseTimeInterval(cin);

	Day* chosenDay = searchDay(date);
	if (chosenDay != nullptr) {
		chosenDay->removeAppointment(time);
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

void Calendar::find() {
	string nameOrComment;
	cin >> nameOrComment;
	for (size_t i = 0; i < days.size(); ++i) {
		days[i].findAndPrintAppointment(nameOrComment);
	}
}
void Calendar::findSlot() {
	Date fromDate = Parser::parseDate(cin);
	unsigned minutesOfSearched = Parser::parseTime(cin);
	TimeInterval empty(0, 0);
	TimeInterval freeIntervalFound = empty;
	while(freeIntervalFound == empty){
		Day* nextDay = searchDay(fromDate);
		freeIntervalFound = nextDay->findFreeInterval(minutesOfSearched);
		++fromDate;
	}
	--fromDate;
	cout << "Free interval found on ";
	fromDate.print();
	freeIntervalFound.print();
	cout << endl;
}

bool compareDaysByBusiness(Day* d1, Day* d2) {
	return d1->getBusyMinutes() > d2->getBusyMinutes();
}
void sortDaysByBusiness(vector<Day*> &days) {
	std::sort(days.begin(), days.end(), compareDaysByBusiness);
}
void Calendar::busyDays() {
	Date from = Parser::parseDate(cin);
	Date to = Parser::parseDate(cin);
	++to;
	vector<Day*> days;
	while (!(from == to)) {
		Day* current = searchDay(from);
		days.push_back(current);
		++from;
	}
	sortDaysByBusiness(days);
	for (size_t i = 0; i < days.size(); ++i) {
		days[i]->getDate().print();
		cout << endl;
		days[i]->printAppointments();
	}
}

void Calendar::load(string fileName) {
	ifstream in(fileName, ios::binary);
	in.read((char*)this, sizeof(Calendar));
	in.close();
}
void Calendar::save(string fileName) {
	ofstream out(fileName, ios::binary);
	if (out.is_open()) {
		out.write((char*)this, sizeof(Calendar));
		out.close();
	}
	else cout << "No file specified.";
}