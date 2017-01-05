/*
 * Weft.cpp
 *
 *  Created on: 01.01.2017
 *      Author: mickpr
 */

#include "Weft.h"
#include <Magick++.h>
#include <map>

Weft::Weft() {
	// TODO Auto-generated constructor stub
}

Weft::Weft(string imageFile, string color, int width, int spacing, float hardness) {

	Image img;
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
	//			w = Weaving::Trapezoid.new(image,6,hardness) {}
	//
	//		    @images["000"] = w.generate("000")
	//		    @images["001"] = w.generate("001")
	//		    @images["010"] = w.generate("010")
	//		    @images["011"] = w.generate("011")
	//		    @images["100"] = w.generate("100")
	//		    @images["101"] = w.generate("101")
	//		    @images["110"] = w.generate("110")
	//		    @images["111"] = w.generate("111")
	//
	//
	//		rescue Exception => e
	//		    puts e.message
	//		    puts e.backtrace.inspect
	//		    raise '--- Reading Wefts Image Error ---'
	//		end
}

Weft::~Weft() {
	// TODO Auto-generated destructor stub
}

Image Weft::getImage(string key) {
	return ImagesHashtable[key];
}

//	attr_accessor :color, :width, :spacing, :images
