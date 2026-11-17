#pragma once
#include "Std.h"

class MyArrayList
{
private:
	student** stdList;
	int biggestStdId;
	int smallestStdId;
	int groupCnt;
	int stdCnt;

public:
	int getSmallestId() const;
	int setSmallestId();
	int getBiggestId() const;
	int setBiggestId();
	int getStdNum() const;
	int setStdNum();
	int getGroupNum() const;
	int setGroupNum();

	void addStd(const student&);
	void deleteStd(const student&);

};