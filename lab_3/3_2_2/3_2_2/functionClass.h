#pragma once

#include <string>
#include <map>
#include <vector>

class variableClass;

class functionClass
{
public:

	functionClass();
	~functionClass();

	bool fn3(std::string function, std::string variable1, std::string variable2, std::string operation);

	bool fn2(std::string function, std::string variable1);

	bool printfns(variableClass &vc)const;

	bool print(std::string function, variableClass &vc)const;

	bool find(std::string function) const;

private:

	std::map <std::string, std::vector<std::string>> setFunctions;
};


