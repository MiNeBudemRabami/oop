#include "pch.h"
#include "Calculator.h"

Calculator::Calculator()
{
}

bool Calculator::Var(std::string const & variable)
{
	return m_variables.Var(variable, m_functions);
}

bool Calculator::Let(std::string const & variable1, double variable2)
{
	return m_variables.Let(variable1, variable2, m_functions);
}

bool Calculator::Let(std::string const & variable1, std::string const & variable2)
{
	return m_variables.Let(variable1, variable2, m_functions, *this);
}

bool Calculator::Find(std::string const & anyName) const
{
	return m_variables.Find(anyName) || m_functions.Find(anyName);
}

double Calculator::Get(std::string const & anyName) const
{
	if (m_variables.Find(anyName))
	{
		return m_variables.Get(anyName);
	}
	return m_functions.Get(anyName, *this);
}

bool Calculator::Fn(std::string const & function, std::string const & variable1)
{
	return m_functions.Fn(function, variable1);
}

bool Calculator::Fn(std::string const & function, std::string const & variable1, std::string const & variable2, std::string const & operation)
{
	return m_functions.Fn(function, variable1, variable2, operation);
}

std::map<std::string, double> const & Calculator::GetAllVariables() const
{
	return m_variables.GetAllData();
}

std::map<std::string, double> Calculator::GetAllFunctions() const
{
	return m_functions.GetAllData(*this);
}
