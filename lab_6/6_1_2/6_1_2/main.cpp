#include "Solver.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector <double> readKoeff()
{
	string command;
	char c = 0;
	string koeff;
	vector <double> KoeffSet;

	getline(cin, command);

	for (size_t i = 0; i < command.size(); i++)
	{
		c = command[i];
		if (c != ' ')
		{
			koeff.push_back(c);
		}
		else
		{
			KoeffSet.push_back(stod(koeff));
			koeff.clear();
		}
	}

	if (!koeff.empty())
	{
		KoeffSet.push_back(stod(koeff));
	}

	return KoeffSet;
}

int main()
{
	for (;;)
	{
		if (cin.eof())
		{
			break;
		}

		vector <double> KoefSet = readKoeff();

		if (KoefSet.size() != 3)
		{
			cout << "not enought args" << endl;
		}
		else
		{
			double a = KoefSet[0];
			double b = KoefSet[1];
			double c = KoefSet[2];

			try
			{
				auto roots = Solve(a, b, c);

				if (roots.numRoots == 1)
				{
					cout << "Found 1 root: " << roots.roots[0] << endl;
				}
				else if (roots.numRoots == 2)
				{
					cout << "Found 2 roots: " << roots.roots[0] << " " << roots.roots[1] << endl;
				}
			}
			catch (std::exception const& e)
			{
				cout << e.what() << endl;
			}
		}
	}

	return 0;
}
