#include "Vertex.h"

// Default Constructor
Vertex::Vertex()
{
    position = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
}

// Contstructor, vec3 -> Vertex
Vertex::Vertex(glm::vec3 a)
{
    position = glm::vec4(a, 1.0f);
}

// Default Destructor
Vertex::~Vertex()
{
}

// Function getVec3, returns x,y,z values of Vertex
glm::vec3 Vertex::getVec3()
{
    return glm::vec3(this->position.x, this->position.y, this->position.z);
}