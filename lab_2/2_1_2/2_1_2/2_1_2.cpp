#include "pch.h"
#include "2_1_2.h"

int main()
{
	vector <float> massive = massiveInput();
	vector <float> processedMassive = massiveProccessing(massive);
	vector <float> sortedMassive = massiveSort(processedMassive);
	printOutput(sortedMassive);
}
