#include "pch.h"
#include "Variables.h"
#include "Functions.h"

Variables::Variables()
{
}

Variables::~Variables()
{
}

bool Variables::var(std::string const& variable, Functions &fn)
{
	if (!find(variable) && !fn.find(variable))
	{
		m_setVariables[variable] = nan("");
		return true;
	}
	return false;
}

bool Variables::Let(std::string const& variable, double value, Functions &fn)
{
	if (fn.find(variable))
	{
		return false;
	}

	m_setVariables[variable] = value;
	return true;
}

bool Variables::Let(std::string const& variable1, std::string const& variable2, Functions &fn)
{
	if (fn.find(variable1))
	{
		return false;
	}

	if (m_setVariables.find(variable2) != m_setVariables.end())
	{
		m_setVariables[variable1] = m_setVariables[variable2];
		return true;
	}

	if (fn.find(variable2))
	{
		m_setVariables[variable1] = fn.get(variable2, *this);
		return true;
	}

	return false;
}

bool Variables::find(std::string const& variable) const
{
	return m_setVariables.find(variable) != m_setVariables.end();
}

double Variables::get(std::string const& variable) const
{
	return m_setVariables.find(variable)->second;
}

std::map<std::string, double> const & Variables::GetAllData() const
{
	return m_setVariables;
}
