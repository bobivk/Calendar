#include "Calendar.h"
using namespace std;

Calendar::Calendar() {

	/*
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
	*/
	load("calendar.txt");
}

Calendar::~Calendar() {
	save("calendar.txt");
}

void Calendar::book() {
	string name, comment;
	cin >> name >> comment;
	Date date = Parser::parseDate(cin);
	TimeInterval time = Parser::parseTimeInterval(cin);
	Appointment* newAppointment = new Appointment(name, comment, time);
	addAppointment(newAppointment, date);
}
void Calendar::addAppointment(Appointment* newAppointment, Date date) {
	vector<Day>::iterator foundDay = searchDay(date);
	foundDay->addAppointment(newAppointment);
	cout << "Booked appointment ";
	date.print(cout);
	newAppointment->print(cout);
}

void Calendar::unbook() {
	Date date = Parser::parseDate(cin);
	TimeInterval time = Parser::parseTimeInterval(cin);

	vector<Day>::iterator chosenDay = searchDay(date);
	if (chosenDay != days.end()) {
		chosenDay->removeAppointment(time);
	}
}
std::vector<Day>::iterator Calendar::searchDay(Date date) {

	vector<Day>::iterator it = std::find_if(days.begin(), days.end(),
		[date](Day& day) -> bool {
			return day.getDate() == date;
		});
	if(it == days.end()){	//if day is not found, then it's empty so create it
		days.emplace_back(Day(date));
		return days.end() - 1;
	}
	return it;
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
		freeIntervalFound = searchDay(fromDate)->findFreeInterval(minutesOfSearched);
		++fromDate;
	}
	--fromDate;
	cout << "Free interval found on ";
	fromDate.print(cout);
	freeIntervalFound.print(cout);
	cout << endl;
}

bool compareDaysByBusiness(Day d1, Day d2) {
	return d1.getBusyMinutes() > d2.getBusyMinutes();
}
void sortDaysByBusiness(vector<Day> &days) {
	std::sort(days.begin(), days.end(), compareDaysByBusiness);
}
void Calendar::busyDays() {
	Date from = Parser::parseDate(cin);
	Date to = Parser::parseDate(cin);
	++to;
	vector<Day> days;
	while (!(from == to)) {
		days.push_back(*searchDay(from));
		++from;
	}
	sortDaysByBusiness(days);
	for (size_t i = 0; i < days.size(); ++i) {
		days[i].print(cout);
	}
}

void Calendar::load(string fileName) {
	ifstream in(fileName, ios::beg);


}
void Calendar::save(string fileName) {
	ofstream out(fileName, ios::trunc);
	for (size_t days_count = 0; days_count < days.size(); ++days_count) {
		days[days_count].print(out);
	}
}
void Calendar::list() {
	for (size_t i = 0; i < days.size(); ++i) {
		days[i].print(cout);
	}
}

void Calendar::mergeWith(string fileName) {
	ifstream in(fileName, ios::beg);

}