#pragma once

#include <string>
#include <map>
#include <vector>

class Variables;

class Functions
{
public:

	Functions();
	~Functions();

	bool Fn(std::string const& function, std::string const& variable1, std::string const& variable2, std::string const& operation);

	bool Fn(std::string const& function, std::string const& variable1);

	bool Find(std::string const& function) const;

	double Get(std::string const& function, Variables const& vc) const;

	std::map<std::string, double> GetAllData(Variables const& vc) const;

private:

	bool FindAny(std::string const& anyName, Variables const& vc) const;

	double GetAny(std::string const& anyName, Variables const& vc) const;

	std::map <std::string, std::vector<std::string>> m_setFunctions;
};


