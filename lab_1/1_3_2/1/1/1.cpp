#include "pch.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <deque>

using namespace std;

int main(int argc, char** argv)
{
	ifstream f(argv[1]);
	ofstream of(argv[2]);
	float matrix[3][3];
	int col = 0;
	int str = 0;
	float curr = 0;
	bool waserror = false;

	for (str = 0; str <= 2; str++)
	{
		for (col = 0; col <= 2; col++)
		{
			if (f.good())
			{
				f >> curr;
				matrix[str][col] = curr;
			}
			else
			{
				waserror = true;
				break;
			}
		}
	}

	if (waserror)
	{
		of << "was error" << endl;
	}
	else
	{
		float det = matrix[0][0] * matrix[1][1] * matrix[2][2] + matrix[1][0] * matrix[2][1] * matrix[0][2] + matrix[0][1] * matrix[1][2] * matrix[2][0] -
					matrix[2][0] * matrix[1][1] * matrix[0][2] - matrix[1][0] * matrix[0][1] * matrix[2][2] - matrix[0][0] * matrix[2][1] * matrix[1][2];

		if (abs(det) > 0.0001)
		{
			float temp[3][3];

			temp[0][0] = matrix[1][1] * matrix[2][2] - matrix[2][1] * matrix[1][2];
			temp[0][1] = matrix[1][0] * matrix[2][2] - matrix[2][0] * matrix[1][2];
			temp[0][2] = matrix[1][0] * matrix[2][1] - matrix[2][0] * matrix[1][1];

			temp[1][0] = matrix[0][1] * matrix[2][2] - matrix[2][1] * matrix[0][2];
			temp[1][1] = matrix[0][0] * matrix[2][2] - matrix[2][0] * matrix[0][2];
			temp[1][2] = matrix[0][0] * matrix[2][1] - matrix[2][0] * matrix[0][1];

			temp[2][0] = matrix[0][1] * matrix[1][2] - matrix[1][1] * matrix[0][2];
			temp[2][1] = matrix[0][0] * matrix[1][2] - matrix[1][0] * matrix[0][2];
			temp[2][2] = matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];

			matrix[0][0] = pow(-1, 1 + 1) * temp[0][0] / det;
			matrix[0][1] = pow(-1, 1 + 2) * temp[0][1] / det;
			matrix[0][2] = pow(-1, 1 + 3) * temp[0][2] / det;

			matrix[1][0] = pow(-1, 2 + 1) * temp[1][0] / det;
			matrix[1][1] = pow(-1, 2 + 2) * temp[1][1] / det;
			matrix[1][2] = pow(-1, 2 + 3) * temp[1][2] / det;

			matrix[2][0] = pow(-1, 3 + 1) * temp[2][0] / det;
			matrix[2][1] = pow(-1, 3 + 2) * temp[2][1] / det;
			matrix[2][2] = pow(-1, 3 + 3) * temp[2][2] / det;

			for (str = 0; str <= 2; str++)
			{
				for (col = 0; col <= 2; col++)
				{
					curr = matrix[col][str];
					
					if (abs(curr) < 0.0000001)
					{
						of << '0' << ' ';
					}
					else
					
					{

						of << setprecision(3) << curr << ' ';
					}
					
				}
				of << '\n';
			}
		}
		else
		{
			of << "determinant = 0";
		}
	}
}