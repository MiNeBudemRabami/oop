#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include "IShape.h"
#include "triangle.h"
#include "rectangle.h"
#include "circle.h"
#include "LineSegment.h"
#include <algorithm>
#include <deque>

using namespace std;

static bool compareArea(unique_ptr<IShape> const& shape1, unique_ptr<IShape> const& shape2)
{
	return (shape1->GetArea() < shape2->GetArea());
}

static bool comparePerimetr(unique_ptr<IShape> const& shape1, unique_ptr<IShape> const& shape2)
{
	return (shape1->GetPerimetr() < shape2->GetPerimetr());
}

IShape& ShapeMinPerimetr(vector <unique_ptr<IShape>> const& shapeSet)
{
	return **min_element(shapeSet.begin(), shapeSet.end(), comparePerimetr);
}

IShape& ShapeMaxArea(vector <unique_ptr<IShape>> const& shapeSet)
{
	return **max_element(shapeSet.begin(), shapeSet.end(), compareArea);
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
	cout.precision(2);
	cout << std::fixed;

	vector <unique_ptr<IShape>> shapeSet;

	for (;;)
	{
		vector <string> parametrSet = readCommand();

		if (cin.eof())
		{
			break;
		}

		else if (parametrSet[0] == "circle")
		{
			Point center;
			center.x = stod(parametrSet[1]);
			center.y = stod(parametrSet[2]);

			shapeSet.push_back(make_unique<Circle>(center, stod(parametrSet[3]), stol(parametrSet[4], 0, 16), stol(parametrSet[5], 0, 16)));
		}

		else if (parametrSet[0] == "LineSegment")
		{
			Point startPoint;
			startPoint.x = stod(parametrSet[1]);
			startPoint.y = stod(parametrSet[2]);

			Point endPoint;
			endPoint.x = stod(parametrSet[1]);
			endPoint.y = stod(parametrSet[2]);

			shapeSet.push_back(make_unique<LineSegment>(startPoint, endPoint, stol(parametrSet[4], 0, 16)));
		}

		else if (parametrSet[0] == "rectangle")
		{
			Point topLeft;
			topLeft.x = stod(parametrSet[1]);
			topLeft.y = stod(parametrSet[2]);

			shapeSet.push_back(make_unique<RectangleC>(topLeft, stod(parametrSet[3]), stod(parametrSet[4]), stol(parametrSet[5], 0, 16), stol(parametrSet[6], 0, 16)));
		}

		else if (parametrSet[0] == "triangle")
		{
			Point vertex1;
			vertex1.x = stod(parametrSet[1]);
			vertex1.y = stod(parametrSet[2]);

			Point vertex2;
			vertex1.x = stod(parametrSet[3]);
			vertex1.y = stod(parametrSet[4]);

			Point vertex3;
			vertex1.x = stod(parametrSet[5]);
			vertex1.y = stod(parametrSet[6]);
			
			shapeSet.push_back(make_unique<Triangle>(vertex1, vertex2, vertex3, stol(parametrSet[7], 0, 16), stol(parametrSet[8], 0, 16)));
		}
	}

	if (shapeSet.size() != 0)
	{
		cout << "shape with min perimetr " << ShapeMinPerimetr(shapeSet).GetPerimetr() << " " << ShapeMinPerimetr(shapeSet).ToString() << endl;
		cout << "shape with max area " << ShapeMaxArea(shapeSet).GetArea() << " " << ShapeMaxArea(shapeSet).ToString() << endl;
	}
}
