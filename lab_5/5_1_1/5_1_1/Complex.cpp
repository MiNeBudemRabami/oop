#include "Complex.h"
#include <math.h>
#include <float.h>

Complex::Complex(double real, double image)
{
	this->real = real;
	this->image = image;
}

double Complex::Re()const
{
	return real;
}

double Complex::Im()const
{
	return image;
}

double Complex::GetMagnitude()const
{
	return sqrt(real * real + image * image);
}

double Complex::GetArgument()const
{
	return atan2(image, real);
}

Complex const Complex::operator+(Complex const& complex) const
{
	return Complex(real + complex.real, image + complex.image);
}

Complex const Complex::operator-(Complex const& complex) const
{
	return Complex(real - complex.real, image - complex.image);
}

Complex const Complex::operator*(Complex const& complex) const
{
	return Complex(real * complex.real - image * complex.image, real * complex.image + image * complex.real);
}

Complex const Complex::operator/(Complex const& complex) const
{
	double sqrSum = complex.Re() * complex.Re() + complex.Im() * complex.Im();
	return *this * Complex(complex.real / sqrSum, -(complex.image / sqrSum));
}

Complex const Complex::operator+() const
{
	return *this;
}

Complex const Complex::operator-() const
{
	return Complex(-real, -image);
}

Complex& Complex::operator+=(Complex const& complex)
{
	*this = *this + complex;
	return *this;
}

Complex& Complex::operator-=(Complex const& complex)
{
	*this = *this - complex;
	return *this;
}

Complex& Complex::operator*=(Complex const& complex)
{
	*this = *this * complex;
	return *this;
}

Complex& Complex::operator/=(Complex const& complex)
{
	*this = *this / complex;
	return *this;
}

bool Complex::operator==(Complex const& complex) const
{
	bool realsAreEqual = fabs(real - complex.real) < DBL_EPSILON;
	bool imagesAreEqual = fabs(image - complex.image) < DBL_EPSILON;
	return realsAreEqual && imagesAreEqual;
}

bool Complex::operator!=(Complex const& complex) const
{
	return !(*this == complex);
}
