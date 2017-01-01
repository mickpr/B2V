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

using namespace std;

class Weft {

private:
	string 	name;
	string 	color;
	int 	width;
	int 	spacing;
	float 	hardness;
	//Hash		images;
public:
	Weft();
	Weft(string image, string color, int width, int spacing, float hardness);
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
