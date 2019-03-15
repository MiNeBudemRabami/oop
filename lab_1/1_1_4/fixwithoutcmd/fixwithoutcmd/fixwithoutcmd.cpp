#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <deque>

using namespace std;

int main()
{
	ifstream f("input.txt");
	ofstream of("output.txt");

	string SearchString = "ABCD";
	string ReplaceString = "ZYX";

	int SearchStringLength = SearchString.length();

	deque <char> buffer;
	buffer.clear();
	int i = 0;
	char c = ' ';

	while (!f.eof())
	{
		int temp = f.get();
		if (temp == -1)
		{
			break;
		}
		c = temp;

		if (c == SearchString[i])
		{
			buffer.push_back(c);

			if (buffer.size() == SearchStringLength)
			{
				of << ReplaceString;
				buffer.clear();
			}
		}
		else
		{
			while (!buffer.empty())
			{
				of << buffer.front();
				buffer.pop_front();
			}

			if (c == SearchString[i])
			{
				buffer.push_back(c);

				if (buffer.size() == SearchStringLength)
				{
					of << ReplaceString;
					buffer.clear();
				}
			}
			else
			{
				of << c;
			}
		}
	}
}
