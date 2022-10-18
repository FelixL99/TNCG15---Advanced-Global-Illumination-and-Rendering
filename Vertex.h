#ifndef VERTEX_H
#define VERTEX_H

#include "../glm/glm/glm.hpp"

/*
CLASS Vertex
Defines three spatial coordinates x,y,z
and a fourth component w = 1.0f for homogeneous coordinates
*/

class Vertex
{
public:

    // Constructors & Destructors
    Vertex();
    Vertex(glm::vec3);
    virtual ~Vertex();

    // Functions
    glm::vec3 getVec3();

protected:

private:

    // Define variables
    glm::vec4 position;
};

#endif // VERTEX_H