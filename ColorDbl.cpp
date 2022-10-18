#include "ColorDbl.h"

// Default Constructor
ColorDbl::ColorDbl()
{
    color = glm::vec3(0.0f);
}

// Constructor, vec3 -> ColorDbl
ColorDbl::ColorDbl(glm::vec3 c)
{
    color = c;
}

// Default Destructor
ColorDbl::~ColorDbl()
{
}

// Function getColorVec, returns vec3 color
glm::vec3 ColorDbl::getColorVec() {
    return color;
}