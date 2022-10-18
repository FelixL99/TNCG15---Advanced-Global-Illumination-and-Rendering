#ifndef DIRECTION_H
#define DIRECTION_H

#include "../glm/glm/glm.hpp"

#include "Vertex.h"

/*
CLASS Direction
Defines the direction as a Vertex
*/

class Direction
{
public:

    // Constructors & Destructors
    Direction();
    Direction(Vertex);
    virtual ~Direction();

    // Functions
    Vertex getVertex();

protected:

private:

    // Define variables
    Vertex direction;
};

#endif // DIRECTION_H