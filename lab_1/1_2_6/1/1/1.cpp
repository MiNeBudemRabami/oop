#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <deque>
#include <stdlib.h>

using namespace std;

const int intMax = 2147483647;

string reverse(string value)
{
	string revercedString;
	
	for (unsigned int i = value.size(); i > 0; i--)
	{
		if (value[i - 1] != '-')
		{
			revercedString.push_back(value[i - 1]);
		}
	}
	return revercedString;
}

int toInt(char curr, int sourceNotation)
{
	int currInt = curr;
	
	
	if ((curr >= '0') && (curr <= '9'))
	{
		currInt = curr - '0'; //48
	}
	else if ((curr >= 'A') && (curr <= 'Z'))
	{
		currInt = curr - 'A' + 10; //55
	}
	else if ((curr >= 'a') && (curr <= 'z'))
	{
		currInt = curr - 'a' + 10; //87
	}
	else
	{
		return -1;
	}
	

	if (currInt < sourceNotation)
	{
		return currInt;
	}
	else
	{
		return -1;
	}
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

int toDex(string &value, int sourceNotation)
{
	value = reverse(value);
	int dexValue = 0;
	int n = sourceNotation;
	int curr = 0;
	bool wasError = false;
	bool tooLong = false;

	for (unsigned int i = 0; i < value.size(); i++)
	{
		curr = toInt(value[i], sourceNotation);
		
		if (curr == -1)
		{
			wasError = true;
			break;
		}

		if (i > 9) 
		{
			tooLong = true;
			break;
		}

		if (dexValue > 147483647)
		{
			if (curr >= 2)
			{
				tooLong = true;
				break;
			}
			else
			{
				dexValue = curr * pow(n, i) + dexValue;
			}
		}
		else
		{
			dexValue = curr * pow(n, i) + dexValue;
		}
	}

	if (tooLong)
	{
		return -2;
	}
	else
	{
		if (wasError)
		{
			return -1;
		}
		else
		{
			return dexValue;
		}
	}
}

string toDest(int dexValue, int destinationNotation)
{
	string destValue;
	destValue.clear();
	int intOst = 0;
	char charOst = ' ';

	while (dexValue > 0)
	{
		intOst = dexValue % destinationNotation;
		charOst = toChar(intOst);
		dexValue = dexValue / destinationNotation;
		destValue.push_back(charOst);
	}

	destValue = reverse(destValue);
	return destValue;
}

int main(int argc, char** argv)
{
	if (argc < 3)
	{
		cout << "not enought arguments";
	}
	else
	{
		string stringSourceNotation = argv[1];
		//string stringSourceNotation = "10";
		string StringDestinationNotation = argv[2];
		//string StringDestinationNotation = "10";

		bool negative = false;
		bool waserror = false;

		string value = argv[3];

		//string value = "12345678";

		if ((stringSourceNotation.empty()) || (StringDestinationNotation.empty()) || (value.empty()))
		{
			cout << "was error";
		}
		else
		{
			int sourceNotation = toDex(stringSourceNotation, 10);
			int destinationNotation = toDex(StringDestinationNotation, 10);

			if (value[0] == '-')
			{
				negative = true;
			}

			int dexValue = toDex(value, sourceNotation);
			if (dexValue == -1)
			{
				cout << "unexpected symbol" << endl;
			}
			else
			{ 
				if (dexValue == -2)
				{
					cout << "too long" << endl;
				}
				else
				{
					string destValue = toDest(dexValue, destinationNotation);
					if (negative)
					{
						cout << '-';
					}
					cout << destValue << endl;
				}
			}
		}
	}
}