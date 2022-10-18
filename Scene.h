#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <iostream>
#include <string>
#include <iomanip>

#include "Triangle.h"
#include "Ray.h"
#include "Direction.h"
#include "Vertex.h"
#include "Tetrahedron.h"

using namespace std;

/*
CLASS Scene
Defines the triangles for the scene/room
*/

class Scene
{
public:
    
    // Constructors & Destructors
    Scene();
    virtual ~Scene();
    
    // Functions
    void createRoom();
    void createTetrahedron();
    Triangle triangleIntersected(Ray& r, glm::vec3& intersectionPoint);
    Tetrahedron tetrahedronIntersected(Ray& r, glm::vec3& intersectionPoint);

protected:

private:

    // Define Variables
    vector<Triangle> triangles;
    vector<Tetrahedron> tetrahedrons;

    // Define some colors for the scene
    ColorDbl red = ColorDbl(glm::vec3(1.0f, 0.0f, 0.0f));
    ColorDbl green = ColorDbl(glm::vec3(0.0f, 1.0f, 0.0f));
    ColorDbl blue = ColorDbl(glm::vec3(0.0f, 0.0f, 1.0f));
    ColorDbl orange = ColorDbl(glm::vec3(1.0f, 0.45f, 0.0f));
    ColorDbl gray = ColorDbl(glm::vec3(0.5f, 0.5f, 0.5f));
    ColorDbl cyan = ColorDbl(glm::vec3(0.0f, 1.0f, 1.0f));
    ColorDbl lightGray = ColorDbl(glm::vec3(0.9f, 0.9f, 0.9f));
    ColorDbl white = ColorDbl(glm::vec3(1.0f, 1.0f, 1.0f));
};

#endif // SCENE_H

