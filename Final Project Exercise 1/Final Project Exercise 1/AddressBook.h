#pragma once
// AddressBook.h
// Class declaration for AddressBook

#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include "stdafx.h"
#include <string>
#include <iostream>
#include "List.h"


class AddressBook : public List<AddressBook> {
	friend class List<AddressBook>;
	friend std::ostream& operator << (std::ostream&, const AddressBook&);
public:
	AddressBook();
	AddressBook(std::string, std::string, std::string, std::string); //constructor
	~AddressBook(); //destructor
	void printAll(); //prints all
	void add(AddressBook);
	void remove(std::string);
	AddressBook print(std::string); //prints specific address
	void generateBday(std::string); //generates birthday cards
	void printBday(AddressBook);
	void generateAnni(std::string); //generates anniversary cards
	void printAnni(AddressBook);
	void load(); //loads initial addresses from initial.properties	
	std::string getName();

	std::string name; //name	
	std::string streetAddress; //street address	
	std::string bday; //birthday
	std::string anni; //anniversary
};

#endif
