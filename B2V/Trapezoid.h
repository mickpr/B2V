#ifndef TRAPEZOID_H_
#define TRAPEZOID_H_
#include <string>
#include <exception>
#include <iostream>
#include <Magick++.h>
using namespace std;
using namespace Magick;

class Trapezoid {

private:
	std::string image_filename;
	int 		parts_in_brick_width;
	double 		hardness;
	Magick::Image image;
	int 		width, height;
	Magick::Image  img_left, img_middle, img_right;

public:
	Trapezoid();
	virtual ~Trapezoid();
	void init(std::string imageFilename, int part_width, double hardness);
	Magick::Image generate(std::string key);
};


#endif /* TRAPEZOID_H_ */
