#ifndef TETRAHEDRON_H
#define TETRAHEDRON_H

#pragma once

#include <vector>
#include <cmath>
#include <iostream>
#include <math.h>

#include "Triangle.h"
#include "Ray.h"
#include "ColorDbl.h"

class Tetrahedron
{
public:
	
	// Constructors & Destructors
	Tetrahedron();
	Tetrahedron(Vertex v1, Vertex v2, Vertex v3, Vertex v4, ColorDbl color);
	~Tetrahedron();

	// Functions
	Triangle getTetrahedronTriangle(int _ind);
	bool rayIntersection(Ray& r, glm::vec3 outIntersectionPoint);

private:

	// Define Variables
	vector<Triangle> triangles;
};

#endif // TETRAHEDRON_H