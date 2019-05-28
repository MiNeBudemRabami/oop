#include "pch.h"
#include "functionClass.h"
#include "iostream"


functionClass::functionClass()
{
}


functionClass::~functionClass()
{
}

void functionClass::fn3(std::string function, std::string variable1, std::string variable2, char operation)
{
	if (operation == '+')
	{
		setFunctions[function] = std::stod(variable1) + std::stod(variable2);
	}
	if (operation == '-')
	{
		setFunctions[function] = std::stod(variable1) - std::stod(variable2);
	}
	if (operation == '*')
	{
		setFunctions[function] = std::stod(variable1) * std::stod(variable2);
	}
	if (operation == '/')
	{
		setFunctions[function] = std::stod(variable1) / std::stod(variable2);
	}
}
	

void functionClass::fn2(std::string function, std::string variable)
{
	setFunctions[function] = std::stod(variable);
}



bool functionClass::find(std::string function)
{
	bool result;

	if (setFunctions.find(function) != setFunctions.end())
	{
		result = true;
	}
	else
	{
		result = false;
	}
	return result;
}

void functionClass::printfns() const
{
	for (auto &a : setFunctions)
	{
		std::cout << a.first << " = " << a.second << std::endl;
	}
	std::cout << std::endl;
}

void functionClass::print(std::string function)
{
	std::cout << setFunctions[function];
}