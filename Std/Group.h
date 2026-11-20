#pragma once
#include "MyString.h"

class Group
{
private:
	MyString* group;
	int capacity;
	int size;
public:
	Group() {};
	void reSize();
	void addGroup(const MyString&);
	//void deleteGroup(const MyString&);
};