#pragma once
#include"Date.h"
#include"TimeInterval.h"
#include<string>
using namespace std;

struct Parser
{
	static Date parseDate(string dateString);
	static TimeInterval parseTimeInterval(string startTimeString, string endTimeString);
};

