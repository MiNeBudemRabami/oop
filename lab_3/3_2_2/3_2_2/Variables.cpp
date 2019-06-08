#include "pch.h"
#include "Variables.h"
#include "iostream"
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
	else return false;
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

	std::cout << "second variable is undeclared" << std::endl;
	return false;
}

bool Variables::printvars() const
{
	for (auto &variable  : setVariables)
	{
		std::cout << variable.first << " = " << variable.second << std::endl;
	}
	std::cout << std::endl;
	return true;
}

bool Variables::find(std::string variable) const
{
	bool result;

	if (setVariables.find(variable) != setVariables.end())
	{
		result = true;
	}
	else 
	{
		result = false;
	}
	return result;
}

double Variables::get(std::string variable) const
{
	return setVariables.find(variable)->second;
}

bool Variables::print(std::string variable) const
{
	bool result;

	if (setVariables.find(variable) == setVariables.end())
	{
		std::cout << "id isnt mantioned" << std::endl;
		result = false;
	}
	else
	{
		std::cout << variable << " = " << setVariables.find(variable)->second << std::endl ;
		result = true;
	}
	std::cout << std::endl;
	return result;
}