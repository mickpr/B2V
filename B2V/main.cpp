#include <Magick++.h>
#include <iostream>
#include <string>
#include <libjson/libjson.h>
#include <unordered_map>

using namespace std;
using namespace Magick;

int main(int argc,char **argv)
{
  InitializeMagick(*argv);

  // Construct the image object. Separating image construction from the
  // the read operation ensures that a failure to read the image file
  // doesn't render the image object useless.
  Image image;
  try {
    // Read a file into image object
    image.read( "girl.jpg" );

    // Crop the image to specified size (width, height, xOffset, yOffset)
    image.crop( Geometry(100,100, 100, 100) );

    // Write the image to a file
    image.write( "x.gif" );
  }
  catch( Exception &error_ )
    {
      cout << "Caught exception: " << error_.what() << endl;
      return 1;
    }


printf("test JSON-a\n");

JSONNODE *n = json_new(JSON_NODE);
json_push_back(n, json_new_a("String Node", "String Value"));
json_push_back(n, json_new_i("Integer Node", 42));
json_push_back(n, json_new_f("Floating Point Node", 3.14));
json_push_back(n, json_new_b("Boolean Node", 1));
json_char *jc = json_write_formatted(n);
printf("%s\n", jc);
json_free(jc);
json_delete(n);

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
  return 0;
}
