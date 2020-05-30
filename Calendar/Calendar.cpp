#include "Calendar.h"
using namespace std;

Calendar::Calendar() {
	load("calendar.txt", false);
}
Calendar::Calendar(const Calendar& other):
	days{ other.days }{}

Calendar::~Calendar() {
	save("calendar.txt");
}

void Calendar::book() {
	string name, comment;
	cin >> name >> comment;
	Date date = Parser::parseDate(cin);
	TimeInterval time = Parser::parseTimeInterval(cin);
	Appointment newAppointment(name, comment, time);
	addAppointment(newAppointment, date);
}
void Calendar::addAppointment(Appointment newAppointment, Date date) {
	vector<Day>::iterator foundDay = searchDay(date);
	if (!foundDay->appointmentExists(newAppointment)) {
		foundDay->addAppointment(newAppointment);
		cout << "Booked appointment ";
		date.print(cout);
		newAppointment.print(cout);

	}
}

void Calendar::unbook() {
	Date date = Parser::parseDate(cin);
	TimeInterval time = Parser::parseTimeInterval(cin);

	vector<Day>::iterator chosenDay = searchDay(date);
	if (chosenDay != days.end()) {
		chosenDay->removeAppointment(time);
	}
}
bool compareDaysByDate(Day d1, Day d2) {
	return d1.getDate() < d2.getDate();
}
std::vector<Day>::iterator Calendar::searchDay(Date date) {

	vector<Day>::iterator it = std::find_if(days.begin(), days.end(),
		[date](Day& day) -> bool {
			return day.getDate() == date;
		});
	if(it == days.end()){	//if day is not found, then it's empty so create it
		days.emplace_back(Day(date));
		//sort days by their date
		std::sort(days.begin(), days.end(), compareDaysByDate);
		return std::find_if(days.begin(), days.end(), [date](Day& day) -> bool {
			return day.getDate() == date;
		});
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
void Calendar::findSlot(Date fromDate, unsigned minutesOfSearched) {
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

vector<string> splitString(string input, char delim) {
	stringstream ss(input);
	string current;
	vector<string> result;
	while (getline(ss, current, delim)) {
		result.push_back(current);
	}
	return result;
}

void Calendar::load(string fileName, bool merging) {
	ifstream in(fileName, ios::beg);
	cout << "Loading data from file " << fileName << endl;
	string line;
	while (getline(in, line)) {
		vector<string> dayInfo = splitString(line, ' ');
		Date date = Parser::parseDate(dayInfo[0]);
		if (dayInfo[1] == "holiday,") searchDay(date)->setAsHoliday();
		int appointmentCount = stoi(dayInfo[2]);
		for (int i = 0; i < appointmentCount; ++i) {
			string appointmentstr;
			getline(in, appointmentstr);
			vector<string> appointmentInfo = splitString(appointmentstr, ' ');
			TimeInterval time = Parser::parseTimeInterval(appointmentInfo[0], appointmentInfo[2]);
			if (merging) {
				if (!searchDay(date)->isTimeIntervalFree(time)) {
					cout << "Time interval ";
					time.print(cout);
					cout << "on ";
					date.print(cout);
					cout << "is taken, please enter a new date and time for " << appointmentInfo[4]
						<< ".\n Enter 'keep' to keep both appointments.\n";
					string newDate;
					cin >> newDate;
					if (newDate != "keep") {
						date = Parser::parseDate(newDate);
						time = Parser::parseTimeInterval(cin);
					}
				}
			}
			Appointment appointment(appointmentInfo[4], appointmentInfo[6], time);
			addAppointment(appointment, date);
		}
	}
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
	load(fileName, true);
}