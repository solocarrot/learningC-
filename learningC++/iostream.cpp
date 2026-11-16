//#include <fstream>
//using std::ifstream;
//using std::ofstream;
//using std::endl;
//
//int main()
//{
//	ifstream inStream;
//	ofstream outStream;
//
//	inStream.open("infile.txt");
//	outStream.open("outfile.txt");
//
//	int first, second, third;
//	inStream >> first >> second >> third;
//	outStream << "The sum of the 3\n"
//		<< "numbers in infile.txt\n"
//		<< "is " << (first + second + third)
//		<< endl;
//
//	inStream.close();
//	outStream.close();
//
//
//}	

#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

int main(int argc, char* argv[])
{
	char ch;
	ifstream istr;
	ofstream ostr;

	istr.open(argv[1], ios::in);
	if (!istr.is_open())
	{
		cout << argv[1] << "을 열수없습니다." << endl;
		assert(false);
	}

}