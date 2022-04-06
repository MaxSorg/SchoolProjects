//AddressTest.cpp

#include"stdafx.h"
#include <iostream>
#include <stdlib.h>
#include "List.h"
#include "AddressBook.h"

using namespace std;
void mainMenu(AddressBook& addresses);
void enterName(AddressBook& addresses);
void deleteName(AddressBook& addresses);
void changeName(AddressBook& addresses);
void generateBday(AddressBook& addresses);
void generateAnni(AddressBook& addresses);

void resetInput();

int main()
{
	// Load the address book
	AddressBook addresses;
	addresses.load();

	// Start the mainMenu loop
	mainMenu(addresses);
	return 0;
}

void mainMenu(AddressBook& addresses)
{
	// Display main menu
	cout << "* * * * * * * * * Main Menu * * * * * * * * *" << endl;
	cout << "1. Enter a new name" << endl;
	cout << "2. Delete a name" << endl;
	cout << "3. Change a name or date" << endl;
	cout << "4. Generate birthday cards" << endl;
	cout << "5. Generate anniversary cards" << endl;
	cout << "6. Exit the program" << endl;
	cout << "7. Print address book." << endl;
	cout << "Length of book: " << addresses.getLength();
	cout << "Select a code: ";

	//user input determines which case to select

	int code;
	cin >> code;
	cout << endl;

	// exception handling if they enter wrong code data type (string, etc.)
	while (cin.fail())
	{
		resetInput();
		cout << "Input failed. Enter code here: ";
		cin >> code;
		cout << endl;
	}

	// select case for function based on inputted data
	switch (code)
	{
	case 1:
		cout << "Enter Name: " << endl;
		enterName(addresses);
		break;
	case 2:
		cout << "Delete Name: " << endl;
		deleteName(addresses);
		break;
	case 3:
		cout << "Change Name: " << endl;
		changeName(addresses);
		break;
	case 4:
		cout << "Generate Birthday card: " << endl;
		generateBday(addresses);
		break;
	case 5:
		cout << "Generate Anniversary card: " << endl;
		generateAnni(addresses);
		break;
		// Saves and exits the program
	case 6:
		cout << "Closing.." << endl;		
		exit(0);// Exits the program
		break;
	case 7:
		cout << "Printing Address Book: " << endl;
		addresses.printAll();
		break;
	default:
		// if none of these cases
		cerr << "Sorry, wrong number." << endl;
		break;
	};
	mainMenu(addresses);
}

void enterName(AddressBook& addresses)
{
	resetInput();
	// takes user input and stores in temporary object
	AddressBook cur;
	cout << "Enter name:";
	getline(cin, cur.name);

	cout << "Enter Address:";
	getline(cin, cur.streetAddress);

	cout << "Enter Birthday:";
	getline(cin, cur.bday);

	cout << "Enter Anniversary:";
	getline(cin, cur.anni);

	cout << endl;

	// send object to add function to create new address book entry
	addresses.add(cur);
}

void deleteName(AddressBook& addresses)
{
	resetInput();
	// user inputs required name to be deleted
	string name;
	cout << "Enter name to delete: ";
	getline(cin, name);
	cout << endl;

	// delete it
	addresses.remove(name);
}

void changeName(AddressBook& addresses)
{
	resetInput();
	// user inputs name to be renamed
	string name;
	cout << "Enter name to rename: ";
	getline(cin, name);

	// search for name, create new object
	AddressBook addressToBeDeleted = addresses.print(name);

	//if address doesnt exist, exit
	if (addressToBeDeleted.name == "NULL")
	{
		cerr << "Does not exist" << endl;
		return;
	}


	// new address
	AddressBook* changeAddress = new AddressBook;
	changeAddress->streetAddress = addressToBeDeleted.streetAddress;	
	changeAddress->bday = addressToBeDeleted.bday;
	changeAddress->anni = addressToBeDeleted.anni;
	
	addresses.remove(name);

	// get new name
	cout << "Enter new name: ";
	getline(cin, name);
	cout << endl;
	changeAddress->name = name;

	// add to the address book
	addresses.add(*changeAddress);
}

void generateBday(AddressBook& addresses)
{
	resetInput();
	// get date
	string date;
	cout << "Enter date: ";
	cin >> date;

	// generate card
	addresses.generateBday(date);
}

void generateAnni(AddressBook& addresses)
{
	
	// get date
	string date;
	cout << "Enter date: ";
	cin >> date;

	// Generate card
	addresses.generateAnni(date);
}

void resetInput()
{
	// if input fails, ignore line
	if (cin.fail())
	{
		// flushes buffer
		cin.clear();
		
	}

	// ignore newline character
	if (cin.peek() == '\n')
	{
		cin.ignore();
	}
}