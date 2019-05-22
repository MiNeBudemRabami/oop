#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void initVector(int upperBound)
{
	vector<bool> resheto(upperBound, true);
}

void screening(vector <bool> & resheto)
{
	for (int i = 2; i * i <= resheto.size(); ++i)
	{
		if (resheto[i])
		{
			for (int j = i * i; j < resheto.size(); j += 2 * i)
			{
				resheto[j] = false;
			}
		}
	}
}

void counting(vector <bool> & resheto)
{
	int count = 1;

	for (int i = 3; i < resheto.size(); i += 2)
	{
		if (resheto[i])
		{
			count++;
		}
	}
	cout << count;
}

void print(vector <bool> & resheto)
{
	for (int i = 3; i < resheto.size(); i += 2)
	{
		if (resheto[i])
		{
			cout << i <<' ';
		}
	}
}

void nothingToOutput()
{
	int count = 0;
	cout << count;
}