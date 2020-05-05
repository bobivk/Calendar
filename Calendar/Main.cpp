#include"Calendar.h"
#include<iostream>
#include<string>
using namespace std;

void help() {
	cout << "Welcome to your personal calendar!\n";
	cout << "Choose an option:\n";
	cout << "1. book <appointment_name> <appointment_comment> <date> <start_time> <end_time>\n";
	cout << "2. agenda <date>\n";
	cout << "3. unbook <date> <start_time> <end_time>\n";
	cout << "4. holiday <date>\n";
	cout << "5. find <appointment_name_or_comment>\n";
	cout << "6. findslot <from_date> <length_in_hours>\n";
	cout << "7. busydays <from_date> <to_date>\n";

	cout << "save\n";
	cout << "save_as <fileName>\n";
	cout << "open <fileName>\n";
	cout << "help\n";
	cout << "exit\n\n";
	cout << "Please enter dates in the format <DD.MM.YYYY> and time in the format <HH:MM>.\n";
	cout << endl << endl;
}

int main() {
	help();
	Calendar calendar;
	bool running = true;
	string fileName = "calendar.bin";
	//calendar.load(fileName);
	Appointment appointment("appointment1", "comment1", TimeInterval(480, 540));
	Date date(10, 4, 2020);
	Day* chosenDay = calendar.searchDay(date);
	if (chosenDay != nullptr) {
		chosenDay->addAppointment(appointment);
		cout << "Booked appointment ";
		appointment.print();
	}
	Appointment appointment2("appointment2", "comment2", TimeInterval(550, 660));
	Date date2(10, 4, 2020);
	Day* chosenDay2 = calendar.searchDay(date2);
	if (chosenDay2 != nullptr) {
		chosenDay2->addAppointment(appointment2);
		cout << "Booked appointment ";
		appointment2.print();
	}

	while (running) {
		cout << "$ ";
		string command;
		cin >> command;
		if (command == "book") {
			calendar.book();
		}
		if (command == "agenda") {
			Date date = Parser::parseDate(cin);
			calendar.searchDay(date)->printAppointments();
		}
		if (command == "unbook") {
			calendar.unbook();
		}
		if (command == "holiday") {
			Date date = Parser::parseDate(cin);
			calendar.searchDay(date)->setAsHoliday();
			cout << "Day set as holiday.\n";
		}
		if (command == "find") {
			calendar.find();
		}
		if (command == "findslot") {
			calendar.findSlot();
		}
		if (command == "busydays") {
			calendar.busyDays();
		}
		if (command == "save") {
			calendar.save(fileName);
			cout << "Saved file " << fileName << endl;
		}
		if (command == "save_as") {
			cin >> fileName;
			calendar.save(fileName);
			cout << "Saved file " << fileName << endl;
		}
		if (command == "open") {
			cin >> fileName;
			calendar.load(fileName);
			cout << "Loaded data from " << fileName << endl;
		}
		if (command == "help") help();
		if (command == "exit") {
			calendar.save(fileName);
			running = false;
		}
	}
	return 0;
}
