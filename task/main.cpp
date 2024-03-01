#include "opencv2/highgui/highgui.hpp"
#include "imageGenerator.h"
#include "figures.h"

int main() {

	Rectangle rect(Point2D(40, 76), Point2D(200, 300), Color(100, 50, 200));
	Circle circl(50, Point2D(76, 21));
	Triangle triang(Point2D(100, 100), Point2D(90, 60), Point2D(50, 0), Color(255, 0, 255));

	imageGenerator image(200, 200, CV_8UC3, cv::Scalar(255, 255, 255));
	
	image.draw(rect);
	image.draw(circl);
	image.draw(triang);

	image.showImage();

	return 0;
}