//CapitalizeA.cpp

// capitalize all words that start with a from 'input.txt' and store in 'output.txt'

#include "stdafx.h"
#include <string>
#include <iostream>
#include <sstream>
#include <cctype>
#include <fstream>

using namespace std;

int main()
{
	
	ifstream is; 
	string line;
	istringstream str; //string variable to hold input file data for manipulation
	ofstream os;
	os.open("output.txt");
	is.open("input.txt");
	
	while (!is.eof()) {
		getline(is, line);
		istringstream str(line);
		while(str) {
			string word;
			str >> word;
			if (word[0] == 'a') {
				word[0] = 'A';
			}
			os << word << ' ';
		}
	}
	is.close();	
	os.close();
	

    return 0;
}

