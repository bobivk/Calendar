#pragma once
#include<iostream>
#include<fstream>
struct Date
{
	unsigned day;
	unsigned month;
	unsigned year;

	Date() = default;
	Date(unsigned day, unsigned month, unsigned year);
	Date(const Date& other);
	bool operator==(const Date& other) const;
	void operator++();
	void operator--();
	void print(std::ostream& out) const;
};

