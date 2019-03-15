#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <deque>

using namespace std;

int main(int argc, char** argv)
{
	if ((argc == 5) )
	{
		
		string sourceNotation = argv[1];
		string destinationNotation = argv[2];
		string value = argv[3];

		deque <char> buffer;
		buffer.clear();
		char c = ' ';

		
	}
	else
	{
		if ((argc <= 5) && (argc >= 3))
		{
			ofstream of(argv[2]);
			of << "invalid call format";
		}
		else
		{
			ofstream of("output_error.txt");
			of << "invalid call format";
		}
	}	
}
