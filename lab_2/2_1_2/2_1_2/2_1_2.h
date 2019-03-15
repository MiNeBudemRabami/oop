#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void printOutput(vector <float> massive)
{
	for (unsigned int i = 0; i < massive.size(); i++)
	{
		cout << massive[i] << ' ';
	}
}

float findMin(vector <float> massive)
{
	float min = massive[0];
	for (unsigned int i = 0; i < massive.size(); i++)
	{
		if (massive[i] < min)
		{
			min = massive[i];
		}
	}
	cout << min << endl;
	return min;
}

vector <float> massiveProccessing(vector <float> massive)
{
	vector <float> multiOnMin;
	float minEl = findMin(massive);
	for (unsigned int i = 0; i < massive.size(); i++)
	{
		multiOnMin.push_back(massive[i] * minEl);
	}
	return multiOnMin;
}


vector <float> massiveSort(vector <float> massive)
{
	sort(massive.begin(), massive.end());
	return massive;
}


vector <float> massiveInput()
{
	vector <float> massive;
	float curr = 0;
	while (cin >> curr)
	{
		massive.push_back(curr);
	}
	return massive;
}
