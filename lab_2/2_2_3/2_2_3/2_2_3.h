#pragma once

#include <string>
#include <deque>

using namespace std;

void replace(string SearchString, string ReplaceString, istream &in, ostream &out)
{
	deque <char> buffer;
	buffer.clear();
	char c = ' ';

	while (!in.eof())
	{
		int temp = in.get();
		if (in.eof())
		{
			break;
		}
		c = temp;

		if (c == SearchString[buffer.size()])
		{
			buffer.push_back(c);

			if (buffer.size() == SearchString.length())
			{
				out << ReplaceString;
				buffer.clear();
			}
		}
		else
		{
			if (!buffer.empty())
			{
				while (!buffer.empty())
				{
					out << buffer.front();
					buffer.pop_front();
				}
			}
			out << c;
		}
	}
}
