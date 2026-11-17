#include "MyArrayList.h"
#include <assert.h>

int main()
{
	MyArrayList arr;
	fstream stdIn;
	stdIn.open("std.txt");

	if (!stdIn.is_open())
	{
		cout << "파일을 열수없습니다";
		assert(false);
	}

	stdIn >> arr.setSmallestId() >> arr.setBiggestId();
	stdIn >> arr.


}