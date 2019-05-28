#include "pch.h"
#include <iostream>
#include <string>
#include "variableClass.h"
#include "functionClass.h"
#include <vector>


using namespace std;

int main()
{
	variableClass variable;

	functionClass function;
	 
	string command = "";

	for(;;)
	{
		cin >> command;

		if (command == "var")
		{
			string id;
			cin >> id;
			variable.var(id);
		}

		if (command == "let")
		{
			string id1;
			string id2;
			char equalsymb;

			cin >> id1;
			cin >> equalsymb;

			if (equalsymb != '=')
			{
				cout << "= is exepted" << endl;
			}
			else
			{
				cin >> id2;

				if (isdigit(id2[0]))
				{
					variable.let2(id1, stod(id2));
				}
				else
				{
					variable.let1(id1, id2);
				}
			}
			cout << endl;
		}

		if (command == "fn")
		{
			string id1;
			string id2;
			string id3;
			char equalsymb;
			char operationSymb;

			cin >> id1;
			cin >> equalsymb;

			if (equalsymb != '=')
			{
				cout << "= is exepted" << endl;
			}
			else
			{
				cin >> id2;
				cin >> operationSymb;
				
				if (operationSymb == '\n')
				{
					function.fn2(id1, id2);
				}
				else
				{
					cin >> id3;

					if (id3 == "")
					{
						cout << "second identif. is exepted" << endl;
					}

					else
					{
						function.fn3(id1, id2, id3, operationSymb);
					}
				}
			}
			
		}

		if (command == "print")
		{
			string id;
			cin >> id;

			if (variable.find(id))
			{
				variable.print(id);
			}

			else if (function.find(id)) 
			{
				function.print(id);
			}

		}

		if (command == "printvars")
		{
			variable.printvars();
		}

		if (command == "printfns")
		{
			function.printfns();
		}

		if (cin.eof())
		{
			break;
		}
	}
}