#include "ppm.h"

#include <fstream>
#include <iomanip>

using namespace std;

cPPMImage::cPPMImage()
{
  iWidth = 0;
  iHeight = 0;
  sMagicNumber = "P3";
  iMaxColorValue = 255;
}

cPPMImage::cPPMImage(const std::string& sPathToFile) : cPPMImage()
{
  ReadFromFile(sPathToFile);
}

void cPPMImage::ReadFromFile(const std::string& sPathToFile)
{
  ifstream file;
  strPixel pix;
  int r, g, b;
  this->sPathToFile = sPathToFile;
  file.open(sPathToFile);
  file >> sMagicNumber >> iWidth >> iHeight >> iMaxColorValue;
  for (int i = 0; i < (iWidth * iHeight); i++) {
    file >> r >> g >> b;
    pix = {r, g, b};
    vecData.push_back(pix);
  } 
  file.close();
}

void cPPMImage::WriteToFile(const std::string& sPathToFile)
{
  ofstream file;
  int counter = 0;
  file.open(sPathToFile);
  file << sMagicNumber << "\n" << iWidth  << " " << iHeight << "\n" << iMaxColorValue << "\n";
  for(auto& pix : vecData) {
    // I might as well make the human readable image format human readable.
    file << setw(3) << pix.r  << " " << setw(3) << pix.g << " " << setw(3) << pix.b;
    if (counter == iWidth) {
      counter = 0;
      file << "\n";
    } else {
      file << "\t\t";
    }
    counter++;
  }
  file.close();
}

strPixel& cPPMImage::at(int x, int y)
{
  return vecData[y*iWidth + x];
}

strPixel cPPMImage::at(int x, int y) const
{
  return vecData[y*iWidth + x];
}

void cPPMImage::CreateImage(int width, int height, std::string magicNum, int maxColorValue)
{
  iWidth = width;
  iHeight = height;
  sMagicNumber = magicNum;
  iMaxColorValue = maxColorValue;
  for(int i = 0; i < (iWidth * iHeight); i ++) {
    strPixel pix;
    vecData.push_back(pix);
  }
}

int cPPMImage::width() const
{
  return iWidth;
}

int cPPMImage::height() const
{
    return iHeight;
}
