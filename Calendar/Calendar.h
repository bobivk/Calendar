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
	Calendar();
	Day* searchDay(Date date);
	void book();
	void unbook();
	void find();
	void findSlot();
	void load(string fileName);
	void save(string fileName);
	void busyDays();
};

