#include "pch.h"
#include <iostream>
#include <string>
#include <deque>
#include "catch.hpp"

using namespace std;

int main(int argc, char** argv)
{
	if (argc < 3)
	{
		char curr;
		while (!cin.eof())
		{
			cin >> curr;
			cout << curr;
		}
	}
	else
	{
		string SearchString = argv[1];
		string ReplaceString = argv[2];
	

		deque <char> buffer;
		buffer.clear();
		char c = ' ';

		while (!cin.eof())
		{
			int temp = cin.get();
			if (cin.eof())
			{
				break;
			}
			c = temp;

			if (c == SearchString[buffer.size()])
			{
				buffer.push_back(c);

				if (buffer.size() == SearchString.length())
				{
					cout << ReplaceString;
					buffer.clear();
				}
			}
			else
			{
				if (!buffer.empty())
				{
					while (!buffer.empty())
					{
						cout << buffer.front();
						buffer.pop_front();
					}
				}
				cout << c;
			}
		}
	}
}