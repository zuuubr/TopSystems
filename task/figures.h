#pragma once

#include <string>

class Color {

public:
	unsigned char red;
	unsigned char green;
	unsigned char blue;

	Color(unsigned char red_ = 0, unsigned char green_ = 0, unsigned char blue_ = 0);

};

class Point2D {

public:

	const int x;
	const int y;
	
	Point2D();
	Point2D(int x_pos, int y_pos);

};

class Curve
{

	Color color;
	const std::string figureName;

public:

	Curve(void);
	Curve(std::string name);
	Curve(std::string name, Color cl);

	std::string getName();
	void setColor(Color newColor);
	Color getColor();

	virtual void printPoint2D() = 0;
};


class Circle : public Curve
{

public:
	Point2D centre;
	float radius;

	Circle(float Or);
	Circle(float Or, Point2D position);
	Circle(float Or, Point2D position, Color cl);

	void printPoint2D();
};

class Rectangle : public Curve
{

public:
	Point2D left_top_point;
	Point2D right_bottom_point;

	Rectangle(Point2D top, Point2D bottom);
	Rectangle(Point2D top, Point2D bottom, Color cl);
	Rectangle(float x1, float y1, float x2, float y2, Color cl);

	void printPoint2D();
	float getHeight();
	float getWidth();
};

class Triangle : public Curve
{

public:
	Point2D one;
	Point2D two;
	Point2D three;

	Triangle(Point2D one_pos, Point2D two_pos, Point2D three_pos);
	Triangle(Point2D one_pos, Point2D two_pos, Point2D three_pos, Color cl);

	void printPoint2D();
};
