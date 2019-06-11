#include "Complex.h"
#include <math.h>
#include <float.h>

Complex::Complex(double real, double image)
{
	this->m_real = real;
	this->m_image = image;
}

double Complex::Re()const
{
	return m_real;
}

double Complex::Im()const
{
	return m_image;
}

double Complex::GetMagnitude()const
{
	return sqrt(m_real * m_real + m_image * m_image);
}

double Complex::GetArgument()const
{
	return atan2(m_image, m_real);
}

Complex const Complex::operator+(Complex const& complex) const
{
	return Complex(m_real + complex.m_real, m_image + complex.m_image);
}

Complex const Complex::operator-(Complex const& complex) const
{
	return Complex(m_real - complex.m_real, m_image - complex.m_image);
}

Complex const Complex::operator*(Complex const& complex) const
{
	return Complex(m_real * complex.m_real - m_image * complex.m_image, m_real * complex.m_image + m_image * complex.m_real);
}

Complex const Complex::operator/(Complex const& complex) const
{
	double sqrSum = complex.Re() * complex.Re() + complex.Im() * complex.Im();
	return *this * Complex(complex.m_real / sqrSum, -(complex.m_image / sqrSum));
}

Complex const Complex::operator+() const
{
	return *this;
}

Complex const Complex::operator-() const
{
	return Complex(-m_real, -m_image);
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
	bool realsAreEqual = fabs(m_real - complex.m_real) < DBL_EPSILON;
	bool imagesAreEqual = fabs(m_image - complex.m_image) < DBL_EPSILON;
	return realsAreEqual && imagesAreEqual;
}

bool Complex::operator!=(Complex const& complex) const
{
	return !(*this == complex);
}
