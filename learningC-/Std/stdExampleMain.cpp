//#include "stdExample.h"
//
//int main()
//{
//	fstream stdOutStrm;
//	stdOutStrm.open("File1.txt", ios::binary | ios::out);
//	if (!stdOutStrm.is_open())
//	{
//		cout << "File1 can not be opened";
//		assert(false);
//	}
//
//	Student std1(1, "John", 3.1);
//	Student std2(2, "Mary", 4.0);
//	Student std3(3, "yoon", 0.8);
//
//	stdOutStrm.write(reinterpret_cast<char*>(&std1), sizeof(Student));
//	stdOutStrm.write(reinterpret_cast<char*>(&std2), sizeof(Student));
//	stdOutStrm.write(reinterpret_cast<char*>(&std3), sizeof(Student));
//}