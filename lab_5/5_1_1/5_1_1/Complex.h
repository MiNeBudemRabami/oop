#pragma once

class Complex
{
public:
	Complex(double real = 0, double image = 0);
	double Re()const;
	double Im()const;
	double GetMagnitude()const;
	double GetArgument()const;

	Complex const operator+(Complex const& complex) const;
	Complex const operator-(Complex const& complex) const;
	Complex const operator*(Complex const& complex) const;
	Complex const operator/(Complex const& complex) const;
	Complex const operator+() const;
	Complex const operator-() const;
	Complex& operator+=(Complex const& complex);
	Complex& operator-=(Complex const& complex);
	Complex& operator*=(Complex const& complex);
	Complex& operator/=(Complex const& complex);
	bool operator==(Complex const& complex) const;
	bool operator!=(Complex const& complex) const;

private:
	double real;
	double image;
};
