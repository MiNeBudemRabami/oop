#include "pch.h"
#include "Variables.h"
#include "Functions.h"

Variables::Variables()
{
}

Variables::~Variables()
{
}

bool Variables::Var(std::string const& variable, Functions &fn)
{
	if (!Find(variable) && !fn.Find(variable))
	{
		m_setVariables[variable] = nan("");
		return true;
	}
	return false;
}

bool Variables::Let(std::string const& variable, double value, Functions &fn)
{
	if (fn.Find(variable))
	{
		return false;
	}

	m_setVariables[variable] = value;
	return true;
}

bool Variables::Let(std::string const& variable1, std::string const& variable2, Functions &fn)
{
	if (fn.Find(variable1))
	{
		return false;
	}

	if (m_setVariables.find(variable2) != m_setVariables.end())
	{
		m_setVariables[variable1] = m_setVariables[variable2];
		return true;
	}

	if (fn.Find(variable2))
	{
		m_setVariables[variable1] = fn.Get(variable2, *this);
		return true;
	}

	return false;
}

bool Variables::Find(std::string const& variable) const
{
	return m_setVariables.find(variable) != m_setVariables.end();
}

double Variables::Get(std::string const& variable) const
{
	return m_setVariables.find(variable)->second;
}

std::map<std::string, double> const & Variables::GetAllData() const
{
	return m_setVariables;
}
