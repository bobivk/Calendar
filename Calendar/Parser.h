#pragma once
#include"Date.h"
#include"TimeInterval.h"
#include<string>
#include<fstream>
using namespace std;

struct Parser
{
	static Date parseDate(istream& input);
	static TimeInterval parseTimeInterval(istream& input);
	static unsigned parseTime(istream& input);
};

