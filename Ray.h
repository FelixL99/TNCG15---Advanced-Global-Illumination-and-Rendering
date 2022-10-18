#ifndef RAY_H
#define RAY_H

#include "../glm/glm/glm.hpp"

#include "Vertex.h"
#include "ColorDbl.h"
#include "Direction.h"

/*
CLASS Ray
Defines two instances of Vertex as start and end point of a ray
Ray color is defined as ColorDbl
*/

class Ray
{
public:

    // Constructors & Destructors
    Ray();
    Ray(Vertex s, Vertex e);
    virtual ~Ray();

    // Functions
    Vertex getStart();
    Direction getDirection();
    void setColor(ColorDbl c);
    ColorDbl getColor();
    void setT(float _t);
    float getT();
    void setImportance(float i);
    float getImportance();

protected:

private:

    // Define variables
    Vertex rayStart, rayEnd;
    ColorDbl color;
    float t;
    float importance;
    //float alpha;

};

#endif // RAY_H