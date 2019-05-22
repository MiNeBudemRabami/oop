#include "pch.h"
#include "2_4_4.h"

using namespace std;

int main()
{
	int upperBound = 0;
	cin >> upperBound;

	if ((upperBound > 2) && (upperBound < 1000))
	{
		initVector(upperBound);
		screening(resheto);
		print(resheto);
	}
	else if (upperBound > 1000)
	{
		initVector(upperBound);
		screening(resheto);
		counting(resheto);
	}
	else
	{
		nothingToOutput;
	}
}

