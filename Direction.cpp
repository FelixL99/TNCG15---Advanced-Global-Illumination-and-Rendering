#include "Direction.h"

// Default Constructor
Direction::Direction()
{
}

// Constructor, Vertex -> Direction
Direction::Direction(Vertex a)
{
    direction = a;
}

// Default Destructor
Direction::~Direction()
{
}

Vertex Direction::getVertex() {
    return direction;
}