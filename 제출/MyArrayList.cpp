#include "MyArrayList.h"

MyArrayList::MyArrayList()
{
	size = 0;
	capacity = 4;
	stdList = new student * [capacity];
}

MyArrayList::~MyArrayList()
{
	for (int i = 0; i < size; i++)
	{
		delete stdList[i];
	}
	delete[] stdList;
	stdList = nullptr;
}

void MyArrayList::resize()
{
	if (size == capacity)
	{
		capacity *= 2;
		student** temp = new student * [capacity];
		for (int i = 0; i < this->size; i++)
		{
			temp[i] = stdList[i];
		}
		delete[] stdList;
		stdList = temp;
	}
}

bool MyArrayList::existSame(int id)
{
	//중복이 존재하는지 확인하는 함수 resize하는 타이밍을 재기위해서
	for (int i = 0; i < size ; i++)
	{
		if (stdList[i]->getId() == id)
		{
			return true;
		}
	}
	return false;
}

void MyArrayList::insertStd(int id, const MyString& group, const MyString& name)
{
	if (existSame(id) == true) return;

	resize();
	student* tempStd = new student(id, group, name);

	int insertPos;
	for (insertPos = size - 1; insertPos >= 0; insertPos--)
	{
		if (id < stdList[insertPos]->getId())
		{
			stdList[insertPos + 1] = stdList[insertPos];
		}
		else break;
	}
	stdList[insertPos + 1] = tempStd;

	size++;
}

void MyArrayList::deleteGroup(const MyString& g)
{
	for (int i = 0; i < size; i++)
	{
		if (g == stdList[i]->getGroup()) return;
	}
	groupCnt--;
}

void MyArrayList::deleteStd(int id)
{
	//1. id로 학생찾기 2. 학생지우기 3. 앞으로당기기
	//++ 그룹이름에대해서도 더이상 학생이없으면 그룹을 없애주기
	int deletePos;
	for (deletePos = 0; deletePos < size ; deletePos++)
	{
		if (id == stdList[deletePos]->getId())
		{
			MyString temp = stdList[deletePos]->getGroup();
			delete stdList[deletePos];
			
			for (int i = deletePos; i < size - 1; i++)
			{
				stdList[i] = stdList[i + 1];
			}
			size--;
			deleteGroup(temp);
			return;
		
		}
	}
}

//출력하기전에 가장큰 id와 작은 id를 수정하기
void MyArrayList::changeBiggest()
{
	if (stdList[size - 1]->getId() > biggestStdId) biggestStdId = stdList[size - 1]->getId();
}

void MyArrayList::changeSmallest()
{
	if (stdList[0]->getId() < smallestStdId) smallestStdId = stdList[0]->getId();
}

void MyArrayList::printAll(ostream& out)
{
	if (size == 0)
	{
		return;
	}
	changeSmallest();
	changeBiggest();

	out << smallestStdId << "-" << biggestStdId << endl;

	out << size << " " << groupList.getSize() << endl;

	for (int i = 0; i < size; i++)
	{
		out << stdList[i]->getId() << " " << stdList[i]->getGroup() << " " << stdList[i]->getName() << endl;
	}
}

// 그룹이름을 배열로 저장하는거랑 그냥 MyString으로 저장하는거랑차이