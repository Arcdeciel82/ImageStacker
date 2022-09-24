/**
 * @file ppm.h
 * @author Curt Lynch
 * @date 2022-09-22
 * @brief PPM image class
 * 
 * useful tools for working with ppm images read/write/modify
 */
#ifndef PPM_H
#define PPM_H

#include <string>
#include <vector>


/**
 * pod struct holds info for a single pixel
 *
 * @struct strPixel ppm.h "ImageStacker/ppm.h"
 * @brief one single pixel
 *
 */
struct strPixel
{
    int r = 0;
    int g = 0;
    int b = 0;
};


/**
 * provides tools to read write hold and manipulate ppm images
 *
 * @class cPPMImage ppm.h "ImageStacker/ppm.h"
 * @brief ppm image class
 *
 */
class cPPMImage
{
    private:
    int iWidth;
    int iHeight;
    int iMaxColorValue;
    std::string sMagicNumber;
    std::vector<strPixel> vecData;

    public:

/**
 * default constructor
 *
 * @pre 
 * @post cPPMImage initialized with size 0x0 image
 * 
 */
    cPPMImage();

/**
 * paramaterized constructor
 *
 * @param const std::string& sPathToFile path to ppm image file
 * @pre 
 * @post cPPMImage initialized with ppm image file on disk
 * 
 */
    cPPMImage(const std::string& sPathToFile);

/**
 * loads cPPMImage from file on disk
 *
 * @param const std::string& sPathToFile path to ppm image file
 * @pre 
 * @return void 
 * @post cPPMImage contains data from ppm image file on disk
 * 
 */
    void readFromFile(const std::string& sPathToFile);

/**
 * writes cPPMImage data to disk in ppm format
 *
 * @param const std::string& sPathToFile path to write image data to
 * @pre 
 * @return void 
 * @post file written to disk
 * 
 */
    void writeToFile(const std::string& sPathToFile);

/**
 * accessor for pixel data at (x,y) position of image
 *
 * @param int x x-coordinate location
 * @param int y y-coordinate location
 * @pre 
 * @return strPixel& strPixel at (x,y) location
 * @post 
 * 
 */
    strPixel& at(int x, int y);

/**
 * accessor for pixel data at (x,y) position of image
 *
 * @param int x x-coordinate location
 * @param int y y-coordinate location
 * @pre 
 * @return strPixel strPixel at (x,y) location
 * @post 
 * 
 */
    strPixel at(int x, int y) const;

/**
 * Creates a new image with dimensions (x,y)
 *
 * @param int width width of new image
 * @param int height height of new image
 * @param std::string magicNum = "P3" magic number of new image
 * @param int maxColorValue = 255 maximum rgb value of new image
 * @pre 
 * @return void 
 * @post contains new image with desired resolution
 * 
 */
    void createImage(int width, int height, std::string magicNum = "P3", int maxColorValue = 255);

/**
 * returns width of image
 *
 * @pre cPPMImage should contain image data
 * @return int width of image
 * @post 
 * 
 */
    int getWidth() const;

/**
 * returns height of image
 *
 * @pre cPPMImage should contain image data
 * @return int height of image
 * @post 
 * 
 */
    int getHeight() const;
};
#endif //PPM_H
