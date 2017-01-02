#include <Magick++.h>
#include <iostream>
#include <string>
//sudo apt-get install libjsoncpp-dev
//	  https://en.wikibooks.org/wiki/JsonCpp

#include <jsoncpp/json/json.h>
#include <unordered_map>
#include <fstream>
#include "Weft.h"
#include "TimeCounter.h"

using namespace std;
using namespace Magick;

int main(int argc,char **argv)
{
	Weft c;


	InitializeMagick(*argv);
	TimeCounter timer;

	timer.start();

	try
	{
		ifstream ifs("example.json");
		Json::Reader reader;
		Json::Value obj;
		reader.parse(ifs, obj); // reader can also read strings

		cout << "BitmapFile: " << obj["BitmapFile"].asString() << endl;
		cout << "FirstWeftOn: " << obj["FirstWeftOn"].asString() << endl;
		cout << "FirstWarpOn: " << obj["FirstWarpOn"].asString() << endl;

		cout << "Wefts" << std::endl;
		const Json::Value& wefts = obj["Wefts"]; // array of characters
		for (unsigned int i = 0; i < wefts.size(); i++){
			cout << "    color: " << wefts[i]["color"].asString(); //.asUInt();
			cout << "    width: " << wefts[i]["width"].asString();
			cout << "  spacing: " << wefts[i]["spacing"].asString();
			cout << "    image: " << wefts[i]["image"].asString();
			cout << " hardness: " << wefts[i]["hardness"].asString();
			cout << endl;
		}

		cout << "Warps" << std::endl;
		const Json::Value& warps = obj["Warps"]; // array of characters
		for (unsigned int i = 0; i < warps.size(); i++){
			cout << "    color: " << warps[i]["color"].asString(); //.asUInt();
			cout << "    width: " << warps[i]["width"].asString();
			cout << "  spacing: " << warps[i]["spacing"].asString();
			cout << "    image: " << warps[i]["image"].asString();
			cout << " hardness: " << warps[i]["hardness"].asString();
			cout << endl;
		}
	} catch( Exception &error_ ) {
		cout << "Caught exception: " << error_.what() << endl;
		return 1;
    }

	// Construct the image object. Separating image construction from the
	// the read operation ensures that a failure to read the image file
	// doesn't render the image object useless.
	Image image, img;
	try {
		// Read a file into image object
		image.read( "girl.jpg" );

		// Crop the image to specified size (width, height, xOffset, yOffset)
		image.crop( Geometry(100,100, 100, 100) );
		// Write the image to a file
		image.write( "x.gif" );

		// Create base image (white image of 300 by 200 pixels)
		img = Image( Geometry(300,200), Color("white") );

		img.strokeColor("red"); // Outline color
		img.fillColor("green"); // Fill color
		img.strokeWidth(5);
		// Draw a circle
		img.draw( DrawableCircle(100,100, 50,100) );
		// Draw a rectangle
		img.draw( DrawableRectangle(200,200, 270,170) );

		//img.display( );
	}
	catch( Exception &error_ )  {
		cout << "Caught exception: " << error_.what() << endl;
		return 1;
    }




	std::unordered_map<std::string, int> months;
    months["January"] = 31;
    months["February"] = 28;
    months["March"] = 31;
    months["April"] = 30;
    months["May"] = 31;
    months["June"] = 30;
    months["July"] = 31;
    months["August"] = 31;
    months["September"] = 30;
    months["October"] = 31;
    months["November"] = 30;
    months["December"] = 31;
    std::cout << "September has " << months["September"] << " days " << std::endl;
    std::cout << "April     has " << months["April"]     << " days " << std::endl;
    std::cout << "December  has " << months["December"]  << " days " << std::endl;
    std::cout << "February  has " << months["February"]  << " days " << std::endl;

	// // string na  c_str()
	// string dupa = "asdasdasd";
	// printf("%s\n",dupa.c_str());

    //    // char* na string
    //    char * dupa2 = "dupa2";
    //    string dupa3 = dupa2;
    //    cout << dupa3;


    //timer.wait(1201);

    timer.stop();
    cout << "czas trwania " << std::to_string(timer.getTime()) << " sek.";
    return 0;
}
