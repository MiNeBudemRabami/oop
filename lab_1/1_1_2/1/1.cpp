#include "pch.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
	std::ifstream f(argv[1]);
	std::ifstream g(argv[2]);
	bool isequal = true;
	int pos_x = 1;
	int pos_y = 1;
	char c1;
	char c2;

	for(;;)
	{
		c1 = f.get();

		c2 = g.get();

		if (c1 == c2)
		{
			isequal = true;
			pos_x++;

			if (c1 == '\n')
			{
				++pos_y;
				pos_x = 1;
			}
		}
		else
		{
			isequal = false;
			break;
		}

		if (f.eof() && g.eof())
		{
			isequal = true;
			break;
		}
	
		if ((!f.eof() && g.eof()) || (f.eof() && !g.eof()))
		{
			isequal = false;
			break;
		}
	}

	if (isequal)
	{
		std::cout << "files are equal" << endl;
	}
	else
	{
		std::cout << "files are not equal, difference became at " << pos_y << " line " << pos_x <<" simbol" << endl;
	}
	std::cin.get();
}