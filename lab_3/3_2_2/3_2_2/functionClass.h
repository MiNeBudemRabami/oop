#pragma once

#include <string>
#include <map>

class functionClass
{
public:

	functionClass();
	~functionClass();

	void fn3(std::string function, std::string variable1, std::string variable2, char operation);

	void fn2(std::string function, std::string variable1);

	bool find(std::string function);

	void printfns()const;

	std::map <std::string, double> setFunctions;

private:

};


