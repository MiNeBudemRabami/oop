#include "pch.h"
#include "Calculator.h"

Calculator::Calculator()
{
}

bool Calculator::Var(std::string const & variable)
{
	return m_variables.var(variable, m_functions);
}

bool Calculator::Let(std::string const & variable1, double variable2)
{
	return m_variables.let1(variable1, variable2, m_functions);
}

bool Calculator::Let(std::string const & variable1, std::string const & variable2)
{
	return m_variables.let2(variable1, variable2, m_functions);
}

bool Calculator::Find(std::string const & anyName) const
{
	return m_variables.find(anyName) || m_functions.find(anyName);
}

bool Calculator::Fn(std::string const & function, std::string const & variable1)
{
	return m_functions.fn2(function, variable1);
}

bool Calculator::Fn(std::string const & function, std::string const & variable1, std::string const & variable2, std::string const & operation)
{
	return m_functions.fn3(function, variable1, variable2, operation);
}

bool Calculator::Print(std::string const & anyName) const
{
	if (m_variables.find(anyName))
	{
		return m_variables.print(anyName);
	}
	return m_functions.print(anyName, m_variables);
}

bool Calculator::PrintVars() const
{
	return m_variables.printvars();
}

bool Calculator::PrintFns() const
{
	return m_functions.printfns(m_variables);
}
