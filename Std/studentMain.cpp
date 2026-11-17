#include "MyArrayList.h"
#include <assert.h>

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		cout << "오류발생";
		assert(false);
	}
	MyArrayList arr;
	fstream stdIn;
	stdIn.open(argv[1]);

	if (!stdIn.is_open())
	{
		cout << "파일을 열수없습니다";
		assert(false);
	}

	int smallestId, biggestId;
	stdIn >> smallestId >> biggestId;
	
	int	stdCnt, groupCnt;
	stdIn >> stdCnt >> groupCnt;

	int stdId;
	char groupName[2];
	MyString name1, name2;

	stdIn >> stdId >> groupName >> name1 >> name2;
	student* std = new student(stdId, groupName, name1 + name2);
	//학생 객체를만들었으니까 이제 MyArr(student주소를 가지는 주소의배열)에 대입하기
	//근데 대입할때 이 순서도 중요한데 와우 

}