#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

#include "stacker.h"

using namespace std;

int main() {
  string sInputBaseFile = "ppms/";
  stacker s1;
  string sImage;
  string sOutputFile;
  int num;
  cout << "Please enter the image you wish to stack: \n";
  getline(cin, sImage);
  cout << "Please enter the number of images: \n";
  cin >> num;
  cout << "Stacking images:\n";
  
  for (int i = 1; i <= num; i++) {
    stringstream ssFile;
    ssFile << sInputBaseFile << sImage << "/" << sImage;
    ssFile << "_" << setfill('0') << setw(3) << right << i << ".ppm";
    cout << "\t" << ssFile.str() << endl;
    s1.addImage(ssFile.str());
  }
  cout << endl;
  s1.stack();
  sOutputFile = sImage + ".ppm";
  s1.writeToFile(sOutputFile);
  cout << "Stacking completed.\n";
  cout << "Output written to: " << sOutputFile << endl; 

  return 0;
}