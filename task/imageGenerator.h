#pragma once

#include "opencv2/highgui/highgui.hpp"
#include "figures.h"

// ѕозиционирование фигур на изображение
typedef enum {
	LEFT,
	TOP,
	RIGHT,
	BOTTOM,
	CENTRE
} POSITION;

class imageGenerator
{
	cv::Mat image;

	unsigned int rows;
	unsigned int cols;

	int typeOfImage;

public:

	imageGenerator(unsigned int height, unsigned int width, int typeOfImage, cv::Scalar color);
	imageGenerator(const imageGenerator& obj);
	imageGenerator(cv::Mat& img);
	imageGenerator();

	void draw(Circle figure);
	void draw(Rectangle figure);
	void draw(Triangle figure);

	void showImage(cv::String name = "image");
	bool saveImage(cv::String name);
	static imageGenerator loadImage(cv::String name);

	int getHeight();
	int getWidth();
	cv::Mat getMat();
};

