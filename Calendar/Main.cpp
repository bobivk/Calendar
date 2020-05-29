#include"Calendar.h"
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
	cout << "7. findslotwith <from_date> <length_in_hours> <calendar_filename>\n";
	cout << "8. busydays <from_date> <to_date>\n";
	cout << "9. list\n";
	cout << "10. merge <calendar_filename>\n";
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
	string fileName = "calendar.txt";
	calendar.load(fileName);

	
	Appointment* appointment = new Appointment("appointment1", "comment1", TimeInterval(480, 540));
	Date date(10, 4, 2020);
	calendar.addAppointment(appointment, date);
	Appointment* appointment2 = new Appointment("appointment2", "comment2", TimeInterval(550, 660));
	Date date2(10, 4, 2020);
	calendar.addAppointment(appointment2, date2);

	while (running) {
		cout << "$ ";
		string command;
		cin >> command;
		if (command == "book") {
			calendar.book();
		}
		else if (command == "agenda") {
			Date date = Parser::parseDate(cin);
			calendar.searchDay(date)->logAppointments();
		}
		else if (command == "unbook") {
			calendar.unbook();
		}
		else if (command == "holiday") {
			Date date = Parser::parseDate(cin);
			calendar.searchDay(date)->setAsHoliday();
			date.print(cout);
			cout << " set as holiday.\n";
		}
		else if (command == "find") {
			calendar.find();
		}
		else if (command == "findslot") {
			calendar.findSlot();
		}
		else if (command == "findslotwith") {
			
		}
		else if (command == "busydays") {
			calendar.busyDays();
		}
		else if (command == "list") {
			calendar.list();
		}
		else if (command == "merge") {
			string mergingFileName;
			cin >> mergingFileName;
			calendar.mergeWith(mergingFileName);
		}
		else if (command == "save") {
			calendar.save(fileName);
			cout << "Saved file " << fileName << endl;
		}
		else if (command == "save_as") {
			cin >> fileName;
			calendar.save(fileName);
			cout << "Saved file " << fileName << endl;
		}
		else if (command == "open") {
			cin >> fileName;
			calendar.load(fileName);
			cout << "Loaded data from " << fileName << endl;
		}
		else if (command == "help") help();
		else if (command == "exit") {
			calendar.save(fileName);
			running = false;
		}
		else cout << "Invalid command.\n";
	}
	return 0;
}

