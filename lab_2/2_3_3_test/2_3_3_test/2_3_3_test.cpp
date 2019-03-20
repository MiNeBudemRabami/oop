#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

typedef map<string, string> dictionaryType;

void toLow(string &inputWord)
{
	for (unsigned int i = 0; i < inputWord.size(); i++)
	{
		inputWord[i] = tolower(inputWord[i]);
	}
}

void savingChanges(dictionaryType &dictionary, string file)
{
	ofstream f(file);
	for (auto it = dictionary.begin(); it != dictionary.end(); ++it)
	{
		f << it->first << std::endl;
		f << it->second << std::endl;
	}
}

void readingChanges(dictionaryType &dictionary, string file)
{
	ifstream f(file);
	string line, first;
	bool flag = false;
	while (getline(f, line))
	{
		if (!flag)
		{
			first = line;
		}
		else
		{
			dictionary[first] = line;
		}
		flag = !flag;
	}
}

void saveWithQuestion(dictionaryType &dictionary, string file, bool editFlag)
{
	if (!editFlag)
	{
		return;
	}

	cout << "Save (y/n)?" << endl;

	string ans;
	while (cin >> ans)
	{
		if (ans == "y")
		{
			savingChanges(dictionary, file);
			return;
		}
		else if (ans == "n")
		{
			return;
		}
	}
}

int main(int argc, char ** argv)
{
	if (argc != 2)
	{
		cout << "dictionary not mantioned" << endl;
	}
	else
	{
		dictionaryType dictionary;
		readingChanges(dictionary, argv[1]);
		bool editFlag = false;

		string inputWord;
		while (getline(cin, inputWord))
		{
			if (inputWord == "...")
			{
				saveWithQuestion(dictionary, argv[1], editFlag);
				break;
			}

			auto it = dictionary.find(toLow(inputWord));
			if (it == dictionary.end())
			{
				cout << "plz, input new translation" << endl;
				string line2;
				if (getline(cin, line2))
				{
					if (!line2.empty())
					{
						dictionary[toLow(inputWord)] = line2;
						editFlag = true;
					}
				}
			}
			else
			{
				cout << it -> second << endl;
			}
		}
	}
}