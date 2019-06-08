#include "pch.h"
#include <iostream>
#include <string>
#include "Calculator.h"
#include <vector>

using namespace std;

vector <string> ReadCommand()
{
	char c = ' ';
	vector <string> setStrings;
	string id;

	for(;;)
	{
		for(;;)
		{
			c = cin.get();

			if ((c == ' ') || (c == '\n'))
			{
				break;
			}

			id.push_back(c);
		}
		setStrings.push_back(id);
		id.clear();

		if (c == '\n')
		{
			break;
		}
	}

	return setStrings;
}

bool CheckCommand(vector <string> id)
{
	bool result = true;

	if (id[0] == "var" || id[0] == "print")
	{
		if ((id.size() != 2))
		{
			result = false;
		}
	}

	if (id[0] == "fn")
	{
		if (id.size() == 1 || id.size() == 2 || id.size() == 3 || id.size() == 5 || id.size() > 6)
		{
			result = false;
		}

		else if (id.size() == 6)
		{
			if (id[4] != "+" && id[4] != "-" && id[4] != "*" && id[4] != "/")
			{
				result = false;
			}
			if (id[2] != "=")
			{
				result = false;
			}
		}
		else if (id.size() == 4)
		{
			if (id[2] != "=")
			{
				result = false;
			}
		}
	}

	if (id[0] == "printvars" || id[0] == "printfns")
	{
		if (id.size() != 1)
		{
			result = false;
		}
	}

	if (id[0] == "let")
	{
		if (id.size() != 4)
		{
			result = false;
		}
	}

	return result;
}

int main()
{
	Calculator calculator;

	cout.precision(2);
	cout << std::fixed;

	for (;;)
	{
		vector <string> id = ReadCommand();

		if (CheckCommand(id))
		{
			if (id[0] == "var")
			{
				if (!calculator.Var(id[1]))
				{
					cout << id[1] << " name is already taken" << endl << endl;
				}
			}

			else if (id[0] == "let")
			{
				if (isdigit(id[3][0]))
				{
					if (!calculator.Let(id[1], stod(id[3])))
					{
						cout << id[1] << " name is already taken" << endl << endl;
					}
				}
				else
				{
					if (!calculator.Let(id[1], id[3]))
					{
						cout << id[1] << " name is already taken" << endl << endl;
					}
				}
				cout << endl;
			}

			else if (id[0] == "fn")
			{
				string id1 = id[1];
				string id2 = id[3];	

				if (calculator.Find(id1))
				{
					cout << id1 << " name is already taken" << endl << endl; 
				}
				
				else if (!calculator.Find(id2))
				{
					cout << id2 << " wasnt mantioned" << endl << endl;
				}

				else if (id.size() == 4)
				{
					calculator.Fn(id1, id2);
				}

				else if (id.size() == 6)
				{ 
					string id3 = id[5];
					string operation = id[4];
					
					if (!calculator.Find(id3))
					{
						cout << id3 << " wasnt mantioned" << endl << endl;
					}

					else
					{
						calculator.Fn(id1, id2, id3, operation);
					}
				}

			}

			else if (id[0] == "print")
			{
				string id1 = id[1];

				if (calculator.Find(id1))
				{
					std::cout << id1 << " = " << calculator.Get(id1) << std::endl;
				}
			}
			else if (id[0] == "printvars")
			{
				for (auto &variable : calculator.GetAllVariables())
				{
					std::cout << variable.first << " = " << variable.second << std::endl;
				}
				std::cout << std::endl;
			}

			else if (id[0] == "printfns")
			{
				for (auto &function : calculator.GetAllFunctions())
				{
					std::cout << function.first << " = " << function.second << std::endl;
				}
			}
		}

		else if (cin.eof())
		{
			break;
		}
		else
		{
			cout << "unexpected command" << endl << endl;
		}

	}
}