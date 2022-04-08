#pragma once
//calendar.h
//calendar class declaration

#ifndef CALENDAR_H
#define CALENDAR_H
#include "stdafx.h"
#include <iostream>
class Calendar {
public:
	Calendar();
	Calendar(int, int, int);
	void incrementDate();
	void printWarn();
	void printDate();
	void setWarn(int, int, int);
private:
	int day;
	int week;
	int month;
	bool warn;
	int warnDay;
	int warnWeek;
	int warnMonth;
};

#endif
