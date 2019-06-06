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

static bool compareArea(IShape* shape1, IShape* shape2)
{
	return (shape1->GetArea() < shape2->GetArea());
}

static bool comparePerimetr(IShape* shape1, IShape* shape2)
{
	return (shape1->GetPerimetr() < shape2->GetPerimetr());
}

IShape* ShapeMinPerimetr(vector <IShape*> shapeSet)
{
	return *min_element(shapeSet.begin(), shapeSet.end(), comparePerimetr);
}

IShape* ShapeMaxArea(vector <IShape*> shapeSet)
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
	deque <Circle> circleSet;
	deque <RectangleC> rectangleSet;
	deque <Triangle> triangleSet;
	deque <LineSegment> LineSegmentSet;
	vector <IShape*> shapeSet;

	for (;;)
	{
		parametrSet = readCommand();

		if (cin.eof())
		{
			break;
		}

		if (parametrSet[0] == "circle")
		{
			Point center;
			center.x = stod(parametrSet[1]);
			center.y = stod(parametrSet[2]);

			Circle circle(center, stod(parametrSet[3]), stol(parametrSet[4], 0, 16), stol(parametrSet[5], 0, 16));
			circleSet.push_back(circle);
			shapeSet.push_back(&circleSet.back());
		}

		if (parametrSet[0] == "LineSegment")
		{
			Point startPoint;
			startPoint.x = stod(parametrSet[1]);
			startPoint.y = stod(parametrSet[2]);

			Point endPoint;
			endPoint.x = stod(parametrSet[1]);
			endPoint.y = stod(parametrSet[2]);

			LineSegment LineSegment(startPoint, endPoint, stol(parametrSet[4], 0, 16));
			LineSegmentSet.push_back(LineSegment);
			shapeSet.push_back(&LineSegmentSet.back());
		}

		else if (parametrSet[0] == "rectangle")
		{
			Point topLeft;
			topLeft.x = stod(parametrSet[1]);
			topLeft.y = stod(parametrSet[2]);

			RectangleC rectangle(topLeft, stod(parametrSet[3]), stod(parametrSet[4]), stol(parametrSet[5], 0, 16), stol(parametrSet[6], 0, 16));
			rectangleSet.push_back(rectangle);
			shapeSet.push_back(&rectangleSet.back());
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
			
			Triangle triangle(vertex1, vertex2, vertex3, stol(parametrSet[7], 0, 16), stol(parametrSet[8], 0, 16));
			triangleSet.push_back(triangle);
			shapeSet.push_back(&triangleSet.back());
		}
	}

	cout.precision(2);
	cout << std::fixed;

	cout << "shape with min perimetr " << to_string(ShapeMinPerimetr(shapeSet)->GetPerimetr()) << " " << ShapeMinPerimetr(shapeSet)->ToString()  << endl;
	cout << "shape with max area " << to_string(ShapeMaxArea(shapeSet)->GetArea()) << " " <<  ShapeMaxArea(shapeSet)->ToString()  << endl;
}
