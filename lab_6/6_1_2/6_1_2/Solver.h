#pragma once

#include <stdexcept>

struct EquationRoots
{
	int numRoots;
	double roots[2];
};

// Вычисляем корни квадратного уравнения ax^2 + bx + c = 0
EquationRoots Solve(double a, double b, double c);
