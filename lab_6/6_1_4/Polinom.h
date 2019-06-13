#pragma once

struct EquationRoot4
{
	double a4;
	double b3 = 0;
	double c2 = 0;
	double d1 = 0;
	double free = 0;
};

class Polinom
{
public:
	Polinom();
	~Polinom();

	EquationRoot4 Solve4()const;

private:

	double m_a4 = 0;
	double m_b3 = 0;
	double m_c2 = 0;
	double m_d1 = 0;
	double m_free = 0;

};

