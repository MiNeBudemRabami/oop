#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <deque>

using namespace std;

int main(int argc, char** argv) 
{
	ifstream f("input.txt");
	ofstream of("output.txt");

	string SearchString = argv[1];
	string ReplaceString = argv[2];

	deque <char> buffer;
	buffer.clear();
	char c = 0;

	while (!f.eof())
	{
		int temp = f.get();
		
		if (temp = -1)
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
