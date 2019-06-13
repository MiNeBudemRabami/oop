#pragma once

#include <stdexcept>

struct EquationRoots
{
	int numRoots;
	double roots[2];
};

// ¬ычисл€ем корни квадратного уравнени€ ax^2 + bx + c = 0
EquationRoots Solve(double a, double b, double c);
