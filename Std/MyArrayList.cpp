#include "MyArrayList.h"

MyArrayList::MyArrayList()
{
	size = 0;
	capacity = 4;
	stdList = new student*[capacity];
}

void MyArrayList::resize()
{
	if (size == capacity)
	{
		capacity *= 2;
		student** temp= new student*[capacity];
		for (int i = 0; i < this->size; i++)
		{
			temp[i] = stdList[i];
		}
		delete[] stdList;
		stdList = temp;
	}
}

void MyArrayList::insertStd(const student& std)
{
	student* tempStd = new student(std);
	//stdList의 크기가 0이면 id비교할필요없이 바로 대입해주기
	if (size == 0)
	{
		stdList[size] = tempStd;
		size++;
	}
	else
		//stdList의 크기가 1개보다많으면 이제 size - 1의 Id를 비교해서 새로들어올 Id가 더크면 젤뒤에 그냥넣지만 작다면 사이값에 대입하기 빈칸으로 만들고 뒤로 한칸씩밀어주기
	{
		//이게 새로운값이 젤 클때의 경우
		if (std.getId() > stdList[size - 1]->getId())
		{
			stdList[size] = tempStd;
			size++;
		}
		//새로들어올 값이 사이에 들어갈 경우
		else
		{
			int i = size - 2;
			while (std.getId() < stdList[i]->getId())
			{
				i--;
			}
			//i + 1 이가르키는 인덱스는 들어가야할 id의 위치와 같아졌다 
			size++;
			for (;i < size;i++)
			{
				
			}
		}
	}
}

void MyArrayList::pushList(int i)
//i에서 부터 size까지 쭉쭉밀어내는함수 (size는 안건들여도되나?)
{
	size++;
	
}
//이제 생성자만들어주고, 입력받은거 삽입하는 함수를 만들어줘야돼 이때 학번가지고 순서정하는거에 집중하기. -1차끝 중간값기준으로하면 좋을듯?
// delete구현하기 학번으로 찾아서 그학생을 삭제(size줄이고 앞으로한칸씩당기기)
//출력하는 코드짜기 오퍼레이팅으로 메인에서 안해도알아서되게끔