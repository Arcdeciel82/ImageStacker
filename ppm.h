#ifndef PPM_H
#define PPM_H



#include <string>
#include <vector>

struct strPixel {
    int r = 0;
    int g = 0;
    int b = 0;
};

class cPPMImage {
    private:
    int iWidth;
    int iHeight;
    int iMaxColorValue;
    std::string sMagicNumber;
    std::string sPathToFile;
    std::vector<strPixel> vecData;

    public:
    cPPMImage();
    cPPMImage(const std::string& sPathToFile);
    void ReadFromFile(const std::string& sPathToFile);
    void WriteToFile(const std::string& sPathToFile);
    strPixel& at(int x, int y);
    strPixel at(int x, int y) const;
    void CreateImage(int width, int height, std::string magicNum = "P3", int maxColorValue = 255);
    int width() const;
    int height() const;
};
#endif //PPM_H
