#pragma once
class Date
{
	unsigned day{ 0 };
	unsigned month{ 0 };
	unsigned year{ 0 };
public:
	Date() = default;
	Date(unsigned day, unsigned month, unsigned year);
};


