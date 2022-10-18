#ifndef CAMERA_H
#define CAMERA_H

#include "Vertex.h"
#include "Pixel.h"
#include "Scene.h"
#include "Direction.h"
#include "Ray.h"
#include "Tetrahedron.h"

//#include "../glm/glm/glm.hpp"

#include <array>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
#include <iostream>

// Image Size, SIZExSIZE
const int SIZE = 800;

/*
CLASS Camera
Defines camera position and handles rendering the scene to an image
*/

class Camera
{
public:

    // Constructors & Destructors
    Camera() : image(SIZE, std::vector<Pixel>(SIZE)) {};
    virtual ~Camera();

    // Functions
    void render(Scene scene);
    void createImage(const string filename = "image.ppm");
    void setEye(int _eye);

protected:

private:

    // Define Variables
    Vertex eye1 = Vertex(glm::vec3(-2.0f, 0.0f, 0.0f));
    Vertex eye2 = Vertex(glm::vec3(-1.0f, 0.0f, 0.0f));
    std::vector<std::vector<Pixel>> image;

    // eyeSwitch (0 -> eye1, 1 -> eye2), changes with function setEye 
    int eyeSwitch = 1;
};

#endif // CAMERA_H