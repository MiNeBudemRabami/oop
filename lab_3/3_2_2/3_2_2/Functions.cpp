#include "pch.h"
#include "Functions.h"
#include "Calculator.h"

Functions::Functions()
{
}

Functions::~Functions()
{
}

bool Functions::Fn(std::string const& function, std::string const& variable1, std::string const& variable2, std::string const& operation)
{
	m_setFunctions[function] = { variable1, operation, variable2 };
	return true;
}
	

bool Functions::Fn(std::string const& function, std::string const& variable)
{
	m_setFunctions[function] = { variable };
	return true;
}

bool Functions::Find(std::string const& function) const
{
	return m_setFunctions.find(function) != m_setFunctions.end();
}

double Functions::Get(std::string const& function, Calculator const& calc) const
{
	if (Find(function))
	{
		auto &fnData = m_setFunctions.find(function)->second;
		double ans = 0;

		if (fnData.size() == 1)
		{
			if (calc.Find(fnData[0]))
			{
				ans = calc.Get(fnData[0]);
			}
			else
			{
				return nan("");
			}
		}
		else if (fnData.size() == 3)
		{
			if (calc.Find(fnData[0]) && calc.Find(fnData[2]))
			{
				double left = calc.Get(fnData[0]);
				double right = calc.Get(fnData[2]);

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

std::map<std::string, double> Functions::GetAllData(Calculator const& calc) const
{
	std::map<std::string, double> result;
	for (auto &function : m_setFunctions)
	{
		result[function.first] = Get(function.first, calc);
	}
	return result;
}
