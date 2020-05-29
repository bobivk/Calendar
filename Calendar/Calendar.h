#pragma once
#include"Day.h"
#include"Parser.h"
#include<vector>
#include<algorithm>
#include<fstream>

class Calendar
{
	vector<Day> days;

public:
	Calendar(std::string filename);
	Day* searchDay(Date date);
	void book();
	void unbook();
	void find();
	void findSlot();
	void load(std::string fileName);
	void save(std::string fileName);
	void busyDays();
};

