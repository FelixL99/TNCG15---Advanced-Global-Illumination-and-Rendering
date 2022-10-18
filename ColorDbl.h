#ifndef COLORDBL_H
#define COLORDBL_H

#include "../glm/glm/glm.hpp"

/*
CLASS ColorDbl
Defines three double precision variables that contain
the intensities in the R,G,B channels
*/

class ColorDbl
{
public:

    // Constructors & Destructors
    ColorDbl();
    ColorDbl(glm::vec3);
    virtual ~ColorDbl();

    // Functions
    glm::vec3 getColorVec();

    // Operator ColorDbl * float
    ColorDbl operator*(const float& f)
    {
        ColorDbl c;
        c.color = this->color * f;
        return c;
    }

protected:

private:

    // Define variables
    glm::vec3 color;

};

#endif // COLORDBL_H