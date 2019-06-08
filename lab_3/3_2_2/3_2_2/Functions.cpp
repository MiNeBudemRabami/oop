#include "pch.h"
#include "Variables.h"
#include "Functions.h"

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

double Functions::Get(std::string const& function, Variables const& vc) const
{
	if (Find(function))
	{
		auto &fnData = m_setFunctions.find(function)->second;
		double ans = 0;

		if (fnData.size() == 1)
		{
			if (FindAny(fnData[0], vc))
			{
				ans = GetAny(fnData[0], vc);
			}
			else
			{
				return nan("");
			}
		}
		else if (fnData.size() == 3)
		{
			if (FindAny(fnData[0], vc) && FindAny(fnData[2], vc))
			{
				double left = GetAny(fnData[0], vc);
				double right = GetAny(fnData[2], vc);

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
	for (auto &function : m_setFunctions)
	{
		result[function.first] = Get(function.first, vc);
	}
	return result;
}

bool Functions::FindAny(std::string const& anyName, Variables const& vc) const
{
	return vc.Find(anyName) || Find(anyName);
}

double Functions::GetAny(std::string const& anyName, Variables const& vc) const
{
	if (!FindAny(anyName, vc))
	{
		return nan("");
	}

	if (Find(anyName))
	{
		return Get(anyName, vc);
	}

	return vc.Get(anyName);
}
