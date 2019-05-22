#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>

using namespace std;

typedef map<string, set<string>> dictionaryType;

void toLow(string &word) //std locale
{
/*
	for (unsigned int i = 0; i < word.size(); i++)
	{
		word[i] = tolower(word[i]);
	}
*/
}

void savingChanges(dictionaryType &dictionary, string fileName)
{
	ofstream file(fileName);
	for (auto it = dictionary.begin(); it != dictionary.end(); ++it)
	{
		file << it->first << std::endl;
		for (auto &elem : it->second)
		{
			file << elem << std::endl;
		}
		file << "#end" << std::endl;
	}
}

void readingChanges(dictionaryType &dictionary, string fileName)
{
	ifstream file(fileName);
	string line, first;
	bool flag = false;
	while (getline(file, line))
	{
		if (!flag)
		{
			first = line;
			flag = true;
		}
		else
		{
			if (line != "#end")
			{
				dictionary[first].insert(line);
			}
			else
			{
				flag = false;
			}
		}
	}
}

void saveWithQuestion(dictionaryType &dictionary, string file, bool editFlag)
{
	if (!editFlag)
	{
		return;
	}

	cout << "Save (y/n)?" << endl;

	string answer;
	while (cin >> answer)
	{
		if (answer == "y")
		{
			savingChanges(dictionary, file);
			return;
		}
		else if (answer == "n")
		{
			return;
		}
	}
}

int main(int argc, char ** argv)
{
	if (argc != 2)
	{
		cout << "dictionary not mentioned" << endl;
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

			toLow(inputWord);

			auto it = dictionary.find(inputWord);
			if (it == dictionary.end())
			{
				cout << "plz, input new translation" << endl;
				string translation;
				if (getline(cin, translation))
				{
					if (!translation.empty())
					{
						toLow(translation);

						dictionary[inputWord].insert(translation);
						dictionary[translation].insert(inputWord);

						editFlag = true;
					}
				}
			}
			else
			{
				bool flag = false;
				for (auto &elem : it->second)
				{
					if (flag)
					{
						cout << ", ";
					}
					cout << elem;
					flag = true;
				}
				cout << endl;
			}
		}
	}
}