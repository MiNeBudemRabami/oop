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

	bool fn3(std::string function, std::string variable1, std::string variable2, std::string operation);

	bool fn2(std::string function, std::string variable1);

	bool find(std::string function) const;

	double get(std::string function, Variables const& vc) const;

	std::map<std::string, double> GetAllData(Variables const& vc) const;

private:

	bool findAny(std::string anyName, Variables const& vc) const;

	double getAny(std::string anyName, Variables const& vc) const;

	std::map <std::string, std::vector<std::string>> setFunctions;
};


