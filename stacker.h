#ifndef STACKER_H
#define STACKER_H

#include "ppm.h"
#include <vector>
#include <string>

class stacker {
  private:
  std::vector<cPPMImage> images;
  cPPMImage output;

  public:

/**
 * default constructor
 *
 * @pre 
 * @post stackers is ready for images
 * 
 */
  stacker();

/**
 * 'stacks' the images, averaging all color data into one ppm image ready for output
 *
 * @pre stacker should have some images to stack
 * @return Void 
 * @post output is updates
 * 
 */
  Void stack();

/**
 * reads a ppm image file from disk and adds it to the images vector
 *
 * @param std::string sPathToFile path to ppm image file
 * @pre 
 * @return void 
 * @post images contains the new image
 * 
 */
  void addImage(std::string sPathToFile);

/**
 * adds an already loaded cPPMImage to the images vector for processing
 *
 * @param const cPPMImage& image image to add
 * @pre 
 * @return void 
 * @post images contains the new image
 * 
 */
  void addImage(const cPPMImage& image);

/**
 * returns a copy of the output cPPMImage
 *
 * @pre stack should previously have been called
 * @return cPPMImage 
 * @post 
 * 
 */
  cPPMImage getOutput();

/**
 * writes the output image to disk
 *
 * @param std::string sPathToFile path to save location
 * @pre stack should previously have been called
 * @return void 
 * @post output has been written to sPathToFile
 * 
 */
  void writeToFile(std::string sPathToFile);
};
#endif //STACKER_H
