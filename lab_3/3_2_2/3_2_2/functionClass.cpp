#include "pch.h"
#include "variableClass.h"
#include "functionClass.h"
#include "iostream"


functionClass::functionClass()
{
}


functionClass::~functionClass()
{
}

bool functionClass::fn3(std::string function, std::string variable1, std::string variable2, std::string operation)
{
	bool result = true;

	setFunctions[function] = { variable1, operation, variable2 };

	return result;
}
	

bool functionClass::fn2(std::string function, std::string variable)
{
	setFunctions[function] = { variable };
	return true;

}



bool functionClass::find(std::string function) const
{
	bool result;

	if (setFunctions.find(function) == setFunctions.end())
	{
		result = false;
	}
	else
	{
		result = true;
	}
	return result;
}

double functionClass::get(std::string function, variableClass &vc) const
{
	if (find(function))
	{
		auto &fnData = setFunctions.find(function)->second;
		double ans = 0;

		if (fnData.size() == 1)
		{
			if (vc.find(fnData[0]))
			{
				ans = vc.get(fnData[0]);
			}
			else
			{
				return nan("");
			}
		}
		else if (fnData.size() == 3)
		{
			if (vc.find(fnData[0]) && vc.find(fnData[2]))
			{
				double left = vc.get(fnData[0]);
				double right = vc.get(fnData[2]);

				if (fnData[1] == "+")
				{
					ans = left + right;
				}
				else if (fnData[1] == "-")
				{
					ans = left - right;
				}
				else if (fnData[1] == "*")
				{
					ans = left * right;
				}
				else if (fnData[1] == "/")
				{
					ans = left / right;
				}
				else
				{
					return nan("");
				}
			}
			else
			{
				return nan("");
			}
		}
		else
		{
			return nan("");
		}

		return ans;
	}
	else
	{
		return nan("");
	}
}

bool functionClass::printfns(variableClass &vc) const
{
	for (auto &function : setFunctions)
	{
		//std::cout << function.first << " = " << function.second << std::endl;
		print(function.first, vc);
	}
	std::cout << std::endl;
	return true;
}

bool functionClass::print(std::string function, variableClass &vc) const
{
	if (find(function))
	{ 
		std::cout << get(function, vc) << std::endl;
		return true;
	}
	else
	{
		std::cout << "id isnt mantioned" << std::endl;
		return false;
	}
}