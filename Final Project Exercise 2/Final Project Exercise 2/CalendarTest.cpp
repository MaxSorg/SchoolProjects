// CalendarTest.cpp
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <conio.h>
#include"Calendar.h"
using namespace std;
int main()
{
	cout << "This program will prompt you to enter the current date.\n";
	cout << "It will then ask if you would like to set a reminder for students as to when the last day\nto drop a class is.";
	cout << "\nEnter todays date in the following format: \n(mm w d), mm is the month (1-12), w is the week (1-4), and d is the day (1-7): ";
	int m, w, d;
	cin >> m >> w >> d;
	Calendar c1(d, w, m);
	c1.printDate();
	cout << "Incrementing the date by one...\n";
	c1.incrementDate();
	c1.printDate();
	cout << "Would you like to set the aforementioned reminder? (Y/N)";
	char warn = 'N';
	cin >> warn;
	if (warn == 'Y' || 'y') {
		cout << "Please enter the reminder date in the same format as before: ";
		cin >> m >> w >> d;
		c1.setWarn(d, w, m);
	}
	cout << "Incrementing the date by one...\n";
	c1.incrementDate();
	c1.printDate();
	_getch();
    return 0;
}

