#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <array>
#include <iostream>
#include <stdlib.h>
#include <math.h>

#include "../glm/glm/glm.hpp"
#include <../glm/glm/gtx/rotate_vector.hpp>

#include "Vertex.h"
#include "Direction.h"
#include "ColorDbl.h"
#include "Ray.h"

using namespace std;

/*
CLASS Triangle
Defines a triangle of three Vertex
Triangle has a color (ColorDbl)
Triangle has a normal direction (Direction)
Function rayIntersection(Ray r) computes intersection between Ray and Triangle with Möller-Trumbore algorithm
*/

class Triangle
{
public:

    // Constructors & Destructors
    Triangle();
    Triangle(Vertex, Vertex, Vertex, ColorDbl);
    virtual ~Triangle();

    // Functions
    Vertex getVertex(int v);
    Direction getNormal();
    ColorDbl getColor();
    bool rayIntersection(Ray& r, glm::vec3 outIntersectionPoint);

protected:

private:

    // Define variables
    Vertex v1;
    Vertex v2;
    Vertex v3;
    ColorDbl color;
    Direction normal;
};

#endif // TRIANGLE_H