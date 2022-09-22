#include <iostream>
#include <string>

#include "stacker.h"

using namespace std;

int main() {
  string sInputPaths[] = {
    "ppms/cone_nebula/cone_nebula_001.ppm", 
    "ppms/cone_nebula/cone_nebula_002.ppm", 
    "ppms/cone_nebula/cone_nebula_003.ppm", 
    "ppms/cone_nebula/cone_nebula_004.ppm", 
    "ppms/cone_nebula/cone_nebula_005.ppm", 
    "ppms/cone_nebula/cone_nebula_006.ppm", 
    "ppms/cone_nebula/cone_nebula_007.ppm", 
    "ppms/cone_nebula/cone_nebula_008.ppm", 
    "ppms/cone_nebula/cone_nebula_009.ppm", 
    "ppms/cone_nebula/cone_nebula_010.ppm", 
  };
  
  stacker s1;
  for (auto& path : sInputPaths) {
    s1.addImage(path);
  }
  s1.stack();
  s1.writeToFile("test.ppm");

  return 0;
}