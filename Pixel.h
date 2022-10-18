#ifndef PIXEL_H
#define PIXEL_H

#include "ColorDbl.h"
#include "Ray.h"

/*
CLASS Pixel
Defines a pixel in the rendered image
contains one instance of ColorDbl that holds the color and intensity for this pixel with a high dynamic range.
Has a references to the rays that go through it.
*/

class Pixel
{
public:

    // Contstructors & Destructors
    Pixel();
    Pixel(ColorDbl, Ray);
    virtual ~Pixel();

    // Functions
    ColorDbl getColor();
    void setColor(ColorDbl);

protected:

private:

    // Define variables
    ColorDbl color;

    // reference ray, refRay& don't work with constructors
    Ray refRay = Ray();
};

#endif // PIXEL_H