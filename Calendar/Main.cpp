#include "Main.h"
#include<iostream>

int main() {
		TimeInterval t(0, 15);
		char name[5];
		char comment[5];
		std::cin >> name >> comment;
		Appointment a(name, comment, t);
		Calendar cal;
		cal.addAppointment(a);
		return 0;
}
