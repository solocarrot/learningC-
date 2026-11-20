#pragma once
#include "Std.h"
#include <assert.h>

class MyArrayList
{
private:
	student** stdList;
	int biggestStdId;
	int smallestStdId;
	int groupCnt;
	int stdCnt;
	int capacity;
	int size;

public:
	MyArrayList() {};
	void resize();
	bool existSame(int);
	void insertStd(int, const MyString&, const MyString&);
	void deleteStd(int);
	void pushList(int);

	void changeBiggest();
	void changeSmallest();

	void deleteGroup(const Group&);
	void printAll(std::ostream& out);
};