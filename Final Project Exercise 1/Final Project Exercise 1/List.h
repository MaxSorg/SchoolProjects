#pragma once
//List.h

#ifndef LIST_H
#define LIST_H
#include "stdafx.h"
#include <stdio.h>
#include <iostream>


template <typename Type>
class List
{
	
public:
	List();
	virtual ~List();
	int getLength();
	virtual void print();
	void add(Type value);
	void remove(Type value);
protected:
	int length;
	struct Node {

		Type val;
		Node* next;
	};
	Node* head;
	Node* tail;
	
};


template <typename Type>
List<Type>::List()
{	
	head = nullptr;
	tail = nullptr;

	length = 1;
}


template <typename Type>
List<Type>::~List()
{
	Node* prev = nullptr;
	Node* it = head;
	while (it != nullptr)
	{
		prev = it;
		it = it->next;
		delete prev;
	}
}


//Prints the list

template <typename Type>
void List<Type>::print()
{
	int index = 0;
	Node* it = head;
	while (it != nullptr)
	{
		std::cout << "{" << index << ":" << it->val << "}";
		if (it->next != nullptr)
		{
			std::cout << ", ";
		}
		it = it->next;
	}
}

//number of nodes in list
template <typename Type>
int List<Type>::getLength()
{
	return length;
}

template <typename Type>
void List<Type>::add(Type value)
{
	Node* newNode = new Node;
	newNode->val = value;
	newNode->next = nullptr;

	if (head == nullptr)
	{
		head = tail = newNode;
	}
	else
	{
		tail->next = newNode;
		tail = newNode;
	}
	length++;
}

//traverses list until match is found, then deletes
template <typename Type>
void List<Type>::remove(Type value)
{
	Node* it = head;
	Node* prev = nullptr;
	while (it->next != nullptr)
	{
		if (it->val == value)
		{
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
		}
		prev = it;
		it = it->next;
	}
	length--;
}

#endif 
