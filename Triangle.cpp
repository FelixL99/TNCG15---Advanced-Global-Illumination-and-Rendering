#include "Triangle.h"
#define M_PI

// Default Constructor
Triangle::Triangle()
{}

// Contructor, 3x Vertex + ColorDbl -> Triangle
Triangle::Triangle(Vertex a, Vertex b, Vertex c, ColorDbl col) // should it be a reference to the surface?
{
    v1 = a;
    v2 = b;
    v3 = c;

    normal = getNormal();

    color = col;
}

// Default Destructor
Triangle::~Triangle()
{
}

// Function getNormal, returns Direction of normal
Direction Triangle::getNormal()
{
    glm::vec3 e1 = v2.getVec3() - v1.getVec3();
    glm::vec3 e2 = v3.getVec3() - v1.getVec3();

    glm::vec3 normlized = (glm::normalize(glm::cross(e1, e2)));
    return Direction(Vertex(normlized));
}

// Function getVertex(int v), returns Vertex point depending on v
Vertex Triangle::getVertex(int v)
{
    if (v == 1)
        return v1;

    if (v == 2)
        return v2;

    return v3;
}

// Function getColor, returns color
ColorDbl Triangle::getColor()
{
    return color;
}

// Function rayIntersection(Ray r, glm::vec3 outPoint), returns bool false if no intersection, true if intersection, inputarg glm::vec3 gets intersectionpoint if true
/* https://en.wikipedia.org/wiki/M%C3%B6ller%E2%80%93Trumbore_intersection_algorithm */
bool Triangle::rayIntersection(Ray& r, glm::vec3 outIntersectionPoint)
{
    const float EPSILON = 0.0000001;
    
    glm::vec3 e1, e2, h, s, q;
    float a, f, u, v;
    
    e1 = v2.getVec3() - v1.getVec3();
    e2 = v3.getVec3() - v1.getVec3();
    h = glm::cross(r.getDirection().getVertex().getVec3(), e2);
    a = glm::dot(e1, h);
    
    if (a > -EPSILON && a < EPSILON)
        return false;    // This ray is parallel to this triangle.

    f = 1.0 / a;
    s = r.getStart().getVec3() - v1.getVec3();
    u = f * glm::dot(s, h);
    
    if (u < 0.0 || u > 1.0)
        return false;
    
    q = glm::cross(s, e1);
    v = f * glm::dot(r.getDirection().getVertex().getVec3(), q);

    if (v < 0.0 || u + v > 1.0)
        return false;
    
    // At this stage we can compute t to find out where the intersection point is on the line.
    float t = f * glm::dot(e2, q);
    r.setT(t);

    if (t > EPSILON) // Ray intersection
    {
        outIntersectionPoint = r.getStart().getVec3() + r.getDirection().getVertex().getVec3() * t;
        return true;
    }
    else // This means that there is a line intersection but not a ray intersection.
        return false;
}