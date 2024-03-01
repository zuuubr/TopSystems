#include "imageGenerator.h"
#include <opencv2/imgproc.hpp>


imageGenerator::imageGenerator(unsigned int height, unsigned  int width, int type, cv::Scalar color)
: rows(height), cols(width), typeOfImage(type)
{

    cv::Mat img(rows, cols, type, color);
    image = img;

}

imageGenerator::imageGenerator(const imageGenerator& obj) {
    image = obj.image;

    rows = obj.rows;
    cols = obj.cols;
    
    typeOfImage = obj.typeOfImage;
}

imageGenerator::imageGenerator(cv::Mat& img) {
    image = img;

    rows = image.rows;
    cols = image.cols;
}

imageGenerator::imageGenerator()
: rows(400), cols(400), typeOfImage(CV_8UC1)
{

    cv::Mat img(rows, cols, typeOfImage, cv::Scalar(0));
    image = img;

}

void imageGenerator::draw(Circle figure) {

    Color cl = figure.getColor();
    cv::Scalar color(cl.blue, cl.green, cl.red);

    cv::circle(
        image,
        cv::Point(figure.centre.x, figure.centre.y),
        figure.radius,
        color
    );
}

void imageGenerator::draw(Rectangle figure) {

    Color cl = figure.getColor();
    cv::Scalar color(cl.blue, cl.green, cl.red);

    cv::rectangle(
        image,
        cv::Point(figure.left_top_point.x, figure.left_top_point.y),
        cv::Point(figure.right_bottom_point.x, figure.right_bottom_point.y),
        color
    );

}

void imageGenerator::draw(Triangle figure) {

    Color cl = figure.getColor();
    cv::Scalar color(cl.blue, cl.green, cl.red);

    cv::line(image, cv::Point(figure.one.x, figure.one.y), cv::Point(figure.two.x, figure.two.y), color);
    cv::line(image, cv::Point(figure.two.x, figure.two.y), cv::Point(figure.three.x, figure.three.y), color);
    cv::line(image, cv::Point(figure.three.x, figure.three.y), cv::Point(figure.one.x, figure.one.y), color);
}

int imageGenerator::getHeight() {
    return rows;
}

int imageGenerator::getWidth() {
    return cols;
}

void imageGenerator::showImage(cv::String name) {
    cv::namedWindow(name, cv::WINDOW_AUTOSIZE);
    cv::imshow(name, image);
    cv::waitKey(0);

    cv::destroyWindow(name);
}

bool imageGenerator::saveImage(cv::String name) {
    return cv::imwrite(name, image);
}

imageGenerator imageGenerator::loadImage(cv::String name) {

    cv::Mat img;
    img = cv::imread(name);

    return imageGenerator(img);
}

cv::Mat imageGenerator::getMat() {
    return image;
}
