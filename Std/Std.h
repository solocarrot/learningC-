#pragma once
#include <fstream>
#include <iostream>
#include "MyString.h"
#include "Group.h"

class student
{
private:
	Group stdGroup;
	int stdId;
	MyString stdName;

public:
	void deleteStd(int);
	void addStd(student);
	student(int id, const MyString& group, const MyString& name)
		:stdId(id), stdName(name)
	{
		stdGroup.addGroup(group);
	}
	int getId() const { return stdId; }
	MyString& getGroup() const { return	 }


};