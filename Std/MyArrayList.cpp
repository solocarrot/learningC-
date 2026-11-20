#include "MyArrayList.h"

MyArrayList::MyArrayList()
{
	size = 0;
	capacity = 4;
	stdList = new student * [capacity];
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
	for (int i = 0; i < size - 1; i++)
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
	////stdList의 크기가 0이면 id비교할필요없이 바로 대입해주기
	//if (size == 0)
	//{
	//	stdList[size] = tempStd;
	//	size++;
	//}
	//else
	//	//stdList의 크기가 1개보다많으면 이제 size - 1의 Id를 비교해서 새로들어올 Id가 더크면 젤뒤에 그냥넣지만 작다면 사이값에 대입하기 빈칸으로 만들고 뒤로 한칸씩밀어주기
	//{
	//	//이게 새로운값이 젤 클때의 경우
	//	if (id > stdList[size - 1]->getId())
	//	{
	//		stdList[size] = tempStd;
	//		size++;
	//	}
	//	//새로들어올 값이 사이에 들어갈 경우
	//	else
	//	{
	//		int i = size - 2;
	//		while (id < stdList[i]->getId())
	//		{
	//			i--;
	//		}
	//		//i + 1이 가르키는 인덱스는 들어가야할 id의 위치와 같아졌다 
	//		size++;
	//		for (int j = i + 1;j < size - 1;j++)
	//		{
	//			stdList[j + 1] = stdList[j];
	//		}
	//		stdList[i + 1] = tempStd;
	//	}
	//}
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


//		if (id > stdList[deletePos]->getId()) continue;
//		else if(id == stdList[deletePos]->getId())
//		{
//			//id가 deletePos의 위치에 있는 값과 같다면 덮어씌우고 id도 바꿔주기
//			stdList[deletePos] = stdList[deletePos + 1];
//			id = stdList[deletePos]->getId();
//		}
//		else
//		{
//			cout << "제거할 값을 찾을 수 없습니다";
//			break;
//		}
//
//	}
//
//	//마지막학생을 nullptr로만들고 size를 한칸줄이기
//	stdList[size - 1] = nullptr;
//	size--;
//
//}

// 들어올 때마다 최댓값을 변경하는 함수들
// 
//void MyArrayList::changeBiggest1(int id)
//{
//	if (id > biggestStdId) biggestStdId = id;
//}
//
//void MyArrayList::changeSmallest1(int id)
//{
//	if (id < smallestStdId) smallestStdId = id;
//}

//출력하기전에 가장큰 id와 작은 id를 수정하기
void MyArrayList::changeBiggest()
{
	if (stdList[size - 1]->getId() > biggestStdId) biggestStdId = stdList[size - 1]->getId();
}

void MyArrayList::changeSmallest()
{
	if (stdList[0]->getId() < smallestStdId) smallestStdId = stdList[0]->getId();
}




// 1. 학생삽입에서 학번같은경우구현 (resize를 하는타이밍에 유의) 
// 2. insert하면서 최고학번 최저학번 학생수 그룹수 바꾸는것도 구현하기 출력하기전에 하는게 좋겠ㅈ? insert랑 delete할때ㅎ마다하는게좋으듯
// 3. 출력하는 함수구현하기.


// 그룹이름을 배열로 저장하는거랑 그냥 MyString으로 저장하는거랑차이