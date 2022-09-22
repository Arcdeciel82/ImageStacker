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
  output.WriteToFile(sPathToFile);
}

void stacker::stack()
{
  if(images.size() == 0) {
    return;
  }
  output.CreateImage(images.front().width(), images.front().height());
  
  for(int x = 0; x < output.width(); x++) {
    for (int y = 0; y < output.height(); y++) {
      int r = 0;
      int g = 0;
      int b = 0;
      for(cPPMImage& img : images) {
        r += img.at(x,y).r;
        g += img.at(x,y).g;
        b += img.at(x,y).b;
      }
      r /= images.size();
      g /= images.size();
      b /= images.size();
      output.at(x,y) = {r, g, b};
    }
  }
}
