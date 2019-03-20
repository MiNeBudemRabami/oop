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
		if ((inputWord[i] >= 'A') && (inputWord[i] <= 'Z'))
		{
			inputWord[i] = inputWord[i] + 'Z' - 'A';
		}
		else if ((inputWord[i] >= 'a') && (inputWord[i] <= 'z'))
		{
			//its ok
		}
		else if ((inputWord[i] >= 'А') && (inputWord[i] <= 'Я'))
		{
			inputWord[i] = inputWord[i] + 'А' - 'Я';
		}
		else if ((inputWord[i] >= 'а') && (inputWord[i] <= 'я'))
		{
			//ok again
		}
		else
		{
			inputWord = "-1";
			break;
		}
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