#pragma once
#include<iostream>
struct Date
{
	unsigned day;
	unsigned month;
	unsigned year;

	Date() = default;
	Date(unsigned day, unsigned month, unsigned year);
	bool operator==(Date& other) const;
	void operator++();
	void operator--();
	void print() const;
};

