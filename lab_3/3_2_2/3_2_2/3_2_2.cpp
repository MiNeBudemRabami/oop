#include "pch.h"
#include <iostream>
#include <string>
#include "variableClass.h"
#include "functionClass.h"
#include <vector>

using namespace std;

vector <string> readCommand()
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

bool checkCommand(vector <string> id)
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
	variableClass variable;

	functionClass function;

	for (;;)
	{
		vector <string> id = readCommand();

		if (checkCommand(id))
		{
			if (id[0] == "var")
			{
				if (!variable.var(id[1], function))
				{
					cout << id[1] << " name is already taken" << endl << endl;
				}
			}

			else if (id[0] == "let")
			{
				if (isdigit(id[3][0]))
				{
					if (!variable.let1(id[1], stod(id[3]), function))
					{
						cout << id[1] << " name is already taken" << endl << endl;
					}
				}
				else
				{
					if (!variable.let2(id[1], id[3], function))
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

				if (variable.find(id1) || function.find(id1))
				{
					cout << id1 << " name is already taken" << endl << endl; 
				}
				
				else if (variable.find(id2) == false)
				{
					cout << id2 << " wasnt mantioned" << endl << endl;
				}

				else if (id.size() == 4)
				{
					function.fn2(id1, id2);
				}

				else  if(id.size() == 6)
				{ 
					string id3 = id[5];
					string operation = id[4];
					
					if (variable.find(id3) == false)
					{
						cout << id3 << " wasnt mantioned" << endl << endl;
					}

					else
					{
						function.fn3(id1, id2, id3, operation);
					}
				}

			}

			else if (id[0] == "print")
			{
				string id1 = id[1];

				if (variable.find(id1))
				{
					variable.print(id1);
				}

				else if (function.find(id1))
				{
					function.print(id1, variable);
				}
			}
			else if (id[0] == "printvars")
			{
				variable.printvars();
			}

			else if (id[0] == "printfns")
			{
				function.printfns(variable);
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