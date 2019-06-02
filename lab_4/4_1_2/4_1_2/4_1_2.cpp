#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include "shapeInterface.h"
#include "triangleClass.h"
#include "rectangleClass.h"
#include "circleClass.h"
#include <algorithm>
#include <deque>

using namespace std;

static bool compareArea(ShapeInterface* shape1, ShapeInterface* shape2)
{
	return (shape1->getArea() < shape2->getArea());
}

static bool comparePerimetr(ShapeInterface const* shape1, ShapeInterface const* shape2)
{
	return (shape1->getPerimetr() < shape2->getPerimetr());
}

ShapeInterface* ShapeMaxPerimetr(vector <ShapeInterface*> shapeSet)
{
	return *max_element(shapeSet.begin(), shapeSet.end(), comparePerimetr);
}

ShapeInterface* ShapeMaxArea(vector <ShapeInterface*> shapeSet)
{
	return *max_element(shapeSet.begin(), shapeSet.end(), compareArea);
}

vector <string> readCommand()
{
	string command;
	char c = 0;
	string parametr;
	vector <string> parametrSet;

	getline(cin, command);

	for (size_t i = 0; i < command.size(); i++)
	{
		c = command[i];
		if (c != ' ')
		{
			parametr.push_back(c);
		}
		else
		{
			parametrSet.push_back(parametr);
			parametr.clear();
		}
	}

	if (!parametr.empty())
	{
		parametrSet.push_back(parametr);
	}
	
	
	return parametrSet;
}

int main()
{
	vector <string> parametrSet;
	deque <CircleClass> circleSet;
	deque <RectangleClass> rectangleSet;
	deque <TriangleClass> triangleSet;
	vector <ShapeInterface*> shapeSet;

	for (;;)
	{
		parametrSet = readCommand();

		if (cin.eof())
		{
			break;
		}

		if (parametrSet[0] == "circle")
		{
			PointClass center;
			center.x = stod(parametrSet[1]);
			center.y = stod(parametrSet[2]);

			CircleClass circle(center, stod(parametrSet[3]), stol(parametrSet[4], 0, 16), stol(parametrSet[5], 0, 16));
			circleSet.push_back(circle);
			shapeSet.push_back(&circleSet.back());
		}

		else if (parametrSet[0] == "rectangle")
		{
			//RectangleClass rectangle();
		}

		else if (parametrSet[0] == "triangle")
		{
			TriangleClass triangle;
		}
	}

	cout << ShapeMaxPerimetr(shapeSet)->toString();
}
