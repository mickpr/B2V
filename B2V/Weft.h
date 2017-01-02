/*
 * Weft.h
 *
 *  Created on: 01.01.2017
 *      Author: mickpr
 */

#ifndef WEFT_H_
#define WEFT_H_

#include <string>
#include <unordered_map>
#include <Magick++.h>
#include <unordered_map>

using namespace std;
using namespace Magick;

class Weft {

private:
	string 	name;
	string 	color;
	int 	width;
	int 	spacing;
	float 	hardness;
	std::unordered_map<std::string, Magick::Image> ImagesHashtable;

//	Image	image000;
//	Image	image001;
//	Image	image010;
//	Image	image011;
//	Image	image100;
//	Image	image101;
//	Image	image110;
//	Image	image111;

public:
	Weft();
	Weft(string imageFile, string color, int width, int spacing, float hardness=1.0);
	Image getImage(string key);
	virtual ~Weft();
};

#endif /* WEFT_H_ */

//
//
//struct image{int i,j,k;};
//struct hash_image{
//  size_t operator()(const image &img) const{
//    return std::hash<int>()(img.i) ^ std::hash<int>()(img.j) ^ std::hash<int>()(img.k);
//  }
//};
