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
  stacker();
  void stack();
  void addImage(std::string sPathToFile);
  void addImage(const cPPMImage& image);
  cPPMImage getOutput();
  void writeToFile(std::string sPathToFile);
};
#endif //STACKER_H
