#include "Ray.h"

// Default Constructor
Ray::Ray()
    : rayStart(Vertex()), rayEnd(Vertex()), importance(1.0f)
{ }

// Constructor, 2x Vertex (start point, end point) -> Ray
Ray::Ray(Vertex s, Vertex e)
    : rayStart(s), rayEnd(e), importance(1.0f)
{ }

// Default Destructor
Ray::~Ray()
{
}

// Function getStart, returns ray start point
Vertex Ray::getStart()
{
    return rayStart;
}

// Function getDirection, returns direction between start & end point (endPoint - startPoint)
Direction Ray::getDirection()
{
    return Direction(rayEnd.getVec3() - rayStart.getVec3());
}

// Function setColor, set ray color
void Ray::setColor(ColorDbl c)
{
    color = c;
}

// Function getColor, get ray color
ColorDbl Ray::getColor()
{
    return color;
}

// Function setImportance, set importance of ray
void Ray::setT(float _t)
{
    t = _t;
}

// Function getImportance, get importance of ray
float Ray::getT()
{
    return t;
}

// Function setImportance, set importance of ray
void Ray::setImportance(float i)
{
    importance = i;
}

// Function getImportance, get importance of ray
float Ray::getImportance()
{
    return importance;
}




