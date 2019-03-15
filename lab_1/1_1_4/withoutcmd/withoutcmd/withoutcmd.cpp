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

	string SearchString = "";
	string ReplaceString = "";

	deque <char> buffer;
	buffer.clear();
	char c = ' ';

	while (!f.eof())
	{
		int temp = f.get();
		if (f.eof())
		{
			break;
		}
		c = temp;

		if (c == SearchString[buffer.size()])
		{
			buffer.push_back(c);

			if (buffer.size() == SearchString.length())
			{
				of << ReplaceString;
				buffer.clear();
			}
		}
		else
		{
			if (!buffer.empty())
			{
				
				while (!buffer.empty())
				{
					of << buffer.front();
					buffer.pop_front();
				}
				of << c;
			}
			else
			{
				of << c;
			}
		}
	}
}