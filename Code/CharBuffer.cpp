Image image("earth.png");
int width=128,height=128;
//width and height are width and height of image "earth"
//initialize
unsigned char *pixels = new unsigned char[width*height];

//write image pixels in unsigned char array

image.write( 0, 0, width, height, "I", CharPixel, pixels );
