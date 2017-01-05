#ifndef WEFT_H_
#define WEFT_H_

#include <string>
#include <map>
#include <Magick++.h>

using namespace std;
using namespace Magick;

class Weft {

private:
	string 	name;
	string 	color;
	int 	width;
	int 	spacing;
	float 	hardness;
	std::map<std::string, Magick::Image> ImagesHashtable;

public:
	Weft();
	Weft(string imageFile, string color, int width, int spacing, float hardness=1.0);
	Image getImage(string key);
	virtual ~Weft();
};

#endif /* WEFT_H_ */

