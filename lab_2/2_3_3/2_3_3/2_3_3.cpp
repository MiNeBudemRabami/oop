#include "pch.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

void print(string & word)
{
	cout << word;
}

void toLow(string & inputWord)
{

	for (unsigned int i = 0; i < inputWord.size(); i++)
	{
		
	}
}

void savingChanges()
{
}

void translate(string & inputWord)
{
	toLow(inputWord);

}

int main()
{
	string inputWord = "";
	for (;;)
	{
		cin >> inputWord;

		if (inputWord == "...")
		{
			savingChanges();
			break;
		}

		translate(inputWord);

	}
}