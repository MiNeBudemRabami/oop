#include "pch.h"
#include "variableClass.h"
#include "iostream"
#include "functionClass.h"


variableClass::variableClass()
{
}


variableClass::~variableClass()
{
}


bool variableClass::var(std::string variable)
{
	std::cout << std::endl;

	if (setVariables.find(variable) == setVariables.end())
	{
		setVariables[variable] = nan("");
		return true;
	}
	else return false;
}

bool variableClass::let1(std::string variable, double value)
{
	std::cout << std::endl;

	setVariables[variable] = value;
	return true;
}

bool variableClass::let2(std::string variable1, std::string variable2, functionClass &fn)
{
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

bool variableClass::printvars() const
{
	for (auto &variable  : setVariables)
	{
		std::cout << variable.first << " = " << variable.second << std::endl;
	}
	std::cout << std::endl;
	return true;
}

bool variableClass::find(std::string variable)
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

double variableClass::get(std::string variable)
{
	return setVariables.find(variable)->second;
}

bool variableClass::print(std::string variable) 
{
	bool result;

	if (setVariables.find(variable) == setVariables.end())
	{
		std::cout << "id isnt mantioned" << std::endl;
		result = false;
	}
	else
	{
		std::cout << variable << " = " << setVariables[variable] << std::endl ;
		result = true;
	}
	std::cout << std::endl;
	return result;
}