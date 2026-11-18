#pragma once
#include "Std.h"

class MyArrayList
{
private:
	student** stdList;
	//int biggestStdId;
	//int smallestStdId;
	//int groupCnt;
	//int stdCnt;
	int capacity;
	int size;

public:
	MyArrayList() {};
	void resize();
	/*void appendStd(const student&);*/
	void insertStd(const student&);
	void deleteStd(const student&);
	void pushList(int);

};