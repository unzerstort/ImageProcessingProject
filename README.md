# Image Processing Project

This is the final project of the course **Introduction to Programming Techniques (ITP)**, taught by professor Gustavo Girão in 2019.1.

## How to use it

In order to compile and execute the project, all you need to do is clone its repository and run `make` after getting into its root folder so it can create the executable.

```
git clone https://github.com/htmluke/ImageProcessing-ITP
make
./exe
```

## About the project
In this project, we implemented a C program that reads ASCII formatted ppm images (P3) and applies filters according to the user's choice. For such, we developed a diverse amount of functions that range from the ones responsible for the menu to the ones that'll handle the image's pixels.

## Functionalities
The functionalities we developed for this project were divided into two types: the filters and the transformations. The filters are the manipulations which only alter the pixels' colors, while the transformations work by altering their positions inside the matrix.

### Filters

* **Grayscale**
  In order to convert each color to its respective gray tone, we should first obtain the values of each RGB (red, green and blue) pixels. After that, the algorithm we used to make this conversion weights the human eye's sensitivity to these colors. It multiplies each value for its percentage of perception which is 30%, 59% and 11%, respectively.

* **Thresholding**
  The thresholding filter is, basically, a binarization of a grayscaled image. Which means we should first convert a colored image to a grayscaled one and then apply this filter. It is one of the simplest ways of segmentating an image, because it only fixes a constant value and verifies if the pixel value is less than or greater than it, the pixel will be replaced by a black or a white one.

* **Blurring, Sharpening, Edge Detection and Embossing**
  In all of these filters we're using **kernels**, which are small matrices with pre-defined values inside of them, depending on the filter you want to apply. The kernel is applied to the image's pixels and its neighbours by a process called *convolution*. For further explanations about kernels, see https://en.wikipedia.org/wiki/Kernel_(image_processing).

    * **Blurring:** this function simply blurs the image according to the user's choice of intensity.
                    In order to allow that, we implemented a recursive function that receives the image and a n number entered by the user (referring to the blur intensity) and calls itself (n-1) times.

    * **Sharpening:** the sharpening filter basically accentuates edges and minor details of the original
                      image.

    * **Edge Detection:** this filter is based on detecting the points of the image where there are changes
                          in its brightness, which are commonly organized into edges. In our algorithm, we
                          applied the grayscale filter to the image before applying edge detection so we could get better results.

    * **Embossing:** in order to emboss an image, each pixel of it is replaced by a highlight or a shadow,
                     depending on the image's dark/light contrasts. Typically, the low contrast areas are replaced by a gray background, but in our project we didn't do that. We preferred to maintain its color.

* **Negative colors**
  This filter is based on the difference between the maximum RGB value and red, green and blue pixels. After calculating that difference, the results are assigned to its respective pixel.

* **Blacklight**
  The blacklight filter is a simulation of the real UV-A light effect. Firstly we'll calculate the luminance of the image, that is, the same formula we used in the grayscale filter. The algorithm used gets the absolute value between the RGB pixel values amd the luminance (separately, of course), so that it can multiply the result by the intensity the user inserts (a value between 1 and 7), in order to adjust the brightness of the effect.  


### Transformations

* **Rotation**
  This process is basically about changing the pixels' positions through matrix manipulations. We allocated dynamically a matrix with its dimensions inverted, so that the pixels from the original image are passed to the rotated image with its unmodified dimensions, according to the desired rotation.

* **Enlarge**
  The enlarge function requires the dynamic allocation of a new image twice the size of the original and, after that, each pixel from the original image will become four pixels in the enlarged image. The process of filling the new image is made through the parameter of its original pixel, always verifying the already existing pixels. Depending on whether the line or column value of the matrix is odd or even, it's possible to fill the new image maintaining the original image's characteristics.

* **Reduce**
  In the image reduction process, it's possible to notice that its functioning is the opposite of enlarging. Thus, the only ones that need to be observed are the images that contain dimensions of odd values. For them, the solution we obtained was to remove a line of pixels from the dimensions that had odd values. Besides that, after the new image is allocated, it receives, in each new pixel, the average established between four pixels of the original image, returning its reduced version.

* **Reflection**
  The reflection function is similar to the rotation function, since the image will also have its pixels replaced. The only difference is that both the original image's pixels and the reflected image's indexes will be "inverted", so that the reflection may occur, whether it's vertical or horizontal, simulating a mirror reflection.

* **Overlay**
  The overlay process applies an image over another one (simulating png images), being its primary project the application of "borders" and/or marks above images. So that it occurs, one condition is established: after a new image is read (besides the initial image), only the pixels of zero value will be excluded from the image with this proccess applied, considering that RGB values range from 0 to 255. That is, if the pixel value is different from zero, it is passed to the initial image, overlaying the primary pixel. It's important to pay attention to the fact that the image to be applied must have the same size of the initial one, in order to avoid segmentation problems.

## What we would have done differently
  * **Menu**
    Our initial idea for the menu was that the user would be given the choice to do whatever they wanted to with their image, that is, the user should have the possibility to choose more than one filter in sequence. However, the way we initially projected the menu didn't allow the user to do that and we ended up not paying many attention to this. In the end, we were lacking time to alter it.

  * **Convolution process**
    After analyzing the functions that use kernels, I (Sandra) thought we could have made an utilitary function to do every convolution needed without having to repeat it every time we wanted to apply a kernel. Unfortunately, in order to do that, the mentioned function should be generalized to any kernel, which would augment its complexity and would be difficult to implement it (given the lack of time, once more).

  * **Extra filters**
    We wanted to add a wider range of filters, but we spent a lot of time trying to implement the functions that use convolution. It paid off, but we could've done more. For instance, we wanted to add an ordered dithering filter (besides thresholding).

## Authors

* **Lucas Emanoell** - [htmluke](https://github.com/htmluke)
* **Sandra Bastos** - [unzerstort](https://github.com/unzerstort/)

### Each author's contributions

**Lucas Emanoell**
  * Transformation functions (all);
  * Filters that use kernels (all);
  * Negative colors filter;
  * Recursive function to apply blurring;
  * Menu functions.

**Sandra Bastos**
  * File reading and writing;
  * Utility functions;
  * Grayscale, thresholding and blacklight filters;
  * Menu alterations;
  * Code formatting;
  * Makefile;
  * Project documentation, translation and modularization.
