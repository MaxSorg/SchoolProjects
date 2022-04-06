#pragma once
//listnode class tempalte definintion

#ifndef LISTNODE_H
#define LISTNODE_H

#include "stdafx.h"
template<typename Type>class List;

template<typename Type>
class ListNode {
	friend class List<Type>;
public:
	explicit ListNode(const Type& info)
		: data{ info }, nextPtr{ nullptr } {}

	Type getData() const { return data; }
private:
	Type data;
	List<Type>* nextPtr;
};

#endif

