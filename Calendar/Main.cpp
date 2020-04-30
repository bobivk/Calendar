#include "Main.h"
#include<iostream>]
#include<string>
using namespace std;

int main() {
		cout << "Welcome to your personal calendar\n";
		cout << "Choose an option:\n";
		cout << "1. book <appointment_name> <appointment_comment> <date> <start_time> <end_time>\n";
		cout << "2. agenda <date>\n";
		cout << "3. unbook <date> <start_time> <end_time>\n";

		cout << "exit\n";
		cout << "Please enter dates in the format <DD.MM.YYYY> and time in the format <HH:MM>.\n";
		Calendar calendar;
		bool running = true;
		while (running) {
			string command;
			cin >> command;
			if (command == "book") {
				calendar.book();
			}
			if (command == "agenda") {
				string dateStr;
				cin >> dateStr;
				Date date = Parser::parseDate(dateStr);
				calendar.searchDay(date)->printAppointments();
			}
			if (command == "unbook") {
				calendar.unbook();
			}
			if (command == "exit") running = false;
		}
		return 0;
}
