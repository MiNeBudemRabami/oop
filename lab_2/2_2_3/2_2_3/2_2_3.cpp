#include "pch.h"
#include <iostream>
#include "2_2_3.h"

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

		replace(SearchString, ReplaceString, cin, cout);
	}
}