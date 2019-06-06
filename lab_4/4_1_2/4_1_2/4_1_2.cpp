#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include "shapeInterface.h"
#include "triangleClass.h"
#include "rectangleClass.h"
#include "circleClass.h"
#include "lineSegmentClass.h"
#include <algorithm>
#include <deque>

using namespace std;

static bool compareArea(ShapeInterface* shape1, ShapeInterface* shape2)
{
	return (shape1->getArea() < shape2->getArea());
}

static bool comparePerimetr(ShapeInterface* shape1, ShapeInterface* shape2)
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
	deque <LineSegmentClass> lineSegmentSet;
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

		if (parametrSet[0] == "lineSegment")
		{
			PointClass startPoint;
			startPoint.x = stod(parametrSet[1]);
			startPoint.y = stod(parametrSet[2]);

			PointClass endPoint;
			endPoint.x = stod(parametrSet[1]);
			endPoint.y = stod(parametrSet[2]);

			LineSegmentClass lineSegment(startPoint, endPoint, stol(parametrSet[4], 0, 16));
			lineSegmentSet.push_back(lineSegment);
			shapeSet.push_back(&lineSegmentSet.back());
		}

		else if (parametrSet[0] == "rectangle")
		{
			PointClass topLeft;
			topLeft.x = stod(parametrSet[1]);
			topLeft.y = stod(parametrSet[2]);

			RectangleClass rectangle(topLeft, stod(parametrSet[3]), stod(parametrSet[4]), stol(parametrSet[5], 0, 16), stol(parametrSet[6], 0, 16));
			rectangleSet.push_back(rectangle);
			shapeSet.push_back(&rectangleSet.back());
		}

		else if (parametrSet[0] == "triangle")
		{
			PointClass vertex1;
			vertex1.x = stod(parametrSet[1]);
			vertex1.y = stod(parametrSet[2]);

			PointClass vertex2;
			vertex1.x = stod(parametrSet[3]);
			vertex1.y = stod(parametrSet[4]);

			PointClass vertex3;
			vertex1.x = stod(parametrSet[5]);
			vertex1.y = stod(parametrSet[6]);
			
			TriangleClass triangle(vertex1, vertex2, vertex3, stol(parametrSet[7], 0, 16), stol(parametrSet[8], 0, 16));
			triangleSet.push_back(triangle);
			shapeSet.push_back(&triangleSet.back());
		}
	}

	cout.precision(2);
	cout << std::fixed;

	cout << "shape with max perimetr " << to_string(ShapeMaxPerimetr(shapeSet)->getPerimetr()) << " " << ShapeMaxPerimetr(shapeSet)->toString()  << endl;
	cout << "shape with max area " << to_string(ShapeMaxArea(shapeSet)->getArea()) << " " <<  ShapeMaxArea(shapeSet)->toString()  << endl;
}
