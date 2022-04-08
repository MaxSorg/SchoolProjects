//calendar.cpp
//calendar class definition

#include "stdafx.h"
#include <iostream>
#include<string>
#include "Calendar.h"
using namespace std;
Calendar::Calendar() {
	day = 1;
	week = 1;
	month = 1;
	warn = false;
	}

Calendar::Calendar(int day, int week, int month) {
	this->day = day;
	this->week = week;
	this->month = month;
}

void Calendar::incrementDate() {
	if (day == 7) {
		if (week == 4) {
			if (month == 12) {
				day = 1;
				week = 1;
				month = 1;
			}
			else month++;
			week = 1;
			day = 1;
		}
		else week++;
		day = 1;	
	}
	else day++;
	if (warn == true) {
		printWarn();
	}
	
}

void Calendar::setWarn(int day, int week, int month) {
	warnDay = day;
	warnWeek = week;
	warnMonth = month;
	warn = true;
}

void Calendar::printWarn() {
	if (warnDay == day && warnWeek == week && warnMonth == month) {
		cout << "Warning, last chance to drop your class is today!\n";
	}
}

void Calendar::printDate() {
	cout << "Todays date is " << month << "/" << week << "/" << day << endl;
}