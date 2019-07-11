#include "pch.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
	ifstream etalon1(argv[2]);
	ifstream result1(argv[1]);

	bool isequal = true;
	char ResChar, EtalChar;
	for (;;)
	{
		ResChar = result1.get();

		EtalChar = etalon1.get();

		if (ResChar == EtalChar)
		{
			isequal = true;
		}
		else
		{
			isequal = false;
			break;
		}

		if (result1.eof() && etalon1.eof())
		{
			isequal = true;
			break;
		}

		if ((!result1.eof() && etalon1.eof()) || (result1.eof() && etalon1.eof()))
		{
			isequal = false;
			break;
		}
	}
	if (isequal)
	{
		cout <<  "test is done" << endl;
	}
	else
	{
		cout << "test falled" << endl;
	}
}