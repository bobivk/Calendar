#pragma once
#include"Day.h"
#include"Parser.h"
#include<vector>
#include<algorithm>
#include<fstream>

class Calendar
{
	std::vector<Day> days;

public:
	Calendar();
	~Calendar();
	void book();
	void addAppointment(Appointment*, Date);
	void unbook();
	void find();
	void findSlot();
	std::vector<Day>::iterator searchDay(Date date);
	void load(std::string fileName);
	void save(std::string fileName);
	void busyDays();
	void list();
	void mergeWith(std::string fileName);
};

