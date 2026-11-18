#pragma once
#include <fstream>
#include <iostream>
#include "MyString.h"

class student
{
private:
	char groupName[2];
	int stdId;
	MyString stdName;

public:
	void deleteStd(int);
	void addStd(student);
	student(int id, char group[2], const MyString& name)
		:stdId(id), stdName(name)
	{
		groupName[0] = group[0];
		groupName[1] = group[1];
	}
	int getId() const { return stdId; }


};