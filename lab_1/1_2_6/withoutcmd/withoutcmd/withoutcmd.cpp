#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <deque>
#include <stdlib.h>

using namespace std;

string reverse(string value)
{
	string revercedString;
	revercedString.clear();

	for (unsigned int i = value.size(); i > 0 ; i--)
	{
		if (value[i-1] != '-')
		{
			revercedString.push_back(value[i-1]);
		}
	}

	return revercedString;
}

int toInt(char curr)
{
	int currInt = curr;
	if ((curr >= '0') && (curr <= '9'))
	{
		currInt = curr - 48;
	}
	if ((curr >= 'A') && (curr <= 'Z'))
	{
		currInt = curr - 55;
	}
	if ((curr >= 'a') && (curr <= 'z'))
	{
		currInt = curr - 87;
	}
	return currInt;
}
 
char toChar(int currInt)
{
	char currChar = ' ';
	if ((currInt >= 0) && (currInt <= 9))
	{
		currChar = currInt + 48;
	}
	if ((currInt >= 10) && (currInt <= 15))
	{
		currChar = currInt + 55;
	}

	return currChar;
}

int toDex(string value, int sourceNotation)
{
	value = reverse(value);
	int dexValue = 0;
	int n = sourceNotation;
	int curr = 0;

	for (int i = 0; i <= value.size(); i++)
	{
		curr = toInt(value[i]);
		dexValue = curr * pow(n, i) + dexValue;
	}
	return dexValue;
}

string toDest(int dexValue, int destinationNotation)
{
	string destValue;
	destValue.clear();
	int intOst = 0;
	char charOst = ' ';

	while (dexValue > 1)
	{
		intOst = dexValue % destinationNotation;
		charOst = toChar(intOst);
		dexValue = dexValue / destinationNotation;
		destValue.push_back(charOst);
	}
	charOst = toChar(dexValue);
	destValue.push_back(charOst);
	destValue = reverse(destValue);
	return destValue;
}

int main()
{
	int sourceNotation = 16;
	int destinationNotation = 10;
	bool negative = true;

	string value = "-1e1A0";
	
	if (value[0] == '-')
	{
		negative = true;
	}

	int dexValue = toDex(value, sourceNotation);
	string destValue = toDest(dexValue, destinationNotation);

	if (negative)
	{
		cout << '-';
	}
	cout << destValue;
}