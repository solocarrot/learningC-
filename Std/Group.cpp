#include "Group.h"

Group::Group()
{
	capacity = 4;
	size = 0;
}

void Group::reSize()
{
	if (size == capacity)
	{
		MyString* temp = new MyString[capacity * 2];
		for (int i = 0; i < size; i++)
		{
			temp[i] = group[i];
 		}
		delete[] group;
		group = temp;
		capacity *= 2;
	}
}

//txt를 읽으면서 학생을 MyArrayList에 추가할때 그룹이 있나없나 확인하고 없으면 추가하기
void Group::addGroup(const MyString& g)
{
	for (int i = 0; i < size; i++)
	{
		if (g == group[i])
		{
			return;
		}
	}
	reSize();
	group[size] = g;
	size++;
}

//딜리트그룹은 MyArrayList에서 해결해야되는 데 좀 찝찝함.
//void Group::deleteGroup(const MyString& g)
//{
//	for (int i = 0; i < size; i++)
//	{
//		if (g == group[i])
//		{
//			 
//		}
//	}
//}