#include "pch.h"
#include "Variables.h"
#include "Functions.h"
#include "iostream"


Functions::Functions()
{
}


Functions::~Functions()
{
}

bool Functions::fn3(std::string function, std::string variable1, std::string variable2, std::string operation)
{
	bool result = true;

	setFunctions[function] = { variable1, operation, variable2 };

	return result;
}
	

bool Functions::fn2(std::string function, std::string variable)
{
	setFunctions[function] = { variable };
	return true;
}



bool Functions::find(std::string function) const
{
	return setFunctions.find(function) != setFunctions.end();
}

double Functions::get(std::string function, Variables const& vc) const
{
	if (find(function))
	{
		auto &fnData = setFunctions.find(function)->second;
		double ans = 0;

		if (fnData.size() == 1)
		{
			if (findAny(fnData[0], vc))
			{
				ans = getAny(fnData[0], vc);
			}
			else
			{
				return nan("");
			}
		}
		else if (fnData.size() == 3)
		{
			if (findAny(fnData[0], vc) && findAny(fnData[2], vc))
			{
				double left = getAny(fnData[0], vc);
				double right = getAny(fnData[2], vc);

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

std::map<std::string, double> Functions::GetAllData(Variables const& vc) const
{
	std::map<std::string, double> result;
	for (auto &function : setFunctions)
	{
		result[function.first] = get(function.first, vc);
	}
	return result;
}

bool Functions::findAny(std::string anyName, Variables const& vc) const
{
	return vc.find(anyName) || find(anyName);
}

double Functions::getAny(std::string anyName, Variables const& vc) const
{
	if (!findAny(anyName, vc))
	{
		return nan("");
	}

	if (find(anyName))
	{
		return get(anyName, vc);
	}

	return vc.get(anyName);
}
