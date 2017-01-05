#include "Weft.h"
#include <Magick++.h>
#include <map>

Weft::Weft() :
	name (""),
	color("#ffffff"),
	width(32),
	spacing(32),
	hardness(1.0)
{
}

Weft::~Weft(){
	//delete &ImagesHashtable;
}

Weft::Weft(string imageFile, string color, int width, int spacing, float hardness) :
	name(""),
	color("#ffffff"),
	width(32),
	spacing(32),
	hardness(1.0)
{
	Image img;
	hardness = 1.0;
	img.magick("RGB");
	img.read(imageFile);
	ImagesHashtable["000"] = img;
	ImagesHashtable["001"] = img;
	ImagesHashtable["010"] = img;
	ImagesHashtable["011"] = img;
	ImagesHashtable["100"] = img;
	ImagesHashtable["101"] = img;
	ImagesHashtable["110"] = img;
	ImagesHashtable["111"] = img;
}

Image Weft::getImage(string key) {
	return ImagesHashtable[key];
}
