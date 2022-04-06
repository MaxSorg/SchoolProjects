//AddressBook.cpp
//AddressBook class definition

#include "stdafx.h"
#include <string>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "AddressBook.h"
AddressBook::AddressBook(){}
AddressBook::AddressBook(std::string name, std::string streetAddress, std::string bday, std::string anni) {
	this->name = name;
	this->streetAddress = streetAddress;
	this->bday = bday;
	this->anni = anni;
}

AddressBook::~AddressBook() {
	//destructor
}

void AddressBook::printAll() {
	
		Node* it = head;
		while (it != nullptr)
		{
			std::cout << it->val << std::endl;
			it = it->next;
		}
	
}

std::string AddressBook::getName() {
	return name;
}

void AddressBook::remove(std::string name) {
	// start the iterator at the head
	
	Node* prev = nullptr;
	Node* it = head;
	
	while (it != nullptr)
	{
		//get name
		std::string curName = ((AddressBook)it->val).getName();

		// if name matches one wanting deletion
		if (curName == name)
		{
			// traverse list
			if (prev == nullptr)
			{
				head = it->next;
				delete it;
			}
			
			else
			{
				prev->next = it->next;
				delete it;
			}
			// Decrease the length on removal
			length--;
		}
		// Set the previous node to be the iterator
		prev = it;
		// Set the iterator to the next value
		it = it->next;
	}
}
	

AddressBook AddressBook::print(std::string name) {
	// Set the iterator to the head of the linked list
	Node* it = head;

	// While our name isn't found, and we haven't gone through the whole list
	while (it != nullptr)
	{
		// Extract the iterators name
		std::string curName = ((AddressBook)it->val).name;

		// If the iterators name is equal to the wanted name, then the value is found and returned
		if (curName == name)
		{
			return it->val;
		}
		it = it->next;
	}

	// If the address wasn't found, return the address with the name of NULL
	AddressBook nullAdd;
	nullAdd.name = "NULL";
	return nullAdd;
}

void AddressBook::generateBday(std::string date) {
	// Go through every address
	Node* it = head;
	while (it != nullptr)
	{
		// If it's birthday is equal to the date passed in, print it's birthday card
		AddressBook curAddress = ((AddressBook)it->val);
		if (date == curAddress.bday)
		{
			printBday(curAddress);
		}
		it = it->next;
	}
}

void AddressBook::printBday(AddressBook curAddress) {
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "Dear " << curAddress.name << "," << std::endl << std::endl;
	std::cout << "Have a happy birthday!" << std::endl;	
}

void AddressBook::generateAnni(std::string date) {
	// Go through every address
	Node* it = head;
	while (it != nullptr)
	{
		// If it's anniversary is equal to the date passed in, print it's birthday card
		AddressBook curAddress = ((AddressBook)it->val);
		if (date == curAddress.anni)
		{
			printAnni(curAddress);
		}
		it = it->next;
	}
}

void AddressBook::printAnni(AddressBook curAddress) {
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "Dear " << curAddress.name << "," << std::endl << std::endl;
	std::cout << "Have a happy anniversary!" << std::endl;
}

void AddressBook::add(AddressBook newAddress) {
	// Create a new node with our address
	Node* newNode = new Node;
	newNode->val = newAddress;
	newNode->next = nullptr;

	
	if (head == nullptr)
	{
		head = tail = newNode;
	}
	else
	{
		// Create an iterator, and previous iterator
		Node* prev = nullptr;
		Node* it = head;

		// traverse list
		while (it != nullptr)
		{
			// compare new name to current names alphabetically
			std::string curName = ((AddressBook)it->val).name;
			if (curName > newAddress.name)
			{
				
				if (prev == nullptr)
				{
					head = newNode;
					newNode->next = it;
				}
				else
				{
					prev->next = newNode;
					newNode->next = it;
				}
				return;
			}
			else
			{
				
				if (it->next == nullptr)
				{
					it->next = newNode;
					it = newNode->next;
				}
				else
				{
					prev = it;
					it = it->next;
				}

			}

		}
	}
	// Increment the length when an item is added
	++length;
}

void AddressBook::load() {
	
	std::ifstream in;
	in.open("initial.properties");

	// If the file doesnt exist, print error
	if (!in.good())
	{
		std::cerr << "Cannot open initial.properties" << std::endl;
		return;
	}

	
	while (in.good())
	{
		// create new AddressBook object, load info from input file
		AddressBook* curAddress = new AddressBook;
		std::string temp;

		getline(in, temp);
		curAddress->name = temp;

		getline(in, temp);
		curAddress->streetAddress = temp;
		
		getline(in, temp);
		curAddress->bday = temp;

		getline(in, temp);
		curAddress->anni = temp;

		// add new address
		if (in.good())
		{
			add(*curAddress);
		}
	}

	// close stream
	in.close();
}

std::ostream& operator<<(std::ostream& output, const AddressBook& curAddress)
{
	
	output << "Name:             " << curAddress.name << std::endl
		<< "Address:          " << curAddress.streetAddress << std::endl
		<< "Birthday: " << curAddress.bday << std::endl
		<< "Anniversary:    " << curAddress.anni << std::endl;
	return output;
}