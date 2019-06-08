#include "pch.h"
#include "Variables.h"
#include "Functions.h"

Variables::Variables()
{
}

Variables::~Variables()
{
}

bool Variables::var(std::string variable, Functions &fn)
{
	if (!find(variable) && !fn.find(variable))
	{
		setVariables[variable] = nan("");
		return true;
	}
	return false;
}

bool Variables::let1(std::string variable, double value, Functions &fn)
{
	if (fn.find(variable))
	{
		return false;
	}

	setVariables[variable] = value;
	return true;
}

bool Variables::let2(std::string variable1, std::string variable2, Functions &fn)
{
	if (fn.find(variable1))
	{
		return false;
	}

	if (setVariables.find(variable2) != setVariables.end())
	{
		setVariables[variable1] = setVariables[variable2];
		return true;
	}

	if (fn.find(variable2))
	{
		setVariables[variable1] = fn.get(variable2, *this);
		return true;
	}

	return false;
}

bool Variables::find(std::string variable) const
{
	return setVariables.find(variable) != setVariables.end();
}

double Variables::get(std::string variable) const
{
	return setVariables.find(variable)->second;
}

std::map<std::string, double> const & Variables::GetAllData() const
{
	return setVariables;
}
