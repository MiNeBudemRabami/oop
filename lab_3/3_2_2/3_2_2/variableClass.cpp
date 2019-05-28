#include "pch.h"
#include "variableClass.h"
#include "iostream"


variableClass::variableClass()
{
}


variableClass::~variableClass()
{
}


bool variableClass::var(std::string variable)
{
	if (setVariables.find(variable) == setVariables.end())
	{
		setVariables[variable] = nan("");
		return true;
	}
	else return false;
}

void variableClass::let2(std::string variable1, double variable2)
{
	setVariables[variable1] = variable2;
}

bool variableClass::let1(std::string variable1, std::string variable2)
{
	if (setVariables.find(variable2) != setVariables.end())
	{
		setVariables[variable1] = setVariables[variable2];
		return true;
	}
	else
	{
		std::cout << "second variable is undeclared" << std::endl;
		return false;
	}
}

void variableClass::printvars() const
{
	for (auto &a  : setVariables)
	{
		std::cout << a.first << " = " << a.second << std::endl;
	}
	std::cout << std::endl;
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

void variableClass::print(std::string variable) 
{
	std::cout << variable << " = " << setVariables[variable] << std::endl << std::endl;
}