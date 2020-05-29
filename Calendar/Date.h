#pragma once
#include<iostream>
struct Date
{
	unsigned day;
	unsigned month;
	unsigned year;

	Date() = default;
	Date(unsigned day, unsigned month, unsigned year);
	Date(const Date& other);
	bool operator==(Date& other) const;
	void operator++();
	void operator--();
	void print(std::ostream& out) const;
};

