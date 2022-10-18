#include "Tetrahedron.h"

// Default Constructor
Tetrahedron::Tetrahedron() 
{
}

// Constructor, 4x Vertex & ColorDbl -> Tetrahedron
Tetrahedron::Tetrahedron(Vertex v0, Vertex v1, Vertex v2, Vertex v3, ColorDbl color) 
{

	// Create 4 faces (Triangles) of a tetrahedra with given color
	triangles.push_back(Triangle(v0, v1, v2, color));
	triangles.push_back(Triangle(v1, v2, v3, color));
	triangles.push_back(Triangle(v0, v1, v3, color));
	triangles.push_back(Triangle(v0, v2, v3, color));
}

// Default Destructor
Tetrahedron::~Tetrahedron() 
{
}

// Function getTetrahedronTriangle, returns triangle in index position _ind
Triangle Tetrahedron::getTetrahedronTriangle(int _ind) 
{
	return triangles[_ind];
}

// Function rayIntersection, checks for intersection between ray and tetrahedron
// The ray will either not intersect the tetrahedron or it intersects two triangles.
// In the latter case we pick the intersection with the lower value of t
bool Tetrahedron::rayIntersection(Ray& r, glm::vec3 outIntersectionPoint)
{
    int intersections = 0;
    glm::vec3 intersectionPoint = glm::vec3(0);
    Ray tempRay = r;

    // Go through all triangles
    for (int i = 0; i < triangles.size(); ++i)
    {
        // Check for intersections
        if (triangles[i].rayIntersection(r, intersectionPoint))
        {
            intersections++;
            // Save the intersection point with the lowest t value
            if (r.getT() <= tempRay.getT()) 
            {
                tempRay = r;
                outIntersectionPoint = intersectionPoint;
            }
        }
    }

    // Return true if we have more than 1 intersection, intersection point saved in variable outIntersectionPoint
    if (intersections > 1)
    {
        return true;
    }
    // Else return false, no intersections
    else
    {
        return false;
    }
}