#include "Pixel.h"

// Default Constructor
Pixel::Pixel()
    : color(ColorDbl(glm::vec3(0.0f, 0.0f, 0.0f))), refRay(Ray())
{
}

// Constructor ColorDbl -> Pixel
Pixel::Pixel(ColorDbl c, Ray r)
{
    color = c;

    refRay = r;
}

// Default Destructor
Pixel::~Pixel()
{
}

// Function getColor, returns ColorDbl color
ColorDbl Pixel::getColor() {
    return color;
}

// Function setColor, sets ColorDbl color
void Pixel::setColor(ColorDbl c) {
    color = c;
}