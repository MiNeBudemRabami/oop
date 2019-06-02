#pragma once

class ComplexClass
{
public:
	ComplexClass(double real = 0, double image = 0);
	double Re()const;
	double Im()const;
	double GetMagnitude()const;
	double GetArgument()const;

	ComplexClass const operator+(ComplexClass const& complex) const;
	ComplexClass const operator-(ComplexClass const& complex) const;
	ComplexClass const operator*(ComplexClass const& complex) const;
	ComplexClass const operator/(ComplexClass const& complex) const;
	ComplexClass const operator+() const;
	ComplexClass const operator-() const;
	ComplexClass& operator+=(ComplexClass const& complex);
	ComplexClass& operator-=(ComplexClass const& complex);
	ComplexClass& operator*=(ComplexClass const& complex);
	ComplexClass& operator/=(ComplexClass const& complex);
	bool operator==(ComplexClass const& complex) const;
	bool operator!=(ComplexClass const& complex) const;

private:
	double real;
	double image;
};
