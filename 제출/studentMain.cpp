#include "MyArrayList.h"
#include <fstream>
#include <cstring>
#include <assert.h>

using namespace std;

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        cout << "오류발생" << endl;
        assert(false);
    }

    MyArrayList arr;
    ifstream stdIn;
    stdIn.open(argv[1]);

    if (!stdIn.is_open())
    {
        cout << "파일을 열수없습니다" << endl;
        assert(false);
    }


    int smallestId, biggestId;

    stdIn >> smallestId >> biggestId;


    int stdCnt, groupCnt;
    stdIn >> stdCnt >> groupCnt;
  


    int stdId;
    MyString groupName;
    MyString name1, name2;

    for (int i = 0; i < stdCnt; i++)
    {
        stdIn >> stdId >> groupName >> name1 >> name2;
        arr.insertStd(stdId, groupName, name1 + " " + name2);
    }
    stdIn.close();

    char cmd;
    while (true)
    {
        cin >> cmd;

        if (cmd == 'L')
        {
            arr.printAll();
        }
        else if (cmd == 'I')
        {
            cin >> stdId >> groupName >> name1 >> name2;
            arr.insertStd(stdId, groupName, name1 + " " + name2);
        }
        else if (cmd == 'D')
        {
            cin >> stdId;
            arr.deleteStd(stdId);
        }
        else if (cmd == 'Q')
        {
            ofstream stdOut;
            stdOut.open(argv[1]);
            arr.writeData(stdOut);
            stdOut.close();
            break;
        }
    }

    return 0;
}