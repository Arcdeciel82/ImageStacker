# Image Stacker

A tool used to reduce noise across several images.

# Process

It was a fairly simple process to denoise these images. 

Simply read in all the pixel data from all 10 images, 
then average the color values of each pixel together and output a new image.

# Getting Started

Stacker uses the included cPPMImage library to manage accessing and storing the ppm images.

To stack your own ppm images simply include stacker.h and add the ppm images using relative paths.

```cpp
stacker stack1;
stack1.addImage(std::string sPathToInputFile);
```

When all images have been added to stacker, process the output by calling the stack method.  
Follow with the writeToFile method to create a new ppm image on disk.  

```cpp
stack1.stack();
stack1.writeToFile(std::string sPathToOutputFile);
```

# Results

|Starting Images (with suspiciously uniform noise)|After Image Stacking|
|:---:|:---:|
|![image](https://i.imgur.com/ibaxY6i.png)|![image](https://i.imgur.com/AqCNkMM.png)|
|![image](https://i.imgur.com/ZvyhTR9.png)|![image](https://i.imgur.com/pEtQXPj.png)|
|![image](https://i.imgur.com/PAlP4AZ.png)|![image](https://i.imgur.com/e9ck0B9.png)|
|![image](https://i.imgur.com/HTjeeJe.png)|![image](https://i.imgur.com/qDlcYMc.png)|
