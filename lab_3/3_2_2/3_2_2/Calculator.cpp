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

double Calculator::Get(std::string const & anyName) const
{
	if (m_variables.find(anyName))
	{
		return m_variables.get(anyName);
	}
	return m_functions.get(anyName, m_variables);
}

bool Calculator::Fn(std::string const & function, std::string const & variable1)
{
	return m_functions.fn2(function, variable1);
}

bool Calculator::Fn(std::string const & function, std::string const & variable1, std::string const & variable2, std::string const & operation)
{
	return m_functions.fn3(function, variable1, variable2, operation);
}

std::map<std::string, double> const & Calculator::GetAllVariables() const
{
	return m_variables.GetAllData();
}

std::map<std::string, double> Calculator::GetAllFunctions() const
{
	return m_functions.GetAllData(m_variables);
}
