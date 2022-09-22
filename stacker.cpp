#include "stacker.h"
#include <iostream>

using namespace std;

stacker::stacker()
{
  
}

void stacker::addImage(std::string sPathToFile)
{
  cPPMImage image(sPathToFile);
  images.push_back(image);
}

void stacker::addImage(const cPPMImage& image)
{
  images.push_back(image);
}

cPPMImage stacker::getOutput()
{
  return output;
}

void stacker::writeToFile(std::string sPathToFile)
{
  output.writeToFile(sPathToFile);
}

void stacker::stack()
{
  // If no images have been added, does nothing
  if(images.size() == 0) {
    return;
  }
  // create an output images based on the first image's dimensions
  output.createImage(images.front().getWidth(), images.front().getHeight());
  
  // Average the individual rgb values at each pixel.
  for(int x = 0; x < output.getWidth(); x++) {
    for (int y = 0; y < output.getHeight(); y++) {
      // Probably could use a fancy operator overload or a 3dvector to clean this up
      // ints to collect each pixels rgb values
      int r = 0;
      int g = 0;
      int b = 0;
      for(cPPMImage& img : images) {
        // add each value
        r += img.at(x,y).r;
        g += img.at(x,y).g;
        b += img.at(x,y).b;
      }
      // compute the avg
      r /= images.size();
      g /= images.size();
      b /= images.size();
      // set the pixel in our output image to the computed avg value
      output.at(x,y) = {r, g, b};
    }
  }
}
