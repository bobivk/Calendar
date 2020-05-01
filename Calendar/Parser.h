#pragma once
#include"Date.h"
#include"TimeInterval.h"
#include<string>
using namespace std;

struct Parser
{
	static Date parseDate();
	static TimeInterval parseTimeInterval();
};

