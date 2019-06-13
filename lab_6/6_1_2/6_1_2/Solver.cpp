#include "Solver.h"
#include <math.h>

EquationRoots Solve(double a, double b, double c)
{
	if (a == 0)
	{
		throw std::invalid_argument("a should not be 0");
	}

	double dSquare = b * b - 4 * a * c;

	if (dSquare < 0)
	{
		throw std::domain_error("No real roots");
	}

	EquationRoots result;
	double d = sqrt(dSquare);

	if (d == 0)
	{
		result.numRoots = 1;
		result.roots[0] = -b / (2 * a);
	}
	else
	{
		result.numRoots = 2;
		result.roots[0] = (-b + d) / (2 * a);
		result.roots[1] = (-b - d) / (2 * a);
	}

	return result;
}
