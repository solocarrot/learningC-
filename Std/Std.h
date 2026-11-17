#pragma once
#include <fstream>
#include <iostream>
#include "MyString.h"

class student
{
private:
	char groupNum[2];
	int stdId[8];
	MyString stdName;

public:
	void deleteStd(int);
	void addStd(student);

};

