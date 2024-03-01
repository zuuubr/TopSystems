#include "figures.h"
#include <iostream>

Color::Color(unsigned char red_, unsigned char green_, unsigned char blue_) 
: red(red_), green(green_), blue(blue_) 
{ }

Point2D::Point2D() : x(0), y(0)
{ }

Point2D::Point2D(int x_pos, int y_pos) : x(x_pos), y(y_pos) 
{ }

Curve::Curve(void) : figureName("unknown") , color(0, 0, 0)
{ }

Curve::Curve(std::string name) : figureName(name), color(0, 0, 0)
{ }

Curve::Curve(std::string name, Color cl) : figureName(name), color(cl)
{ }

std::string Curve::getName() {
	return figureName;
}

void Curve::setColor(Color newColor) {
	color = newColor;
}

Color Curve::getColor() {
	return color;
}

Circle::Circle(float Or) 
: Curve("Circle", Color(0, 0, 0)), radius(abs(Or)), centre(0.0, 0.0)
{ }

Circle::Circle(float Or, Point2D position) 
: Curve("Circle", Color(0, 0, 0)), radius(abs(Or)), centre(position)
{ }

Circle::Circle(float Or, Point2D position, Color cl)
: Curve("Circle", cl), radius(abs(Or)), centre(position)
{ }

void Circle::printPoint2D() {
	std::cout << "( " << centre.x << ", " << centre.y << " ) ";
}

Rectangle::Rectangle(Point2D top, Point2D bottom)
: Curve("Rectangle", Color(0, 0, 0)), left_top_point(top), right_bottom_point(bottom)
{ }

Rectangle::Rectangle(Point2D top, Point2D bottom, Color cl)
: Curve("Rectangle", cl), left_top_point(top), right_bottom_point(bottom)
{ }

Rectangle::Rectangle(float x1, float y1, float x2, float y2, Color cl)
: Curve("Rectangle", cl), left_top_point(x1, y1), right_bottom_point(x2, y2) 
{ }

void Rectangle::printPoint2D() {
	std::cout << "( " << left_top_point.x << ", " << left_top_point.y << " ) ";
	std::cout << "( " << right_bottom_point.x << ", " << right_bottom_point.y << " ) ";
}

float Rectangle::getHeight() {
	return right_bottom_point.y - left_top_point.y;
}

float Rectangle::getWidth() {
	return right_bottom_point.x - left_top_point.x;
}

Triangle::Triangle(Point2D one_pos, Point2D two_pos, Point2D three_pos)
: Curve("Triangle", Color(0, 0, 0)), one(one_pos), two(two_pos), three(three_pos)
{ }

Triangle::Triangle(Point2D one_pos, Point2D two_pos, Point2D three_pos, Color cl)
: Curve("Triangle", cl), one(one_pos), two(two_pos), three(three_pos)
{ }

void Triangle::printPoint2D() {
	std::cout << "( " << one.x << ", " << one.y << " ) ";
	std::cout << "( " << two.x << ", " << two.y << " ) ";
	std::cout << "( " << three.x << ", " << three.y << " ) ";
}
