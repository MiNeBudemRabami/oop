#include "ComplexClass.h"
#include <math.h>
#include <float.h>

ComplexClass::ComplexClass(double real, double image)
{
	this->real = real;
	this->image = image;
}

double ComplexClass::Re()const
{
	return real;
}

double ComplexClass::Im()const
{
	return image;
}

double ComplexClass::GetMagnitude()const
{
	return sqrt(real * real + image * image);
}

double ComplexClass::GetArgument()const
{
	return atan2(image, real);
}

ComplexClass const ComplexClass::operator+(ComplexClass const& complex) const
{
	return ComplexClass(real + complex.real, image + complex.image);
}

ComplexClass const ComplexClass::operator-(ComplexClass const& complex) const
{
	return ComplexClass(real - complex.real, image - complex.image);
}

ComplexClass const ComplexClass::operator*(ComplexClass const& complex) const
{
	return ComplexClass(real * complex.real - image * complex.image, real * complex.image + image * complex.real);
}

ComplexClass const ComplexClass::operator/(ComplexClass const& complex) const
{
	double sqrSum = complex.Re() * complex.Re() + complex.Im() * complex.Im();
	return *this * ComplexClass(complex.real / sqrSum, -(complex.image / sqrSum));
}

ComplexClass const ComplexClass::operator+() const
{
	return *this;
}

ComplexClass const ComplexClass::operator-() const
{
	return ComplexClass(-real, -image);
}

ComplexClass& ComplexClass::operator+=(ComplexClass const& complex)
{
	*this = *this + complex;
	return *this;
}

ComplexClass& ComplexClass::operator-=(ComplexClass const& complex)
{
	*this = *this - complex;
	return *this;
}

ComplexClass& ComplexClass::operator*=(ComplexClass const& complex)
{
	*this = *this * complex;
	return *this;
}

ComplexClass& ComplexClass::operator/=(ComplexClass const& complex)
{
	*this = *this / complex;
	return *this;
}

bool ComplexClass::operator==(ComplexClass const& complex) const
{
	bool realsAreEqual = fabs(real - complex.real) < DBL_EPSILON;
	bool imagesAreEqual = fabs(image - complex.image) < DBL_EPSILON;
	return realsAreEqual && imagesAreEqual;
}

bool ComplexClass::operator!=(ComplexClass const& complex) const
{
	return !(*this == complex);
}
