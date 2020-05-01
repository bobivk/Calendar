#pragma once
#include"Day.h"
#include"Parser.h"
#include<vector>

class Calendar
{
	vector<Day> days;

public:
	Calendar();
	Day* searchDay(Date date);
	void book();
	void unbook();
	void find();
};

