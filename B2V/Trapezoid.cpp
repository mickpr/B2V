/*
 * Trapezoid.cpp
 *
 *  Created on: 05.01.2017
 *      Author: mickpr
 */

#include "Trapezoid.h"

using namespace std;
using namespace Magick;

Trapezoid::Trapezoid() {
	// TODO Auto-generated constructor stub
}

Trapezoid::~Trapezoid() {
	// TODO Auto-generated destructor stub
//	delete &image;
//	delete &img_left;
//	delete &img_middle;
//	delete &img_right;
}

void Trapezoid::init(std::string imageFilename, int part_width, double hardness) {
	try
	{
		image.read(imageFilename);


		Geometry newSize = Geometry(200, 200);
		// Resize without preserving Aspect Ratio
		newSize.aspect(true);
		image.resize(newSize);

		//image.resize(Geometry(100,100));

		width = image.columns();
		height = image.rows();

		// copy three images into via copy constructor :)
		img_left = Magick::Image(image);
		img_right= Magick::Image(image);
		img_middle=Magick::Image(image);

	} catch ( std::exception &error_ ) {
		cout << "Trapezoid::init exception: " << error_.what() << endl;
    }
}

Magick::Image Trapezoid::generate(std::string key) {

	Magick::Image img;
	//int n;

	// crop - lewy   gorny rog zostaje
	// chop - prawy dolny rog zostaje.
	//img_left.chop(Magick::Geometry(0,0));
	parts_in_brick_width =3;

	cout << "Image has width=" << width << " and " << height << endl;
	cout << "Middle: " << width << " and " << height << endl;

//	[0,0]      [szerokosc-1,0][szer,0].......[width-1-szer,0].......[width-1,0]
//	................................................................
//	[0,height] [szer-1,height][szer,height]..[width-1-szer,height]..[width-1,height]


	img_left.crop(Magick::Geometry(width/parts_in_brick_width,height));
	cout << "Image left: " <<img_left.columns()<< "x"<< img_left.rows() << endl;
	img_middle.crop(Magick::Geometry(width-(width/parts_in_brick_width),height));
	img_middle.chop(Magick::Geometry(width/parts_in_brick_width,0));
	cout << "Image midl: " <<img_middle.columns()<< "x"<< img_middle.rows() << endl;
	img_right.chop(Magick::Geometry(width-width/parts_in_brick_width,0));
	cout << "Image right: " <<img_right.columns()<< "x"<< img_right.rows() << endl;
	return img_middle;

/*
 *
n=0  # zmienna pomocnicza
		img_left  = @img.crop(0,0,@width/@parts_in_brick_width,@height)
		img_left.virtual_pixel_method = Magick::TransparentVirtualPixelMethod
		# puts n
		n=n+@width/@parts_in_brick_width
		img_middle= @img.crop(n,0,@width-2*@width/@parts_in_brick_width,@height)
		img_middle.virtual_pixel_method = Magick::TransparentVirtualPixelMethod
		# puts n
		n=@width-n
		img_right = @img.crop(n,0,@width/@parts_in_brick_width, @height)
		img_right.virtual_pixel_method = Magick::TransparentVirtualPixelMethod


#		@hardness =0.8 # procentowo (0..1) grubosc nitki cienkiej w porownaniu do grubej
		squeeze = (@height-(@height*@hardness).ceil)/2

		img_dst = Magick::Image::new(@width,@height) { self.background_color = "Transparent" }

		# left
		width = img_left.columns
		height = img_left.rows
		points = [1.5, 0,0, 0,0, width,0, width,squeeze, width,height, width,height - squeeze, 0,height, 0,height]

		if val[0]=='0' && val[1]=='0'
			points = [1.5, 0,0, 0,squeeze, width,0, width,squeeze, width,height, width,height - squeeze, 0,height, 0,height-squeeze]
			img_left = img_left.distort(Magick::PolynomialDistortion, points)
		end
		if val[0]=='0' && val[1]=='1'
			points = [1.5, 0,0, 0,squeeze, width,0, width,0, width,height, width,height, 0,height, 0,height-squeeze]
			img_left = img_left.distort(Magick::PolynomialDistortion, points) #.flop
		end
		if val[0]=='1' && val[1]=='0'
			img_left = img_left.distort(Magick::PolynomialDistortion, points)
		end
		if val[0]=='1' && val[1]=='1'
			# none
		end

		# middle
		width = img_left.columns
		height = img_left.rows

		if val[1]=='0'

			# if val[0]=='1' && val[2]=='1'
			# 	points_barrel = [0.0, 0.0, 0.0, 1.0,   0.0, -0.1, -0.5, 1.9]
			# 	img_middle=img_middle.distort(Magick::BarrelDistortion, points_barrel)
			# else
				# make image smaller (on height size)
				points = [1.5, 0,0, 0,squeeze, width,0, width,squeeze, width,height, width,height - squeeze, 0,height, 0,height-squeeze]
				img_middle = img_middle.distort(Magick::PolynomialDistortion, points)
			# end
		else
		#	we don't change middle image in this case
		end

		# right
		width = img_left.columns
		height = img_left.rows

		if val[1]=='0' && val[2]=='0'
			points = [1.5, 0,0, 0,squeeze, width,0, width,squeeze, width,height, width,height - squeeze, 0,height, 0,height-squeeze]
			img_right = img_right.distort(Magick::PolynomialDistortion, points)
		end
		if val[1]=='0' && val[2]=='1'
			points = [1.5, 0,0, 0,squeeze, width,0, width,0, width,height, width,height, 0,height, 0,height-squeeze]
			img_right = img_right.distort(Magick::PolynomialDistortion, points)
		end
		if val[1]=='1' && val[2]=='0'
			points = [1.5, 0,0, 0,0, width,0, width,squeeze, width,height, width,height - squeeze, 0,height, 0,height]
			img_right = img_right.distort(Magick::PolynomialDistortion, points)
		end
		if val[1]=='1' && val[2]=='1'
			#none
		end

		#img_left = shadow(img_left, Direction::Left)
		#img_right = shadow(img_right, Direction::Right)

		img_dst.composite!(img_left,0,0,Magick::OverCompositeOp)
		img_dst.composite!(img_middle,img_left.columns,0,Magick::OverCompositeOp)
		img_dst.composite!(img_right,(img_left.columns+img_middle.columns),0,Magick::OverCompositeOp)
		img_dst



 */

//	return img;
}






