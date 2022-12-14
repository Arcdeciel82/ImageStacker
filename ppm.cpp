/**
 * @file ppm.cpp
 * @author Curt Lynch
 * @date 2022-09-22
 * @brief cPPMImage implementation
 * 
 * defining cPPMImage methods
 */

#include "ppm.h"

#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

cPPMImage::cPPMImage()
{
  iWidth = 0;
  iHeight = 0;
  // cPPMImage only knows the P3 type of ppms; this will work for now.
  sMagicNumber = "P3";
  iMaxColorValue = 255;
}

cPPMImage::cPPMImage(const std::string& sPathToFile)
: cPPMImage()
{
  readFromFile(sPathToFile);
}

void cPPMImage::readFromFile(const std::string& sPathToFile)
{
  // initialize the input stream and some temp variables to make things easier to read
  ifstream file;
  strPixel pix;
  int r, g, b;
  file.open(sPathToFile);

  // Read data
  if (file)
  {
  file >> sMagicNumber >> iWidth >> iHeight >> iMaxColorValue;
  } else if (!file)
  {
    cerr << "cPPMImage: input file stream breaks before pixel data can be read.\n";
    return;
  }
  for (int i = 0; i < (iWidth * iHeight); i++)
  {
    // updates pix with each pixels data then stores a copy in vecData.
    file >> r >> g >> b;
    pix = {r, g, b};
    vecData.push_back(pix);
    if(!file)
    {
      cerr << "cPPMImage: input file stream breaks before reading all pixel data.\n";
      return;
    }
  } 
  file.close();
}

void cPPMImage::writeToFile(const std::string& sPathToFile)
{
  //initialize file stream, counter helps us place the newline after each column... or row... however you want to look at it.
  ofstream file;
  int counter = 1;
  file.open(sPathToFile);

  file << sMagicNumber << "\n" << iWidth  << " " << iHeight << "\n" << iMaxColorValue << "\n";
  for(auto& pix : vecData)
  {
    // I might as well make the human readable image format human readable. Probably uses /way/ more disk space.
    file << setw(3) << pix.r  << " " << setw(3) << pix.g << " " << setw(3) << pix.b;
    // Logic for whether to add a newline or tab.
    if (counter == iWidth)
    {
      file << "\n";
      counter = 1;
    } else
    {
      file << "\t\t";
      counter++;
    }
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

void cPPMImage::createImage(int width, int height, std::string magicNum, int maxColorValue)
{
  iWidth = width;
  iHeight = height;
  sMagicNumber = magicNum; // once again cPPMImage only knows 1 magic number, probably shouldn't have code to change it.
  iMaxColorValue = maxColorValue;
  for(int i = 0; i < (iWidth * iHeight); i ++)
  {
    strPixel pix;
    vecData.push_back(pix);
  }
}

int cPPMImage::getWidth() const
{
  return iWidth;
}

int cPPMImage::getHeight() const
{
    return iHeight;
}
